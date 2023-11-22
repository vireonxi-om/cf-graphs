// Problem: Eastern Exhibition
// URL: https://codeforces.com/problemset/problem/1486/B
// Rating: 1500
// Tags: binary search, geometry, shortest paths, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;

void solve(){
    scanf("%d", &n);
    int x[1100], y[1100];
    for(int i=1; i<=n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    sort(x+1, x+n+1);
    sort(y+1, y+n+1);
    ll ans=1;
    if(n%2==0){
        ans=(ll)(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1);
    }
    printf("%lld\n", ans);
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}



