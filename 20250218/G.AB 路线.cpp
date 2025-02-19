// 三维bfs

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1010, M = 11;
int n, m, k, ans = 0x3f3f3f3f;
char g[N][N];
bool st[N][N][M];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void bfs()
{
	queue<array<int, 5>> q;
	q.push({1, 1, 1, 0});
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		int x0 = t[0], y0 = t[1], cnt = t[2], res = t[3];
		if (x0 == n && y0 == m)
		{
			ans = min(ans, res);
			continue;
		}
		if (st[x0][y0][cnt]) continue;
		st[x0][y0][cnt] = true;
		for (int i = 0; i < 4; i ++ )
		{
			int x = x0 + dx[i], y = y0 + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m)
			{
				if (cnt == k && g[x][y] != g[x0][y0] && !st[x][y][1]) q.push({x, y, 1, res + 1});
				if (cnt != k && g[x][y] == g[x0][y0] && !st[x][y][cnt + 1]) q.push({x, y, cnt + 1, res + 1});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> g[i][j];
	bfs();
	if (ans == 0x3f3f3f3f) cout << -1 << endl;
  else cout << ans << endl;
	return 0;
}
