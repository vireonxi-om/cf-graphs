// Problem: Armchairs
// URL: https://codeforces.com/problemset/problem/1525/D
// Rating: 1800
// Tags: dp, flows, graph matchings, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[5100][5100];
vector<int> p0, p1;


int main(){
    scanf("%d", &n);
    int num;
    p0.push_back(0); p1.push_back(0);
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        if(num) p1.push_back(i);
        else p0.push_back(i);
    }
    for(int i=0; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j]=2e9;
    }
    int tot=p0.size(); tot--;
    for(int i=1; i<=tot; i++){
        for(int j=1; j<=n-tot; j++){
            dp[i][j]=min(dp[i][j], dp[i-1][j-1]+abs(p0[i]-p1[j]));
            dp[i][j]=min(dp[i][j], dp[i-1][j]);
        }
    }
    printf("%d\n", dp[tot][n-tot]);
    return 0;
}