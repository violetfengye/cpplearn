/*
*函数是不可以嵌套定义的，但是可以嵌套声明。
*可以通过lambda表达式和嵌套类来实现类似嵌套定义的效果。
*/

#include <iostream>

void outerFunction1() {
    // 定义一个局部类
    class InnerClass {
    public:
        void innerFunction(int x) {
            std::cout << "Inner function way1: " << x << std::endl;
        }
    };
    
    InnerClass obj;
    obj.innerFunction(42);  // 调用类的成员函数
}

void outerFunction2() {
    // Lambda 表达式，相当于在函数内定义了一个匿名函数
    auto innerFunction = [](int x) {
        std::cout << "Inner function way2: " << x << std::endl;
    };
    
    innerFunction(42);  // 调用 Lambda 表达式
}

int main() {
    outerFunction1();
    outerFunction2();
    return 0;
}
