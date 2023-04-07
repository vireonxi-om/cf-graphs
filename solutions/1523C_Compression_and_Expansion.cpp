// Problem: Compression and Expansion
// URL: https://codeforces.com/problemset/problem/1523/C
// Rating: 1600
// Tags: brute force, data structures, greedy, implementation, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> ans;

void solve(){
    scanf("%d", &n);
    int num;
    ans.clear();
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        if(num==1){
            ans.push_back(num);
        }
        else{
            auto it=ans.end();
            it--;
            if((*it)==num-1){
                ans[it-ans.begin()]=num;
            }
            else{
                while((*it)!=num-1){
                    ans.erase(it);
                    it=ans.end();
                    it--;
                }
                ans[it-ans.begin()]=num;
            }
        }
        int len=ans.size();
        for(int k=0; k<len-1; k++){
            printf("%d.", ans[k]);
        }
        printf("%d\n", ans[len-1]);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
