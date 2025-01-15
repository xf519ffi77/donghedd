#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500010;
int n;
int a[N];
bool check(int mid)
{
	for (int i = 1; i <= mid; i ++ )
		if (a[i] * 2 > a[i + n - mid]) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	int l = 1, r = n / 2;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	if (l == 1 && a[1] * 2 > a[2]) l = 0;
	cout << l << endl;
	return 0;
}