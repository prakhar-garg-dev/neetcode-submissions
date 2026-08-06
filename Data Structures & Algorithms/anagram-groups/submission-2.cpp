class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;

        // create a string of the count of the freq of each character using the array taken
        // check if the string with the same frequency of character is in the map if not append it -> if the string with the same frequency exist in the map then push back to the vector of the strings
        // empty the count array each time after collecting all the strings anagrams 

        for(auto&it:strs){
            vector<int>countChar(26);
            string str;
            for(auto&ch:it){
                countChar[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                string countString=to_string(countChar[i])+"$";
                str+=countString;
            }
            mp[str].push_back(it);
            
            
        }
        vector<vector<string>> res;
        for(auto&it:mp){
            res.push_back(it.second);
        }
        return res;

    }
};
