#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 60;
char s[N][N], t[N][N];
void solve()
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			cin >> s[i][j];
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> t[i][j];
	for (int i = 1; i + m - 1 <= n; i ++ )
		for (int j = 1; j + m - 1 <= n; j ++ )
			if (s[i][j] == t[1][1])
			{
				bool flag = true;
				for (int k = i; k <= i + m - 1; k ++ )
				{
					
					for (int r = j; r <= j + m - 1; r ++ )
						if (s[k][r] != t[k - i + 1][r - j + 1])
						{
							flag = false;
							break;
						}
					if (!flag) break;
				}
				if (flag)
				{
					cout << i  << ' ' << j << endl;
					return;
				}
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
