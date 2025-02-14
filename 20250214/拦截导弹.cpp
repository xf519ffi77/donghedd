#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1010;
int n, ans, res;
int a[N], f[N], g[N];
void solve()
{
	string line;
	getline(cin, line);
	stringstream ssin(line);
	while (ssin >> a[n]) n ++ ;
	for (int i = 0; i < n; i ++ )
	{
	    f[i] = g[i] = 1;
	    for (int j = 0; j < i; j ++ )
	        if (a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
	        else g[i] = max(g[i], g[j] + 1);
        ans = max(ans, f[i]);
        res = max(res, g[i]);
	}
	cout << ans << endl << res << endl;
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
//const int N = 1010;
//int n, ans, res;
//int a[N], f[N], g[N];
//void solve()
//{
//	string line;
//	getline(cin, line);
//	stringstream ssin(line);
//	while (ssin >> a[n]) n ++ ;
//	for (int i = 0; i < n; i ++ )
//	{
//	    f[i] = g[i] = 1;
//	    for (int j = 0; j < i; j ++ )
//	        if (a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
//	        else g[i] = max(g[i], g[j] + 1);
//        ans = max(ans, f[i]);
//        int k = 0;
//        while (k < res && g[k] < a[i]) k ++ ;
//        g[k] = a[i];
//        if (k >= res) res ++ ;
//	}
//	cout << ans << endl << res << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
////	cin >> t;
//	while (t -- ) solve();
//	return 0;
//}
