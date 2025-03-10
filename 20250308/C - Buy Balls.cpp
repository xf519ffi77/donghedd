#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	LL ans = 0;
	cin >> n >> m;
	vector<LL> a(n + 1, 0), b(m + 1, 0);
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= m; i ++ ) cin >> b[i];
	sort(a.begin() + 1, a.end(), greater<LL>());
	sort(b.begin() + 1, b.end(), greater<LL>());
	int r = 0;
	while (a[r + 1] >= 0 && r + 1 <= n) r ++ ;
	vector<LL> s(min(n, m) + 1, 0);
	for (int i = 1; i <= min(n, m); i ++ ) s[i] = s[i - 1] + a[i] + b[i];
	for (int i = 1; i <= r; i ++ ) a[i] += a[i - 1];
	for (int i = 0; i <= min(n, m); i ++ )
		ans = max(ans, s[i] + (r > i ? (a[r] - a[i]) : 0));
	cout << ans << endl;
	return 0;
}
