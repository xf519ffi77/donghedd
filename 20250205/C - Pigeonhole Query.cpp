#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int cnt[N], site[N];
void solve()
{
	int n, q, res = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cnt[i] = 1, site[i] = i;
	while (q -- )
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int p, h;
			cin >> p >> h;
			if (cnt[site[p]] == 2) res -- ;
			cnt[site[p]] -- ;
			if (cnt[h] == 1) res ++ ;
			cnt[h] ++ ;
			site[p] = h;
		}
		else cout << res << endl;
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
