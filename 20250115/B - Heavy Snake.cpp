#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 110;
int n, d;
int t[N], l[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= n; i ++ ) cin >> t[i] >> l[i];
	for (int i = 1; i <= d; i ++ )
	{
		int ans = 0;
		for (int j = 1; j <= n; j ++ )
			ans = max(ans, t[j] * (l[j] + i));
		cout << ans << endl;
	}
	return 0;
}