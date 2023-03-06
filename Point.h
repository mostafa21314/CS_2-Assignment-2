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
	float GetX() const;
	float GetY() const;
	void PrintXY() const;
	float Distance(const Point &) const;
};
Point Center(Point*, int);
void Belong(Point*, Point*, const Point &);
#endif

