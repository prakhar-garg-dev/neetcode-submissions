class Solution {
public:
    bool isAnagram(string s, string t) {
        int countArr[26];
        for(int i=0;i<s.size();i++){
            countArr[s[i]-'a']++;
        } 
        for(int i=0;i<t.size();i++){
            countArr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(countArr[i]!=0){
                return false;
            }
        }
        
        
        return true;
    }
};
