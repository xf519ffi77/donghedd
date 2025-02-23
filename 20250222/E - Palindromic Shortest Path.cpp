// bfs
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	vector<string> g(n + 1);
	vector<vector<int>> a(n + 1, vector<int>(n + 1, -1));
	queue<PII> q;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> g[i];
		g[i] = " " + g[i];
	}
	for (int i = 1; i <= n; i ++ )
	{
		q.push({i, i});
		a[i][i] = 0;
	}
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
		{
			if (i == j || g[i][j] == '-') continue;
			q.push({i, j});
			a[i][j] = 1;
		}
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		int i = t.first, j = t.second;
		for (int k = 1; k <= n; k ++ )
			for (int l = 1; l <= n; l ++ )
				if (g[k][i] != '-' && g[j][l] != '-' && g[k][i] == g[j][l] && a[k][l] == -1)
				{
					a[k][l] = a[i][j] + 2;
					q.push({k, l});
				}
	}
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			cout << a[i][j] << " \n"[j == n];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
