// 二分图，按位异或，贡献法 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int M = 100010, N = M * 2;
int n, m;
int ans[N], val[N];
int h[N], w[N], e[N], ne[N], idx;
bool st[N];
vector<int> res; // 存储同一个连通块中的所有结点。在同一连通块中， 其中一个点的值确定了则可以确定其他所有点的的值，由此也可判断是否存在矛盾 
void add(int a, int b, int c)
{
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs(int u)
{
	st[u] = true;
	res.push_back(u);
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j]) 
		{
			if (val[j] == (val[u] ^ w[i])) continue;
			cout << "-1\n";
			exit(0);
		}
		val[j] = val[u] ^ w[i];
		dfs(j);
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	while (m -- )
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z), add(y, x, z);		
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (st[i]) continue;
		dfs(i);
		int root = 0;
		// 一个点的某一位上可能是1也可能是0 
		// 使用root维护（判断）最小值 
		for (int k = 30; k >= 0; k -- )
		{
			int cnt0 = 0, cnt1 = 0;
			for (auto u : res)
				if (val[u] & (1 << k)) cnt1 ++ ;
				else cnt0 ++ ;
			if (cnt0 < cnt1) root |= (1 << k);
			// 总和最小即每一位上1的数量最小 
		}
		for (auto u : res) ans[u] = val[u] ^ root;
		res.clear();
	}
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];
	return 0;
}
