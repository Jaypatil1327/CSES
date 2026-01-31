#include<bits/stdc++.h>
using namespace std ; 
int mod = 1e9 + 7 ; 
vector<int> dp ; 
int f(vector<int> &v , int sum) {
    if(sum == 0) return 1 ; 
    if(dp[sum] != -1) return dp[sum] ; 
    long long ways = 0 ; 
    for(int i = 0 ; i < v.size() ; i++) {
        if(sum - v[i] >= 0) {
            ways = ( ( ways % mod) + (f(v , sum - v[i]) % mod) ) % mod ; 
        } else break; 
    }
    return dp[sum] = ways ; 
}

int fbu(vector<int> &v , int sum) {
    dp[0] = 1 ; 
    for(int i = 1 ; i < dp.size() ; i++) {
        long long ways = 0 ; 
        for(int j = 0 ; j < v.size() ; j++) {
            if(i - v[j] >= 0) {
                ways += dp[i - v[j]] ; 
            } 
        }
      
        dp[i] = ways % mod; 
    }
    return dp[dp.size() - 1] ; 
}

int main() {
    int n , sum ; 
    cin >> n >> sum ; 
    dp.clear() ; 
    dp.resize(sum + 1 , 0) ; 
    vector<int> v ; 
    for(int i = 0 ; i < n ; i++) {
        int x ; 
        cin >> x ; 
        v.push_back(x) ; 
    }
    cout << fbu(v , sum) ; 
}