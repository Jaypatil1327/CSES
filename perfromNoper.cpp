#include<bits/stdc++.h>
using namespace std ; 

vector<int> dp ; 

int f(int n) {
    if(n == 1) return 0 ; 
    if(dp[n] != -1) return dp[n] ; 
    int x = f(n-1) ; 
    int y = (n % 2 == 0) ? f(n/2) : INT_MAX ; 
    int z = (n % 3 == 0) ? f(n/3) : INT_MAX  ; 

    return dp[n] = 1 + min(min(x , y) , z) ; 
}

int fb(int n) {
    dp[0] = 0 ; 
    dp[1] = 0 ; 
    
    for(int i = 2 ; i <= n ; i++) {
        int x = dp[i-1] ; 
        int y = i % 2 == 0 ? dp[i/2] : INT_MAX ; 
        int z = i % 3 == 0 ? dp[i/3] : INT_MAX ; 

        dp[i] = 1 + min(min(x , y) , z) ; 
    }
    return dp[n] ; 
}
int main() {
    cout << "Enter the number : " ; 
    int n ; 
    cin >> n ;
    
    dp.clear() ; 
    dp.resize(n+1 , -1) ; 
    cout << "minimum number of operation : " << fb(n) ; 
}