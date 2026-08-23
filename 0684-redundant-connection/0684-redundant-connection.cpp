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
     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        auto isConnected = [&](int u, int v) {
            unordered_set<int> visited;
            stack<int> stack;
            stack.push(u);

            while (!stack.empty()) {
                int node = stack.top();
                stack.pop();

                if (visited.count(node)) continue;
                visited.insert(node);

                if (node == v) return true;

                for (int neighbor : graph[node]) {
                    stack.push(neighbor);
                }
            }
            return false;
        };

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];

            if (graph.count(u) && graph.count(v) && isConnected(u, v)) {
                return edge;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};