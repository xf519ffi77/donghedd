#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 110;
int n;
LL a[N];
bool flag;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	if (n == 2)
	{
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 2; i <= n - 1; i ++ )
		if (a[i] * a[i] != a[i - 1] * a[i + 1])
		{
			flag = true;
			break;
		}
	if (flag) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
