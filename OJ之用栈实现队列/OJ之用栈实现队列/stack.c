#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_array != NULL)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 2 : (ps->_capacity) * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

STDataType StackTop(Stack* ps)//����λ��ջ����Ԫ��
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}
bool Stackempty(Stack* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top == 0;
}
size_t StackSize(Stack* ps)//����ջ��ʵ�ʴ���
{
	assert(ps);
	return ps->_top;
}
