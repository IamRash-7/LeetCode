class KthLargest {
    priority_queue<int, vector<int>, greater<int>> maxheap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i:nums)
        {
            maxheap.push(i);
            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }
    }
    
    int add(int val) {
        maxheap.push(val);
            if(maxheap.size()>size)
            {
                maxheap.pop();
            }
        return maxheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */