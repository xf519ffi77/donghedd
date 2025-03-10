#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<int> pre(n + 1, 0);
	for (int i = 1; i <= n; i ++ )
		pre[i] += s[i] - '0' + pre[i - 1];
	for (int i = n; i >= 1; i -- )
	{
		pre[i - 1] += pre[i] / 10;
		pre[i] %= 10;
	}
	bool flag = false;
	for (int i = 0; i <= n; i ++ )
		if (pre[i] || flag)
		{
			flag = true;
			cout << pre[i];
		}
	cout << endl;
		
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
