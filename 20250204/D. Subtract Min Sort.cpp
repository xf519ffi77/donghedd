#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010;
int a[N];
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i < n; i ++ )
	{
		if (a[i] > a[i + 1])
		{
			cout << "NO" << endl;
			return;
		}
		a[i + 1] -= a[i];
	}
	cout << "Yes" << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
