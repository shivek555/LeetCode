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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        deque<int>dq;
        int start=0;
        int end=0;
        long long reqOps=0;
        long long ans=0;
        for(;end<nums.size();end++){
            while(!dq.empty()&&nums[end]>nums[dq.back()]){
                int curr=dq.back();
                dq.pop_back();
                int next=!dq.empty()?dq.back():start-1;
                reqOps+=(long long)(nums[end]-nums[curr])*(long long)(curr-next);
            }
            //cout<<start<<" "<<end<<" "<<reqOps<<endl;
            dq.push_back(end);
            while(!dq.empty()&&reqOps>(long long)k){
                reqOps-=(long long)(nums[dq.front()]-nums[start]);
                if(dq.front()==start){
                    dq.pop_front();
                }
                start++;
            }
            //cout<<start<<" "<<end<<" "<<reqOps<<endl;
            ans+=(end-start+1);
        }

        return ans;
    }
};