#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;//定义一个动态生长的数组
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);//返回栈顶
bool Stackempty(Stack* ps);//判断栈是否为空
size_t StackSize(Stack* ps);//返回栈的实际存量

void Stacktest();

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
		size_t newcapacity = (ps->_capacity == 0) ? 2 : (ps->_capacity)* 2;
		ps->_array = (STDataType* )realloc(ps->_array,sizeof( STDataType )*newcapacity);
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

STDataType StackTop(Stack* ps)//返回位于栈顶的元素
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top-1];
}
bool Stackempty(Stack* ps)//判断栈是否为空
{
	assert(ps);
	return ps->_top == 0;
}
size_t StackSize(Stack* ps)//返回栈的实际存量
{
	assert(ps);
	return ps->_top;
}

void Stacktest()
{
	Stack s1;
	StackInit(&s1);
	StackPush(&s1, 9);
	StackPush(&s1, 8);
	StackPush(&s1, 7);
	while (!Stackempty(&s1))
	{
		printf("%d ", StackTop(&s1));
		StackPop(&s1);
	}
	printf("\n");
	StackDestory(&s1);
}