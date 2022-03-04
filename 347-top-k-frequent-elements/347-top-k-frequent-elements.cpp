class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority queue (vector or pairs) to store index and it's count
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // map to count no. of appearances initially
        unordered_map<int, int> cnt;
        
        // initialize map
        for (auto num : nums) cnt[num]++;
        
        // for elements in map, push it in min-heap
        for (auto kv : cnt) {
            pq.push({kv.second, kv.first});
            
            // push new and pop top if greater than k elements
            while (pq.size() > k) pq.pop();
        }
        
        // remove elements from heap and push in array
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};