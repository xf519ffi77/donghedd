// tarjan
// 无向图的双连通性，边的双连通性

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 200010, M = N * 2;
int n, m;
LL sum, ans = 1e18;
LL w[N];
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
//int stk[N], top;
//int id[N], dcc_cnt;
//bool is_bridge[M];
bool flag;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void tarjan(int u, int p)
{
	dfn[u] = low[u] = ++ timestamp;
//	stk[ ++ top] = u;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			w[u] += w[j]; // w[u]表示以u为根节点且包含u的子树的权值 
			if (dfn[u] < low[j])
			{
				flag = true; // u和j之间有桥
				ans = min(ans, abs(sum - 2 * w[j]));
			}
		}
		else if (i != (p ^ 1))
			low[u] = min(low[u], dfn[j]);
	}
//	if (dfn[u] == low[u])
//	{
//		dcc_cnt ++ ;
//		int y;
//		do
//		{
//			y = stk[top -- ];
//			id[y] = dcc_cnt;
//		} while (y != u);
//	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> w[i];
		sum += w[i];
	}
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	tarjan(1, -1);
	if (w[1] != sum) cout << sum - 2 * w[1] << endl;
	else
	{
		if (flag) cout << ans << endl;
		else cout << -1  << endl;
	}
	return 0;
}