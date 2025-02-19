#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, m, ans, res1, res2;
int a[N], b[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= m; i ++ ) cin >> b[i];
	for (int i = 0, j = 0; i <= n && j <= m; )
	{
		if (res1 == res2)
		{
			res1 = a[ ++ i];
			res2 = b[ ++ j];
		}
		if (res1 > res2)
		{
			res2 += b[ ++ j];
			ans ++ ;
		}
		else if (res1 < res2)
		{
			res1 += a[ ++ i];
			ans ++ ;
		}
	}
	cout << ans << endl;
	return 0;
}
