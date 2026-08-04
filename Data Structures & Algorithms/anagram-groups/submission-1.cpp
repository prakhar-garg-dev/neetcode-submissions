class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        if(strs.size()==1){
            return {strs};
        }
        
        for(auto&it:strs){
            string sortedString=it;
            sort(sortedString.begin(),sortedString.end());
            mp[sortedString].push_back(it);
        }
        vector<vector<string>> resp;
        for(auto&it:mp){
            resp.push_back(it.second);
        }
        return resp;
    }
};
