#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve()
{
	int n, x;
	cin >> n >> x;
	if (n == 1)
	{
		cout << x << endl;
		return;
	}
	int t = x, j = -1;
	while (t)
	{
		if (t & 1) j ++ ;
		else break;
		t >>= 1;
	}
	if (j == -1)
	{
		cout << x << " ";
		for (int i = 1; i < n; i ++ ) cout << 0 << " \n"[i == n - 1];
	}
	else
	{
		if (pow(2, j + 1) - 1 == x)
		{
			if (n >= pow(2, j) + 1)
			{
				for (int i = 0; i < min(n, x + 1); i ++ )
				{
					cout << i << " " ;
				}
				for (int i = 1; i <= (n - (x + 1)); i ++ ) cout << 0 << " ";
				cout << endl;
			}
			else
			{
				cout << x << " ";
				for (int i = 0; i < n - 1; i ++ )
				{
					cout << i << " \n"[i == n - 2]; 
				}
			}
		}
		else
		{
			cout << x << " ";
			int cnt = 1;
			for (int i = 0; i < n && cnt < n; i ++ )
				if ((x | i) <= x)
				{
					cout << i << " ";
					cnt ++ ;
				}
			while (cnt < n)
			{
				cout << 0 << " ";
				cnt ++ ;
			}
			cout << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t -- ) solve();
	return 0;
}
