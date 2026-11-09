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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <int> answer(n, 1);
        
        vector <vector <int>> graph(n);
        for (vector v: paths) {
            graph[v[0] - 1].push_back(v[1] - 1);
            graph[v[1] - 1].push_back(v[0] - 1);
        }
        
        for (int garden = 0; garden < n; garden++) {
            vector <bool> colors(5, false);
            for (int c: graph[garden]) {
                colors[answer[c]] = true;
            }
            
            for (int i = 4; i > 0; i--) {
                if (!colors[i]) {
                    answer[garden] = i;
                }
            }            
        }
        
        return answer;
    }
};