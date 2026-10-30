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
    unordered_set<string> perfect;
    unordered_map<string, string> caps, vowels;

    string normalize(string s) {
        for (char& c : s) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (const string& word : wordlist) {
            perfect.insert(word);

            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            caps.emplace(lower, word);
            vowels.emplace(normalize(lower), word);
        }

        vector<string> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            if (perfect.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caps.count(lower)) {
                ans.push_back(caps[lower]);
                continue;
            }

            string vowel = normalize(lower);

            if (vowels.count(vowel))
                ans.push_back(vowels[vowel]);
            else
                ans.push_back("");
        }

        return ans;
    }
};
