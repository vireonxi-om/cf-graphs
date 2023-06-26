// Problem: Diameter of Graph
// URL: https://codeforces.com/problemset/problem/1581/B
// Rating: 1200
// Tags: constructive algorithms, graphs, greedy, math
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
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

LL n, m, k;


void solve(){
    scanf("%lld%lld%lld", &n, &m, &k);
    LL tot = n * (n - 1) / 2;
    if (m > tot) printf("NO\n");
    else if (n == 1) {
        if (k >= 2) printf("YES\n");
        else printf("NO\n");
    }
    else if (m == tot) {
        if (k >= 3) printf("YES\n");
        else printf("NO\n");
    }
    else if (m >= n - 1) {
        if (k >= 4) printf("YES\n");
        else printf("NO\n");
    }
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}



