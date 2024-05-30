#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int main(void)
{
    int n, a;
    long long S;
    long double sum{}, dum{};
    cin >> n >> S;
    double x = S * 1.0 / n; // x代表平均数
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a > x)
        {
            q.push(a);
        }
        if (a < x)
        {
            sum += pow(a - x, 2);
            dum += x - a;
        }
    }
    if (q.size())
    {
        while (!q.empty())
        {
            double p = dum / q.size(); // 比平均数多的人该付的部分
            if (q.top() - x >= p)
            {
                sum += q.size() * p * p;
                break;
            }
            else
            {
                sum += pow(q.top() - x, 2);
                dum -= q.top() - x;
                q.pop();
            }
        }
    }
    cout << fixed << setprecision(4) << sqrt(sum / n);
    return 0;
}
/*
// P8664
#include <bits/stdc++.h>
using namespace std;
//const int N=10;
const int N=5e5+4;
double aa[N]={0};
inline double pow2(double x){
    return x*x;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n; double S; cin>>n>>S;//S记录剩余钱数
    for(int i=1;i<=n;++i) cin>>aa[i];
    sort(aa+1,aa+1+n);
    double last=0,sum=0,ave=S/n;
    for(int i=1;i<=n&&S;++i){
        if(aa[i]>=S/(n-i+1)){//剩余的金额后面的人平摊即可
            sum+=pow2(S/(n-i+1)-ave)*(n-i+1); S=0; break;
        }
        S-=aa[i]; sum+=pow2(aa[i]-ave);
    }
    sum=sqrt(sum/n);
    cout<<fixed<<setprecision(4)<<sum<<endl;
    return 0;
}
*/