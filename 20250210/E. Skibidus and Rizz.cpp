#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool cmp(int a, int b)
{
	return a > b;
}
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (max(n - m, m - n) > k || k > max(n, m))
	{
		cout << "-1\n";
		return;
	}
	if (!n || !m)
	{
		for (int i = 1; i <= n + m; i ++ ) cout << (!n) ? 1 : 0;
		cout << endl;
		return;
	}
	int a;
	unordered_map<int, int> mp;
	if (n > m) a = 0;
	else a = 1;
	for (int i = 1; i <= n + m; i ++ )
	{
		if (i <= k)
		{
			cout << a;
			mp[a] ++ ;
		}
		else
		{
			if (mp[a] == max(n, m))
			{
				for (int j = i; j <= n + m; j ++ ) cout << 1 - a;
				break;
			}
			if (mp[1 - a] == min(n, m))
			{
				for (int j = i; j <= n + m; j ++ ) cout << a;
				break;
			}
			if ((i - k) & 1)
			{
				cout << 1 - a;
				mp[1 - a] ++ ;
			}
			else
			{
				cout << a;
				mp[a] ++ ;
			}
		}
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
