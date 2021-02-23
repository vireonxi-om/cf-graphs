// Problem: Road Construction
// URL: https://codeforces.com/problemset/problem/1252/L
// Rating: 2300
// Tags: flows, graphs
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

int num = 1, st, ed, maxflow, flag;
LL ans;
queue<int> q;
int e[M], f[M], w[M], pre[M], last[N];
int d[N], dd[N], pp[N], now[N];
void insert(int x, int y, int z, int c) {
	e[++num] = y, f[num] = z, w[num] = c, pre[num] = last[x], last[x] = num;
	e[++num] = x, f[num] = 0, w[num] = -c, pre[num] = last[y], last[y] = num;
}
bool spfa() {
	repn(i, st, ed) {
		d[i] = dd[i] = inf, pp[i] = 0;
	}
	q.push(st);
	d[st] = dd[st] = 0;
	pp[st] = 1;
	while (!q.empty()) {
		int x = q.front();
		for (int i = last[x]; i; i = pre[i]) {
			if (!f[i]) continue;
			int y = e[i];
			if (d[y] > d[x] + w[i] || d[y] == d[x] + w[i] && dd[y] > dd[x] + 1) {
				d[y] = d[x] + w[i];
				dd[y] = dd[x] + 1;
				if (!pp[y]) pp[y] = 1, q.push(y);
			}
		}
		pp[x] = 0;
		q.pop();
	}
	if (d[ed] == inf) return false;
	return true;
}
int dfs(int x, int incf) {
	if (x == ed) return incf;
	int flow = 0, ww;
	for (int i = now[x]; i; i = pre[i]) {
		if (f[i] && dd[e[i]] == dd[x] + 1 && d[e[i]] == d[x] + w[i]) {
			ww = dfs(e[i], min(incf - flow, f[i]));
			f[i] -= ww, f[i ^ 1] += ww;
			flow += ww;
			ans += (LL)ww * (LL)w[i];
			if (f[i]) now[x] = i;
			if (flow == incf) return incf;
		}
	}
	if (!flow) dd[x] = -1;
	return flow;
}
void dinic() {
	while (spfa()) {
		repn(i, st, ed) now[i] = last[i];
		maxflow += dfs(st, inf);
	}
}
int n, k, cnt, fat[N];
int find(int x) {
	return fat[x] == x ? x: fat[x] = find(fat[x]);
}
map<int, int> S, nu;
map<PII, int> ys;
vector<int> g[N];
int sx, sy, anc[N], dep[N], ind[N], cp[N], v[N];
int ansx[N], ansy[N], head[N];
vector<int> h[N];
PII edge[N];
void cdfs(int x, int fa) {
	anc[x] = fa;
	dep[x] = dep[fa] + 1;
	for (auto y: g[x]) {
		if (y != fa) ind[y] = ys[mp(x, y)], cdfs(y, x);
	}
}
int main() {
	IO;
	cin >> n >> k;
	st = 0;
	cnt = n;
	repn(i, 1, n) fat[i] = i;
	repn(i, 1, n) {
		int x, y;
		cin >> x; y = i;
		edge[i] = mp(x, y);
		ys[mp(x, y)] = ys[mp(y, x)] = i;
		int fx = find(x), fy = find(y);
		if (fx != fy) {
			fat[fx] = fy;
			g[x].pb(y);
			g[y].pb(x);
		}
		else sx = x, sy = y;
		int k;
		cin >> k;
		while (k--) {
			int z;
			cin >> z;
			if (!S.count(z)) S[z] = ++cnt;
			insert(i, S[z], 1, 0);
		}
	}
	repn(i, 1, k) {
		int x;
		cin >> x;
		nu[x]++;
		if (S.count(x)) h[S[x]].pb(i);
	}
	cdfs(1, 0);
	int cnum = n, snum = 0, osx = sx, osy = sy;
	cp[ys[mp(sx, sy)]] = 1;
	while (sx != sy) {
		if (dep[sx] > dep[sy]) cp[ind[sx]] = 1, sx = anc[sx];
		else cp[ind[sy]] = 1, sy = anc[sy];
	}
	repn(i, 1, n) {
		if (cp[i]) insert(st, i, 1, -1), cnum--, snum++;
		else insert(st, i, 1, -1000000);
	}
	ed = cnt + 1;
	for (auto p: S) {
		int idx = p.fi, nidx = p.se;
		insert(nidx, ed, nu[idx], 0);
	}
	dinic();
	ans = abs(ans);
	if (ans / 1000000 != cnum || ans % 1000000 < snum - 1) {
		cout << "-1\n";
		return 0;
	}
	repn(i, 1, n) {
		for (int j = last[i]; j; j = pre[j]) {
			if (e[j] > n && f[j] == 0) {
				int cur = h[e[j]][head[e[j]]++];
				ansx[cur] = edge[i].fi;
				ansy[cur] = edge[i].se;
				break;
			}
		}
	}
	repn(i, 1, k) {
		cout << ansx[i] << " " << ansy[i] << "\n";
	}
	return 0;
}