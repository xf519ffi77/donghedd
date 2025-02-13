#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1, 0), c(n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		b[a[i]] ++ ;
	}
	auto query = [&](int x, int y)
	{
		cout << "? " << x << " " << y << endl;
		int v;
		cin >> v;
		return v;
	};
	for (int i = 1; i <= n; i ++ )
		if (!b[i])
		{
			if (!query(i, i == 1 ? 2 : 1)) cout << "! A" << endl;
			else cout << "! B" << endl;
			return;
		}
	for (int i = 1; i <= n; i ++ ) c[a[i]] = i;
	int v = query(c[1], c[n]);
	if (v < n - 1) cout << "! A" << endl;
	else if (v > n - 1) cout << "! B" << endl;
	else
	{
		int w = query(c[n], c[1]);
		if (v == w) cout << "! B"  << endl;
		else cout << "! A" << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
