#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	stack<int> s;
	string t;
	cin >> t;
	int n = (int)t.size();
	for (int i = 0; i < n; i ++ )
	{
		if (t[i] == '(') s.push(1);
		else if (t[i] == '[') s.push(2);
		else if (t[i] == '<') s.push(3);
		else if (t[i] == ')')
		{
			if (s.empty() || s.top() != 1)
			{
				cout << "No\n";
				return;
			}
			else s.pop();
		}
		else if (t[i] == ']')
		{
			if (s.empty() || s.top() != 2)
			{
				cout << "No\n";
				return;
			}
			else s.pop();
		}
		else
		{
			if (s.empty() || s.top() != 3)
			{
				cout << "No\n";
				return;
			}
			else s.pop();
		}
	}
	if (s.size()) cout << "No\n";
	else cout << "Yes\n";
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
