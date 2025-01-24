#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100010;
int n; 
LL a[N];
void solve()
{
    bool flag = false;
	cin >> n;
    for (int i  = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if (a[i] == 1) flag = true;
    }
    if (flag) cout << -1 << endl;
    else cout << 1e+9 + 7 << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

// 因数，质数