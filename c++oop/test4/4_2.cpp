#include <bits/stdc++.h>
using namespace std;
const int PI = 3.14;
// point
class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y) { this->x = x, this->y = y; }
    void show() { cout << "Point: (" << x << ", " << y << ")" << endl; }
    void modify(int x, int y) { this->x = x, this->y = y; }
};
// circle
class Circle : public Point
{
protected:
    float radius;

public:
    Circle(int x, int y, float radius) : Point(x, y) { this->radius = radius; }
    int getArea()
    {
        return PI * radius * radius;
    }

    void show()
    {
        Point::show();
        cout << "Circle: radius = " << radius << endl;
    }

    void modify(int x, int y, float radius)
    {
        Point::modify(x, y);
        this->radius = radius;
    }
};
// cylinder
class Cylinder : public Circle
{
private:
    float height;

public:
    Cylinder(int x, int y, float radius, float height) : Circle(x, y, radius)
    {
        this->height = height;
    }

    int getArea()
    {
        return 2 * PI * radius * (radius + height);
    }

    void show()
    {
        Circle::show();
        cout << "Cylinder: height = " << height << endl;
    }

    void modify(int x, int y, float radius, float height)
    {
        Circle::modify(x, y, radius);
        this->height = height;
    }
};

int main()
{
    Point p(1, 4);
    p.show();
    cout << endl;

    Circle c(20, 55, 46);
    c.show();
    cout << "Area of Circle: " << c.getArea() << endl;
    cout << endl;

    Cylinder cy(100, 9, 32, 78);
    cy.show();
    cout << "Area of Cylinder: " << cy.getArea() << endl;

    return 0;
}