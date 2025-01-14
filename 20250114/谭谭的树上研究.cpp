#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010, M = N * 2;
int n, m, l, r;
LL ans;
int h[N], e[M], ne[M], idx;
LL d[N][2];
bool st[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void bfs(int u, LL distance, int o)
{
	st[u] = true;
	d[u][o] = distance;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j]) bfs(j, distance + 1, o);
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for (int i = 1; i < n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	cin >> l >> r;
	bfs(l, 0, 0);
	memset(st, false, sizeof(st));
	bfs(r, 0, 1);
	for (int i = 1; i <= n; i ++ )
		ans += min(d[i][0], d[i][1]);
	cout << ans * m << endl;
	return 0;
}
