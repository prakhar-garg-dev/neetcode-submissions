class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prefixP=1,suffixP=1;
        vector<int>res(n,1);
        for(int i=1;i<n;i++){
            prefixP*=nums[i-1];
            res[i]=prefixP;
        }
        for(int j=n-2;j>=0;j--){
            suffixP*=nums[j+1];
            res[j]*=suffixP;
        }
        return res;
    }
};