
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

class disjointset{
    public:
    vector<int>rank,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(parent[node]==node){
            return node;

        }
        return parent[node]=findpar(parent[node]);
    }
    void unionr(int u,int v){
        int ul_u=findpar(u);
        int ul_v=findpar(v);
        if(ul_u==ul_v) return;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v]=ul_u;
        }
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }
};
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointset d(n);
        unordered_map<string,int>mapy;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapy.find(mail)==mapy.end()){
                    mapy[mail]=i;
                }else{
                    d.unionr(i,mapy[mail]);
                }
            }
        }
        vector<string>mergemail[n];
        for(auto it:mapy){
            string mail=it.first;
           int node = d.findpar(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};