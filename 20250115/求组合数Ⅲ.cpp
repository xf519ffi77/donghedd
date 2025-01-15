
// 1 <= b <= a <= 1e+18
// 1 <= p <= 1e+5

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int n, p;

int qmi(LL a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = res * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return res;
}

int C(LL a, LL b)
{
	LL res = 1;
	for (LL i = 1, j = a; i <= b; i ++ , j -- )
	{
		res = res * j % p;
		res = res * qmi(i, p - 2) % p;
	}
	return res;
}

int lucas(LL a, LL b)
{
	if (a < p && b < p) return C(a, b);
	else return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	while (n -- )
	{
		LL a, b;
		cin >> a >> b >> p;
		cout << lucas(a, b) << endl;
	}
	return 0;
}