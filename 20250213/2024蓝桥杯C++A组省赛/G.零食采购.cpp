#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010, M = N * 2;
int n, q;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][21];
int c[N], cnt[N][21]; // cnt[i][j]表示1到i的路径中第j种商品的数量 
void add(int a,  int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void dfs(int u, int p)
{
	depth[u] = depth[p] + 1;
	fa[u][0] = p;
	for (int k = 1; k <= 20; k ++ ) fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j == p) continue;
		for (int k = 1; k <= 20; k ++ ) cnt[j][k] += cnt[u][k];
		cnt[j][c[j]] ++ ;
		dfs(j, u);
	}
}
int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 20; k >= 0; k -- )
		if (depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	if (a == b) return a;
	for (int k = 20; k >= 0; k -- )
		if (fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	return fa[a][0];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> c[i];
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	cnt[1][c[1]] ++ ;
	dfs(1, 0);
	while (q -- )
	{
		int u, v;
		cin >> u >> v;
		int p = lca(u, v), ans = 0;
		for (int i = 1; i <= 20; i ++ )
			if (cnt[u][i] + cnt[v][i] - 2 * cnt[p][i] + (c[p] == i) > 0) ans ++ ;
		cout << ans << endl;
	}
	return 0;
}
