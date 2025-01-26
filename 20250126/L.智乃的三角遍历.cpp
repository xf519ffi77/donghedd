//欧拉路径：欧拉路径是指从图中任意一个点开始到图中任意一个点结束的路径，并且图中每条边通过的且只通过一次。
//欧拉回路：欧拉回路是指起点和终点相同的欧拉路路径
//
//对于无向图，所有边都是连通的
//（1）存在欧拉路径的充分必要条件：
//	度数为奇数的点只能是0个或者2个
//（2）存在欧拉回路的充分必要条件：
//	度数为奇数的只能是0个'
//
//对于有向图，所有边都是连通的
//（1）存在欧拉路径的充分必要条件：
//	要么所有点的出度均等于入度。
//	要么除了两个点之外，其余所有点的出度等于入度，剩余的两个点：一个满足出度比入度多1（起点），另一个满足入度比出度多1（终点）。
//（2）存在欧拉回路的充分必要条件：
//	所有点的出度均等于入度

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 40, M = 110;
int n, idx;
bool st[M];
vector<int> ans;
vector<PII> g[N];
void add(int a, int b)
{
	g[a].push_back({b, idx});
	g[b].push_back({a, idx ++ });
}
void dfs(int u)
{
	for (auto i : g[u])
	{
		if (!st[i.second])
		{
			st[i.second] = true;
			dfs(i.first);
		}
	}
	ans.push_back(u);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1 + i * (i - 1) / 2; j <= i * (i + 1) / 2; j ++ )
		{
			int a = j + i, b = j + i + 1;
			add(j, a), add(j, b), add(a, b);
		}
	dfs(1);
	cout << "Yes" << endl;
	for (int i = 0; i < ans.size(); i ++ ) cout << ans[i] << ' ';
    return 0;
}
