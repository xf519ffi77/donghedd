
// 1 <= b <= a <= 1e+5

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef  long long LL;
const int N = 100010, mod = 1e+9 + 7;
int n;
LL factorial[N], infactorial[N];
int quickpower(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	factorial[0] = infactorial[0] = 1;
	for (int i = 1; i < N; i ++ )
	{
		factorial[i] = factorial[i - 1] * i % mod;
		infactorial[i] = infactorial[i - 1] * quickpower(i, mod - 2, mod) % mod;
	}
	cin >> n;
	while (n -- )
	{
		int a, b;
		cin >> a >> b;
		cout << factorial[a] * infactorial[b] % mod * infactorial[a - b] % mod << endl;
	}
	return 0;
}