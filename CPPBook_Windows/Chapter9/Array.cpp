#include "Array.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string.h> 
#include <stdio.h>
using namespace std;
template <class T>
ostream & operator << (ostream & out, const Array<T> & obj)
{
	for(int i=0; i< obj.size; i++){
		out << obj.ptr[i];
		//out << obj[i];
	}
	out << endl;
	return out;
}

//Array<int>  a1(10)
//构造函数
template <class T>
Array<T>::Array(int len)
{
	size =  len;
	ptr = new T [size];
}


//Array<int>  a1= a2
//拷贝构造函数
template <class T>
Array<T>::Array(const Array & obj)
{
	size = 0;
	delete [] ptr;
	
		size =  obj.size;
	ptr = new T [size];
	
	for(int i=0; i< size; i++){
		//ptr[i] = obj.ptr[i];
		ptr[i] = obj[i];
	}
}

//析构函数
template <class T>
Array<T>::~Array()
{
	if(ptr != NULL)
	{
		delete [] ptr;
		ptr =  NULL;
		size = 0;
	}
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
	
	
	if(size != obj.getsize()){
		if(ptr != NULL)
		{
			delete [] ptr;
			ptr = NULL;
			size = 0;
		}
	
		size = obj.getsize();
		ptr = new T[size];
	}	
		for(int i=0; i< size; i++){
			ptr[i] = obj[i];
		}
	
	return *this;
}

template <class T>
int Array<T>::getsize() const
{
	return  size;
}

class Teacher
{
	public:
	
	Teacher(){
		age =10;
		name = new char[1];
		strcpy(name,"");
	}
	Teacher(char *name,int age){

		this->age = age;
		int sizei = strlen(name);
		cout << " sizei" << sizei <<endl;
		this->name = new char[sizei+1];

		strcpy(this->name,name);

	}
	Teacher(const Teacher & obj){
		cout << " run Teacher  Constructor with args" <<endl;
		age = obj.age;
		name = new char[strlen(obj.name)+1];
		strcpy(name,obj.name);
	}
	
	friend ostream & operator <<(ostream & out , const Teacher & obj){
		out << obj.name << ", " <<obj.age;
		return out;
	}

	Teacher & operator =( const Teacher & obj){
		cout << "run Teacher operator =" <<endl;
		if(name!= NULL){
			delete [] name;
			name = NULL;
			age = 10;
		}
		age = obj.age;
		name = new char[strlen(obj.name)+1];
		strcpy(name,obj.name);
		return *this;
	}
	
private:
protected:
	char *name;  //T类型指针，用于存放动态分配的数组内存首地址
	int age; //数组大小（元素个数）
};

int main()
{
	cout << "Teacher object" <<endl;
	Teacher t1("zhansan",20);	
	Teacher t2("lisi",20);
	Teacher t3("wangswu",20);
	Teacher t4("zhaoliu",20);

	Array<Teacher > vtr2(4);
	 vtr2[0] = t1;
	  vtr2[1] = t2;
	   vtr2[2] = t3;
	    vtr2[3] = t4;
		cout << vtr2 << endl;
	
	Array<int> vtr(10);
	for(int i=0; i< vtr.getsize() ; i++){
		vtr[i] = i;
	}
	cout << vtr<<endl;
	
	Array<char> vtr1(10);
	for(int i=0; i< vtr1.getsize() ; i++){
		vtr1[i] = 'a'+i;
	}
	cout << vtr1<<endl;
	
	return 0;
}