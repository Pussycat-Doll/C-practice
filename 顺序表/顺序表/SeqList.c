#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SeqList* ps)//��ʼ��
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListDestory(SeqList* ps)//����
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

SeqListCheckCapacity(SeqList* ps)//����Ƿ���Ҫ���ݣ���ִ��
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity =( ps->_capacity == 0) ? 4 : ps->_capacity*2;
		ps->_array = (DataType*)realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType x)//β��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;

	//SeqListInsert(ps, ps->_size, x);
}
void SeqListPushFront(SeqList* ps, DataType x)//ͷ��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	size_t i = 0;
	for (i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[0] = x;
	ps->_size++;

	//SeqListInsert(ps, 0, x);
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps && ps->_size > 0);
	ps->_size--;

	//SeqListErase(ps, ps->_size-1);
}
void SeqListPopFront(SeqList* ps)//ͷɾ
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[ps->_size - 1] = 0;
	ps->_size--;

	//SeqListErase(ps, 0);
}
void SeqListInsert(SeqList* ps, size_t pos, DataType x)//��ĳ��λ�ò���һ��Ԫ��
{
	assert(ps && pos <= ps->_size);
	SeqListCheckCapacity(ps);
	size_t i = 0;
	for (i = ps->_size; i > pos; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[pos] = x;	
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)//ɾ��ĳ��λ�õ�Ԫ��
{
	assert(ps && pos < ps->_size);
	size_t i = 0;
	for (i = pos; i < ps->_size-1; i++) 
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
size_t SeqListSize(SeqList* ps)//����˳���ʵ������Ԫ�صĸ���
{
	assert(ps);
	return ps->_size;
}

size_t SeqListFind(SeqList* ps, DataType x)//����ĳһ��Ԫ��,�������±�
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
			return i;
	}
	return -1;
}

DataType SeqListAt(SeqList* ps, size_t pos)//����λ��pos��ֵ
{
	assert(ps);
	return ps->_array[pos];
}

void SeqListBubbleSort(SeqList* ps)//��˳������ð������(����)
{//ʱ�临�Ӷȣ�O��N^2��
	assert(ps);
	DataType temp;
	size_t i = 0,j = 0;
	for (size_t i = 0; i < ps->_size; i++)
	{
		for (size_t j = 0; j < ps->_size - i - 1; j++)
		{
			if (ps->_array[j] > ps->_array[j + 1])
			{
				
				temp = ps->_array[j];
				ps->_array[j] = ps->_array[j + 1];
				ps->_array[j + 1] = temp;
			}
		}
	}
}

size_t SeqListBinaryFind(SeqList* ps, DataType x)//���ֲ���
//Ҫ��ʱ�临�Ӷȣ�O(N)   �ռ临�Ӷȣ�O(1)
{
	assert(ps);
	size_t start = 0;
	size_t end = ps->_size - 1;//����ұ�
	//size_t end = ps->_size;//����ҿ�
	size_t mid = start + (end - start) / 2;
	while (start <= end)//Ҫ�������俪��һ��
	{
		if (x > ps->_array[mid])
		{
			start = mid + 1;//���
			mid = start + (end - start) / 2;
		}
		else if (x < ps->_array[mid])
		{
			end = mid - 1;//�ұ�
			mid = start + (end - start) / 2;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, DataType x)//ȥ���ظ���Ԫ��
{
	assert(ps);
	size_t index = 0;
	for (size_t i = 0; i < ps->_size;i++)
	{
		if (ps->_array[i] != x)
		{
			ps->_array[index++] = ps->_array[i];
		}
	}
	ps->_size = index;
}