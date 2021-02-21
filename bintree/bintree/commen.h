
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#define ElemType char

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}