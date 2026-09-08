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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& G) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});                                                   
        while(size(q)) {
            auto path = move(q.front()); q.pop();
            if(path.back() == size(G)-1) ans.push_back(move(path));    
            else
                for(auto child : G[path.back()]) {                     
                    path.push_back(child);
                    q.push(path);                                      
                    path.pop_back();
                }
        }
        return ans;
    }
};