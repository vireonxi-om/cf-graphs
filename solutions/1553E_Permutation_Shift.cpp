// Problem: Permutation Shift
// URL: https://codeforces.com/problemset/problem/1553/E
// Rating: 2100
// Tags: brute force, combinatorics, constructive algorithms, dfs and similar, dsu, graphs, math
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

const int N = 310000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const LL p = 998244353;


int n, m;
int a[N], fa[N], cnt[N];
vector<int> g[N], ans;

int findf(int i) {
    return fa[i] == i ? i : fa[i] = findf(fa[i]);
}

bool check(int k) {
    repn(i, 1, n){ fa[i] = i; cnt[i] = 0;}
    repn(i, 1, n) {
        if ((a[i] - i + n) % n == k) continue;
        int t = (a[i] - k + n) % n;
        if (t == 0) t = n;
        int u = findf(i), v = findf(t);
        if (u != v) fa[u] = v;
    }
    repn(i, 1, n) cnt[findf(i)] ++;
    int sum = 0;
    repn(i, 1, n){
        if (cnt[i]) sum += cnt[i] - 1;
    }
    if (sum <= m) return true;
    else return false;
}

void solve(){
    scanf("%d%d", &n, &m);
    rep(i, 0, n) g[i].clear();
    ans.clear();
    repn(i, 1, n) {
        scanf("%d", &a[i]);
        g[(a[i] - i + n) % n].pb(i);
    }
    rep(i, 0, n) {
        if (g[i].size() < n / 3) continue;
        if (check(i)) ans.pb((n - i) % n);
    }
    sort(all(ans));
    printf("%d ", ans.size());
    for(auto x: ans) printf("%d ", x);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

