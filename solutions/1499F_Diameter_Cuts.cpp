// Problem: Diameter Cuts
// URL: https://codeforces.com/problemset/problem/1499/F
// Rating: 2400
// Tags: combinatorics, dfs and similar, dp, trees
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

const int N = 5003;
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, k, sz[N];
LL dp[N][N], n_dp[N], sum;
vector<int> g[N];

void dfs(int x, int fa) {
    sz[x] = 1;
    dp[x][0] = 1;
    for (auto y: g[x]) {
        if (y == fa) continue;
        dfs(y, x);
        repn(j, 0, sz[x] + sz[y]) n_dp[j] = 0;
        sum = 0;
        repn(j, 0, sz[y]){
            if (j > k) break;
            sum = (sum + dp[y][j]) % mod;
        }
        repn(j1, 0, sz[x]){
            if (j1 > k) break;
            n_dp[j1] = (n_dp[j1] + ((dp[x][j1] * sum) % mod)) % mod;
        }
        repn(j1, 0, sz[x]) {
            repn(j2, 0, sz[y]) {
                if(j1 + j2 + 1 > k) continue;
                n_dp[max(j1, j2 + 1)] = (n_dp[max(j1, j2 + 1)] + ((dp[x][j1] * dp[y][j2]) % mod)) % mod;
            }
        }
        sz[x] += sz[y];
        repn(j, 0, sz[x]) dp[x][j] = n_dp[j];
    }

}

int main() {
    IO;
    scanf("%d%d", &n, &k);
    int u, v;
    rep(i, 1, n){
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1, 0);
    LL ans = 0;
    repn(i, 0, k){
        ans = (ans + dp[1][i]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

