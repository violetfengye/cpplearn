#include<bits/stdc++.h>
using namespace std;
int main(void){
    string a, b;
    cin >> a;
    cin.get();
    cin >> b;
    int d = max(a.length(), b.length())+1;
    const int dd = d;
    int c[dd]{};
    for (int i = 0; i < a.length()/2;i++){
        int temp = a[i];
        a[i] = a[a.length() - 1];
        a[a.length() - 1] = temp;
    }
    for (int i = 0; i < b.length() / 2; i++)
    {
        int temp = b[i];
        b[i] = b[b.length() - 1];
        b[b.length() - 1] = temp;
    }
    for (int i = 0; i < d;i++){
        string e, f;
        e = a[i];
        f = b[i];
        c[i] +=stoi(e)+stoi(f);
        if(c[i]>=10){
            c[i] -= 10;
            c[i + 1] += 1;
        }
    }
    if(c[dd-1]=0){
        for (int i = dd - 2; i >= 0;i++){
            cout << c[i];
        }
    }
    else{
        for (int i = dd - 1; i >= 0; i++)
        {
            cout << c[i];
        }
    }
    return 0;
}