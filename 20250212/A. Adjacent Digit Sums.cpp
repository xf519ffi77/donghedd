#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int x, y;
	cin >> x >> y;
	if (y - x == 1 || (x > y && ((x - y + 1) % 9 == 0))) cout << "YES\n";
	else cout << "NO\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
