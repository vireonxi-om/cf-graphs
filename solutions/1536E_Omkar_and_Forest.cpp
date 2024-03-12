// Problem: Omkar and Forest
// URL: https://codeforces.com/problemset/problem/1536/E
// Rating: 2300
// Tags: combinatorics, graphs, math, shortest paths
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char a[2100][2100];
ll ans[5100000];
const ll M=1000000007;

void solve(){
    scanf("%d%d", &n, &m);
    int cnt=0;
    for(int i=1; i<=n; i++){
        scanf("%s", a[i]);
        for(int j=0; j<m; j++) if(a[i][j]=='#') cnt++;
    }
    ll result=ans[cnt];
    if(cnt==n*m) result--;
    printf("%lld\n", result);
}

int main(){
    int t;
    ans[0]=1;
    for(int i=1; i<=4100000; i++){
        ans[i]=2*ans[i-1];
        ans[i]%=M;
    }
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


