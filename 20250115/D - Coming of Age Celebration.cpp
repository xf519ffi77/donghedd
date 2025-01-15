#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500010;
int n;
int a[N], d[N], ans[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		d[i] += d[i - 1];
		ans[i] = a[i] + d[i];
		int t = min(ans[i], n - i);
		ans[i] -= t;
		if (i + 1 <= n) d[i + 1] ++ ;
		if (i + 1 + t <= n) d[i + 1 + t] -- ;
	}
	for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
	return 0;
}