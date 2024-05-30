#include<bits/stdc++.h>
using namespace std;
// stl;
void test1_queue(){
    //例题：p1996,
    queue<int>q;
    int x = 0;
    q.push(x);//将x推入队列
    q.pop();//排出第一个元素
    q.front();//返回第一个元素
    q.back();//返回最后一个元素
    q.size();//返回队列元素个数
    q.empty();//判断队列是否为空

}
void test2_stack(){
    //例题：
    stack<int> st;
    int x = 0;
    st.push(x);//将x推入栈
    st.pop();//弹出第一个元素
    st.top();//返回栈顶元素值
    st.size();//返回栈的元素个数
    st.empty();//判断栈是否为空
}
void test3_deque(){
    //例题：
    deque<int> q;
    int x{};
    q.size();//双端队列的大小
    q.empty();//判断双端队列是否为空
    q.push_back(x);//往队列末尾插入元素x
    q.push_front(x);//往队列首位插入元素x
    q.pop_back();//弹出队尾元素
    q.pop_front();//弹出队首元素
    q.front();//返回队首元素值
    q.back();//返回队尾元素值
}
void test4_vector(){
    vector<int> vec;
    int x{};
    vector<int>::iterator it = vec.begin();
    vec.push_back(x);//往数组末尾加入元素x
    vec.pop_back();//弹出数组最后一个元素
    vec.begin();//返回数组第一个元素的迭代器
    vec.end();//返回数组最后一个元素迭代器
    vec.clear();//清空数组，将大小变为0
    vec.empty();//判断数组是否为空
    vec.size();//返回数组大小
    vec.resize(x);//将数组大小设置为x
    vec.erase(it);//删除迭代器it位置的元素
    vec.erase(it, it + 5);//删除it到it+4的所有元素
    vec.insert(it, x);//将迭代器it位置处插入一个元素x
    vec.insert(it, x);//在迭代器it位置前插入x
}
void test5_map(){
    map<int, int> mp;
    int key{}, value{};
    map<int, int>::iterator it=mp.begin();
    mp.size();//返回mp的大小
    mp.empty();//判断mp是否为空
    mp.clear();//清空mp所有元素
    mp.erase(it);//删除迭代器it所指向的key的键值对
    mp.erase(key);//删除key的键值对
    mp.find(key);//返回key值的所在的迭代器，若未找到则返回mp.end()
    mp.insert(pair<int,int>(key,value));//插入键值对<key,value>
    mp[key] = value;//插入键值对<key,value>
    mp.begin();//返回迭代器头部
    mp.end();//返回迭代器尾部
}
void test6_set(){
    set<int> s;
    //集合中元素是唯一的，且元素总是排好顺序的
    int x{};
    set<int>::iterator it,first,last;
    s.insert(x);//插入元素x
    s.erase(it);//删除迭代器it对应的值
    s.erase(x);//删除容器中元素x
    s.erase(first, last);//删除迭代器[first,last)区间所对应的值
    s.begin();//返回迭代器头部
    s.end();//返回迭代器尾部
    s.find(x);//返回指向元素x的迭代器
    s.lower_bound(x);//返回指向第一个不小于或者等于x的元素的迭代器
    s.upper_bound(x);//返回指向第一个大于x的元素的迭代器
    s.empty();//判断容器是否为空
    s.count(x);//容器中x的个数，由于set容器元素唯一性，该函数返回值只能是0/1
    s.size();//返回容器中的元素个数
    s.clear();//清空容器
}
void test7_priority_queue(){
    priority_queue<int> Q;
    priority_queue<int, vector<int>, greater<int> > q1;//小到大排序
    priority_queue<int, vector<int>, less<int> > q1;//大到小排序
    //优先队列/堆中，元素总是排好顺序的，默认按大根堆构建（大到小）
    int x{};
    Q.push(x);//插入元素x
    Q.pop();//弹出最上面的元素
    Q.top();//返回顶部元素的值
    Q.size();//返回容器大小
    Q.empty();//判断容器是否为空
}
int main(void){
    return 0;
}