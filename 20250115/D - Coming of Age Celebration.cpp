#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500010;
int n;
int a[N], cnt[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		for (int j = 1; j < i; j ++ )
		{
			if (a[j] >= 1)
			{
				a[j] -- ;
				a[i] ++ ;
			}
		}
	}
	for (int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
	return 0;
}