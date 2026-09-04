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
   vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> res(n, 0);
    stack<int> st;  

    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.top()]) {
            int j = st.top();
            st.pop();
            res[j] = i - j;
        }

        st.push(i);
    }

    return res;
}
};