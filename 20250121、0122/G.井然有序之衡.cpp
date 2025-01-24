#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int n; 
LL a[N];
void solve()
{
	LL s = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		s += a[i];
	}
	if (s != (LL)n * (n + 1) / 2)
	{
		cout << -1 << endl;
		return;
	}
	sort(a + 1, a + n + 1);
	s = 0;
	for (int i = 1; i <= n; i ++ ) s += abs(a[i] - i);
	cout << s / 2 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}

// 暴力，思维