// Problem: Dating
// URL: https://codeforces.com/problemset/problem/1949/F
// Rating: 2200
// Tags: greedy, sortings, trees
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, len[N], pp[N];
vector<int> f[N], h[N];
vector<PII> g[N];
set<PII> S;
int main() {
	IO;
	cin >> n >> m;
    repn(i, 1, n) {
        cin >> len[i];
        repn(j, 1, len[i]) {
            int x;
            cin >> x;
            f[i].pb(x);
            g[x].pb(mp(len[i],i));
        }
    }
    repn(i, 1, m) {
        sort(all(g[i]));
        rep(j, 1, SZ(g[i])) {
            int x = g[i][j - 1].se;
            int y = g[i][j].se;
            if (!S.count(mp(x, y))) {
                S.insert(mp(x, y));
                h[y].pb(x);
            }
        }
    }
    repn(i, 1, n) {
        for (auto x: f[i]) pp[x] = 1;
        for (auto id: h[i]) {
            for (auto y: f[id]) if (!pp[y]) {
                cout << "YES\n";
                cout << i << " " << id << "\n";
                return 0;
            }
        }
        for (auto x: f[i]) pp[x] = 0;
    }
    cout << "NO\n";
	return 0;
}
