// 1 <= b <= a <= 2000
// C(a, b) = C(a - 1, b) + C(a - 1, b - 1)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int n;
int C[N][N];
void __init__()
{
	for (int i = 0; i < N; i ++ )
		for (int j = 0; j <= i; j ++ )
		    if (!j) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j  - 1]) % mod;
}
int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
	__init__();
	cin >> n;
	while (n -- )
	{
		int a, b;
		cin >> a >> b;
		cout << C[a][b] << endl;
	}
	return 0;
}