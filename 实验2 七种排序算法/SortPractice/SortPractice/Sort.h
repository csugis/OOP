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
	//�Ƚ��������Ĵ�С
	inline bool comp(T& a, T& b)
	{
		if (ro == '<')return a < b;
		else          return a > b;
	}
public:
	CSort(T* , int , int, char op);
	~CSort();
public:
	
	//ð������
	void BubbleSort(T*, const int );
	//ѡ������
	void SelectSort(T*, const int);

	//��������	
	void InsertSort(T*, const int);
	//������
	void HeapAdjust(T*, const int, const int);
	void HeapSort(T*, const int);
	//ϣ������
	void ShellSort(T*, const int);
	//�鲢����
	void Merge(T*, T*, int, int, int);
	void MergeSort(T*, const int);
	//��������	
	void QuickSort(T*, const int);
	//��������������
	void Sort();
};