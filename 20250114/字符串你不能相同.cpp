#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
LL solve()
{
	string s;
	cin >> s;
	LL n = s.length(), ans = n * (n + 1) / 2 - 3;
	LL cnt1 = 0, cnt2 = 0, cnt3 = 0;
	char c = s[0];
	for (int i = 0; i < n; i ++ )
		if (s[i] == c) cnt1 ++ ;
		else break;
	c = s[n - 1];
	for (int i = n - 1; i >= 0; i -- )
		if (s[i] == c) cnt2 ++ ;
		else break;
	if (cnt1 == n) return 0;
	if (s[0] == s[n - 1]) cnt3 = cnt1 * cnt2;
	return ans - cnt1 - cnt2 - cnt3 + 2;
	
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T -- ) cout << solve() << endl;;
	return 0;
}