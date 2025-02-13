#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int b[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve()
{
	int ans = 0;
	for (int y = 2000; y <= 2024; y ++ )
	{
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) b[2] = 29;
		else b[2] = 28;
		string s1 = to_string(y);
		int res = 0;
		for (int i = 0; i < 4; i ++ ) res += a[s1[i] - '0'];
		for (int m = 1; m <= 12; m ++ )
		{
			if (y == 2024 && m > 4) break;
			int res1 = res;
			string s2 = to_string(m);
			if (s2.size() == 1) s2 = "0" + s2;
			for (int i = 0; i < 2; i ++ ) res1 += a[s2[i] - '0'];
			for (int d = 1; d <= b[m]; d ++ )
			{
				if (y == 2024 && m == 4 && d > 13) break;
				int res2 = res1;
				string s3 = to_string(d);
				if (s3.size() == 1) s3 = "0" + s3;
				for (int i = 0; i < 2; i ++ ) res2 += a[s3[i] - '0'];
				if (res2 > 50) ans ++ ;
			}
		}
	}
	cout << ans << endl; // 3228
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
