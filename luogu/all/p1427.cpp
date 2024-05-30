#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main(void){
    int i;
    while(cin>>i){
        if (i == 0)
        {
            break;
        }
        st.push(i);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
/*以下是题解
//P1427
#include <bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
int main()
{
    stack<int>st;
    int temp;
    for(;;){
        temp=read();
        if(temp) st.push(temp);
        else break;
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
*/