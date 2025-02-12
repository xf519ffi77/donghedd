#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3e5 + 10;
int n;
int p[N], q[N], ans[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> p[i];
	for (int i = 1; i <= n; i ++ ) cin >> q[i];
	for (int i = 1; i <= n; i ++ ) ans[q[i]] = q[p[i]];
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
