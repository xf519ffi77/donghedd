#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 200010, M = 19;
int n;
int a[N];
int st[N][M], f[N];
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int query(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
void solve()
{
	memset(st, 0, sizeof(st));
	memset(f, 0, sizeof(f));
	cin >> n;
	map<int, vector<int>> mp;
	mp[0].push_back(0);
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		st[i][0] = a[i];
		f[i] = f[i - 1] ^ a[i];
		mp[f[i]].push_back(i);
	}
	for (int j = 1; j < M; j ++ )
		for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
	LL ans = 0;
	for (int l = 1; l <= n; l ++ )
	{
		int r = l + 1;
		while (r <= n)
		{
			int x = r, y = n;
			int g = query(l, r);
			while (x < y)
			{
				int mid = x + y + 1 >> 1;
				if (query(l, mid) == g) x = mid;
				else y = mid - 1;
			}
			auto &v = mp[g ^ f[l - 1]];
			int le = lower_bound(v.begin(), v.end(), r) - v.begin();
			int ri = upper_bound(v.begin(), v.end(), y) - v.begin();
			ans += (LL)ri - le;
			r = y + 1;
		}
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

// gcd，xor，二分，ST表/线段树，STL