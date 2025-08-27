// Problem: Mocha and Hiking
// URL: https://codeforces.com/problemset/problem/1559/C
// Rating: 1200
// Tags: constructive algorithms, graphs
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
const int M = 11000000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;

int n;
int a[11000];

void solve(){
    scanf("%d", &n);
    bool yes = false;
    int id = -1;
    repn(i, 1, n) {
        scanf("%d", &a[i]);
        if (id < 0 && i > 1 && a[i] == 1 && a[i - 1] == 0){
            id = i - 1;
        }
    }
    if (id < 0) {
        if (a[1] == 1) id = 0;
        else if (a[n] == 0) id = n;
    }
    if (id == 0) printf("%d ", n + 1);
    repn(i, 1, n) {
        printf("%d ", i);
        if (i == id) printf("%d ", n + 1);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

