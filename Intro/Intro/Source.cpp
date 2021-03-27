#include<iostream>
using namespace std;

#define tab "\t"

struct Point //“ип данных Point
{
	double x;
	double y;
};
    
void main()
{
	setlocale(LC_ALL, "");
	//type name;
	int a; // ќбъ€вл€ем переменную 'a' типа 'int'
	Point A; // ќбъ€вл€ем переменную 'A' типа 'Point'
	         // ќбъ€вл€ем объект структуры 'Point'
	         // —оздаем экземпл€р структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

}