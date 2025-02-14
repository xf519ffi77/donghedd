#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3010;
int n;
int a[N], b[N];
int f[N][N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= n; i ++ ) cin >> b[i];
	for (int i = 1; i <= n; i ++ )
	{
		int Max = 1;
		for (int j = 1; j <= n; j ++ )
		{
			f[i][j] = f[i - 1][j];
			if (a[i] == b[j]) f[i][j] = max(f[i][j], Max);
			if (a[i] > b[j]) f[i][j] = max(Max, f[i][j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) ans = max(ans, f[n][i]);
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}

//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//const int N = 3010;
//int n;
//int a[N], b[N];
//int f[N][N];
//void solve()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i ++ ) cin >> a[i];
//	for (int i = 1; i <= n; i ++ ) cin >> b[i];
//	for (int i = 1; i <= n; i ++ )
//		for (int j = 1; j <= n; j ++ )
//		{
//			f[i][j] = f[i - 1][j];
//			if (a[i] == b[j])
//			{
//				f[i][j] = max(f[i][j], 1); 
//				for (int k = 1; k < j; k ++ )
//					if (b[j] > b[k]) f[i][j] = max(f[i][j], f[i][k] + 1);
//			}
//		}
//	int ans = 0;
//	for (int i = 1; i <= n; i ++ ) ans = max(ans, f[n][i]);
//	cout << ans << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
////	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
