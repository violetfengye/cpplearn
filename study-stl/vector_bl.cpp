#include<bits/stdc++.h>
using namespace std;
void print(int a)
{
    cout << a << " ";
}
void test1(void){
    vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    // 遍历方式1
    vector<int>::iterator itbegin = a.begin();
    vector<int>::iterator itend = a.end();
    while(itbegin!=itend){
        cout << *itbegin << " ";
        itbegin++;
    }
    cout << endl;
    // 遍历方式2
    for (vector<int>::iterator i = a.begin(); i != a.end();i++){
        cout << *i << " ";
    }
    cout << endl;
    // 遍历方式3
    for_each(a.begin(), a.end(), print);
}
int main(void){
    test1();
    return 0;
}