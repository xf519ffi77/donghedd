#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500010;
int n;
int a[N], c[N], d[N], ans[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		c[i] = c[i - 1] + d[i]; // 差分，c[i]记录前i-1个人中有几个会给第i个人送石头 
		a[i] += c[i];
		int t = min(a[i], n - i);
		a[i] -= t;
		// 利用差分，[i + 1, i + t + 1]整体++ 
		d[i + 1] ++ ;
		d[i + t + 1] -- ;
	}
	for (int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
	return 0;
}