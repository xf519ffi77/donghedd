#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int cnt[N], ans[N];
struct block
{
	int x, id; // x为行数，id为编号 
}; 
bool cmp(block a, block b)
{
	return a.x < b.x;
}
void solve()
{
	int n, w, q;
	cin >> n >> w;
	vector<vector<block>> a(w + 1);
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; i ++ )
	{
		int x, y;
		cin >> y >> x;
		cnt[y] ++ ;  // 计算每一列有多少个砖块
		a[y].push_back({x, i});
	}
	int num = 0x3f3f3f3f;
	for (int i = 1; i <= w; i ++ )
	{
		num = min(num, cnt[i]); // 求消除次数 
		sort(a[i].begin(), a[i].end(), cmp);
	}
	// 0 ~ num之间的砖块都会被消除
	for (int i = 0; i < num; i ++ )
	{
		int t = 0;
		for (int j = 1; j <= w; j ++ )
			t = max(t, a[j][i].x);
		for (int j = 1; j <= w; j ++ )
			ans[a[j][i].id] = t;
	}
	
	cin >> q;
	while (q -- )
	{
		int t, id;
		cin >> t >> id;
		if (ans[id] == -1 || t < ans[id]) cout << "Yes" << endl;
		else cout << "No" << endl;
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
