#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void InsertSort(int* arr, int n)//����
{
	for (int i = 0; i < n - 1; i++)//���˲����������һ����Ϊ�������飬�ӵڶ�������ʼ��������������룩
	{
		//���ˣ��൱����һ���Ѿ�����������в���һ������
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = temp;
	}
}
void ShallSort(int* arr, int n)//��Ԥ�����ٽ��в�������
//����ѭ����gapԽ��ԽС�����Ϊ1��ʱ����ǲ�������
{
	for (int gap = n / 3; gap > 0; gap = gap/3 +1)//Ϊʲô���ܼ�1....
	{
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = temp;
		}
	}	
}
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	int min_index = 0;
	int max_index = 0;
	for (size_t i = 0; i < (n-1)/2; i++)
	{
		begin = i;
		end = n - i - 1;
		while (begin < end)
		{
			if (arr[begin] < arr[min_index])
			{
				min_index = begin;
			}
			if (arr[begin] > arr[max_index])
			{
				max_index = begin;
			}
			begin++;
		}
		swap(&arr[i], &arr[min_index]);
		swap(&arr[n - i - 1], &arr[max_index]);
	}
}
int partone1(int* arr, int left, int right)//����ָ�뷨
{
	int key = arr[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;
		while (left < right && arr[right] >= key)
			right--;
		if (left < right)
		{
			swap(&arr[left], &arr[right]);
		}
	}
	swap(&arr[left], &arr[key_index]);
	return left;
}
void select_mid(int* arr, int left, int right)//���м�ֵ����right��λ����ȥ
{
	int mid = left + (right - left) / 2;
	if (arr[mid] > arr[left] && arr[mid] < arr[right])
		swap(&arr[mid], &arr[right]);
	if (arr[mid] < arr[left] && arr[mid] > arr[right])
		swap(&arr[mid], &arr[right]);
	if (arr[left] > arr[right] && arr[left] < arr[mid])
		swap(&arr[left], &arr[right]);
	if (arr[left] < arr[right] && arr[left] > arr[mid])
		swap(&arr[left], &arr[right]);
}

int partone2(int* arr, int left, int right)//�ڿӷ�
{
	int key = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] < key)
		{
			left++;
		}
		arr[right] = arr[left];
		while (left < right && arr[right] > key)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}
int partSort3(int*arr, int left, int right)
{
	int key = arr[right];
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (arr[cur] < key && prev++ != cur)
		{
			swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	prev++;
	swap(&arr[prev], &arr[cur]);
	return prev;
}


void QuickSort(int* arr, int left, int right)
{
	select_mid(arr, left, right);//�Ż�һ��������ȡ�м�ֵ�����ⷢ��������������ʱ�临�Ӷ�ΪO(N^2)��
	int key = arr[right];
	if (left > right)
		return;
	if (right - left + 1 < 10)//�����Ż�������ʣ�������С��ʱ���ò�������
	{
		InsertSort(arr + left, right - left + 1);
		return;
	}
	int key_index = partSort3(arr, left, right);
	if (left < key_index - 1);
		QuickSort(arr, left, key_index - 1);
	if (right > key_index + 1)
		QuickSort(arr, key_index + 1, right);
}

void Merge(int* arr, int left, int mid, int right, int* temp)
//�Ƚ����������е�Ԫ�أ�����С��ȡ�����Ž���ʱ����temp��
//[left, mid] [mid+1, right]
//�ٽ���Ż�ԭ������
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[i++] = arr[begin1++];
		else
			temp[i++] = arr[begin2++];
	}
	//if (begin1 == end1)
	{
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}
	}
	//if (begin2 == end2)
	{
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
	}
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
}
void _Margesort(int* arr, int left, int right, int* temp)
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;
	_Margesort(arr, left, mid, temp);//ʹ�������
	_Margesort(arr, mid + 1, right, temp);//ʹ�ұ�����
	Merge(arr, left, mid, right, temp);//�鲢�������������
}
void MargeSort(int *arr,int n)
{
	int *temp = (int*)malloc(sizeof(int)* n);//����һ����ʱ����
	if (temp == NULL)
		return ;
	_Margesort(arr, 0, n - 1,temp);
	free(temp);
}

void Print(int* arr, int _size)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test()
{

	int array[] = { 1, 9, 3, 0, 4, 2, 5, 7, 8 ,6};
	int size = sizeof(array) / sizeof(int);
	//InsertSort(array, size);
	//Print(array,size);
	//ShallSort(array, size);
	//Print(array, size);
	//SelectSort(array, size);
	//Print(array, size);
	//int x = partone1(array, 0, 9);
	QuickSort(array, 0, 9);
	Print(array, size);
	//MargeSort(array, size);
	//Print(array, size);
}