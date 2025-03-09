#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
void solve()
{
	int n, ans = 0;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n / 2; i ++ ) ans += a[n - i + 1] - a[i];
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
