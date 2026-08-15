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
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        unordered_map<int,vector<pair<int,int>>> mpp;
        for(int i=0; i<n; i++){
            dp[i][0] = (mat[i][0]==1);
            mpp[dp[i][0]].push_back({i,0});
        }
        for(int j=0; j<m; j++){
            dp[0][j] = (mat[0][j]==1);
            mpp[dp[0][j]].push_back({0,j});
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j]==0) continue;
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                mpp[dp[i][j]].push_back({i,j});
            }
        }
        
        int ans = 0;
        for(auto& it : mpp){
            int s = it.first;
            vector<pair<int,int>> v = it.second;
            int x = v.size();
            if(x<=1) continue;
            for(int i=0; i<x; i++){
                for(int j=i+1; j<x; j++){
                    int r1=v[i].first;
                    int c1=v[i].second;
                    int r2=v[j].first;
                    int c2=v[j].second;

                    if(abs(r1-r2)>=s || abs(c1-c2)>=s){
                        ans=max(ans,s);
                        break;
                    }
                }
            }  
            
        }
        return ans*ans;

        
    }
};