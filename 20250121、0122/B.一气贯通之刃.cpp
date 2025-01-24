#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010, M = N * 2;
int n;
int h[N], e[M], ne[M], idx;
int IN[N], OUT[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i ++ )
	{
		int u, v;
		cin >> u >> v;
		IN[u] ++ , OUT[u] ++ ;
		IN[v] ++ , OUT[v] ++ ;
		if (IN[u] > 2 || OUT[u] > 2 || IN[v] > 2 || OUT[v] > 2)
		{
			cout << -1 << endl;
			return;
		}
		add(u, v), add(v, u);
	}
	int st = 0, en = 0;
	for (int i = 1; i <= n; i ++ )
		if (IN[i] == 1) st = i;
	for (int i = 1; i <= n; i ++ )
		if (OUT[i] == 1 && st != i) en = i;
	cout << st << en << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}

// 树的概念