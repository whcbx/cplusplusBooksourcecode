#include<iostream>
using namespace std;

template <class T> class Array;
template <class T>
ostream & operator << (ostream & out, const Array<T> & obj);

template <class T>
class Array
{
	friend ostream & operator << <T>(ostream & out, const Array<T> & obj);
public:
	
	Array(int size =0);
	Array(const Array & obj);
	~Array();
	T & operator[](int index);
	Array & operator = (const Array & obj);
	int getsize() const;
private:
protected:
	T * ptr;  //T类型指针，用于存放动态分配的数组内存首地址
	int size; //数组大小（元素个数）
};