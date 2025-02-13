#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10; 
int n, m, ans;
int a[N], b[N];
unordered_map<int, vector<int>> mpa, mpb;
void dfs(int x, int y, int cnt)
{
	if (a[x] != b[y]) return;
	ans = max(ans, cnt + 1);
	for (int i = 0; i < mpa[x].size(); i ++ )
		for (int j = 0; j < mpb[y].size(); j ++ )
			dfs(mpa[x][i], mpb[y][j], cnt + 1);
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= m; i ++ ) cin >> b[i];
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		cin >> u >> v;
		mpa[u].push_back(v);
	}
	for (int i = 1; i < m; i ++ )
	{
		int u, v;
		cin >> u >> v;
		mpb[u].push_back(v);
	}
	dfs(1, 1, 0);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
