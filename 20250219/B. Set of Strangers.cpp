#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, m, flag = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
	unordered_map<int, int> mp;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
			if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1])
			{
				flag = a[i][j];
				break;
			}
		if (flag) break;
	}
	if (!flag) flag = a[1][1];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			if (a[i][j] == flag) continue;
			if (!mp[a[i][j]] || (mp[a[i][j]] == 1 && (a[i - 1][j] == a[i][j] || a[i][j - 1] == a[i][j])))
			{
				ans ++ ;
				mp[a[i][j]] ++ ;
			}
		}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
