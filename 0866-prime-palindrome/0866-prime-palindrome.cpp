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
    bool isPrime(int num) {
        if (num == 1)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    int makePalindrome(int num) {
        string ans = to_string(num);
        string s = to_string(num);
        s.pop_back();
        reverse(s.begin(), s.end());
        ans += s;
        int K = stoi(ans);
        return K;
    }
    int primePalindrome(int n) {
        if (n <= 2)
            return 2;
        else if (n <= 3)
            return 3;
        else if (n <= 5)
            return 5;
        else if (n <= 7)
            return 7;
        else if (n <= 11)
            return 11;
        int ans;
        for (int i = 1;; i++) {
            int palin = makePalindrome(i);
            if (palin >= n && isPrime(palin)) {
                ans = palin;
                break;
            }
        }
        return ans;
    }
};