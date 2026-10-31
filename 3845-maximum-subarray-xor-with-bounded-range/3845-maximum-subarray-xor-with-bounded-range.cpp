class Node {
    public:
        Node *links[2];
        int cnt;
        Node () {
            cnt = 0;
            links[0] = links[1] = nullptr;
        }

        bool containsKey (int bit) {
            return (links[bit] != nullptr);
        }

        Node *get (int bit) {
            return links[bit];
        }

        void put (int bit, Node *node) {
            links[bit] = node;
        }

        void increaseCnt () {
            cnt++;
        }

        void decreaseCnt () {
            cnt--;
        }

        int getCnt () {
            return cnt;
        }
};

class Trie {
    private:
        Node *root;
    public:
        Trie () {
            root = new Node();
        }

        void insert (int num) {
            Node *node = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!node -> containsKey(bit)) {
                    node -> put(bit, new Node());
                }

                node = node -> get(bit);
                node -> increaseCnt();
            }
        }

        void remove (int num) {
            Node *node = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (node -> containsKey(bit)) {
                    Node *temp = node;
                    node = node -> get(bit);
                    node -> decreaseCnt();
                }
            }
        }

        int getMax (int num) {
    		Node *node = root;
    
    		int maxVal = 0;
    		for (int i = 31; i >= 0; i--) {
    			int bit = (num >> i) & 1;
    
    			if (node -> containsKey(1 - bit) && node -> links[1 - bit] -> getCnt() > 0) {
    				maxVal = maxVal | (1 << i);
    				node = node -> get(1 - bit);
    			} else {
    				node = node -> get(bit);
    			}
    		}
    
    		return maxVal;
    	}
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        deque<int> mindq, maxdq;

        int i = 0, j = 0;
        Trie trie;

        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ nums[i];
        }

        trie.insert(0);
        while (j < n) {
            while (!maxdq.empty() && nums[j] > nums[maxdq.back()]) {
                maxdq.pop_back();
            }
            maxdq.push_back(j);

            while (!mindq.empty() && nums[j] < nums[mindq.back()]) {
                mindq.pop_back();
            }
            mindq.push_back(j);

            while (i < j && nums[maxdq.front()] - nums[mindq.front()] > k) {
                if (i == 0) {
                    trie.remove(0);
                } else {
                    trie.remove(prefix[i - 1]);
                }
                
                
                while (maxdq.front() == i) maxdq.pop_front();
                while (mindq.front() == i) mindq.pop_front();
                
                i++;
            }

            mx = max(mx, trie.getMax(prefix[j]));
            trie.insert(prefix[j]);
            j++;
        }

        return mx;
    }
};