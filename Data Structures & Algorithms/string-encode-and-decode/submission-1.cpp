class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string s;
        s=to_string(strs[0].size())+"#"+strs[0];
        for(int i=1;i<strs.size();i++)
            s+=to_string(strs[i].size())+"#"+strs[i];;
        return s;
    }

    vector<string> decode(string s) {
      vector<string> strs;
      int strStart,i=0;
      int n= s.size();
    while(i<n){
        strStart=i;
        while(s[strStart]!='#')
            strStart++;
        int length=stoi(s.substr(i,strStart-i));
        string temp=s.substr(strStart+1,length);
        strs.push_back(temp);
        i=strStart+length+1;
      }
      // Example string I considered while solving    "786#H#ELLO.....94#9ADFLJDADF..."
      return strs;
        
    }
};
