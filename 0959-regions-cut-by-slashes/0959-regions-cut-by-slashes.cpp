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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int total = 4 * n * n;

        vector<int> parent(total), sz(total, 1);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        int regions = total;

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (sz[a] < sz[b]) swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];
            regions--;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cell = 4 * (i * n + j);

                int top = cell;
                int right = cell + 1;
                int bottom = cell + 2;
                int left = cell + 3;

                if (grid[i][j] != '/') {
                    unite(top, right);
                    unite(bottom, left);
                }

                if (grid[i][j] != '\\') {
                    unite(top, left);
                    unite(right, bottom);
                }

                if (i > 0) {
                    unite(top, 4 * ((i - 1) * n + j) + 2);
                }

                if (j > 0) {
                    unite(left, 4 * (i * n + j - 1) + 1);
                }
            }
        }

        return regions;
    }
};