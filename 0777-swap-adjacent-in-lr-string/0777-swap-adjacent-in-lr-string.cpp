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
    bool canTransform(string start, string result) {
            int cntR=0, cntL=0;
        int n = start.size();
        for(int i=0;i<n;i++){
            if(start[i]=='R') cntR++;
            if(result[i]=='R'){
                if(cntL || cntR==0) return 0;
                cntR--;
            }
            if(result[i]=='L') cntL++;
            if(start[i]=='L'){
                if(cntR || cntL==0) return 0;
                cntL--;
            }
        }
        return cntR==0 && cntL==0;
    }
};