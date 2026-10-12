class Solution {
public:
    bool isPalindrome(string s) {
       string str;
       for(auto&it:s){
        if(!isalnum(it))
            continue;
         str+=tolower(it);//appending the same string without spaces & special symbols 
        //  cout<<str<<endl;
       }
       string rev=str;
       reverse(rev.begin(),rev.end());
     
     return str==rev; 
    }
};