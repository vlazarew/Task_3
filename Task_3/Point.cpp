#include "stdafx.h"
#include "Point.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <sstream>

//конструкторы
Point::Point(double x, double y)
{
	SetCoordnt(x, y);
}

Point::Point()
{
	SetCoordnt(0, 0);
}

//возвращает х
double Point::GetX()
{
	return _x;
}

//возвращает y
double Point::GetY()
{
	return _y;
}

//возвращает радиус
double Point::GetRadius()
{
	return sqrt(_x * _x + _y * _y);
}

//возвращает угол
double Point::GetAngle()
{
	double radius = GetRadius(), result = (radius == 0 ? 0 : acos(_x / radius));
	result = (_y < 0 ? M_PI * 2 - result : result);
	return result;
}

//устанавливает координаты точки
void Point::SetCoordnt(double x, double y)
{
	_x = x;
	_y = y;
}

//рассто¤ние до начала координат
double Point::DistToBegOfCoord()
{
	return GetRadius();
}

//сдвиг по x
void Point::MoveX(double x)
{
	_x += x;
}

//сдвиг по у
void Point::MoveY(double y)
{
	_y += y;
}

//ввод с клавиатуры
void Point::Read()
{
	try
	{
		std::cout << "Введите координаты" << std::endl;
		double x = _x, y = _y;
		std::cout << "x: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		SetCoordnt(x, y);
	}
	catch (...)
	{
		std::cout << "Некорректный ввод";
	}
}

//вывод на экран декартовых
void Point::Display()
{
	std::cout << "x: " << _x << " y: " << _y << std::endl;
}

//рассто¤ние до точки p
double Point::DistanceToPoint(Point p)
{
	return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
}

//совпадение с точкой p
bool Point::Overlap(Point p)
{
	const double eps = 0.0000001;
	return this->DistanceToPoint(p) < eps;
}

//перевод координат в строку
std::string Point::ToString()
{
	std::string result;
	std::ostringstream ost;
	ost << _x << " " << _y;
	result += ost.str();
	return result;
}

//перегрузка операторов
Point Point::operator + (Point p2)
{
	return Point(this->_x + p2._x, this->_y + p2._y);
}

Point Point::operator - (Point p2)
{
	return Point(this->_x - p2._x, this->_y - p2._y);
}

double Point::operator * (Point p2)
{
	return (this->GetRadius() * p2.GetRadius() * cos(abs(this->GetAngle() - p2.GetAngle())));
}

bool Point::operator == (Point p) {
	if (this->_x == p._x && this->_y == p._y) {
		return true;
	}
	return false;

}

std::ostream& operator << (std::ostream& os, Point p){
	os << p.ToString();
	return os;
}

std::istream& operator >> (std::istream& is, Point p) {
	is >> p._x >> p._y;
	return is;
}
