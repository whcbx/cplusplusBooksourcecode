
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string.h> 
#include <stdio.h>
#include <vector>
#include<map>
using namespace std;

int main()
{
	int arr[3]{1,2,3};
	vector<int> iv {1,2,3};
	map<string,int>  mp;
	
	mp.insert({ "abc", 1 });    //使用这种就可以了
    //其他形式和方式
	mp.insert(make_pair(string("def"),2));
	mp.insert(make_pair("ghj", 4));
	mp.insert(pair<string, int>(string("kmn"), 3));
	mp[string("pqrs")] = 5;
	
	pair<map<string,int >::iterator,bool>  ret = mp.insert(map<string, int >::value_type("ghj",3333));
	if(ret.second){
		cout<<"insert success"<<endl;
		cout<<"ret->first->first :"<<ret.first->first <<endl;
		cout<<"ret->first->second :"<<ret.first->second <<endl;
		
	} else{
		cout<<"insert fail"<<endl;
	}
	
	//pair<map<int,string>::iterator,bool> ret1 = mp.insert(map<int, string>::value_type(22,"twotwo"));
	
	//mp
	for(auto i= mp.begin(); i!= mp.end();i++)
	{
		cout<< i->first<< " "<< i->second<< endl;
	}
	
	//pair<map<string,int >::iterator,bool> ret
	for(auto & s:mp)
	{
		cout<< s.first<< " "<< s.second<< endl;
	}
	return 0;
}