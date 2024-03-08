// Problem: Array Differentiation
// URL: https://codeforces.com/problemset/problem/1552/D
// Rating: 1800
// Tags: bitmasks, brute force, constructive algorithms, dfs and similar, dp, graphs, math
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
const int M = 650;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, tot, d[20];
set<int> s;
bool can;

void dfs(int i, int id, int sum) {
    if (can) return;
    if (i == id){
        dfs(i + 1, id, sum);
        return;
    }
    if (i == tot) {
        if (sum == d[id]) can = true;
        return;
    }
    dfs(i + 1, id, sum + d[i]);
    dfs(i + 1, id, sum);
    dfs(i + 1, id, sum - d[i]);
}

void solve(){
    scanf("%d", &n);
    int num;
    s.clear();
    repn(i, 1, n) {
        scanf("%d", &num);
        if (num == 0) continue;
        s.insert(abs(num));
    }
    int now = 0;
    for (auto x : s) d[now++] = x;
    tot = s.size();
    if (tot < n) can=true;
    else{
        can=false;
        rep(i, 0, tot) {
            if (can) break;
            dfs(0, i, 0);
        }
    }
    if (can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}