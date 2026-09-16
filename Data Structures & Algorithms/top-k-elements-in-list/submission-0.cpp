class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<int>>buckets(n+1);
        unordered_map<int,int>freq;
        for(auto&it:nums){
            freq[it]++;
        }
        for(auto&[ele,count]:freq){
            buckets[count].push_back(ele);
        }
        vector<int>result;
        // start from the highest frequency and collect the elements and then stop collecting once you reach for k 
        for(int i=nums.size();result.size()<k;i--){
            for(auto&element:buckets[i]){
                result.push_back(element);
            }
        }
        return result;
    }
};
