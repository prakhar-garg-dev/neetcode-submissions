class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto&it:s)
            cout<<it<<endl;
        int count = 1;
        int maxCount = 0;
        if (nums.size() == 0) {
            return 0;
        }
        for (auto& it : s) {
            int current=it;
            if (s.find(current - 1) == s.end()) {
                count = 1;
                while (s.find(current + 1) != s.end()){
                    count++;
                    current++;
                }
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};