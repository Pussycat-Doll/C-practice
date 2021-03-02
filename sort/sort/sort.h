#pragma once
#include"commen.h"

void Printarr(int arr[], int left, int right)
{
	for (int i = left; i < right; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void InsertSort(int* arr, int left, int right)
{
	//控制end的位置从0走到n-2
	for (int i = left; i < right-1; ++i)
	{
		//单趟排序，在[0,end]区间中插入tmp，依旧有序
		int end = i;
		int temp = arr[i+1];
		while (end >= left)
		{
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
				break;
		}
		arr[end + 1] = temp;
	}
	//时间复杂度：O(n^2),逆序的时候最坏   1+2+3+。。。+n-1 = (n-1)n/2
	//什么时候最好：顺序有序 O(n)       或者接近有序也不错
}
void BinInsertSort(int* arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int end = i-1;
		int start = 0;
		int temp = arr[i];
		while (start <= end)//利用折半查找减少比较的次数
		{
			int mid = start + (end - start) / 2;
			if (temp > arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}
		for (int j = i-1; j >= end + 1; --j)
			arr[j + 1] = arr[j];
		arr[end+1] = temp;
	}
}
void TwowayInserSort(int* arr, int left, int right)//利用循环队列
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp != NULL);

	tmp[0] = arr[left];
	int start = 0, end = 0;

	for (int i = left = 1; i < right; ++i)
	{
		if (arr[i] < tmp[start])
		{
			start = (start - 1 + n) % n;
			tmp[start] = arr[i];
		}
		else if (arr[i] > tmp[end])
		{
			tmp[++end] = arr[i];
		}
		else
		{
			int finish = end;
			while (arr[i] < tmp[finish])
			{
				tmp[(finish + 1) % n] = tmp[finish];
				finish = (finish - 1 + n) % n;
			}
			tmp[(finish + 1) % n] = arr[i];
			++end;
		}
	}
	int k = start;
	for (int i = 0; i < n; ++i)//将tmp中的数据按顺序拷贝到原数组中
	{
		arr[i] = tmp[k];
		k = (k + 1) % n;
	}
	free(tmp);
}
void TestSortEfficiency()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
		a[i] = rand();

	time_t start = clock();
	InsertSort(a, 0, n);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);
}
void ShellSort(int* arr, int left, int right)
{
	//1.预排序：让数组接近于有序 gap越小，越接近有序，也跳得越慢 gap>1
	//2.直接插入排序 gap == 1
	int n = right - left;
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1是保证最后一次一定是1
		for (int i = left; i < n-gap; ++i)
		{
			int end = i;
			int tmp = arr[i + gap];
			while (end >= left)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
	//平均时间复杂度:O(n^1.3)
	//什么情况下最坏--顺序有序的时候，因为此时预排序的工作白做了
}
void SelectSort(int* arr, int left, int right)
{
	int start = left,end = right-1;
	while (start < end)
	{
		int min_index = start;
		for (int i = start+1; i <= end; ++i)
		{
			if (arr[i] < arr[min_index])
				min_index = i;
		}
		if(min_index != start)
			swap(&arr[start], &arr[min_index]);
		++start;
	}
}
void SelectSort_1(int* arr, int left, int right)
{
	int start = left,end = right-1;
	while (start < end)
	{
		int min_index = start,max_index = start;
		for (int i = start; i <= end; ++i)
		{
			if (arr[i] < arr[min_index])
				min_index = i;
			if (arr[i] > arr[max_index])
				max_index = i;
		}
		if(min_index != start)
			swap(&arr[start], &arr[min_index]);
		if (start == max_index)//假如最大值刚好在最小值的位置上，在最小值交换过后，把最大值交换到了min_index的位置上
			max_index = min_index;
		if (max_index != end)
			swap(&arr[end], &arr[max_index]);
		//printf("[%d,%d]——", start, end);
		//Printarr(arr, 0, right);
		++start;
		--end;

	}
	//时间复杂度:n,n-2,n-4,...,0 约等于O(n^2)
	//直接插入排序几乎是最差的排序最好和最坏的都是O(n^2)
}
void _shiftdown(int* arr, int n, int curpos)
{
	int parent = curpos;
	int child = 2 * parent+1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* arr, int left, int right)
{
	int n = right - left;
	int curpos = n/2-1;
	//建小堆——降序
	//升序——建大堆
	while (curpos >= 0)
	{
		_shiftdown(arr, n, curpos);
		--curpos;
	}
	int end = n;
	while (end > 0)
	{
		--end;//把堆顶当前最大的数调节到最后
		swap(&arr[0], &arr[end]);
		_shiftdown(arr, end, 0);
	}
}
void BubbleSort(int* arr, int left, int right)
{
	int n = right - left;
	int flag = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)//单趟排序
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//说明已经有序
			break;
	}
}
int Partition_1(int* arr, int start, int end)//左右指针法
{
	int key = arr[start],keyindex = start;//头作为key尾先走，尾作key头先走
	while (start < end)
	{
		while (start < end && arr[end] >= key)//找大的
			--end;
		while (start < end && arr[start] <= key)//找小
			++start;
		swap(&arr[start], &arr[end]);
	}
	swap(&arr[keyindex], &arr[end]);
	return end;
}
int Partition_2(int* arr, int start, int end)//挖坑法(不断的填坑，挖坑)
{
	int key = arr[end];
	while (start < end)
	{
		//找小
		while (start < end && arr[start] <= key)
			++start;
		arr[end] = arr[start];//找到的小扔到右边的坑里去。同时自己形成新的坑位
		while (start < end && arr[end] >= key)
			--end;
		arr[start] = arr[end];//找到大的扔到左边的坑里去。同时自己形成新的坑
	}
	arr[start] = key;
	return start;
}
int Partition_3(int* arr, int start, int end)//前后指针法
{
	int key = arr[end];
	int prev = start - 1;//prev找大
	int cur = start;//找小
	while (cur < end)//遇到key的位置就终止
	{
		if (arr[cur] < key && ++prev != cur)
			swap(&arr[cur], &arr[prev]);
		++cur;
	}
	++prev;
	swap(&arr[prev], &arr[end]);
	return prev;
}
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyindex = Partition_1(arr, begin, end);
	//int keyindex = Partition_2(arr, begin, end);
	int keyindex = Partition_3(arr, begin, end);
	//[begin,pos-1] pos [pos+1,end]
	QuickSort(arr, begin, keyindex -1);
	QuickSort(arr, keyindex + 1, end);
	//时间复杂度:O（n*logn）
	//快排什么时候很慢——数组有序的时候
}
