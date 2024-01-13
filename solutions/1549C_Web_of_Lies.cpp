// Problem: Web of Lies
// URL: https://codeforces.com/problemset/problem/1549/C
// Rating: 1400
// Tags: graphs, greedy
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
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, m, q;
int cnt[N];

int main(){
    scanf("%d%d", &n, &m);
    repn(i, 1, n) cnt[i]=0;
    int u, v;
    repn(i, 1, m) {
        scanf("%d%d", &u, &v);
        if(u>v) swap(u, v);
        cnt[u]++;
    }
    int t, ans=0;
    repn(i, 1, n){
        if(cnt[i]) ans++;
    }
    scanf("%d", &q);
    repn(i, 1, q) {
        scanf("%d", &t);
        if(t==1){
            scanf("%d%d", &u, &v);
            if(u>v) swap(u, v);
            if(cnt[u]==0) ans++;
            cnt[u]++;
        }
        else if(t==2) {
            scanf("%d%d", &u, &v);
            if(u>v) swap(u, v);
            if(cnt[u]==1) ans--;
            cnt[u]--;
        }
        else{
            printf("%d\n", n-ans);
        }
    }
    return 0;
}


