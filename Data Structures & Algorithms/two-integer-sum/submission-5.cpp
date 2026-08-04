class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Iterate and map the elements together 
        // As in the previous solution we noticed we are finding the difference only in the map and hence we can check the difference before mapping out the elements in the map and if it doesn't exist we can add that element in the map so that later elements difference with targets can find it in the least
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                // Can't be {i,mp[target-nums[i]]} because the difference the difference element if not found would have been stored later only which is most probably always the case.  
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
    }
};
