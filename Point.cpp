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
void Point::PrintXY()//prints x and y
{
	cout <<x<<" , " << y;
}
float Point::GetX()//getter that returns x
{
	return x;
}
float Point::GetY()//getter that returns y
{
	return y;
}
float Point::Distance(Point temp) //Calculates distance between the point and another point
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
void Belong(Point* A, Point* B, Point p) //function to receive an arrays of points (clusters) and a point and calculates to which center of a cluster is the point closer to
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
/*float randfloat()
{
	float temp;
	temp = (float)(rand()) / (float)(rand())// this part was an attempt to use random floats
	return temp;

}*/
int main() {
	
	{  //problem 1
		//Point* cluster = new Point[3];//declares an array of 3 points
		//(cluster)->SetX(2);
		//(cluster)->SetY(3);
		//(cluster+1)->SetX(1);
		//(cluster+1)->SetY(2);      //sets the coordinates of the 3 points
		//(cluster+2)->SetX(0);
		//(cluster+2)->SetY(0);
		//for (int i = 0; i < 3; i++)
		//{
		//	cout << "Coordinates of point " << i + 1 << " is ";
		//		(cluster + i)->PrintXY();
		//	cout << endl;
		//}
		//cout << "The centre of the cluster of these 3 points is ";
		//Center(cluster, 3).PrintXY();  //Prints the center of the cluster of 3 points
	}
	
	
	{    // Problem 2, Please note than the constant num should be changed according to your application and the size of clusters to be used in the function Belong
	//srand(time(NULL));     //initializes the seed for the time                         
	//Point* x = new Point[3]; //declares a cluster of 3 points
	//Point* y = new Point[3]; //declares a cluster of 3 points
	//for (int i = 0; i < 3; i++)// a loop for fill both clusters
	//{
	//	(x + i)->SetX(rand() % 10);
	//	(x + i)->SetY(rand() % 10);
	//	(y + i)->SetX(rand() % 10);
	//	(y + i)->SetY(rand() % 10);
	//}
	//Point center1 = Center(x, 3);  // points to store the centre of each cluster
	//Point center2 = Center(y, 3);
	//cout << "Cluster A has points " << endl;                       
	//for (int i = 0; i < 3; i++)  //loop to print the coordinates of each point in the cluster
	//{
	//	(x + i)->PrintXY();
	//	cout << endl;
	//}
	//cout << "And center "<<endl;
	//center1.PrintXY();
	//cout << endl;
	//cout << "Cluster B has Points " << endl;
	//for (int i = 0; i < 3; i++)     //loop to print the coordinates of each point in the cluster
	//{
	//	(y + i)->PrintXY();
	//	cout << endl;
	//}
	//cout << "And center " << endl;
	//center2.PrintXY();
	//cout << endl;
	//Point z(3, 4);
	//cout << "The Point has coordinates ";
	//z.PrintXY();
	//cout << endl;
	//Belong(x, y, z);   //tests the belong function
	}
	
	{    //Problem 3, Please note than the constant num should be changed according to your application and the size of clusters to be used in the function Belong
	srand(time(NULL));//initializes the seed for rand
	Point* A = new Point[num];//declares an array of points with size 200(cluster A)
	Point* B = new Point[num];//declares another array of points with size 200(cluster B)
	Point* p = new Point[20];//declares a third array of points with size 20
	for (int i = 0; i < num; i++)//loop to fill clusters A and B
	{
		(A + i)->SetX((rand() + 71) % 90);//makes sure each x in cluster A is greater than 70 and less than 90
		(A + i)->SetY((rand() + 71) % 90);//makes sure each y in cluster A is greater than 70 and less than 90
		(B + i)->SetX((rand() + 21) % 40);//makes sure each x in cluster B is greater than 20 and less than 40
		(B + i)->SetY((rand() + 21) % 40);//makes sure each y in cluster A is greater than 20 and less than 40
	}
	/*Center(A, num).PrintXY();
	cout << endl;
	Center(B, num).PrintXY();        //This part shows us the centres of A and B to help us make sure the program is working correctly
	cout << endl;*/
	for (int i = 0; i < 20; i++)//for loop to populate the array p
	{
		(p + i)->SetX((rand() + 6) % 100);//makes sure point in the array p has an x thats greater than 5 and less than 100
		(p + i)->SetY((rand() + 6) % 100);//makes sure point in the array p has a y thats greater than 5 and less than 100
	}
	for (int i = 0; i < 20; i++)//for loop to cout which cluster does each member of array p belong to
	{
		Belong(A, B, *(p + i));
		cout << endl;
		/*(p + i)->PrintXY();//helps us make sure the program is working correctly
		cout << endl;*/
	}
		
	}
	return 0;
}
