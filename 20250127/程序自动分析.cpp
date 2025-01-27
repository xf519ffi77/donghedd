#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
int p[N * 2];
struct Query
{
	int x, y, e;
}query[N];
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
void solve()
{
	int n, cnt = 0;
	cin >> n;
	unordered_map<int, int> S;
	auto get = [&](int x)
	{
		if (S.count(x) == 0) S[x] = ++ cnt;
		return S[x];
	};
	for (int i = 1; i <= n; i ++ )
	{
		int x, y, e;
		cin >> x >> y >> e;
		query[i] = {get(x), get(y), e};
	}
	for (int i = 1; i <= cnt; i ++ ) p[i] = i;
	// 合并所有相等的约束条件 
	for (int i = 1; i <= n; i ++ )
		if (query[i].e == 1)
		{
			int px = find(query[i].x), py = find(query[i].y);
			p[px] = py;
		}
	// 检查所有不等的约束条件 
	for (int i = 1; i <= n; i ++ )
		if (query[i].e == 0)
		{
			int px = find(query[i].x), py = find(query[i].y);
			if (px == py)
			{
				cout << "NO" << endl;
				return;
			}
		}
	cout << "YES" << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
} 
