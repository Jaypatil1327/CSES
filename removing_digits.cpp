#include<bits/stdc++.h>
using namespace std ;

vector<int> dp ; 
int f(int n) {
    if(n < 10) return 1 ;
    
    if(dp[n] != -1) return dp[n] ; 
    int res = INT_MAX ; 
    int temp = n ; 
    while(temp > 0) {
        int d = temp % 10 ; 
        if(d) res = min(f(n - d) , res) ; 
        temp/=10 ; 
    }
    return dp[n] = res + 1 ; 
}

int fbu(int n) {
    if(n <= 9) return 1 ; 
    for(int i = 0 ; i <= 9 ; i++) { // mark all 0-9 as 1
        dp[i] = 1 ; 
    }

    for(int i = 10 ; i < dp.size() ; i++) {
        int res = INT_MAX ; 
        int temp = i ; 

        while(temp > 0) {
            int d = temp % 10 ; 
            if(d) res = min(dp[i-d] , res) ; 
            temp/=10 ; 
        }
        dp[i] = res + 1 ; 
    }

    return dp[dp.size()-1] ; 
}

int main() {
    int n ; 
    cin >> n ; 
    dp.clear() ; 
    dp.resize(n + 1, -1) ; 
    cout << fbu(n) ; 
}