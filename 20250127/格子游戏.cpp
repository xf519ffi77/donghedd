#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
const int N = 210;
int n, m;
int p[N * N];
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n * n; i ++ ) p[i] = i;
	int flag = 0;
	for (int i = 1; i <= m; i ++ )
	{
		int x, y;
		char c;
		cin >> x >> y >> c;
		x -- , y -- ;
		int a = x * n + y; // x, y从0开始，二位转换为一维 
		x += (c == 'D');
		y += (c == 'R');
		int b = x * n + y; // x, y从0开始，二位转换为一维 
		int pa = find(a), pb = find(b);
		if (pa == pb)
		{
			flag = i;
			break;
		}
		else p[pa] = pb;
	}
	if (flag) cout << flag << endl;
	else cout << "draw" << endl;
	return 0;
}
