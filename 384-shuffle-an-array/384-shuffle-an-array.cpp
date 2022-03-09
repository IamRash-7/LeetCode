class Solution {
    private:
    vector<int> arr1;
public:
    Solution(vector<int>& nums) {
        this->arr1 = nums;
    }
    
    vector<int> reset() {
        return arr1;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle = arr1;
        int n = shuffle.size();
        
        for(int i=shuffle.size()-1;i>=0;i--)
        {
            int j = rand() % n;
            swap(shuffle[i],shuffle[j]);
            n--;
        }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */