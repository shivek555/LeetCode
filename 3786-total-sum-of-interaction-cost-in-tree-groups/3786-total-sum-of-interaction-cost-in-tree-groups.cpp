#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;



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
    long long ans;
    void dfs(int u, int p, vector<vector<int>>& g, int tar, int tot, vector<int>& sz, vector<int>& group){
        if(group[u]==tar)
            ++sz[u];
        for(int v: g[u]){
            if(v==p) continue;
            dfs(v, u, g, tar, tot, sz, group);
            sz[u]+=sz[v];
            ans+=1LL*(tot-sz[v])*sz[v];
        }
        
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> g(n);
        ans = 0;
        for(auto& x: edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        unordered_map<int,int> h;
        for(int x: group){
            ++h[x];
        }
        vector<int> sz(n, 0);
        for(auto [x,y]: h){
            dfs(0,-1,g,x,y,sz,group);
            fill(sz.begin(), sz.end(), 0); 
        }
        return ans;
    }
};