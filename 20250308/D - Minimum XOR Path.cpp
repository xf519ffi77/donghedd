#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int N = 11, M = 100;
int n, m;
LL ans = 2e18;
int h[N], e[M], ne[M], idx;
LL w[M];
bool st[N];
void add(int a, int b, LL c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
} 
void dfs(int u, LL res)
{
	if (u == n) 
	{
		ans = min(ans, res);
		return;
	}
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j]) continue;
		dfs(j, res ^ w[i]);
	}
	st[u] = false;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	while (m -- )
	{
		int a, b;
		LL c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
