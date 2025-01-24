#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 200010;
int n;
LL ans;
int a[N], cnt[N * 2]; //a = 1000 = 8, b = 0111 = 7, a ^ b = 1111 = 15 ¡Ö2 * a; 
bool flag[N * 2];
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
vector<int> get_divisors(int n)
{
	vector<int> res;
	for (int i = 1; i <= n / i; i ++ )
	{
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		cnt[a[i]] ++ ;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		if (!flag[a[i]])
		{
			flag[a[i]] = true;
			auto t = get_divisors(a[i]);
			for (int x : t) 
				if (x == gcd(a[i], a[i] ^ x) && x != a[i] && !flag[a[i] ^ x]) ans += (LL)cnt[a[i]] * cnt[a[i] ^ x];
		}
	}
	cout << ans << endl;
	return 0;
}

// xor????gcd???