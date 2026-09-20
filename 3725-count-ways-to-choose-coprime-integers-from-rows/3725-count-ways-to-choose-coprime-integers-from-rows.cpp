const int MOD=1000000007;
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int recur(int idx,int g,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int m=mat.size();
        if(idx==m){
            if(g==1)return 1;
            else return 0;
        }
        if(dp[idx][g]!=-1)return dp[idx][g];
        long long res=0;
        for(int i=0;i<mat[idx].size();i++){
            int value=mat[idx][i];
            int newg;
            if(idx==0)newg=value;
            else newg=__gcd(g,value);

            res=(res+recur(idx+1,newg,mat,dp))%MOD;
        }
        dp[idx][g]=res;
        return res;
    }

    
    int countCoprime(vector<vector<int>>& mat) {
        int m=mat.size();
        vector<vector<int>>dp(m,vector<int>(151,-1));
       return recur(0,0,mat,dp);
    }
};