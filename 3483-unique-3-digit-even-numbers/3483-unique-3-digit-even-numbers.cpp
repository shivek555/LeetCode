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
    int totalNumbers(vector<int>& digits) {
        int freq[10]{};
        for(int digit:digits) freq[digit]++;
        int zero=0;
        int even=0;
        int all=0;
        for(int i=0; i<10; i++){
            if (freq[i]>0){
                if (i==0) zero++;
                if (i%2==0) even++;
                all++;
            }
        }
        int count = even*(all-1)*(all-2);
        if (zero==1) count-=(even-1)*(all-2);

        for(int i=0; i<10; i++){
            if (freq[i]>=2){
                if (i==0) count+=all-1;
                else if (i%2==1) count+=even;
                else{
                    count+=3*(even-1)-zero;
                    count+=2*(all-even);
                }           
            }
        }

        for(int i=2; i<10; i+=2){
            if (freq[i]>=3){
                count++;
            }
        }
        return count;
    }
};