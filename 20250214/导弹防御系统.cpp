#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 51;
int n, ans;
int a[N], up[N], down[N];
void dfs(int u, int su, int sd) // 处理前u个导弹，需要su个上升子序列，sd个下降子序列
{
	if (su + sd >= ans) return;
	if (u == n)
	{
		ans = su + sd;
		return;
	}
	int k = 0;
	while (k < su && up[k] >= a[u]) k ++ ;
	int t = up[k];
	up[k] = a[u];
	if (k < su) dfs(u + 1, su, sd);
	else dfs(u + 1, su + 1, sd);
	up[k] = t;
	k = 0;
	while (k < sd && down[k] <= a[u]) k ++ ;
	t = down[k];
	down[k] = a[u];
	if (k < sd) dfs(u + 1, su, sd);
	else dfs(u + 1, su, sd + 1);
	down[k] = t;
}
void solve()
{
	while (cin >> n, n)
	{
		for (int i = 0; i < n; i ++ ) cin >> a[i];
		ans = n;
		dfs(0, 0, 0);
		cout << ans << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
