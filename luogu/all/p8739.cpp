#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;  // 存储出现的字符以及他们的次数
vector<string> vec; // 存储分割后的一段段序列

bool cmp_value(const pair<int, int> left, const pair<int, int> right) // 这是一个辅助函数，用来找出最大的value
{
    return left.second < right.second;
}

int main(void)
{
    int K;
    string S;
    cin >> K;
    cin >> S;

    if (S.length() % K != 0) // 分割不了，直接跑路
    {
        cout << -1;
        return 0;
    }

    string temp;
    for (int i = 0; i < S.length(); i++)
    { // 将字符串S按K一组组组分割
        temp.push_back(S[i]);
        if ((i + 1) % (S.length() / K) == 0)
        {
            vec.push_back(temp);
            temp.clear();
        }
    }

    long long ans{};
    for (int i = 0; i < S.length() / K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (mp.find(vec[j][i]) == mp.end()) // 如果没有这个键值对，就加进去
            {
                mp[vec[j][i]] = 1;
            }
            else
            {
                mp[vec[j][i]]++;
            }
        }
        auto te = max_element(mp.begin(), mp.end(), cmp_value);//找到最大键值对（以value作比较）
        ans += K - te->second;
        mp.clear(); // 清空mp，开始比较下一组
    }

    cout << ans;
    return 0;
}
/*
// P8739
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int num[30]={0};
int main()
{
    int k; cin>>k;
    string s; cin>>s;
    if(s.size()%k){
        cout<<-1<<endl; return 0;
    }
    int len=s.size()/k;//每段字符串的长度
    long long res=0;
    for(int i=0;i<len;++i){
        memset(num,0,sizeof(num));
        for(int j=0;j<k;++j)
            ++num[s[j*len+i]-'a'];
        int max_num=0;
        for(int j=0;j<26;++j)
            if(num[j]>num[max_num]) max_num=j;
        res+=k-num[max_num];
    }
    cout<<res<<endl;
    return 0;
}
*/