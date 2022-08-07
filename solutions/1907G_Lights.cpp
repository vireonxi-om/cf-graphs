// Problem: Lights
// URL: https://codeforces.com/problemset/problem/1907/G
// Rating: 2200
// Tags: brute force, constructive algorithms, dfs and similar, graphs, greedy, implementation
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n;
string s;
int fa[N], nxt[N], pre[N], st[N], ed[N], yes[N], onc[N]; 
vector<int> g[N], ans;
vector<int> v1, v2;
int cur_sum = 0;

int findfa(int x) {
	return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}

void findcir(int u, int v, int des) {
	nxt[u] = v;
	if (u == des) {
		return;
	}
	for (auto x : g[u]) {
		if (x == v) continue;
		findcir(x, u, des);
	}
}

void findtree(int u, int v, int tr) {
	for (auto x : g[u]) {
		if (x == v || onc[x] == tr) continue;
		findtree(x, u, tr);
	}
	if (s[u - 1] == '1' && onc[u] != tr) {
		ans.pb(u);
		s[u - 1] = '0' + (1 - (s[u - 1] - '0'));
		s[v - 1] = '0' + (1 - (s[v - 1] - '0'));
	}
}

void solve() {
	cin >> n;
	cin >> s;
	repn(i, 1, n) {
		fa[i] = i;
		yes[i] = 0;
		onc[i] = 0;
		g[i].clear();
	}
	ans.clear();
	int num;
	repn(i, 1, n) {
		cin >> num;
		int fi = findfa(i), fj = findfa(num);
		if (fi == fj) {
			st[fi] = num;
			ed[fi] = i;
			findcir(i, 0, num);
			nxt[i] = num;
			int now = num;
			while (now != i) {
				onc[now] = fi;
				pre[nxt[now]] = now;
				now = nxt[now];
			}
			onc[i] = fi;
			pre[nxt[i]] = i;
		}
		fa[fi] = fj;
		g[i].pb(num);
		g[num].pb(i);
	}
	repn(i, 1, n) fa[i] = findfa(i);
	bool can = true;
	repn(i, 1, n) {
		if (yes[fa[i]]) continue;
		yes[fa[i]] = 1;
		
		int now = st[fa[i]], sum = 0, stn = -1;
		while (1) {
			findtree(now, nxt[now], fa[i]);
			if (s[now - 1] == '1') {
				sum ++; stn = now;
			}
			now = nxt[now];
			if (now == st[fa[i]]) break;
		}
		if (sum % 2) can = false;
		if (stn == -1) continue;
		
		v1.clear(); v2.clear();
		string tmp = s;
		now = stn;
		while (1) {
			int num = nxt[now];
			if (tmp[now - 1] == '1') {
				v1.pb(now);
				tmp[now - 1] = '0' + (1 - (tmp[now - 1] - '0'));
				tmp[num - 1] = '0' + (1 - (tmp[num - 1] - '0'));
			}
			if (num == stn) break;
			now = num;
		}
		tmp = s;
		now = stn;
		while (1) {
			int num = pre[now];
			if (tmp[now - 1] == '1') {
				v2.pb(num);
				tmp[now - 1] = '0' + (1 - (tmp[now - 1] - '0'));
				tmp[num - 1] = '0' + (1 - (tmp[num - 1] - '0'));
			}
			if (num == stn) break;
			now = num;
		}
		
		if (v1.size() < v2.size()) for (auto x : v1) ans.pb(x);
		else for (auto x : v2) ans.pb(x);
		s = tmp;
	}
	if (!can) cout << "-1\n";
	else {
		cout << ans.size() << "\n";
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}