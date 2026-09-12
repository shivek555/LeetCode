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
    vector<int> ans;
    vector<int> splitIntoFibonacci(string S) {
        vector<int> x;
        fibonacciSeq(S, x, 0);
        return ans;
    }
    
    void fibonacciSeq(string S, vector<int> vec, int index) {
        if (index == S.length() && vec.size() > 2) {
            ans = vec;
            return;
        }
        long num = 0;
        for (int i = index; i < S.length(); i++) {
            num = num * 10 + S[i] - '0';
            if (num > INT_MAX) return;
            if (S[index] == '0' && i > index) return; 
            if (vec.size() < 2 || num == ((long)vec.back() + (long)vec[vec.size()-2])) {
                vec.push_back(num);
                fibonacciSeq(S, vec, i + 1);
                vec.pop_back();
            }
        }
    }
};