#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int n;
LL a[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
    if (a[1] == a[n])
    {
        cout << n / 2 << endl;
        return;
    }
	LL x, y;
	if (n % 4)
		x = a[(1 + n / 2) / 2], y = a[(n / 2 + 1 + n) / 2];
	else
		x = (a[n / 4] + a[n / 4 + 1]) / 2, y = (a[3 * n / 4] + a[3 * n / 4 + 1]) / 2; 
	LL ans = 0;
    if (x == y)
    {
        LL ans1 = 0, ans2 = 0;
        for (int i = 1, j = n; i < j; i ++ , j -- )
            ans1 += abs(a[i] - (x - 1)) + abs(a[j] - y);
         for (int i = 1, j = n; i < j; i ++ , j -- )
            ans2 += abs(a[i] - x) + abs(a[j] - (y + 1));
        ans = min(ans1, ans2);
    }
	else
        for (int i = 1, j = n; i < j; i ++ , j -- )
		  ans += abs(a[i] - x) + abs(a[j] - y);
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

// 中位数