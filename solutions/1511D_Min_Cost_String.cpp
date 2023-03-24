// Problem: Min Cost String
// URL: https://codeforces.com/problemset/problem/1511/D
// Rating: 1600
// Tags: brute force, constructive algorithms, graphs, greedy, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, yes[30];
vector<int> ans;

int main() {
    scanf("%d%d", &n, &k);
    ans.push_back(1);
    for(int i=1; i<k; i++){
        if(yes[i]==0){ ans.push_back(i); yes[i]=1;}
        for(int j=k; j>i+1; j--){
            ans.push_back(j);
            ans.push_back(i);
        }
        if(i+1<=k) ans.push_back(i+1);
    }
    for(int i=k; i>1; i--) ans.push_back(i);
    int len=ans.size();
    int pos=0;
    while(n--){
        printf("%c", 'a'-1+ans[pos]);
        pos++;
        if(pos==len) pos=0;
    }
    printf("\n");
}