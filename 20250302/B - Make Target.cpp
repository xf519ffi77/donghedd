#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n;
	cin >> n;
	vector<string> s(n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		int j = n + 1 - i;
		if (i > j) continue;
		char c = '.';
		if (i & 1) c = '#';
		for (int k = i; k <= j; k ++ )
			for (int l = i; l <= j; l ++ )
				s[k][l] = c;
	}
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= n; j ++ )
			cout << s[i][j];
		cout << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
