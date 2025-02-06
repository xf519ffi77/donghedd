#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	cout << max(x * a, max(y * b, z * c)) << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
