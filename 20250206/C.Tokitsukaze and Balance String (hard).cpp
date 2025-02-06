#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
LL quickpower(int a, int k)
{
	LL res = 1, t = a;
	while (k)
	{
		if (k & 1) res = res * t % mod;
		t = t * t % mod;
		k >>= 1;
	}
	return res;
}
void solve()
{
	int n, cnt = 0;
	LL ans = 0;
	string s;
	cin >> n >> s;
	if (n == 1)
	{
		if (s == "?") cout << 2 << endl;
		else cout << 1 << endl;
		return;
	}
	s = " " + s; 
	for (int i = 1; i <= n; i ++ )
		if (s[i] == '?') cnt ++ ;
	if (s[1] != '?' && s[n] != '?')
	{
		if (s[1] == s[n]) ans = quickpower(2, cnt) * (n - 2) % mod;
		else ans = quickpower(2, cnt) * 2 % mod;
	}
	else ans = quickpower(2, cnt - 1) * n % mod;
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
