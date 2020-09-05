#include <iostream>
using namespace std;

class Point
{
	int _x, _y;
public:
	Point(int x=0, int y=0) : _x(x), _y(y) {}
	Point& operator++();
	Point operator++(int);
	Point& operator--();
	Point operator--(int);
	friend ostream& operator << (ostream& o, Point& p);
};

Point& Point::operator++()
{
	_x++;
	_y++;
	return *this;
}
/* ++i��C++����Ķ�����󷵻ص��Ǳ�++�Ķ�������ã�ϵͳ������ôʵ�ֵģ�������++i������Ϊ��ֵ��������д��++i=3  */

//��׺ʽ����������һ�������int���β�(����ʹ����������������)
Point Point::operator++(int)
{
	Point temp = *this;
	++*this; //������ǰ׺++������
	return temp;

//��׺ʽ�汾�У�����ֵ����δ������ԭֵ�����������Ѿ��������������ˡ�

}
/* i++��C++����Ķ����ǣ���󷵻ص��Ǳ�++�Ķ����ֵ��ϵͳ������ôʵ�ֵģ�������i++��������Ϊ��ֵ����������д��i++=3 */

Point& Point::operator--()
{
	_x--;
	_y--;
	return *this;
}

Point Point::operator--(int)
{
	Point temp = *this;
	--*this;
	return temp;
}

//��Ԫ����������ֵ����Ϊostream&������֧��<<��������
ostream& operator << (ostream& o, Point& p) {
	o << '(' << p._x << ", " << p._y << ')';
	return o;
}

int main()
{
	Point p(1, 2);
	cout << p << endl;
	cout << p++ << endl;
	cout << ++p << endl;
	cout << p-- << endl;
	cout << --p << endl;
	return 0;
}
