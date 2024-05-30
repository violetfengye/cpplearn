#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    Student(const string &name, int id, double chinese, double math, double english)
        : name(name), id(id), chinese(chinese), math(math), english(english) {}

    // 输出学生信息
    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Chinese: " << chinese << endl;
        cout << "Math: " << math << endl;
        cout << "English: " << english << endl;
    }

    // 重载==运算符（成员函数）
    bool operator==(const Student &other) const
    {
        double avg1 = (chinese + math + english) / 3.0;
        double avg2 = (other.chinese + other.math + other.english) / 3.0;
        return avg1 == avg2;
    }

    // 重载>运算符（成员函数）
    bool operator>(const Student &other) const
    {
        double avg1 = (chinese + math + english) / 3.0;
        double avg2 = (other.chinese + other.math + other.english) / 3.0;
        return avg1 > avg2;
    }
    /*
    由于 == 和 > 运算符被重载了两次，一次是作为成员函数，一次是作为友元函数。这导致了编译器不确定在比较两个Student对象时应该调用哪个函数，产生了警告。因此在这里对友元函数重载进行了注释。
    // 友元函数重载==运算符
    friend bool operator==(const Student &s1, const Student &s2)
    {
        double avg1 = (s1.chinese + s1.math + s1.english) / 3.0;
        double avg2 = (s2.chinese + s2.math + s2.english) / 3.0;
        return avg1 == avg2;
    }

    // 友元函数重载>运算符
    friend bool operator>(const Student &s1, const Student &s2)
    {
        double avg1 = (s1.chinese + s1.math + s1.english) / 3.0;
        double avg2 = (s2.chinese + s2.math + s2.english) / 3.0;
        return avg1 > avg2;
    }
    */
private:
    string name;
    int id;
    double chinese;
    double math;
    double english;
};

int main()
{
    string name;
    int id;
    double chinese;
    double math;
    double english;

    // 输入学生信息
    cout << "Enter student information: " << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Chinese Score: ";
    cin >> chinese;
    cout << "Math Score: ";
    cin >> math;
    cout << "English Score: ";
    cin >> english;

    // 创建学生对象
    Student student1(name, id, chinese, math, english);

    // 输出学生信息
    cout << "Student Information:" << endl;
    student1.display();
    cout << endl;

    // 创建第二个学生对象
    Student student2("John", 2, 85, 90, 95);

    // 测试"=="运算符重载
    if (student1 == student2)
    {
        cout << "Average scores are equal." << endl;
    }
    else
    {
        cout << "Average scores are not equal." << endl;
    }

    // 测试">"运算符重载
    if (student1 > student2)
    {
        cout << "Student1 has higher average scores." << endl;
    }
    else
    {
        cout << "Student2 has higher average scores." << endl;
    }

    return 0;
}