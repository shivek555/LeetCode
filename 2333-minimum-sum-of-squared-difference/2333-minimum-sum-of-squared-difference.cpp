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
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> difference( (int) 1e5+1);
        
        for(int i = 0; i<nums1.size();i++)
        {
            difference[abs(nums1[i] - nums2[i])]++;
        }
        
        int value = 0, left = k1+k2;
        int acc = 0;
        
        for(int i = (int) 1e5; i>=0; i--)
        {
            acc = difference[i];
            if(acc <= left)
            {
                if(i<=1)
                    return 0;
                
                difference[i-1] += difference[i];
                difference[i]=0;
                left -= acc;
            }
            else
            {
                if(i==0)
                    return 0;
                difference[i] -= left;
                difference[i-1] += left;
                break;
            }
        }
        long long answer = 0;
        
        for(int i = 1ll; i<=1e5; i++)
        {
            answer += (long long)difference[i] * ((long long)i*i);
        }
        
        return answer;
    }
};