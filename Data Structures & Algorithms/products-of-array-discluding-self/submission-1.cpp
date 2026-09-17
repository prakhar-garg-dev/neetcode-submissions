class Solution {
public:
    void printVector(vector<int>& vec){
        for(auto&it:vec){
            cout<<it<<"\t";
        }
        cout<<endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixP(n,1);
        vector<int> suffixP(n,1);
        prefixP[0]=1;
        suffixP[n-1]=1;
        for(int prefix=1;prefix<n;prefix++){
            prefixP[prefix]=nums[prefix-1]*prefixP[prefix-1];
        }
        // printVector(prefixP);
        for(int suffix=n-2;suffix>=0;suffix--){
            suffixP[suffix]=nums[suffix+1]*suffixP[suffix+1];
        }
        // printVector(suffixP);
        vector<int>res(n,1);
        for(int i=0;i<n;i++){
            res[i]=prefixP[i]*suffixP[i];
        }
        // printVector(res);
        return res;
    }
};