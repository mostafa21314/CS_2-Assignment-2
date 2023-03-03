#pragma once
#ifndef POINT_H
#define POINT_H
class Point
{
private:
	float x ;
	float y;
public:
	Point();
	~Point();
	Point(float, float);
	void SetX(float);
	void SetY(float);
	float GetX();
	float GetY();
	void PrintXY();
	float Distance(Point);
};
#endif

