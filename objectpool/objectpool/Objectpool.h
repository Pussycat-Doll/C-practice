#pragma once

template<class T,size_t InitNum = 100>
class ObjectPoll
{
public:
	ObjectPoll()
	{
		_start = _end = (char* )malloc(InitNum*sizeof(T));
	}
	T* New()//申请一个对象出来
	{
		if (_start == _end)
			_start = _end = (char*)malloc(InitNum*sizeof(T));
		T* obj = (char* )_start;
		_start += sizeof(T);//???

		new(obj)T;//new的定位表达式:如果数据是从内存池开的，就可以显式调用构造函数并且初始化
		return obj;
	}

	void Delete(T* ptr)//先调用析构函数，再释放内存
	{
		ptr->~T();//显式调用析构函数
		*(int*)ptr = _freeList;
		_freeList = ptr;
	}
private:
	char* _start;
	char* _end;//用char*而不用T*,因为char* +1，刚好+一个字节，更加方便管理内存池指针

	T* _freeList;
};
