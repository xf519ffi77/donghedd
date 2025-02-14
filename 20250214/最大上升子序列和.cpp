#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1010;
int n, ans;
int a[N], f[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ )
	{
	    f[i] = a[i];
	    for (int j = 1; j < i; j ++ )
	        if (a[i] > a[j]) f[i] = max(f[i], f[j] + a[i]);
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
