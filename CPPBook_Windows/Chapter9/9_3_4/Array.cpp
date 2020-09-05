#include "Array.h"
#include <iostream>
using namespace std;
template <class T>
ostream & operator << (ostream & out, const Array<T> & obj)
{
	return out;
}

//构造函数
template <class T>
Array<T>::Array(int size)
{

}



//拷贝构造函数
template <class T>
Array<T>::Array(const Array & obj)
{

}

//析构函数
template <class T>
Array<T>::~Array()
{
}

//重载[]
template <class T>
T & Array<T>::operator[](int index)
{
	return ptr[index];
}

//重载赋值运算符=
template <class T>
Array<T> &  Array<T>::operator = (const Array<T> & obj)
{
	return *this;
}

template <class T>
int Array<T>::getsize() const
{
	return  size;
}


int main()
{
	Array<int> vtr(10);
	
	//std::Array<int> array(10,2);
//	for(auto item : array)
	//{
		
//	}
	return 0;
}