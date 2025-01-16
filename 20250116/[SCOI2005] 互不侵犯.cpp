#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 10, M = 1 << N;
int n, m;
LL ans;
int cnt[M];
LL f[N][N * N][M]; //  f[i][j][k] 表示选到了第i行，已经用了j个国王，该行状态为k 
bool st[M];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(f, 0, sizeof(f));
	cin >> n >> m;
	for (int i = 0; i < 1 << n; i ++ )
	{
		st[i] = true;
		int s = 0; 
		for (int j = 0; j < n; j ++ )
		{
			if (i >> j & 1)
			{
				if (!s && j) st[i] = false;
				s = 0;
			}
			else s ++ ;
		}
		if (st[i])
			for (int j = 0; j < n; j ++ )
				if ((i >> j) & 1) cnt[i] ++ ;
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i ++ )
		for (int k1 = 0; k1 < 1 << n; k1 ++ )
			for (int k2 = 0; k2 < 1 << n; k2 ++ )
				if ((k1 & k2) == 0 && st[k1 | k2])
					for (int j = cnt[k1]; j <= m; j ++ )
						f[i][j][k1] += f[i - 1][j - cnt[k1]][k2];
	for (int i = 0; i < 1 << n; i ++ )
		if (st[i]) ans += f[n][m][i];
	cout << ans << endl;
	return 0;
}