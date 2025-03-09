#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
void solve()
{
	int n, cnt = 0;
	LL ans = 0;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		ans += (LL)abs(a[i]);
	}
	bool flag = false;
	for (int i = 1; i <= n; i ++ )
		if (a[i] > 0) flag = false;
		else if (a[i] < 0 && !flag)	
		{
			cnt ++ ;
			flag = true;
		}
	cout << ans << " " << cnt << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
