#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    template <class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                             tree_order_statistics_node_update>;
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set<pair<int, int>> os;
        long long inv_count = 0;

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (i - k >= 0) {
                int out = nums[i - k];
                int smaller = os.order_of_key({out, 0});
                inv_count -= smaller;
                os.erase({out, i - k});
            }
            int in = nums[i];
            int greater = os.size() - os.order_of_key({in, INT_MAX});
            inv_count += greater;
            os.insert({in, i});
            if (i >= k - 1) {
                ans = min(ans, inv_count);
            }
        }
        return ans;
    }
};