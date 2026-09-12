#define sort(a) sort(begin(a), end(a))
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

void *operator new[](const size_t size) {
    return operator new(size);
}

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

    int maxProfitAssignment(vector<int>& difficulty,
                            vector<int>& profit,
                            vector<int>& worker) {
        int res = 0;
        int j = 0;
        int best = 0;

        vector<pair<int, int>> temp;

        for (int i = 0; i < difficulty.size(); ++i) {
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(temp);
        sort(worker);

        for (int work : worker) {

            while (j < temp.size() && work >= temp[j].first) {
                best = max(best, temp[j].second);
                ++j;
            }

            res += best;
        }

        return res;
    }
};