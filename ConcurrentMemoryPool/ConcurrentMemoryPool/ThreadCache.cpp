#define _CRT_SECURE_NO_WARNINGS 1

#include"ThreadCache.h"
#include"CentralCache.h"
void* ThreadCache::Allocte(size_t size)//�����ڴ�
{
	size_t index = Sizeclass::ListIndex(size);//���������ڴ���freelist�е��±�
	FreeList& freeList = _freelist[index];
	if (!freeList.Empty())//���ڴ�
		return freeList.Pop();
	else//û���ڴ�,Ҫ��CentralCacheȡ�ڴ�
	{
		return FetchFromCentralCache(Sizeclass::RoundUp(size));//����size�Ĵ�С��Ҫ���ж���
		//ΪʲôҪ��CentralCache?Ϊ�˾�����Դ��Ϊ�ڴ���Ƭ��׼��
	} 
}
 
//�ͷ��ڴ棬��������ͷ��ڴ棬���ǰѲ��õ��������ٹҵ�freelist��
void ThreadCache::Deallocte(void* ptr,size_t size)
{
	size_t index = Sizeclass::ListIndex(size);
	FreeList& freeList = _freelist[index];
	freeList.Push(ptr);//������������
	//if ()
	{//���ͷŵ��ڴ�̫�࣬��ֱ�ӻ���CentralCache
		//ReleaseToCentralCache();
	}
}
//��������threadcache
//�����Ļ����ȡNum�����󣬷�������һ����ָ�룬ʣ�µ�num-1���ҵ�freelist�еȴ�����
//void* ThreadCache::FetchFromCentralCache(size_t index)
//{
//	//ģ��ȡ�ڴ���� �Ĵ��룬����ThreadCache���߼�
//	size_t num = 20;//�뵥������Ĵ�С�йأ���Ҫ���е�������ȡ�������ڴ�
//	size_t size = (index + 1) * 8;//���㵥���ڴ�Ĵ�С
//	char* start = (char*)malloc(size*num);
//	char* cur = start; 
//	for (size_t i = 0; i < num - 1; ++i)//����������//Ϊʲô��num-1
//	{
//		char* next = cur + size;
//		NextObj(cur) = next;
//		cur = next;
//	}
//	NextObj(cur) = nullptr;//���һ��Ҫָ���
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freelist[index].PushRange(head, tail);
//
//	return start;
//}

void* ThreadCache::FetchFromCentralCache(size_t size)
{
	size_t num = Sizeclass::NumMoveSize(size);
	//��centralcache�л�ȡ�ڴ�
	void* start = nullptr;
	void* end = nullptr;
	size_t ActuallNum = centralcacheInst.FetchRangeObj(start, end, num, size);
	if (ActuallNum == 1)//���ٻ�ȡһ���ڴ����ʧ�ܻ����쳣
		return start;
	else//����ڴ��������
	{
		size_t index = Sizeclass::ListIndex(size);
		FreeList& list = _freelist[index];
		list.PushRange(NextObj(start), end);//ȡ��Ҫ�õ�һ�����ٰ�ʣ�µĹ�����
		return start;
	}
}