//Mostafa Gaafar
//900214463
#include "Point.h"//including the .h file
#include<iostream>
#include<ctime>//include ctime to use the rand function;
using namespace std;
const int num = 200;//number of points in each cluster
Point::Point()//default constructor of Point
{
	x = 0;
	y = 0;
}
Point::Point(float n, float m)//constructor for Point with set values for x and y
{
	x = n;
	y = m;
}
Point::~Point()//destructor for Point
{
}
void Point::SetX(float p)//setter for x
{
	x = p;
}
void Point::SetY(float q)//setter for y
{
	y = q;
}
void Point::PrintXY() const//prints x and y
{
	cout <<x<<" , " << y;
}
float Point::GetX() const//getter that returns x
{
	return x;
}
float Point::GetY() const//getter that returns y
{
	return y;
}
float Point::Distance(Point temp) const //Calculates distance between the point and another point
{
	return sqrt(pow(x-temp.x,2)+pow(y-temp.y,2));//the same equation written in the assignment but in c++
}
Point Center(Point* C, int n)//centre function that finds the center of an array of Points and returns it as a new point 
{
	float x, y;//will store the x and y coordinates of the centre
	x = 0;
	y = 0;
	for (int i = 0; i < n; i++)//loop to calulate where the centre is
	{
		x += (C + i)->GetX();
		y += (C + i)->GetY();
	}
	Point center(x / n, y / n);//declaring a new point with the coordinates of the centre of the cluster to return it
	return center;
}
void Belong(Point* A, Point* B, const Point &p) //function to receive an arrays of points (clusters) and a point and calculates to which center of a cluster is the point closer to
{
	float d1, d2;
	d1 = Center(A, num).Distance(p);//calculates the distance between the centre of cluster A and point p
	d2 = Center(B, num).Distance(p);//calculates the distance between the centre of cluster B and point p
	if (d1 == d2)//if conditions to cout where p belongs to
		cout << "The point is equal distance from both clusters ";
	else if (d1 > d2)
		cout << "The point belongs to cluster B ";
	else
		cout << "The point belongs to cluster A ";
}
