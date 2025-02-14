#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
int n, ans;
PII a[N];
int f[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		f[i] = 1;
		for (int j = 1; j < i; j ++ )
			if (a[i].second > a[j].second) f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
