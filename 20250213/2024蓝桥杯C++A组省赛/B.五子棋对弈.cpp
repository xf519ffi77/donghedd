#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[5][5];
int check(int x)
{
	int cnt = 0;  // 1Îª°×Æå 
	for (int i = 0; i < 5; i ++ )
		for (int j = 0; j < 5; j ++ )
		{
			a[i][j] = (x >> (i * 5 + j)) & 1;
			cnt += a[i][j];
		}
	if (cnt != 13) return 0;
	for (int i = 0; i < 5; i ++ )
	{
		int num = 0;
		for (int j = 0; j < 5; j ++ ) num += a[i][j];
		if (!num || num == 5) return 0;
	}
	for (int i = 0; i < 5; i ++ )
	{
		int num = 0;
		for (int j = 0; j < 5; j ++ ) num += a[j][i];
		if (!num || num == 5) return 0;
	}
	int num1 = 0, num2 = 0;
	for (int i = 0; i < 5; i ++ )
	{
		num1 += a[i][i];
		num2 += a[i][4 - i];
	}
	if (!num1 || !num2 || num1 == 5 || num2 == 5) return 0;
	return 1;
}
void solve()
{
	int ans = 0, N = 1 << 25;
	for (int i = 0; i < N; i ++ ) ans += check(i);
	cout << ans << endl; // 3126376
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
