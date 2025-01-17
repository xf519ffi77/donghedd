#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 2e+5 + 10;
LL a[N];
void solve()
{
	int n;
	LL x, y, sum = 0, ans1 = 0, ans2 = 0;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
	if (sum <= x)
	{
		cout << 0 << endl;
		return;
	}
	sort(a + 1, a + n + 1);
	for (int i = n, j = 1; i >= 1; i -- )
	{
		if (sum - a[i] - a[i] < x) ans1 -- ;
		while (j <= n && sum - a[i] - a[j] >= x) j ++ ;
		ans1 += (LL)n - j + 1;
	}
	for (int i = n, j = 1; i >= 1; i -- )
	{
		if (sum - a[i] - a[i] < y + 1) ans2 -- ;
		while (j <= n && sum - a[i] - a[j] >= y + 1) j ++ ;
		ans2 += (LL)n - j + 1;
	}
	cout << (ans2 - ans1) / 2 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
// 思维，双指针or二分