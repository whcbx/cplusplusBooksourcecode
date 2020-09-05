/*
#include<iostream>
using namespace std;
void test()
{
	int d;
	int * ptr = new int;
	*ptr=1;
	if(*ptr >0){
		throw exception();
		//throw "Division by zero condition!";
	}
	
	cout << "run delete ptr start" << endl;
	delete ptr;
	return ;
}

int main(){
	test();
	return 0;
}
*/


#include <iostream>
using namespace std;
 
double division(int a, int b)
{
   if( b == 0 )
   {
     throw "Division by zero condition!";
   }
   return (a/b);
}


//template<typename T1, typename T2>
template<typename T>
void test(T * p){
	//cout<< a<< " "<<b<<endl;
	cout<< p<< " "<<endl;
}
void test(...){
	cout<<  "execute multiargs function  ----------"<<endl;
}
 
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
   
 
   try {
     z = division(x, y);
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
   
   std::string str = "hello";
   int var = 5;
   //test<int , std::string >(var,str);
   test(1,2,3,"hello");
   
   int * ptr = &var;
   test(ptr);
   test(var);
 
   return 0;
}