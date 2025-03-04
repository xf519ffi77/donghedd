#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve()
{
	int n, cnt = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ )
	{
		cin >> a[i];
		if (a[i] & 1) cnt ++ ;
	}
	if (cnt & 1) cout << "NO\n";
	else cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
