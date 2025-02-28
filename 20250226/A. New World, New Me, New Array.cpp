#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n, k, p;
	cin >> n >> k >> p;
	if (n * p >= abs(k)) cout << abs(k) / p + (k % p != 0) << endl;
	else cout << -1 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
