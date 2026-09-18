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
     vector<string> maxNumOfSubstrings(string s) {
        int count[26] = {};
        int first[26], last[26];

        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        vector<int> order;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (count[c] == 0) {
                first[c] = i;
                order.push_back(c);
            }

            count[c]++;
            last[c] = i;
        }

        vector<string> res;
        deque<array<int, 3>> queue;

        for (int c : order) {
            queue.push_front({first[c], last[c], count[c]});

            int left = INT_MAX;
            int right = INT_MIN;
            int total = 0;

            for (auto& item : queue) {
                total += item[2];
                left = min(left, item[0]);
                right = max(right, item[1]);

                if (total == right - left + 1) {
                    break;
                }
            }

            if (total == right - left + 1) {
                res.push_back(s.substr(left, right - left + 1));
                queue.clear();
            }
        }

        return res;
    }
};   