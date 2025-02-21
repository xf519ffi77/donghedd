#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n, cnt0 = 0;
	cin >> n;
	vector<int> b(n + 1);
	for (int i = 2; i <= n - 1; i ++ ) cin >> b[i];
	if (b[2] == 0) cnt0 = 2;
	for (int i = 3; i <= n - 1; i ++ )
		if (b[i] == 0) cnt0 ++ ;
		else
		{
			if (cnt0 < 2 && b[i - 1] != 1)
			{
				cout << "NO\n";
				return;
			}
			cnt0 = 0;
		}
	cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
