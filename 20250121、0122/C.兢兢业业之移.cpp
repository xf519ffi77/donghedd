#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<string> s(n + 2, string(n + 2, '1'));
	vector<vector<int>> ans;
	auto move = [&](int x, int y, char c)
	{
		int dx = x, dy = y;
		dx -= (c == 'U');
		dx += (c == 'D');
		dy -= (c == 'L');
		dy += (c == 'R');
		swap(s[x][y], s[dx][dy]);
		ans.push_back({x, y, dx, dy});
	};
	for (int i = 1; i <= n; i ++ )
	{
		cin >> s[i];
		s[i] = "1" + s[i] + "1";
	}
	// ��ֱ�����ƾ������� 
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			for (int k = i; k >= 1; k -- )
				if (s[k][j] == '1' && s[k - 1][j] == '0') move(k, j, 'U');
				else break;
	// ��ֱ�����ƾ�������
	// �������'1'ȫ���������ϰ벿�ֺ���벿�֣������������Ǿ���			
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			for (int k = j; k >= 1; k -- )
				if (s[i][k] == '1' && s[i][k - 1] == '0') move(i, k, 'L');
				else break;
	// �������Ͻ�			
	for (int i = n / 2; i >= 1; i -- )
		for (int j = n; j > n / 2; j -- )
		{
			if (s[i][j] == '0') continue;
			int x = 0, y = 0;
			for (int k = 1; k <= n / 2; k ++ )
				for (int l = 1; l <= n / 2; l ++ )
				{
					if (s[k][l] == '1') continue;
					x = k;
					y = l;
					break;
				}
			for (int k = i; k < x; k ++ ) move(k, j, 'D');
			for (int k = j; k > y; k -- ) move(x, k, 'L');
		}
	// �������½� 
	for (int i = n; i > n / 2; i -- )
		for (int j = n / 2; j >= 1; j -- )
		{
			if (s[i][j] == '0') continue;
			int x = 0, y = 0;
			for (int k = 1; k <= n / 2; k ++ )
				for (int l = 1; l <= n / 2; l ++ )
				{
					if (s[k][l] == '1') continue;
					x = k;
					y = l;
					break;
				}
			for (int k = j; k < y; k ++ ) move(i, k, 'R');
			for (int k = i; k > x; k -- ) move(k, y, 'U');
		}
	cout << ans.size() << endl;
	for (auto i : ans)
	{
		for (auto j : i) cout << j << ' ';
		cout << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t -- ) solve();
	return 0;
}

// ģ��