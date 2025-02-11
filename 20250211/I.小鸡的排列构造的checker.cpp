#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10, M = 3 * N;
int n, m;
int t[N], ans[M];
struct A
{
	int v, id;
}a[N];
struct Query
{
	int l, r, c, id;
}q[M];
bool cmp1(A a, A b)
{
	return a.v < b.v;
}
bool cmp2(Query a, Query b)
{
	return a.c < b.c;
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}
int sum(int x)
{
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
	return res;
}
void solve()
{
	memset(t, 0, sizeof(t));
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		int v;
		cin >> v;
		a[i] = {v, i};
	}
	for (int i = 1; i <= m; i ++ )
	{
		int l, r, c;
		cin >> l >> r >> c;
		q[i] = {l, r, a[c].v, i};
	}
	sort(a + 1, a + n + 1, cmp1);
	sort(q + 1, q + m + 1, cmp2);
	for (int i = 1, j = 1; i <= m; i ++ )
	{
		int x = q[i].c, l = q[i].l, r = q[i].r, id = q[i].id;
		while (j <= n && a[j].v < x)
		{
			add(a[j].id, 1);
			j ++ ;
		}
		ans[id] = sum(r) - sum(l - 1) + l;
	}
	for (int i = 1; i <= m; i ++ ) cout << ans[i] << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
