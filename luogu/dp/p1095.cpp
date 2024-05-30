#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll T = 3e5 + 5;
ll m, s, t, sn, tn;
int main(){
    cin >> m >> s >> t;
    ll p = m / 10;
    m=m % 10;
    while(p--){
        sn += 60, tn++;
        if(sn>=s&&tn<=t){
            cout << "Yes"
                 << "\n"
                 << tn << endl;
            return 0;
        }
        if(tn==t&&sn<s){
            cout << "No"
                 << "\n"
                 << sn << endl;
            return 0;
        }
    }

    ll ssn{sn};
    while(tn<t){
        tn++;
        ssn += 17;
        if (m >= 10)
        {
            sn += 60, m -= 10;
        }
        else{
            m += 4;
        }
        if(sn>ssn){
            ssn = sn;
        }
        if(ssn>=s){
            cout << "Yes"
                 << "\n"
                 << tn << endl;
            return 0;
        }
    }
    cout<<"No"<<"\n"<<ssn << endl;
    return 0;
}
