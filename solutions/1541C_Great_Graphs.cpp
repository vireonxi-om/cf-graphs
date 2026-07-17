// Problem: Great Graphs
// URL: https://codeforces.com/problemset/problem/1541/C
// Rating: 1400
// Tags: constructive algorithms, graphs, greedy, shortest paths, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[110000], sum[110000];

void solve(){
    ll ans;
    scanf("%d%lld", &n, &ans);
    for(int i=1; i<n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n);
    for(int i=1; i<n; i++) sum[i]=sum[i-1]+a[i];
    for(int i=1; i<n; i++) ans+=a[i]*i-sum[i-1];
    ans=a[n-1]-ans;
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}