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
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx = target[0], ty = target[1];
        auto key = [&](const auto& e) {
            const auto& [i, d] = e;
            int dist = abs(d[0] - tx) + abs(d[1] - ty);
            return pair{dist <= d[2] ? dist : INT_MAX, (int)i};   
        };
        auto [dist, i] = ranges::min(drones | views::enumerate | views::transform(key));
        return dist == INT_MAX ? -1 : i;
    }
};