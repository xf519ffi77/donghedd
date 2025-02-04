#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int a, b, c, d, e, cnt = 1, ans = 0;
	cin >> a >> b >> d >> e;
	c = a + b;
	cnt += (b + c == d);
	cnt += (c + d == e);
	ans = max(ans, cnt);
	c = d - b;
	cnt = 1;
	cnt += (a + b == c);
	cnt += (c + d == e);
	ans = max(ans, cnt);
	cnt = 1;
	c = e - d;
	cnt += (a + b == c);
	cnt += (b + c == d);
	ans = max(ans, cnt);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
