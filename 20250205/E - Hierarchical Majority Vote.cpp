#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
struct Node
{
	int num, cnt; // num为该节点(区间)值，cnt为修改该值的最小操作次数 
};
Node dfs(int l, int r)
{
	if (l == r) return {s[l] - '0', 1};
	int mid1 = l + (r - l + 1) / 3, mid2 = r - (r - l + 1) / 3; // 三等分点 
	int cnt[2] = {0, 0};
	Node s1 = dfs(l, mid1 - 1), s2 = dfs(mid1, mid2), s3 = dfs(mid2 + 1, r);
	cnt[s1.num] ++ , cnt[s2.num] ++ , cnt[s3.num] ++ ;
	int num = (cnt[0] > cnt[1] ? 0 : 1);
	if (cnt[num] == 3) return {num, min(s1.cnt + s2.cnt, min(s1.cnt + s3.cnt, s2.cnt + s3.cnt))};
	else if (s1.num == s2.num) return {num, min(s1.cnt, s2.cnt)};
	else if (s1.num == s3.num) return {num, min(s1.cnt, s3.cnt)};
	else if (s2.num == s3.num) return {num, min(s2.cnt, s3.cnt)};
}
void solve()
{
	int n;
	cin >> n >> s;
	s = " " + s;
	n = pow(3, n);
	int ans = dfs(1, n).cnt;
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- ) solve();
	return 0;
}
