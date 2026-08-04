class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        // First create the map and then iterate over it solution
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto&it:mp){
        cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=0;i<nums.size();i++){
            if (mp.find(target-nums[i])!=mp.end() && (mp[target-nums[i]]!=i)){
                    return {i,mp[target-nums[i]]};
            }
        }
    }
};
