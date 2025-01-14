#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int n, q;
int f[2][32];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i <= 1; i ++ )
		for (int j = 0; j <= 30; j ++ )
			f[i][j] = i;
	for (int i = 1; i <= n; i ++ )
	{
		char op;
		int x;
		cin >> op >> x;
		if (op == '&')
		{
			for (int j = 0; j <= 30; j ++ )
			{
				int c = 0;
				if (x & (1 << j)) c = 1; // 判断x的第j位是否为1 
				f[0][j] &= c;
				f[1][j] &= c;
			}
		}
		else if (op == '|')
		{
			for (int j = 0; j <= 30; j ++ )
			{
				int c = 0;
				if (x & (1 << j)) c = 1;
				f[0][j] |= c;
				f[1][j] |= c; 
			}
		}
		else if (op == '^')
		{
			for (int j = 0; j <= 30; j ++ )
			{
				int c = 0;
				if (x & (1 << j)) c = 1;
				f[0][j] ^= c;
				f[1][j] ^= c;
			}
		}
	}
	while (q -- )
	{
		int x, ans = 0;
		cin >> x;
		for (int i = 0; i <= 30; i ++ )
		{
			int c = 0;
			if (x & (1 << i)) c = 1;
			ans |= f[c][i] << i;
		}
		cout << ans << endl;
	}
	return 0;
}
