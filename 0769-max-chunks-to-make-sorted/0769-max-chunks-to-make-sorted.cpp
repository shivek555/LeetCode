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
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> monotonicStack;
        for (int i = 0; i < n; i++) {
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            } else {
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                       arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};