#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, m;
	cin >> n;
	vector<LL> a(n);
	map<LL, int> mp;
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		mp[a[i]] ++ ;
	}
	cin >> m;
	while (m -- )
	{
		LL x, y;
		cin >> x >> y;
		LL z = x * x - y * 4;
		if (z < 0)
		{
			cout << 0 << " ";
			continue;
		}
		LL p = sqrtl(z);
		LL x1 = (x + p) / 2, x2 = (x - p) / 2;
		if (x1 + x2 != x || x1 * x2 != y)
		{
			cout << 0 << " ";
			continue;
		}
		if (x1 == x2) cout << (LL)mp[x1] * (mp[x1] - 1) / 2 << " ";
		else cout << (LL)mp[x1] * mp[x2] << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
