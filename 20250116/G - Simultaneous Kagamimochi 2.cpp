// 2 <= n <= 2e+5
// 1 <= q <= 2e+5
// 二分+ST表

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 200010;
int n, q;
int a[N], st[N][19];
int find(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	int k = 1;
	for (int i = 1; i <= n; i ++ )
	{
		while (k <= n && a[i] * 2 > a[k]) k ++ ;
		st[i][0] = k - i;
	}
	for (int j = 1; j <= 18; j ++ )
		for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	
	cin >> q;
	while (q -- )
	{
		int l, r;
		cin >> l >> r;
		int L = 0, R = r - l + 1 >> 1;
		while (L < R)
		{
			int mid = L + R + 1 >> 1;
			if (find(l, l + mid - 1) <= r - mid + 1 - l) L = mid;
			else R = mid - 1;
		}
		cout << L << endl;
	}
	return 0;
}
/*设k表示可以配对的数量，一定是区间的前k个与后k个按顺序配对
设表示i号饼作为小饼能配对t[i]号饼以及后面编号的饼
则有t[i]<=(R-k+1)+(i-L)
移项得t[i]-i<=R-L+1-k
只要考虑i在范围[L,L+k-1]范围都满足即可
显然满足二分答案条件
用st表维护t[i]-i最大值*/