#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
void solve()
{
	int n, m, ans = 1;
	cin >> n >> m;
	vector<int> a(n + 1), res;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	string s;
	cin >> s;
	int l = 1, r = n;
	for (int i = 0; i < n; i ++ )
		if (s[i] == 'L') l ++ ;
		else r -- ;
	for (int i = n - 1; i >= 0; i -- )
	{
		if (s[i] == 'L')
		{
			l -- ;
			ans = ans * a[l] % m;
		}
		else
		{
			r ++ ;
			ans = ans * a[r] % m;
		}
		res.push_back(ans);
	}
	for (int i = n - 1; i >= 0; i -- ) cout << res[i] << " \n"[!i];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
