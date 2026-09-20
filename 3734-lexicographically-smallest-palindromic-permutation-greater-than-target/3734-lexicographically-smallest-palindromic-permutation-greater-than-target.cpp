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
    string lexPalindromicPermutation(string str, string target) {
        int freq[26] = {0};
        for (char s : str)
            freq[s - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";
                center = 'a' + i;
                freq[i]--;
            }
        }

        int sz = str.length();
        int half = sz / 2;
        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;

        if (check(freq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            string tail = "";
            if (center != 0)
                tail += center;
            tail += rev;
            if (tail > target.substr(half))
                return head + tail;
        }

        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            freq[w - 'a'] += 2;
            if (!check(freq))
                continue;

            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j] -= 2;
                string result = target.substr(0, i + 1);
                result[i] = 'a' + j;

                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }

                string part = result;
                reverse(part.begin(), part.end());
                if (center != 0)
                    result.push_back(center);
                result += part;
                return result;
            }
        }

        return "";
    }

    bool check(int f[]) {
        for (int i = 0; i < 26; i++)
            if (f[i] < 0)
                return false;
        return true;
    }
};