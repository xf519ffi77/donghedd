#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	int ans = a[0];
	for (int i = 1; i < n; i ++ ) ans = (ans / a[i] + 1) * a[i];
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
