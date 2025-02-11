#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	LL k;
	cin >> k;
	LL l = 1, r = k * 2;
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (mid - __lg(mid) >= k) r = mid;
		else l = mid + 1;
	}
	cout << l * 2 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
