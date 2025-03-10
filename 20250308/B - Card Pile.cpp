#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	stack<int> s;
	for (int i = 1; i <= 100; i ++ ) s.push(0);
	int q;
	cin >> q;
	while (q -- )
	{
		int x, op;
		cin >> op;
		if (op == 1) 
		{
			cin >> x;
			s.push(x);
		}
		else
		{
			cout << s.top() << endl;
			s.pop();
		}
	}
	return 0;
}
