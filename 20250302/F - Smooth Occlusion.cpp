#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 200010;
int n;
LL sum, x;
LL d[N], u[N];
bool check(LL h)
{
	// l[i] = max(h - u[i], 0), r[i] = d[i]
	// l[i] <= a[i] <= r[i]
	LL lastl = max(h - u[1], 0LL), lastr = d[1];
	for (int i = 2; i <= n; i ++ )
	{
		// | a[i] - a[i - 1] | <= x
		// a[i - 1] - x <= a[i] <= a[i - 1] + x
		// l[i - 1] - x <= a[i] <= r[i - 1] + x
		// l[i] <= a[i] <= r[i]
		LL l = max(h - u[i], 0LL), r = d[i];
		lastl = max(lastl - x, l);
		lastr = min(lastr + x, r);
		if (lastl > lastr) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	LL l = 1, r = 2e9;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> u[i] >> d[i];
		sum += u[i] + d[i];
		r = min(r, u[i] + d[i]);
	}
	while (l < r)
	{
		LL mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << sum - l * n << endl;
	return 0;
}
