#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int mod = 998244353;
void solve()
{
	int n;
	LL a = 0, b = 0, c = 0;
	cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		int t;
		cin >> t;
		if (t == 1) a = (a + 1) % mod ;
		else if (t == 2) b = (b + a + b) % mod;
		else c = (c + b) % mod;
	}
	cout << c % mod << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
