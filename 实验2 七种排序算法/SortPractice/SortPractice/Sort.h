#pragma once

//using namespace std;
//////////////////////////////////////////////////////////////////////////
template<class T>
class CSort
{
private:
	T* IntData;
	int IntDataNum;
	int SortMethod;
	char ro;
	//比较两个数的大小
	inline bool comp(T& a, T& b)
	{
		if (ro == '<')return a < b;
		else          return a > b;
	}
public:
	CSort(T* , int , int, char op);
	~CSort();
public:
	
	//冒泡排序
	void BubbleSort(T*, const int );
	//选择排序
	void SelectSort(T*, const int);

	//插入排序	
	void InsertSort(T*, const int);
	//堆排序
	void HeapAdjust(T*, const int, const int);
	void HeapSort(T*, const int);
	//希尔排序
	void ShellSort(T*, const int);
	//归并排序
	void Merge(T*, T*, int, int, int);
	void MergeSort(T*, const int);
	//快速排序	
	void QuickSort(T*, const int);
	//调用其他排序函数
	void Sort();
};