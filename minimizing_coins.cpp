#include<bits/stdc++.h>
using namespace std ; 

vector<int> dp ; 
int f(vector<int> &v , int sum) {
    if(sum == 0) return 0 ; 
    
    if(dp[sum] != -2) return dp[sum] ; 

    int res = INT_MAX ; 
    for(int i = 0 ; i < v.size() ; i++) {
        int x = sum - v[i] ;
        if(x >= 0) res = min(res , f(v , x)) ;
    }
    return dp[sum] = (res == INT_MAX ? INT_MAX: res + 1) ;
}

int main(){
    dp.clear() ; 
    int n , sum ; 
    cin >> n >> sum ; 
    vector<int> v ; 
    for(int i = 0 ; i < n ; i++) {
        int x  ; 
        cin >> x ; 
        v.push_back(x) ; 
    }

    dp.resize(sum + 1 , -2) ; 
    int x = f(v , sum) ; 
    cout << (x == INT_MAX ? -1 : x) ;  
}