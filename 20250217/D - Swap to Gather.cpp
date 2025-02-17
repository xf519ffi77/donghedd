#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
void solve()
{
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ )
		if (s[i] == '1') a[cnt ++ ] = i;
	vector<int> b(cnt);
	for (int i = 0; i < cnt; i ++ ) b[i] = a[i] - i;
	sort(b.begin(), b.end());
	int mid = b[cnt / 2];
	LL ans = 0;
	for (int i = 0; i < cnt; i ++ )
		ans += abs(b[i] - mid);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
