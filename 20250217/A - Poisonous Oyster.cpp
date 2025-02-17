#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 31;
void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == "sick")
	{
		if (s2 == "sick") cout << 1 << endl;
		else cout << 2 << endl; 
	}
	else
	{
		if (s2 == "sick") cout << 3 << endl;
		else cout << 4 << endl;
	}
	
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
