#include<iostream>
using namespace std;


class Student
{
	//��Ա��������������Ա������������ж��壬
	//���������ܻὫ�䵱������������
public:
	void ShowInfor()
	{
		cout << _age << endl;
		cout << _name << endl;
		cout << _stuid << endl;
	}
	int GetAGe()
	{
		return _age;
	}
private:
	char _name[10];//��Ա����һ��������ǱȽ���˽��,�������˽�л��߱���
	int _age;
	int _stuid;
	 	 
};
//struct��Ĭ���޶�����Public
//classĬ���ǹ��е�
//int main()
//{
//	Student s1;
//	Student s2;
//	//s1._age = 19;
//	cout << s1.GetAGe() << endl;
//	return 0;
//}

//����һ�����ݽṹջ����
class Stack
{
public:
	void Init(size_t n)
	{}
	void Destory()
	{}
	void Push(int x)
	{}
private:
	int* _a;
	size_t _top;
	size_t _capacity;
};
int main()
{

	return 0;
}