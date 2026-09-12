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
    bool vis[1005];
    void bfs(int src,vector<vector<int>>& rooms)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty())
        {
            int par = q.front();
            q.pop();
            for(int child : rooms[par])
            {
                if(!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis,false,sizeof(vis));
        int n = rooms.size();
        bfs(0,rooms);
        for(int i=0;i<n;i++)
            if(vis[i]==false)
                return false;
        return true;
    }
};