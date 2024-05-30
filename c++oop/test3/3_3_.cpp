#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x{},y{};
public:
    Point() {}
    Point(double x, double y){this->x = x;this->y = y;}
    double getX() { return x; }
    double getY() { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void show() { cout << "Point: (" << x << ", " << y << ")" << endl; }
};

class Circle
{
private:
    Point center;
    double radius;
public:
    Circle() {}
    Circle(Point center, double radius){this->center = center;this->radius = radius;}
    Point getCenter() { return center; }
    double getRadius() { return radius; }
    void setCenter(Point center) { this->center = center; }
    void setRadius(double radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
    void show() { cout << "Circle : center( " << center.getX() << ", " << center.getY() << "), radius " << radius << endl; }
};

class Cylinder
{
private:
    Circle base;
    double height;
public:
    Cylinder(Circle base, double height){this->base = base;this->height = height;}
    Circle getBase() { return base; }
    double getHeight() { return height; }
    void setBase(Circle base) { this->base = base; }
    void setHeight(double height) { this->height = height; }
    double getArea() { return 2 * base.getArea() + 2 * 3.14 * base.getRadius() * height; }
    void show()
    {
        cout << "Cylinder : base(" << base.getCenter().getX() << ", " << base.getCenter().getY() << "), radius " << base.getRadius() << ", height " << height << endl;
    }
};

int main()
{
    Point p1(1, 4);
    Circle c1(Point(20, 55), 46);
    Cylinder cy1(Circle(Point(100, 9), 32), 78);
    p1.show();
    c1.show();
    cy1.show();
    cout << "The area of the circle is " << c1.getArea() << endl;
    cout << "The area of the cylinder is " << cy1.getArea() << endl;
    return 0;
}