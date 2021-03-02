#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}