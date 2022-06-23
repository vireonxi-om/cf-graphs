// Problem: Kingdom of Islands
// URL: https://codeforces.com/problemset/problem/1578/K
// Rating: 2800
// Tags: brute force, graphs, implementation
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, k;
int id[N], num[N], pp[N], cp[N], dp[N], cnum;
vector<int> g[N];
struct edge {
	int x, y, op;
	friend bool operator < (edge a, edge b) {
		return a.op < b.op;
	}
}e[110];
int ans, pos, tmp[N];
void work(int i, int tp) {
	int res = 0, nn = 0;
	rep(j, 0, k) {
		int x = e[j].x, y = e[j].y;
		if (e[j].op == 0) {
			if (i >> j & 1) {
				if (!pp[x]) {
					pp[x] = 1, num[id[x]]--;
					if (num[id[x]] == 0) cnum--;
				}
			}
			else {
				if (!pp[y]) {
					pp[y] = 1, num[id[y]]--;
					if (num[id[y]] == 0) cnum--;
				}
			}
		}
		else {
			if (i >> j & 1) {
				if (pp[x] || pp[y]) continue;
				nn++;
				if (cp[x] == 0) {
					cp[x] = 1, res++, num[id[x]]--;
					tmp[res] = x;
					if (num[id[x]] == 0) cnum--;
				}
				if (cp[y] == 0) {
					cp[y] = 1, res++, num[id[y]]--;
					tmp[res] = y;
					if (num[id[y]] == 0) cnum--;
				}
			}
		}
	}
	repn(j, 1, res) {
		repn(k, j + 1, res) {
			if (id[tmp[j]] != id[tmp[k]]) nn++;
		}
	}
	if (res * (res - 1) / 2 != nn) res = 0;
	else {
		rep(j, 0, k) {
			int x = e[j].x, y = e[j].y;
			if (e[j].op == 1) {
				if (i >> j & 1) {
					if (pp[x] || pp[y]) continue;
					if (dp[id[x]] == 0 && num[id[x]] > 0) dp[id[x]] = 1, res--;
					if (dp[id[y]] == 0 && num[id[y]] > 0) dp[id[y]] = 1, res--;
				}
			}
		}
		res += cnum;
		rep(j, 0, k) {
			int x = e[j].x, y = e[j].y;
			if (e[j].op == 1) {
				if (i >> j & 1) {
					if (pp[x] || pp[y]) continue;
					dp[id[x]] = dp[id[y]] = 0;
				}
			}
		}
	}
	
	if (tp == 0) {
		if (res > ans) ans = res, pos = i;
	}
	else {
		set<int> S;
		vector<int> way;
		rep(j, 0, k) {
			int x = e[j].x, y = e[j].y;
			if (e[j].op == 1) {
				if (pp[x] || pp[y]) continue;
				if (i >> j & 1) {
					if (!S.count(x)) way.pb(x), S.insert(x);
					if (!S.count(y)) way.pb(y), S.insert(y);
					dp[id[x]] = dp[id[y]] = 1;
				}
			}
		}
		repn(j, 1, n) {
			if (dp[j]) continue;
			for (auto x: g[j]) {
				if (pp[x]) continue;
				if (S.count(x)) continue;
				way.pb(x);
				break;
			}
		}
		cout << res << "\n";
		for (int i = 0; i < way.size(); i++) {
			if (i) cout << " ";
			cout << way[i];
		}
		return;
	}
	per(j, 0, k) {
		int x = e[j].x, y = e[j].y;
		if (e[j].op == 0) {
			if (i >> j & 1) {
				if (pp[x]) {
					pp[x] = 0, num[id[x]]++;
					if (num[id[x]] == 1) cnum++;
				}
			}
			else {
				if (pp[y]) {
					pp[y] = 0, num[id[y]]++;
					if (num[id[y]] == 1) cnum++;
				}
			}
		}
		else {
			if (i >> j & 1) {
				if (pp[x] || pp[y]) continue;
				if (cp[x] == 1) {
					cp[x] = 0, num[id[x]]++;
					if (num[id[x]] == 1) cnum++;
				}
				if (cp[y] == 1) {
					cp[y] = 0, num[id[y]]++;
					if (num[id[y]] == 1) cnum++;
				}
			}
		}
	}
	
}
int main()
{
	IO;
	cin >> n >> m;
	cnum = n;
	repn(i, 1, m) cin >> id[i], num[id[i]]++, g[id[i]].pb(i);
	cin >> k;
	rep(i, 0, k) {
		int x, y;
		cin >> x >> y;
		if (id[x] == id[y]) e[i] = (edge){x, y, 1};
		else e[i] = (edge){x, y, 0};
	}
	sort(e, e + k);
	rep(i, 0, 1 << k) {
		work(i, 0);
	}
	work(pos, 1);
	return 0;
}