#pragma once
#include <string.h>
#include <iostream>
class Point
{
private:
	double _x, _y;
public:

	//������������
	Point(double x, double y);

	Point();

	//���������� �
	double GetX();

	//���������� y
	double GetY();

	//���������� ������
	double GetRadius();

	//���������� ����
	double GetAngle();

	//������������� ���������� �����
	void SetCoordnt(double x, double y);

	//���������� �� ������ ���������
	double DistToBegOfCoord();

	//����� �� x
	void MoveX(double x);

	//����� �� �
	void MoveY(double y);

	//���� � ����������
	void Read();

	//����� �� ����� ����������
	void Display();

	//���������� �� ����� p
	double DistanceToPoint(Point p);

	//���������� � ������ p
	bool Overlap(Point p);

	//������� ��������� � ������
	std::string ToString();

	//���������� ����������
	Point operator + (Point p2);

	Point operator - (Point p2);

	double operator * (Point p2);

	bool operator == (Point p);
	
	friend std::ostream& operator << (std::ostream& os, Point p);

	friend std::istream& operator >> (std::istream& is, Point p);
	
};

