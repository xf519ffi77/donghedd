#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
struct K
{
	int v, id;
};
bool cmp(K a, K b)
{
	return a.v < b.v;
}
void solve()
{
	int n;
	cin >> n;
	vector<K> k(n);
	vector<vector<int>> a(n, vector<int>(N));
	vector<vector<int>> cnt(n, vector<int>(N, 0));
	for  (int i = 0; i < n; i ++ )
	{
		cin >> k[i].v;
		k[i].id = i;
		for (int j = 0; j < k[i].v; j ++ )
		{
			cin >> a[i][j];
			cnt[i][a[i][j]] ++ ;
		}
	}
	stable_sort(k.begin(), k.end(), cmp);
	LL ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i ++ )
		for (int j = i + 1; j < n; j ++ )
		{
			LL res = 0;
			int id1 = k[i].id, id2 = k[j].id;
			for (int t = 0; t < k[i].v; t ++ ) res += (LL)cnt[id2][a[id1][t]];
			if (!ans1 || res * ans2 > ans1 * k[i].v * k[j].v) ans1 = res, ans2 = (LL)k[i].v * k[j].v;
		}
	cout << fixed << setprecision(15) << (double)ans1 / ans2;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
