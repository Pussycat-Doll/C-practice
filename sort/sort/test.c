#include"sort.h"

void main()
{
	int arr[] = { 49,38,65,97,76,13,27,49 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Printarr(arr, 0, n);
	//InsertSort(arr, 0, n);
	//BinInsertSort(arr, 0, n);
	//TwowayInserSort(arr, 0, n);
	//ShellSort(arr, 0, n);
//	SelectSort(arr, 0, n);
	//SelectSort_1(arr, 0, n);
	//HeapSort(arr, 0, n);
	//BubbleSort(arr,0,n);
	QuickSort(arr, 0, n-1);
	Printarr(arr, 0, n);

	//TestSortEfficiency();

}