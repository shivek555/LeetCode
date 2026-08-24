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
    bool isPalindromic(string s) {
        string binary = "";

        for (char c : s) {
            int ascii = int(c);

            string bin = bitset<8>(ascii).to_string();

            binary += bin;
        }

        int i = 0;
        int j = binary.size() - 1;

        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};