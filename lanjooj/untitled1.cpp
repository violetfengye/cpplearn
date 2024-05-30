#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> q;
int main()
{
	ll n, cnt{}, ans{};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}
	ll tx{};
	while (q.size())
	{
		if (q[0] == n)
			ans = cnt + 1;
		q.erase(q.begin());
		cnt++;
		ll tmp = q.size();
		if (tmp == 0)
			break;
		for (int i = 1; i <= tmp; i++)
		{
			if (i % 3 == 0)
			{
				ll t = q[i - 1];
				q.erase(q.begin()+i-1+tx);
				tx++;
				if (t == n)
				{
					ans = cnt;
				}
			}
		}
		tx=0;
	}
	cout << cnt << " " << ans;
	return 0;
}
