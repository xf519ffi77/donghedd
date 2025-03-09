#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
void solve()
{
	int n, m, idx = 0;
	cin >> n;
	vector<int> h(n + 1, -1), e(n * 2), ne = e;
	vector<int> f(n + 1, 0);
	auto add = [&](int a, int b)
	{
		e[idx] = b;
		ne[idx] = h[a];
		h[a] = idx ++ ;
	};
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	function<int(int u, int p)> dfs = [&](int u, int p)
	{
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (j == p) continue;
			f[u] += dfs(j, u);
		}
		f[u] = max(f[u], 1);
		return f[u];
	};
	dfs(1, 0);
	cin >> m;
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		cout << (LL)f[a] * f[b] << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
