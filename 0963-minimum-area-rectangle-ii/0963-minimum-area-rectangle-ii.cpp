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
    struct Key {
        int x, y, d;

        bool operator==(const Key& other) const {
            return x == other.x && y == other.y && d == other.d;
        }
    };

    struct Hash {
        size_t operator()(const Key& k) const {
            size_t h = hash<int>()(k.x);
            h ^= hash<int>()(k.y) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= hash<int>()(k.d) + 0x9e3779b9 + (h << 6) + (h >> 2);
            return h;
        }
    };

    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<Key, vector<pair<int, int>>, Hash> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];

                Key key = {
                    points[i][0] + points[j][0],
                    points[i][1] + points[j][1],
                    static_cast<int>(dx * dx + dy * dy)
                };

                mp[key].push_back({i, j});
            }
        }

        double ans = DBL_MAX;

        for (auto& [key, diagonals] : mp) {
            int m = diagonals.size();

            for (int i = 0; i < m; i++) {
                auto [a, b] = diagonals[i];

                for (int j = i + 1; j < m; j++) {
                    auto [c, d] = diagonals[j];

                    long long x1 = points[c][0] - points[a][0];
                    long long y1 = points[c][1] - points[a][1];

                    long long x2 = points[d][0] - points[a][0];
                    long long y2 = points[d][1] - points[a][1];

                    long long cross = x1 * y2 - y1 * x2;

                    ans = min(ans, (double)abs(cross));
                }
            }
        }

        return ans == DBL_MAX ? 0.0 : ans;
    }
};
