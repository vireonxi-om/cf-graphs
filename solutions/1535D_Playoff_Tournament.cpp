// Problem: Playoff Tournament
// URL: https://codeforces.com/problemset/problem/1535/D
// Rating: 1800
// Tags: data structures, dfs and similar, dp, implementation, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k, q, t[1100000];
char s[1100000];
vector<int> g[1100000];

void dfs(int pos){
    int a=-1, b=-1, nxt=-1;
    for(auto x:g[pos]){
        if(x>pos) nxt=x;
        else if(a==-1) a=x;
        else b=x;
    }
    if(a>b) swap(a, b);
    if(a==-1){
        if(s[pos]=='?') t[pos]=2;
        else t[pos]=1;
    }
    else{
        if(s[pos]=='0') t[pos]=t[a];
        else if(s[pos]=='1') t[pos]=t[b];
        else t[pos]=t[a]+t[b];
    }
    if(nxt!=-1) dfs(nxt);
}


int main(){
    scanf("%d%s%d", &k, s+1, &q);
    int n=1;
    for(int i=1; i<=k; i++) n*=2;
    int l=0, r=n/2, p=r/2;
    n--;
    while(r<n){
        for(int i=1; i<=p; i++){
            g[r+i].push_back(l+i*2-1);
            g[l+i*2-1].push_back(r+i);
            g[r+i].push_back(l+i*2);
            g[l+i*2].push_back(r+i);
        }
        l=r; r+=p; p/=2;
    }
    for(int i=1; i<=n; i++) t[i]=1;
    for(int i=1; i<=n; i++) dfs(i);
        int num; char c;
    while(q--){
        scanf("%d%c%c", &num, &c, &c);
        s[num]=c;
        dfs(num);
        printf("%d\n", t[n]);
    }
    return 0;
}


