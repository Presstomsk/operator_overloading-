#include<iostream>
using namespace std;

#define tab "\t"

class Point //Тип данных Point
{
	double x;
	double y;
public:
	double get_x() const
	{   
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x <= 100)
			this->x = x;
		else
			this->x = 100;
	}
	void set_y(double y)
	{
		if (y <= 100)
			this->y = y;
		else
			this->y = 100;
	}
	// Constructors:
	/*Point()
	{   
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		/*this->x += other.x;
		this->y += other.y;*/
		this->set_x(this->x + other.x);
		this->set_y(this->y + other.y);
		return *this;
	}
	Point& operator++()//Prefix increment
	{
		++this->x;
		++this->y;
		return *this;

	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}
	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
	// Methods:
	void print() const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;
	}
};
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << tab << "Y= " << obj.get_y();
	return os;
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}

//#define STRUCT;
//#define CONSTRUCTORS_CHECK;
//#define ASSIGNMENT_CHECK;
//#define STREAMS;
    
void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT
	//type name;
	int a; // Объявляем переменную 'a' типа 'int'
	Point A; // Объявляем переменную 'A' типа 'Point'
			 // Объявляем объект структуры 'Point'
			 // Создаем экземпляр структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A; //Создаем указатель на 'Point'
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT
#ifdef CONSTRUCTORS_CHECK
	Point A;// Default constructor
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	Point B(2, 3);
	B.print();
	Point C = 5;//Single-argument Constructor
	C.print();
	Point D = B;//Copy Constructor
	D.print();
	Point E; 
	E = D;//Copy Assignment;
	E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif //ASSIGNMENT_CHECK
#ifdef STREAMS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	/*Point C = A + B;
	C.print();*/
	//A += B;
	//A.print();
	/*cout << "Prefix:\n";
	(++A).print();	A.print();
	cout << "Postfix:\n";
	A++.print();	A.print();*/
	cout << A << endl;
	cout << B << endl;
	cout << "Введите координаты точки: ";
	cin >> A;
	cout << "Вы ввели: " << A << endl;

#endif// STREAMS
	Point A(2, 3);
	Point B(2, 3);
	/*if (A == B)
	{
		cout<<"Точки равны"<<endl;
	}
	else
	{
		cout << "Точки разные" << endl;
	}*/
	cout << (A != B) << endl;
	A(33, 44);
	A.print();


}