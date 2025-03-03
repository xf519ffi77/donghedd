#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	bool flag = true;
	for (int i = 1; i < n; i ++ )
		if (a[i] <= a[i - 1])
		{
			flag = false;
			break;
		}
	if (flag) cout << "Yes\n";
	else cout << "No\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
