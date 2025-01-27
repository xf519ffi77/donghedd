#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 300010;
int n;
LL ans;
int a[N], l[N], r[N], vis[N]; // vis[x]存储x上一次出现的位置 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ )
	{
		// a[i] = x, 左边不能有 x 和 x - 1 
		l[i] = max(vis[a[i]], vis[a[i] - 1]) + 1;
		vis[a[i]]  = i;
	}
	fill(vis, vis + n + 1, n + 1); // vis[i] = n + 1;
	for (int i = n; i >= 1; i -- )
	{
		// a[i] = x, 右边不能有 x - 1
		r[i] = vis[a[i] - 1] - 1;
		vis[a[i]] = i;
	}
	// 对于位置i来说，左端能取到位置 i - l[i] + 1，右端能取到位置 r[i] - i + 1; 
	for (int i = 1; i <= n; i ++ ) ans += (LL)(i - l[i] + 1) * (r[i] - i + 1);
	cout << ans << endl;
	return 0;
}
