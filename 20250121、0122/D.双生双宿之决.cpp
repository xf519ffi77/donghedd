#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N];
void solve()
{
	unordered_map<int, int> cnt;
	int n, f = 0;
	cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    if (n & 1)
	{
		cout << "No" << endl;
		return;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (!cnt[a[i]]) f ++ ;
		if (f > 2)
		{
			cout << "No" << endl;
			return;
		}
		cnt[a[i]] ++ ;
		if (cnt[a[i]] > n / 2)
		{
			cout << "No" << endl;
			return;
		}
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

// 暴力，思维