#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 5e6 + 10;
int cnt, ans;
LL primes[N];
bool st[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// 线性筛
	for (int i = 2; i < N; i ++ )
	{
		if (!st[i]) primes[cnt ++ ] = i;
		for (int j = 0; primes[j] < N / i; j ++ )
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
	for (int i = 0; i < cnt; i ++ ) primes[i] *= primes[i];
	for (int i = 0; i < cnt; i ++ )
		for (int j = i + 1; j < cnt; j ++ )
		{
			LL t = primes[i] * primes[j];
			if (t > 23333333333333) break;
			if (t >= 2333 && t <= 23333333333333) 
				ans ++ ;
		}
	cout << ans << endl; // 947293
	return 0;
}
