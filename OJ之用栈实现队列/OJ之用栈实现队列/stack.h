#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

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






