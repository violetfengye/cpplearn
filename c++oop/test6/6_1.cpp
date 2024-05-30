#include <iostream>
#include <cmath>
const double PI = 3.14159;
// 定义抽象类Shape
class Shape
{
public:
    virtual double area() = 0; // 纯虚函数
};

// 定义Triangle类
class Triangle : public Shape
{
public:
    Triangle(double base, double height) : base(base), height(height) {}
    double area() override
    {
        return 0.5 * base * height;
    }

private:
    double base;
    double height;
};

// 定义Rectangle类
class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() override
    {
        return width * height;
    }

private:
    double width;
    double height;
};

// 定义Circle类
class Circle : public Shape
{
public:
    Circle(double radius) : radius(radius) {}
    double area() override
    {
        return PI * radius * radius;
    }

private:
    double radius;
};

// 定义Sector类
class Sector : public Shape
{
public:
    Sector(double radius, double angle) : radius(radius), angle(angle) {}
    double area() override
    {
        return 0.5 * radius * radius * angle;
    }

private:
    double radius;
    double angle;
};

int main()
{
    Triangle t(3.0, 4.0);
    Rectangle r(3.0, 4.0);
    Circle c(3.0);
    Sector s(3.0, PI / 6); // 30度扇形

    std::cout << "Triangle area: " << t.area() << std::endl;
    std::cout << "Rectangle area: " << r.area() << std::endl;
    std::cout << "Circle area: " << c.area() << std::endl;
    std::cout << "Sector area: " << s.area() << std::endl;

    return 0;
}
