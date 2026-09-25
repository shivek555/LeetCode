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
    set<string> build(const string& s) {
        set<string> parts;
        set<string> curr = {""};

        int i = 0;

        while (i < s.size()) {
            if (s[i] == '{') {
                int j = i;
                int depth = 0;

                while (true) {
                    if (s[j] == '{') {
                        depth--;
                    } else if (s[j] == '}') {
                        depth++;
                    }

                    if (depth == 0) {
                        break;
                    }

                    j++;
                }

                set<string> options = build(
                    s.substr(i + 1, j - i - 1)
                );

                set<string> next;

                for (const string& a : curr) {
                    for (const string& b : options) {
                        next.insert(a + b);
                    }
                }

                curr = next;
                i = j + 1;
            }

            else if (s[i] == ',') {
                parts.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }

            else {
                set<string> next;

                for (const string& x : curr) {
                    next.insert(x + s[i]);
                }

                curr = next;
                i++;
            }
        }

        parts.insert(curr.begin(), curr.end());

        return parts;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> result = build(expression);

        return vector<string>(result.begin(), result.end());
    }
};