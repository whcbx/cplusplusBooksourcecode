#include <iostream>
#include <cmath>
using namespace std;

int max1(int x,int y); //�������������ֵ

int max1(int x,int y,int z);//�������������ֵ

double max1(double x,double y);//����˫�����������ֵ

double max1(double x,double y,double z);//����˫�����������ֵ


int main()
{
    int a,b,c;
    double m,n,l;

    cout<< "Enter int a: ";
    cin >> a;

    cout << "Enter int b: ";
    cin >> b;

    cout << "Enter int c: ";
    cin >> c;

    cout << "\n";

    cout <<"max of "<<a<<" and "<< b <<" is "<< max1(a,b)<<endl;

    cout <<"max of "<<a<<", "<<b<<" and "<< c <<" is "<< max1(a,b,c)<<endl;

    cout << "\n\n";

    cout<< "Enter double m: ";
    cin >> m;

    cout << "Enter double n: ";
    cin >> n;

    cout << "Enter double l: ";
    cin >> l;

    cout << "\n";

    cout <<"max of "<<m<<" and "<< n <<" is "<< max1(m,n)<<endl;

    cout <<"max of "<<m<<", "<<n<<" and "<< l <<" is "<< max1(m,n,l)<<endl;


    return 0;
}


int max1(int x,int y) //�������������ֵ
{
    if (x==y) return x;
    else if (x>=y)
        return x;
    else
        return y;

}


int max1(int x,int y,int z)//�������������ֵ
{
    return max1(max1(x,y),z);
}

double max1(double x,double y)//����˫�����������ֵ
{
    if (abs(x-y)<1e-10) return x;//�ж����������Ƿ���ȵĳ�������ʽ
    else if (x>=y)
        return x;
    else
        return y;

}

double max1(double x,double y,double z)//����˫�����������ֵ
{
    return max1(max1(x,y),z);
}

