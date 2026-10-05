#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);

alignas(max_align)
static unsigned char BUFFER[256 * 1024 * 1024];

static size_t pos = 0;

void* operator new(const size_t size) {
    const size_t padding =
        (max_align - (pos % max_align)) % max_align;

    pos += padding + size;

    return static_cast<void*>(&BUFFER[pos - size]);
}

void* operator new[](const size_t size) {
    return operator new(size);
}

void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int ans = 0;

        for (int b = 30; b >= 0; b--) {
            long long target = ans | (1LL << b);

            vector<long long> costs;

            for (int& val : nums) {
                long long curr = val;
                long long cost = 0;

                for (int j = 30; j >= 0; j--) {
                    if ((target >> j) & 1LL) {
                        if (!((curr >> j) & 1LL)) {
                            long long rem = curr % (1LL << j);
                            long long add = (1LL << j) - rem;

                            curr += add;
                            cost += add;
                        }
                    }
                }

                costs.push_back(cost);
            }

            sort(costs.begin(), costs.end());

            if (costs.size() >= m) {
                long long totalCost = 0;

                for (int i = 0; i < m; i++) {
                    totalCost += costs[i];
                }

                if (totalCost <= k) {
                    ans = target;
                }
            }
        }

        return ans;
    }
};