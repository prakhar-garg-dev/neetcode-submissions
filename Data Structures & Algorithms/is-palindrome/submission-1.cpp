class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<=j){
            while(i<j&&!isalnum(s[i])){
             cout<<"s[i] was "<<s[i]<<" thus moving the pointer forward"<<endl;   
                i++;
            }
            while(i<j&&!isalnum(s[j])){
            cout<<"s[j] was "<<s[j]<<" thus moving the pointer behind"<<endl;
                j--;
            }
            if (tolower(s[i])!=tolower(s[j]))
            {
                cout<<"the characters "<<s[i]<<" & "<<s[j]<<" don\'t match"<<endl;
                return false;
            }   
            else{
                cout<<"The characters "<<s[i]<<" & "<<s[j]<<" are matching"<<endl;
                i++;
                j--;
            }
        }
        return true;
    }
};