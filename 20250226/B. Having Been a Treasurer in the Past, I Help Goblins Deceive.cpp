#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	LL cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i ++ )
		if (s[i] == '-') cnt1 ++ ;
		else cnt2 ++ ;
	cout << (cnt1 / 2) * (cnt1 / 2 + (cnt1 & 1)) * cnt2 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
