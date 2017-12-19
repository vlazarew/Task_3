#pragma once
#include <string.h>
#include <iostream>
class Point
{
private:
	double _x, _y;
public:

	//конструкторы
	Point(double x, double y);

	Point();

	//возвращает х
	double GetX();

	//возвращает y
	double GetY();

	//возвращает радиус
	double GetRadius();

	//возвращает угол
	double GetAngle();

	//устанавливает координаты точки
	void SetCoordnt(double x, double y);

	//расстояние до начала координат
	double DistToBegOfCoord();

	//сдвиг по x
	void MoveX(double x);

	//сдвиг по у
	void MoveY(double y);

	//ввод с клавиатуры
	void Read();

	//вывод на экран декартовых
	void Display();

	//расстояние до точки p
	double DistanceToPoint(Point p);

	//совпадение с точкой p
	bool Overlap(Point p);

	//перевод координат в строку
	std::string ToString();

	//перегрузка операторов
	Point operator + (Point p2);

	Point operator - (Point p2);

	double operator * (Point p2);

	bool operator == (Point p);
	
	friend std::ostream& operator << (std::ostream& os, Point p);

	friend std::istream& operator >> (std::istream& is, Point p);
	
};

