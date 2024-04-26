#pragma once
#include <string>
using namespace std;

template <class T>
class TwoArray
{
	//template <class T1>
	//friend ostream& operator << (ostream& out, TwoArray<T1>& c);
	//template <class T1>
	//friend ostream& operator << (ostream& out, TwoArray<T1>& c);
public:

	TwoArray(TwoArray& d) { copyIntoP(d); }
	TwoArray& operator = (TwoArray& d) { copyIntoP(d);  return *this;	}
	TwoArray(int s1, int s2)
	{
		int  size = s1 * s2;
		a = new T[size];
		size1 = s1;
		size2 = s2;
	}
	virtual ~TwoArray(void)
	{
		if (a != nullptr)	delete[] a;
	}
	int  get_size1()  const { return size1; }
	int  get_size2()  const { return size2; }
	T& operator()  (int i, int j)
	{
		if (i < 0 || i >= size1)
			throw string("FirstOutOfBounds");
		if (j < 0 || j >= size2)
			throw string("SecondOutOfBounds");
		return a[i * size2 + j];
	}
private:
	void copyIntoP(const TwoArray& d);
	int size1;
	int size2;
	T* a;
};

template <class T>
void TwoArray<T>::copyIntoP(const TwoArray& d)
{	
	if (this == &d)	return;
	if (a != nullptr)	delete[] a;
	if (d.a != nullptr) {
		a = new T[(size1 = d.size1) * (size2 = d.size2)];
		for (int i = 0; i < size1*size2; i++)
			a[i] = d[i];//d.a[i];
	}
	else {
		a = nullptr;
		size1 = 0;
		size2 = 0;
	}
}

template <class T>
istream& operator >> (istream& in, TwoArray<T>& c)
{
	for (int i = 0; i < c.get_size1(); i++)
	{
		for (int j = 0; j < c.get_size2(); j++)
			in >> c(i, j);
	}
	return in;
}

template <class T>
ostream& operator << (ostream& out, TwoArray<T>& c)
{
	for (int i = 0; i < c.get_size1(); i++)
	{
		for(int j=0;j<c.get_size2();j++)
			out << c(i,j) << endl;
	}
	return out;
}