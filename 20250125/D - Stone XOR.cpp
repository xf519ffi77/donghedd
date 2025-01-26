#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 13;
int n;
LL a[N], sum[N];
unordered_set<LL> s;
void dfs(int u, int cnt) // cnt代表分成了几个部分 
{
	if (u == n + 1)
	{
		LL ans = 0;
		for (int i = 1; i <= cnt; i ++ ) ans ^= sum[i];
		s.insert(ans);
		return;
	}
	sum[cnt + 1] = a[u]; // a[u]单独分成一部分，接着dfs 
	dfs(u + 1, cnt + 1);
	sum[cnt + 1] = 0; // a[u]与前面某个部分相结合 
	for (int i = 1; i <= cnt; i ++ )
	{
		sum[i] += a[u];
		dfs(u + 1, cnt);
		sum[i] -= a[u];
	}
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    dfs(1, 0);
    cout << (LL)s.size() << endl;
    return 0;
}
