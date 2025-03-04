#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve()
{
	int n, Max = -2e9, cnt = 0;
	cin >> n;
	vector<int> a(n);
	vector<PII> v;
	unordered_map<int, int> mp;
	for (int i = 0; i < n * (n - 1) / 2; i ++ )
	{
		int t;
		cin >> t;
		Max = max(Max, t);
		mp[t] ++ ;
	}
	for (auto &t : mp)
	{
		int x = t.first, y = t.second;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for (auto &t : v)
	{
		int x = t.first, y = t.second;
		if (y <= n - cnt - 1) a[cnt ++ ] = x;
		else
		{
			for (int j = n - cnt - 1; j >= 1 && y > 0; j -- )
			{
				y -= j;
				a[cnt ++ ] = x;
			}
		}
	}
	
	a[cnt ++ ] = Max;
	for (auto t : a) cout << t << " ";
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
