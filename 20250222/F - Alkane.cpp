// 树形dp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, idx = 0, ans = -1;
	cin >> n;
	vector<vector<int>> f(n + 1, vector<int>(5, -0x3f3f3f3f));
	vector<int> h(n + 1, -1), e(n * 2), ne = e;
	auto add = [&](int a, int b)
	{
		e[idx] = b;
		ne[idx] = h[a];
		h[a] = idx ++ ;
	};
	for (int i = 1; i < n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	function<void(int u, int p)> dfs = [&](int u, int p)
	{
		f[u][0] = 1;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (j == p) continue;
			dfs(j, u);
			for (int k = 4; k >= 1; k -- )
				f[u][k] = max(f[u][k], f[u][k - 1] + max(f[j][0], f[j][3]));
		}
	};
	dfs(1, 0);
	for (int i = 1; i <= n; i ++ )
		ans = max(ans, max(f[i][1], f[i][4]));
	if (ans < 5) cout << -1 << endl;
	else cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
