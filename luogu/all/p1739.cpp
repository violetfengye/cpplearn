#include <bits/stdc++.h>
using namespace std;
stack<char> st1, st2;
int main(void)
{
    char x;
    int p{};
    while (cin >> x)
    {
        if (x == '@')
        {
            break;
        }
        if (x == '(' || x == ')')
        {
            st1.push(x);
        }
    }
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }
    int a{}, b{};
    while (!st2.empty())
    {
        if (st2.top() == '(')
        {
            a++;
        }
        else
        {
            a--;
        }
        if (a < 0)
        {
            break;
        }
        st2.pop();
    }
    if (a == 0)
    {
        p = 1;
    }
    if (p == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
string s;
stack<int>st;
int main()
{
    cin>>s;
    for(int i=0;s[i]!='@';++i){
        if(s[i]=='('){
            st.push(1);
        }
        else if(s[i]==')'){
            if(st.empty()){
                cout<<"NO"<<endl;
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
*/