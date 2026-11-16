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
    string digitSum(string s, int k) {
        vector<int> result;
        if(s.size()<=k){
            return s;
        }
        string S = "";
        for(int i = 0; i < s.size(); i++){
            result.push_back(s[i] - '0');
        }

        for(int i = 0; i < result.size(); i += k){
            int num = 0;
            for(int j = i; j < i + k && j < result.size(); j++){
                num += result[j];
            }
            S += to_string(num);
        }
        if(S.size() <= k){
            return S;
        }
        else{
            return digitSum(S, k);
        }
    }
};