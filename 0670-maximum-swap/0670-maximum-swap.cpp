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
    int maximumSwap(int num) {
        string st = to_string(num);
        int n = st.size();
        priority_queue<pair<char, int>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({st[i], i});
        }
        for(int j = 0; j < n; j++)
        {
            while(! pq.empty() && pq.top().second < j)
                pq.pop();
                if(pq.top().first > st[j])
                {
                    swap(st[j], st[pq.top().second]);
                    break;
                }            
        }
        return stoi(st);
    }
};