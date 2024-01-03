// Problem: Cleaning Robots
// URL: https://codeforces.com/problemset/problem/1252/B
// Rating: 2300
// Tags: dp, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n;
vector<int> g[N];
LL dp[N][4];
LL tmp[3];
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
void dfs(int x, int fa) {
	for (auto y: g[x]) {
		if (y != fa) dfs(y, x);
	}
	// 0
	LL all = 1;
	for (auto y: g[x]) if (y != fa) all = all * dp[y][2] % mod;
	dp[x][0] = all;
	// 1
	LL all0 = 1, all1 = 0, all2 = 0;
	for (auto y: g[x]) if (y != fa) {
		LL nall1 = (all1 * dp[y][2] + all0 * dp[y][3]) % mod;
		LL nall0 = all0 * dp[y][2] % mod;
		all0 = nall0, all1 = nall1;
	}
	dp[x][1] = all1;
	// 2
	all0 = 1, all1 = 0, all2 = 0;
	for (auto y: g[x]) if (y != fa) {
		LL nall0 = all0 * (dp[y][0] + dp[y][1] + dp[y][2]) % mod;
		LL nall1 = (all1 * (dp[y][2] + dp[y][0] + dp[y][1]) + all0 * dp[y][3]) % mod;
		LL nall2 = (all2 * (dp[y][0] + dp[y][1] + dp[y][2]) + all1 * dp[y][3]) % mod;
		all0 = nall0, all1 = nall1, all2 = nall2;
	}
	dp[x][2] = all2;
	// 3
	all0 = 1, all1 = 0;
	for (auto y: g[x]) if (y != fa) {
		LL nall1 = (all1 * (dp[y][0] + dp[y][1] + dp[y][2]) + all0 * dp[y][3]) % mod;
		LL nall0 = all0 * (dp[y][0] + dp[y][1] + dp[y][2]) % mod;
		all0 = nall0, all1 = nall1;
	}
	dp[x][3] = (all1 + dp[x][0]) % mod;
}
int main() {
	IO;
	cin >> n;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	LL ans = dp[1][0] + dp[1][1] + dp[1][2];
	ans %= mod;
	cout << ans << endl;
	return 0;
}