#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int n, m;
int p[N];
struct Edge
{
	int u, v, id;
}edges[N];
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
void solve()
{
	cin >> n >> m;
	int ans = n, cnt = 0;
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int u, v;
		cin >> u >> v;
		int pu = find(u), pv = find(v);
		if (pu == pv) edges[ ++ cnt] = {u, v, i};
		else
		{
			p[pu] = pv;
			ans -- ;
		}
	}
	if (ans == 1)
	{
		cout << 0 << endl;
		return;
	}
	cout << ans - 1 << endl;
	set<int> s;
	for (int i = 1; i <= n; i ++ )
		if (find(i) == i) s.insert(i);
	for (int i = 1; i <= cnt && ans > 1; i ++ )
	{
		int u = edges[i].u, v = edges[i].v, id = edges[i].id;
		int pu = find(u);
		s.erase(pu);
		int res = *s.begin();
		cout << id << ' ' << v << ' ' << res << endl;
		p[pu] = res;
		ans -- ;
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
