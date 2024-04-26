#include "Sort.h"
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
/////////////////////////////////////////////////////////////////////////////////////////
//构造函数
template <class T>
CSort<T>::CSort(T *a, int m, int sm, char op)
{
	IntData = a;
	IntDataNum = m;
	SortMethod = sm;
	ro = op;	
}
//析构函数
template <class T>
CSort<T>::~CSort()
{
}
////////////////////////////////////////////////////////////////
//调用其它排序函数
template<class T>
void CSort<T>::Sort()
{
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||==========================运行排序算法=========================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;

	switch (SortMethod)
	{
	case 1: //冒泡排序
		cout << "\t||                           1: 冒泡排序                         ||" << endl;
		BubbleSort(IntData, IntDataNum);
		break;
	case 2: //选择排序
		cout << "\t||                           2: 选择排序                         ||" << endl;
		SelectSort(IntData, IntDataNum);
		break;
	case 3: //插入排序
		cout << "\t||                           3: 插入排序                         ||" << endl;
		InsertSort(IntData, IntDataNum);
		break;
	case 4: //堆排序
		cout << "\t||                           4: 堆排序                           ||" << endl;
		HeapSort(IntData, IntDataNum);
		break;
	case 5: //Shell排序
		cout << "\t||                           5: 希尔排序                         ||" << endl;
		ShellSort(IntData, IntDataNum);
		break;
	case 6: //归并排序
		cout << "\t||                           6: 归并排序                         ||" << endl;
		MergeSort(IntData, IntDataNum);
		break;
	case 7: //快速排序
		cout << "\t||                           7: 快速排序                         ||" << endl;
		QuickSort(IntData, IntDataNum);
		break;	
	}
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;	

}
/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void CSort<T>::BubbleSort(T* d, const int n)
{
	///////////////////////////////////////////////
	//在下面补充冒泡排序代码
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		bool flag = false;
		for (j = 0; j < n - i; j++)
		{
			k = j + 1;
			if (comp(d[k], d[j]))// 相邻元素两两相比
			{
				swap(d[j], d[k]);// 元素对换		
				flag = true;
			}
		}
		if (flag == false) break;
	}
}
////////////////////////////////////////////////////
//直接选择排序
template<class T>
void CSort<T>::SelectSort(T* d, const int n)
{
	//////////////////////////////////////////////////////////////
	//在下面补充选择排序代码
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;                          //i为无序序列首索引		
		for (j = i + 1; j < n; j++)     //搜索无序序列最小元素的索引k
		{
			if (comp(d[j], d[k])) k = j;
		}
		if (k != i)swap(d[i], d[k]);   //无序序列首元素与最小元素交换
	}	
}
/////////////////////////////////////////////////////////////////////////////////////////
//直接插入排序
template<class T>
void CSort<T>::InsertSort(T* d, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;    //有序序列最后一个数据的索引
		T a = d[i];       //无序序列第一个数据
		while (k >= 0 && comp(a, d[k])) //数据逐一向后移位
		{
			d[k + 1] = d[k];
			k--;
		}
		d[k + 1] = a; //将无序序列第一个数据置于有序序列中
	}
}
///////////////////////////////////////////////////////////////////////////////////////////
//堆排序
template<class T>
void CSort<T>::HeapAdjust(T* d, int left, int right)
{
	T a = d[left];	//根结点	
	for (int j = 2 * left + 1; j <= right; j = 2 * j + 1) //2 * left + 1左叶
	{
		if (j < right && comp(d[j], d[j + 1])) j++;       //j + 1右叶
		if (comp(d[j], a)) break;  //满足堆条件终止循环
		d[left] = d[j];            //叶结点置于根结点
		left = j;		           //改变根索引为叶索引
	}
	d[left] = a; //根结点置于叶结点
}
template<class T>
void CSort<T>::HeapSort(T* d, const int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)HeapAdjust(d, i, n - 1); //建初始堆
	for (int i = n - 1; i > 0; i--)
	{
		swap(d[0], d[i]);          //交换堆顶与堆尾元素
		HeapAdjust(d, 0, i - 1);   //剩余元素重新建堆
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void CSort<T>::ShellSort(T* d, const int n)
{
	int h = 1;
	while (h < n / 3)h = h * 3 + 1; //动态定义增量序列
	while (h > 0)                   //逐渐缩小增量h作直接插入排序
	{
		for (int i = h; i < n; i++) //在当前增量h下对各子序列作直接插入排序
		{
			int j = i - h;      //当前子序列的有序序列最后一个元素的索引
			T a = d[i];         //无序序列的第一个元素			
			while (j >= 0 && comp(a , d[j]))
			{
				d[j + h] = d[j];
				j -= h;
			}
			d[j + h] = a;       //将d[i]插到j + h的位置
		}
		h = h / 3;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//归并排序-非递归方式
template<class T>
void CSort<T>::MergeSort(T* d, const int n)
{
	int size = 1, left, mid, right;//size为子序列长度	
	T* w = new T[n];
	while (size < n)
	{
		left = 0;   //子序列左结点
		while (left + size < n)
		{
			mid = left + size - 1; //子序列中间结点
			right = mid + size;    //子序列右结点
			if (right >= n)right = n - 1;   //右序列长度小于size				
			Merge(d, w, left, mid, right);  //归并两子序列
			left = right + 1;               //下一次归并时左序列的首索引
		}
		size *= 2; //序列长度增加一倍		
	}
	delete[]w;
}
//将序列[first,mid]和[mid+1,right]合并成一个有序序列 
template<class T>
void CSort<T>::Merge(T* d, T* w, int left, int mid, int right)
{
	int i = left;      //左序列起始位置  
	int j = mid + 1;   //右序列起始位置   
	int k = left;      //辅助数组起始位置
	while (k <= right) //两个有序序列最小元素先放入辅助数组
	{
		if (i > mid)w[k++] = d[j++];
		else if (j > right)	w[k++] = d[i++];
		else
		{
			if (comp(d[j], d[i])) w[k++] = d[j++];
			else w[k++] = d[i++];
		}
	}
	//将有序序列替换原有序列
	for (int k = left; k <= right; k++) d[k] = w[k];
}
/////////////////////////////////////////////////////////////////////////////////////////
//快速排序-递归方式
template<class T>
void CSort<T>::QuickSort(T* d, const int n)
{
	if (n <= 1)return;
	const int M = 7, NSTACK = 128; //子序列长度小于7，采用插入排序
	int i, j, k, jstack = -1, left = 0, mid, right = n - 1;
	int istack[NSTACK];
	while (true)
	{
		if (right - left < M)   //插入法排序
		{
			for (j = left + 1; j <= right; j++)
			{
				T a = d[j];
				for (i = j - 1; i >= left && comp(a, d[i]); i--)d[i + 1] = d[i]; //移位				
				d[i + 1] = a; //插入到准确位置
			}
			if (jstack < 0) break;     //排序终止
			right = istack[jstack--];  //子序列右结点
			left = istack[jstack--];  //子序列左结点
		}
		else   //快速排序
		{
			i = left + 1;      //左指针
			j = right;         //右指针
			k = i;             //基准数的索引
			//三元素中值点作为基准数，避免序列为正常序列
			//d[left] < d[k] < d[right]
			mid = (left + right) / 2;
			swap(d[mid], d[k]);
			if (comp(d[right], d[left]))swap(d[left], d[right]);
			if (comp(d[right], d[k]))   swap(d[k], d[right]);
			if (comp(d[k], d[left]))    swap(d[left], d[k]);
			while (true)
			{
				//先从右边开始寻找小于基准数的d[j] 			
				do j--; while (comp(d[k], d[j]));
				//再从左边开始寻找大于基准数的d[i] 		
				do i++; while (comp(d[i], d[k]));
				if (j < i)break;
				//交换d[j]和d[i] 			
				swap(d[i], d[j]);
			}
			swap(d[j], d[k]);//基准数归位	
			jstack += 2;
			if (right - i + 1 >= j - left) //右序列长度大于左序列长度
			{
				istack[jstack - 1] = i;    //右序列左结点
				istack[jstack] = right;    //右序列右结点				
				right = j - 1;             //左序列右节点
			}
			else                           //左序列长度大于右序列长度
			{
				istack[jstack - 1] = left; //左序列左结点
				istack[jstack] = j - 1;	   //左序列右结点			
				left = i;                  //右序列左节点
			}
		}
	}
}
