// Problem: Explorer Space
// URL: https://codeforces.com/problemset/problem/1517/D
// Rating: 1800
// Tags: dp, graphs, shortest paths
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[510][510], b[510][510], dp[510][510][15];
const ll M=1000000007;

void work(int i, int j, int t){
    if(i>1) dp[i][j][t]=min(dp[i][j][t], dp[i-1][j][t-1]+b[i-1][j]);
    if(i<n) dp[i][j][t]=min(dp[i][j][t], dp[i+1][j][t-1]+b[i][j]);
    if(j>1) dp[i][j][t]=min(dp[i][j][t], dp[i][j-1][t-1]+a[i][j-1]);
    if(j<m) dp[i][j][t]=min(dp[i][j][t], dp[i][j+1][t-1]+a[i][j]);
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) for(int j=1; j<m; j++) scanf("%d", &a[i][j]);
    for(int i=1; i<n; i++) for(int j=1; j<=m; j++) scanf("%d", &b[i][j]);
    for(int t=1; t<=k/2; t++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j][t]=1e8;
                work(i, j, t);
            }
        }
    }
    if(k%2){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                printf("-1 ");
            }
            printf("\n");
        }
    }
    else{
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                printf("%d ", 2*dp[i][j][k/2]);
            }
            printf("\n");
        }
    }
    return 0;
}