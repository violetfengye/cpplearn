#include <iostream>
#include <string>

// 自定义的Student类
class Student
{
public:
    Student(const std::string &name, int score) : name(name), score(score) {}
    friend std::ostream &operator<<(std::ostream &out, const Student &s)
    {
        out << "Name: " << s.name << ", Score: " << s.score;
        return out;
    }

private:
    std::string name;
    int score;
};

// 模板类
template <typename T>
class Box
{
public:
    Box(const T &data) : data(data) {}
    void Display()
    {
        std::cout << data << std::endl;
    }

private:
    T data;
};

int main()
{
    Box<int> box1(123);
    Box<float> box2(456.789f);
    Box<char> box3('A');
    Box<Student> box4(Student("Tom", 90));

    box1.Display();
    box2.Display();
    box3.Display();
    box4.Display();

    return 0;
}
