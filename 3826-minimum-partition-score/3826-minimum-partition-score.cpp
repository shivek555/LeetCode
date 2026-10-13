#pragma clang attribute push([[clang::no_sanitize("address", "thread", "memory", "undefined", "coverage"), gnu::target("avx2,bmi2,fma,sse4a,tune=znver3")]], apply_to = any(function))

template <class T1, class T2>
struct Pair {
    T1 first;
    T2 second;
    auto operator<=>(const Pair&) const noexcept = default;
};

using S = Pair<int64_t, int>;

template <class T>
[[clang::always_inline]]
void set_min(T& a, const T b) noexcept {
    if (b < a) a = b;
}

struct Line {
    int64_t m, c;
    int cnt;

    [[clang::always_inline]]
    int64_t eval(int64_t x) const noexcept {
        return m * x + c;
    }
};

[[clang::always_inline]]
bool is_redundant(const Line& a, const Line& b, const Line& c) noexcept {
    return (__int128)(c.c - a.c) * (a.m - b.m) <=
           (__int128)(b.c - a.c) * (a.m - c.m);
}

int64_t solveSmallK(int n, int k, const vector<int64_t>& P) noexcept {
    vector<int64_t> dp_prev(n + 1, 0), dp_curr(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int64_t s = P[i];
        dp_prev[i] = (s * s + s) / 2;
    }

    vector<Line> hull;
    hull.reserve(n + 1);

    for (int part = 2; part <= k; ++part) {
        hull.clear();

        int64_t j = part - 1;
        int64_t m = -2 * P[j];
        int64_t c = 2 * dp_prev[j] + P[j] * P[j] - P[j];
        hull.push_back({m, c, 0});

        int hull_idx = 0;

        for (int i = part; i <= n; ++i) {
            int64_t x = P[i];

            if (i > part) {
                int64_t prev_j = i - 1;
                int64_t m_new = -2 * P[prev_j];
                int64_t c_new = 2 * dp_prev[prev_j] +
                                P[prev_j] * P[prev_j] - P[prev_j];

                Line l = {m_new, c_new, 0};

                while (hull.size() >= 2 &&
                       is_redundant(hull[hull.size() - 2], hull.back(), l)) {
                    hull.pop_back();
                }

                hull.push_back(l);
            }

            while (hull_idx + 1 < hull.size() &&
                   hull[hull_idx].eval(x) >= hull[hull_idx + 1].eval(x)) {
                hull_idx++;
            }

            int64_t min_val = hull[hull_idx].eval(x);
            dp_curr[i] = (min_val + x * x + x) / 2;
        }

        dp_prev = dp_curr;
    }

    return dp_prev[n];
}

int64_t solveAlien(int n, int k, const vector<int64_t>& P) noexcept {
    auto calc = [&](int64_t lambda) -> Pair<int64_t, int> {
        static vector<Line> q;

        if (q.capacity() < n + 1) q.reserve(n + 1);
        q.clear();

        q.push_back({0, 0, 0});

        int idx = 0;
        int64_t val = 0;
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            int64_t x = P[i];

            while (idx + 1 < q.size() &&
                   q[idx].eval(x) >= q[idx + 1].eval(x)) {
                idx++;
            }

            int64_t prev_val = q[idx].eval(x);
            val = x * x + x + 2 * lambda + prev_val;
            cnt = q[idx].cnt + 1;

            int64_t m_new = -2 * x;
            int64_t c_new = val + x * x - x;
            Line l = {m_new, c_new, cnt};

            while (q.size() >= 2 &&
                   is_redundant(q[q.size() - 2], q.back(), l)) {
                q.pop_back();
            }

            q.push_back(l);
        }

        return {val, cnt};
    };

    int64_t l = 0, r = 2e15;
    int64_t best_lambda = 0;

    while (l <= r) {
        int64_t mid = l + (r - l) / 2;
        auto res = calc(mid);

        if (res.second <= k) {
            best_lambda = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    auto final_res = calc(best_lambda);
    return (final_res.first - 2 * (int64_t)k * best_lambda) / 2;
}

#pragma clang attribute pop

class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int64_t> P(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            P[i + 1] = P[i] + nums[i];
        }

        if (k <= 80) {
            return solveSmallK(n, k, P);
        } else {
            return solveAlien(n, k, P);
        }
    }
};