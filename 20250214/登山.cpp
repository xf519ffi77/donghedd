#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1010;
int n, ans;
int a[N], fl[N], fr[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ )
	{
		fl[i] = 1;
		for (int j = 1; j < i; j ++ )
			if (a[i] > a[j]) fl[i] = max(fl[i], fl[j] + 1);
	}
	for (int i = n; i >= 1; i -- )
	{
		fr[i] = 1;
		for (int j = n; j > i; j -- )
			if (a[i] > a[j]) fr[i] = max(fr[i], fr[j] + 1);
	}
	for (int i = 1; i <= n; i ++ ) ans = max(ans, fl[i] + fr[i] - 1);
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
