#include<iostream>
using namespace std;

#define tab "\t"

struct Point //��� ������ Point
{
	double x;
	double y;
};
    
void main()
{
	setlocale(LC_ALL, "");
	//type name;
	int a; // ��������� ���������� 'a' ���� 'int'
	Point A; // ��������� ���������� 'A' ���� 'Point'
	         // ��������� ������ ��������� 'Point'
	         // ������� ��������� ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

}