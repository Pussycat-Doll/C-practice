#pragma once
#include"commen.h"
#include"stack.h"
void Printarr(int arr[], int left, int right)
{
	for (int i = left; i < right; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void InsertSort(int* arr, int left, int right)
{
	//����end��λ�ô�0�ߵ�n-2
	for (int i = left; i < right-1; ++i)
	{
		//����������[0,end]�����в���tmp����������
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
	//ʱ�临�Ӷȣ�O(n^2),�����ʱ���   1+2+3+������+n-1 = (n-1)n/2
	//ʲôʱ����ã�˳������ O(n)       ���߽ӽ�����Ҳ����
}
void BinInsertSort(int* arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int end = i-1;
		int start = 0;
		int temp = arr[i];
		while (start <= end)//�����۰���Ҽ��ٱȽϵĴ���
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
void TwowayInserSort(int* arr, int left, int right)//����ѭ������
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
	for (int i = 0; i < n; ++i)//��tmp�е����ݰ�˳�򿽱���ԭ������
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
	//1.Ԥ����������ӽ������� gapԽС��Խ�ӽ�����Ҳ����Խ�� gap>1
	//2.ֱ�Ӳ������� gap == 1
	int n = right - left;
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1�Ǳ�֤���һ��һ����1
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
	//ƽ��ʱ�临�Ӷ�:O(n^1.3)
	//ʲô������--˳�������ʱ����Ϊ��ʱԤ����Ĺ���������
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
		if (start == max_index)//�������ֵ�պ�����Сֵ��λ���ϣ�����Сֵ�������󣬰����ֵ��������min_index��λ����
			max_index = min_index;
		if (max_index != end)
			swap(&arr[end], &arr[max_index]);
		//printf("[%d,%d]����", start, end);
		//Printarr(arr, 0, right);
		++start;
		--end;

	}
	//ʱ�临�Ӷ�:n,n-2,n-4,...,0 Լ����O(n^2)
	//ֱ�Ӳ������򼸺�������������ú���Ķ���O(n^2)
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
	//��С�ѡ�������
	//���򡪡������
	while (curpos >= 0)
	{
		_shiftdown(arr, n, curpos);
		--curpos;
	}
	int end = n;
	while (end > 0)
	{
		--end;//�ѶѶ���ǰ���������ڵ����
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
		for (int j = 0; j < n - i - 1; ++j)//��������
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//˵���Ѿ�����
			break;
	}
}
int Partition_1(int* arr, int start, int end)//����ָ�뷨
{
	int key = arr[start],keyindex = start;//ͷ��Ϊkeyβ���ߣ�β��keyͷ����
	while (start < end)
	{
		while (start < end && arr[end] >= key)//�Ҵ��
			--end;
		while (start < end && arr[start] <= key)//��С
			++start;
		swap(&arr[start], &arr[end]);
	}
	swap(&arr[keyindex], &arr[end]);
	return end;
}
int Partition_2(int* arr, int start, int end)//�ڿӷ�(���ϵ���ӣ��ڿ�)
{
	int key = arr[end];
	while (start < end)
	{
		//��С
		while (start < end && arr[start] <= key)
			++start;
		arr[end] = arr[start];//�ҵ���С�ӵ��ұߵĿ���ȥ��ͬʱ�Լ��γ��µĿ�λ
		while (start < end && arr[end] >= key)
			--end;
		arr[start] = arr[end];//�ҵ�����ӵ���ߵĿ���ȥ��ͬʱ�Լ��γ��µĿ�
	}
	arr[start] = key;
	return start;
}
int GetMid(int* arr, int begin, int end)//��λȡ�з�
{
	int mid = (begin + end) >> 1;
	if (arr[begin] > arr[mid])
	{
		if (arr[begin] < arr[end])   //end>begin>mid
			return begin;
		else if (arr[mid] > arr[end])//begin>mid>end
			return mid;
		else                         //begin>end>mid
			return end;
	}
	else//begin<mid
	{
		if (arr[begin] > arr[end])    //mid>begin>end
			return begin;
		else if (arr[end] > arr[mid]) //end>mid>begin
			return mid;
		else                          //mid>end>begin
			return end;
	}
}
int Partition_3(int* arr, int start, int end)//ǰ��ָ�뷨
{
	int midindex = GetMid(arr, start, end);
	swap(&arr[midindex], &arr[end]);

	int key = arr[end];
	int prev = start - 1;//prev�Ҵ�
	int cur = start;//��С
	while (cur < end)//����key��λ�þ���ֹ
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
	//ʱ�临�Ӷ�:O��n*logn��
	//����ʲôʱ������������������ʱ��
}
void QuickSortNor(int* arr, int begin, int end)//���ŷǵݹ�д��
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, begin);
	LinkStackPush(&st, end);

	while (!LinkStackIsEmpty(&st))
	{
		int right = LinkStackTop(&st);
		LinkStackPop(&st);
		int left = LinkStackTop(&st);
		LinkStackPop(&st);

		int pos = Partition_2(arr, left, right);
		//[left,pos-1] pos [pos+1,right]
		if (left < pos-1)
		{
			LinkStackPush(&st, left);
			LinkStackPush(&st, pos - 1);
		}
		if (pos + 1 < right)
		{
			LinkStackPush(&st, pos + 1);
			LinkStackPush(&st, right);
		}
	}
	LinkStackDestroy(&st);
}

void _MergeSort(int* arr, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) >> 1;

	//������鲢����������
	_MergeSort(arr, tmp, begin, mid);
	_MergeSort(arr, tmp, mid+1, end);

	//����������鲢��һ��
	//[begin,mid][mid+1,end]
	int begin1 = begin,end1 = mid;
	int begin2 = mid + 1,end2 = end;
	int tmpi = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[tmpi++] = arr[begin1++];
		else
			tmp[tmpi++] = arr[begin2++];
	}
	while(begin1 <= end1)
		tmp[tmpi++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[tmpi++] = arr[begin2++];
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}

void CountSort(int* arr, int n)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int range = max-min + 1;
	int* countarr = malloc(sizeof(int) * range);
	memset(countarr, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)//ͳ�ƴ���
	{
		++countarr[arr[i]-min];
	}
	int j = 0;
	for (int i = 0; i < range; ++i)//���ݴ�������
	{
		while (countarr[i] > 0)
		{
			arr[j++] = i + min;
			--countarr[i];
		}	
	}
	//ʱ�临�Ӷȣ�O(Max(range,N))
	//�ռ临�Ӷȣ�O(range)
}
