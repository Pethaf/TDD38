#include <iostream> 
#include <math.h>
#include <string>
#include "Serializable.h"
#include "Clonable.h"
#include <iostream>
class Point final: public Serializable, public Clonable
{
public:
	Point(float x_ = 0.0,float y_ = 0.0): x{x_},y{y_} { }
	virtual ~Point() = default; 
	float x;
	float y;
	Point* clone() const override { return new Point(*this);}
protected: 
	Point(const Point&) = default;
private:
	std::string to_str() const override { return "Point@someId[x=" +  std::to_string(x) + std::string{"y="}+ std::to_string(y) + "]"; } //x+"y="+y;}  
}; 

class Line final: public Serializable, public Clonable
{
	public:
		Line(float x1_ = 0.0, float y1_=0.0, float x2_=1.0,float y2_=1.0): x1{x1_},y1{y1_},x2{x2_},y2{y2_} { }
		virtual ~Line() = default; 
		double getLength() { return pow(pow((x2-x1),2)+pow((y2-y1),2),0.5); } 
		Line* clone() const override { return new Line(*this); }
	protected:
		Line(const Line&) = default; 
	private:
		float x1, x2, y1,y2;
		std::string to_str() const override { return "Line@someId[x1=" + std::to_string(x1) + std::string("y1=") + std::to_string(y1) + std::string("x2=") + std::to_string(x2) + std::string("y2=") + std::to_string(y2) + "]";} //+x1+ "y1=" + y1 + "x2=" + x2 + "y2=" + y2;}

};

class Plane
{
public:
	virtual ~Plane() = default; 
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
protected:
	Plane() = default;
	Plane(const Plane&) = default;
};

class Circle: public Plane, public Serializable, public Clonable
{
public:
	Circle(double radius_ = 1.0): radius{radius_} { }
	~Circle() = default;
	double area() const override { return 3.14*pow(radius,2);}
	double perimeter() const override { return 2*3.14*radius;}
	Circle* clone() const override { return new Circle(*this);}
private:
	double radius;
	std::string to_str() const override { return "Circle@someId[radius=" + std::to_string(radius); }
};

class Rectangle: public Plane, public Serializable, public Clonable
{
public:
	Rectangle(double x_=1.0, double y_=1.0): x{x_}, y{y_} { }
	~Rectangle() = default;
	Rectangle* clone() const override { return new Rectangle(*this);}
	double area() const override { return x*y;}
	double perimeter() const override { return 2*(x+y);}
protected:
	Rectangle(const Rectangle&) = default;
private:
	std::string to_str() const override { return "Rectangle[x=" + std::to_string(x) + std::string("y=") + std::to_string(y) + "]";}
	double x,y;
};

class Triangle: public Plane, public Serializable, public Clonable
{
public:
	Triangle(double height_ = 1.0, double base_ = 1.0 ): base{base_}, height{height_} { }
	~Triangle() = default; 


}