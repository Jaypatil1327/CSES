#include<bits/stdc++.h>
using namespace std ; 
int MOD = 1e9 + 7 ; 
vector<int> dp ; 

int f(int n) {
    if(n == 0) return 1 ;
    else if(n < 0) return 0 ; 

    if(dp[n] != -1) return dp[n] ; 
    int count = 0 ; 
    for(int i = 1 ; i <= 6 ; i++) {
        count = (count % MOD + f(n-i) % MOD) % MOD ; 
    }
    return dp[n] = (count % MOD) + 1; 
}

int fbu(int n){
    dp[0] = 1 ; 
    for(int i = 1; i < dp.size() ; i++) {
        for(int k = 1 ; k <= 6 ; k++) {
            int id = i - k ; 
            if(id >= 0) {
                dp[i] = (dp[i] % MOD + dp[id] % MOD) % MOD ;
            }
        }
    }
    return dp[dp.size()-1] ; 
}

int main() {
    int n ; 
    cin >> n ; 
    dp.clear() ; 
    dp.resize(n+1 , 0) ; 
    cout << fbu(n) ; 
}