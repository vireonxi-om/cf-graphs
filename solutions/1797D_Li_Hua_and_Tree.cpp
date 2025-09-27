// Problem: Li Hua and Tree
// URL: https://codeforces.com/problemset/problem/1797/D
// Rating: 1900
// Tags: brute force, data structures, dfs and similar, dp, implementation, trees
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
typedef long double LD;

const int N = 110000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m;
vector<int> g[N];
LL im[N], a[N];
int sz[N], f[N];
set<PII> s[N];

void dfs(int u, int v) {
	f[u] = v;
	for (auto x : g[u]) {
		if (x == v) continue;
		dfs(x, u);
		sz[u] += sz[x];
		im[u] += im[x];
		s[u].insert(mp(sz[x], -x));
	}
}

int main() { 
	IO;
	cin >> n >> m;
	repn(i, 1, n) {
		sz[i] = 1;
		cin >> a[i]; im[i] = a[i];
	}
	int u, v;
	repn(i, 1, n - 1) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	int tp, id;
	repn(i, 1, m) {
		cin >> tp >> id;
		if (tp == 1) cout << im[id] << "\n";
		else {
			if (s[id].size() == 0) continue;
			auto it = s[id].end();
			it --;
			int h = -(*it).se;
			im[id] -= im[h];
			im[h] += im[id];
			sz[id] -= sz[h];
			sz[h] += sz[id];
			s[id].erase(it);
			s[h].insert(mp(sz[id], -id));
			f[h] = f[id];
			f[id] = h;
			int fa = f[h];
			s[fa].erase(mp(sz[h], -id));
			s[fa].insert(mp(sz[h], -h));
		}
	}
	return 0;
}



