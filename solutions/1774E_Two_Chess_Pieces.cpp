// Problem: Two Chess Pieces
// URL: https://codeforces.com/problemset/problem/1774/E
// Rating: 1900
// Tags: dfs and similar, dp, greedy, trees
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

const int N = 210000;
const int M = 110000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;



int d, n;

struct node{
    vector<int> nh;
    bool a[2], b[2];
    int dis[2], dpt[2], d;
}t[N];


void pre_dfs(int u, int v){
    t[u].d = t[v].d + 1;
    if (u == 1) t[u].d = 0;
    rep(i, 0, 2) {
        if (t[u].a[i]) {
            t[u].dpt[i] = t[u].d;
            t[u].b[i] = true;
        }
        else {
            t[u].dpt[i] = 0;
            t[u].b[i] = false;
        }
        t[u].dis[i] = 0;
    }
    for (auto lf : t[u].nh){
        if (lf == v) continue;
        pre_dfs(lf, u);
        rep(i, 0, 2) {
            if (! t[lf].b[i]) continue;
            t[u].b[i] = true;
            t[u].dpt[i] = max(t[u].dpt[i], t[lf].dpt[i]);
            t[u].dis[i] += t[lf].dis[i] + 2;
        }
    }
    return;
}

long long ans = 0;

void dfs(int u, int v) {
    //cout << u << " " << v << "\n";
    for (auto lf: t[u].nh) {
        if (lf == v) continue;
        if (t[lf].b[0] && t[lf].b[1]) {
            //cout << "1" << "\n";
            ans += 4;
            dfs(lf, u);
        }
        else if (t[lf].b[0]) {
            if (t[lf].dpt[0] - t[u].d > d) {
                ans += 4;
                //cout << "21" << "\n";
                dfs(lf, u);
                
            } 
            else {
                ans += t[lf].dis[0] + 2;
                //cout << "22" << "\n";
            }
        }
        else if (t[lf].b[1]) {
            if (t[lf].dpt[1] - t[u].d > d) {
                //cout << "31" << "\n";
                ans += 4;
                dfs(lf, u);
            } 
            else {
                ans += t[lf].dis[1] + 2;
                //cout << "32" << "\n";
            }
        }
        else continue;
    }
}

int main() {
    IO;
    cin >> n >> d;
    int u, v;
    rep(i, 1, n) {
        cin >> u >> v;
        t[u].nh.pb(v);
        t[v].nh.pb(u);
    }
    cin >> u;
    repn(i, 1, u) {
        cin >> v;
        t[v].a[0] = true;
    }
    cin >> u;
    repn(i, 1, u) {
        cin >> v;
        t[v].a[1] = true;
    }
    pre_dfs(1, 0);
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}



