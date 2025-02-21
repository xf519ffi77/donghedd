#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	if ((a ^ b) & 1) cout << "NO\n";
	else cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
