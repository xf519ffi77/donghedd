#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
			cin >> g[i][j];
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
		{
			int cnt = 0, Max = 0;
			for (int k = 0; k < 4; k ++ )
			{
				int x = i + dx[k], y = j + dy[k];
				if (x < 0 || x >= n || y < 0 || y >= m) cnt ++ ;
				else if (g[x][y] < g[i][j])
				{
					cnt ++ ;
					Max = max(Max, g[x][y]);
				}
			}
			if (cnt == 4) g[i][j] = Max;
		}
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
			cout << g[i][j] << " \n"[j == m - 1];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
