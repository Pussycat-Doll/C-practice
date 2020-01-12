#pragma once

template<class T,size_t InitNum = 100>
class ObjectPoll
{
public:
	ObjectPoll()
	{
		_start = _end = (char* )malloc(InitNum*sizeof(T));
	}
	T* New()//����һ���������
	{
		if (_start == _end)
			_start = _end = (char*)malloc(InitNum*sizeof(T));
		T* obj = (char* )_start;
		_start += sizeof(T);//???

		new(obj)T;//new�Ķ�λ���ʽ:��������Ǵ��ڴ�ؿ��ģ��Ϳ�����ʽ���ù��캯�����ҳ�ʼ��
		return obj;
	}

	void Delete(T* ptr)//�ȵ����������������ͷ��ڴ�
	{
		ptr->~T();//��ʽ������������
		*(int*)ptr = _freeList;
		_freeList = ptr;
	}
private:
	char* _start;
	char* _end;//��char*������T*,��Ϊchar* +1���պ�+һ���ֽڣ����ӷ�������ڴ��ָ��

	T* _freeList;
};
