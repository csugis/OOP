#pragma once

const int new_size = 50;				//����Ԫ�ز�����ʱ�������ĳ���

template <class T>
class tArray
{
	T * a;
	int size;							//��ЧԪ�ظ���
	int _size;							//ʵ�ʳ���
public:
	T* getTs(void) { return a; }
	int getSize(void) const {return size;}
	int getCapacity(void) const { return _size; }
	tArray(void);
	tArray(int);
	tArray(tArray<T>&);
	tArray<T>& operator = (const tArray<T>&);
	tArray<T>& operator ()(int s);
	~tArray(void);
	T& operator [](int);
	T& push_back(const T& t);
	void pop_back() { size--; }
	void clear() { size = 0; }
};

template <class T>
tArray<T>::tArray(tArray<T>& ta)
{
	if (a == ta.a) return;
	a = new T[size = ta.size];
	for(int i = 0; i < size; i++)
	{
		a[i]= ta.a[i];
	}
	_size = size;
}
template <class T>
tArray<T>& tArray<T>::operator ()(int s)
{
	if(a) delete [] a;
	a = new T[size = s];
	_size = size;
	return *this;
}

template <class T>
tArray<T>& tArray<T>::operator = (const tArray<T>& ta)
{
	if (a == ta.a) return *this;
	if(a) delete [] a;
	a = new T[size = ta.size];
	for(int i = 0; i < size; i++)
	{
		a[i]= ta.a[i];
	}
	_size = size;
	return *this;
}

template <class T>
tArray<T>::tArray(void)
:a(0),size(0),_size(0)
{

}

template <class T>
tArray<T>::tArray(int s)
{
	a = new T[size = s];
	_size = size;
}

template <class T>
tArray<T>::~tArray(void)
{
	if(a) delete [] a;
}

template <class T>
T& tArray<T>::operator [](int i)
{
	if(i>=_size)
	{
		T* temp = new T[_size+=new_size];
		for(int j=0; j<size; j++)
			temp[j] = a[j];
		if(a) delete [] a;
		a = temp;
	}
	size = (i>=size)?(i+1):size;
	return a[i];
}

template <class T>
T& tArray<T>::push_back(const T& t)
{
	int i = size;
	if (i >= _size)
	{
		T* temp = new T[_size += new_size];
		for (int j = 0; j < size; j++)
			temp[j] = a[j];
		if (a) delete[] a;
		a = temp;
	}
	a[i] = t;
	size++;
	return a[i];
}
/*function template
template <class T>
ostream& operator << ( ostream& out, tArray<T>& ta) 
{
	for(int i=0; i<ta.getSize(); i++)
	{
		out<<ta[i]<<endl;
	}
	return out;
}

template <class T>
istream& operator >> ( istream& in, tArray<T>& ta) 
{
	for(int i=0; i<ta.getSize(); i++)
	{
		in>>ta[i];
	}
	return in;
}*/