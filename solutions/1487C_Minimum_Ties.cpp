// Problem: Minimum Ties
// URL: https://codeforces.com/problemset/problem/1487/C
// Rating: 1500
// Tags: brute force, constructive algorithms, dfs and similar, graphs, greedy, implementation, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;

void solve(){
    scanf("%d", &n);
    if(n%2==1){
        for(int i=1; i<=n*(n-1)/2; i++){
            if(i%2==1) printf("1 ");
            else printf("-1 ");
        }
        printf("\n");
    }
    else{
        for(int i=n-1; i>=1; i--){
            for(int j=1; j<=i; j++){
                if(j==1 && i%2==1) printf("0 ");
                else if(j%2==1) printf("1 ");
                else printf("-1 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
