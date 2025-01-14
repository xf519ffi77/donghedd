#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
int n, ans;
int a[N], cnt[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		cnt[a[i]] ++ ;
	}
	sort(a + 1, a + n + 1);
	if (cnt[a[n]] >= 2) cnt[a[n]] = 1;
	for (int i = 1; i <= n; i ++ )
	{
		if (cnt[a[i]] <= 2)  ans += cnt[a[i]];
		else ans += 2;
		cnt[a[i]] = 0;
	}
	cout << ans << endl;
	return 0;
}