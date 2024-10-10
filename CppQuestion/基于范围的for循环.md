# 基于范围的 `for` 循环

**基于范围的 `for` 循环**（range-based for loop）是 C++11 引入的一种简洁语法，用于遍历数组或容器（如 `std::vector`、`std::list` 等）。它可以简化传统的迭代方式，使代码更加易读。

## 语法

```cpp
for (declaration : range) {
    // 循环体
}
```

- **declaration**：循环中每次迭代的变量，可以是值、引用，或者加上 `const` 修饰符。
- **range**：可以是任何可遍历的范围对象，如数组、`std::vector` 等 STL 容器，也可以是自定义实现的范围。

## 基本示例

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用基于范围的 for 循环
    for (int x : vec) {
        std::cout << x << " ";  // 输出：1 2 3 4 5
    }

    return 0;
}
```

## 详细说明

1. **值传递**： 当通过值传递时，`for` 循环会对每个元素进行拷贝。适合读取数据，但不适合修改容器中的元素。

```cpp
for (int x : vec) {
    x += 1;  // 修改的是拷贝的 x，而非原来的元素
}
```

2. **引用传递**： 使用引用传递（`&`），可以直接操作容器中的元素。适合在循环中修改原容器的数据。

```cpp
for (int& x : vec) {
    x += 1;  // 修改的是原始元素
}
```

3. **常量引用传递**： 如果只需要读取数据而不希望拷贝或修改容器中的元素，可以使用常量引用（`const &`），这样可以避免不必要的拷贝操作。

```cpp
for (const int& x : vec) {
    std::cout << x << " ";  // 只读操作，不能修改元素
}
```

## 遍历数组

基于范围的 `for` 循环也可以用于遍历 C 风格的数组。

```cpp
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
    std::cout << x << " ";  // 输出：1 2 3 4 5
}
```

## 自定义类的支持

如果你想让自定义的类支持基于范围的 `for` 循环，需要为类定义 `begin()` 和 `end()` 方法，它们分别返回迭代器的起始位置和结束位置。

示例：

```cpp
#include <iostream>
#include <vector>

class MyContainer {
    std::vector<int> data;
public:
    MyContainer() : data{1, 2, 3, 4, 5} {}
    
    // begin() 和 end() 返回迭代器
    std::vector<int>::iterator begin() { return data.begin(); }
    std::vector<int>::iterator end() { return data.end(); }
};

int main() {
    MyContainer myContainer;

    for (int x : myContainer) {
        std::cout << x << " ";  // 输出：1 2 3 4 5
    }

    return 0;
}
```

## 总结

- **基于范围的 `for` 循环** 是一种简化语法，用于遍历数组和容器，具有更清晰和易读的代码结构。
- 它支持多种传递方式：**值传递**、**引用传递** 和 **常量引用传递**。
- 要让自定义容器支持这种遍历方式，必须实现 `begin()` 和 `end()` 方法。
