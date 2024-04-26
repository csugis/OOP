#pragma once
#include <string>

using namespace std;

template <class T>
class Array
{
	//template <class T1>
	//friend ostream& operator << (ostream& out, Array<T1>& c);
	//template <class T1>
	//friend ostream& operator << (ostream& out, Array<T1>& c);
public:
	Array(void) : size(0), a(nullptr) {}
	Array(int s) 
	{
		a = new T[s];
		size = s;
	}
	Array(const Array& d) { copyIntoP(d); }
	Array& operator= (const Array& d) { copyIntoP(d); return *this; }
	virtual ~Array(void) { if(a != nullptr) delete[] a; }
	int get_size() const { return size; }	
	T& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw string("OutOfBounds");
		return a[i];
	}
private:
	int size;
	T* a;
	void copyIntoP(const Array& d);

};

template <class T>
void Array<T>::copyIntoP(const Array& d)
{
	if (this == &d)	return;
	if (a != nullptr)	delete[] a;
	if (d.a != nullptr) {
		a = new T[size = d.size];
		for (int i = 0; i < size; i++)
			a[i] = d[i];//d.a[i];
	}
	else {
		a = nullptr;
		size = 0;
	}
}

template <class T>
istream& operator >> (istream& in, Array<T>& c)
{
	for (int i = 0; i < c.get_size(); i++)
	{
		in>> c[i];
	}
	return in;
}

template <class T>
ostream& operator << (ostream& out, Array<T>& c)
{	
	for (int i = 0; i < c.get_size(); i++)
	{
		out << c[i] << endl;	
	}
	return out;
}