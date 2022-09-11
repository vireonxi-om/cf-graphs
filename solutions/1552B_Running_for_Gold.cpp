// Problem: Running for Gold
// URL: https://codeforces.com/problemset/problem/1552/B
// Rating: 1500
// Tags: combinatorics, graphs, greedy, sortings
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

int n, a[51000][10];

bool yes(int i, int j){
    if(i==j) return true;
    int cnt=0;
    repn(k, 1, 5) {
        if(a[i][k]<a[j][k]) cnt++;
    }
    if(cnt>2) return true;
    else return false;
}

void solve() {
    scanf("%d", &n);
    int id=1;
    repn(i, 1, n) {
        repn(j, 1, 5){
            scanf("%d", &a[i][j]);
        }
        if(yes(i, id)) id=i;

    }
    bool can=true;
    repn(i, 1, n) {
        if(yes(i, id) && i!=id) can=false;
    }
    if(can) printf("%d\n", id);
    else printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

