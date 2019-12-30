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
	STDataType* _array;//����һ����̬����������
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);//����ջ��
bool Stackempty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
size_t StackSize(Stack* ps);//����ջ��ʵ�ʴ���






