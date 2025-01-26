#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a[6];
	int x = 0, y = 0, cnt = 0;
	for (int i = 1; i <= 5; i ++ )
	{
		cin >> a[i];
		if (a[i] == i) cnt ++ ;
		else
		{
			if (!x) x = i;
			else y = i;
		}
	}
	if (cnt == 3 && y - x == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
