#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int HPDatatype;

typedef struct Heap
{
	HPDatatype* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDatatype* a, int n);
void HeapDestroy(Heap* hp);

void AdjustDown(HPDatatype* a, size_t n, size_t parent);
void AdjustUp(HPDatatype* a, size_t child);

void HeapPush(Heap* hp,HPDatatype x);
void HeapPop(Heap* hp);

HPDatatype HeapTop(Heap* hp);
int HeapSize(Heap* hp);
bool HeapEmpty(Heap* hp);

void HeapPrint(Heap* hp);

void HeapSort(int* a, int n);
void Testheap1();

