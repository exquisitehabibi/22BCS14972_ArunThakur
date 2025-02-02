class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> arr;
        for(char c : s){
            if(!isalnum(c)){
                continue;
            }
            else{
                arr.push_back(tolower(c));
                cout<<c;
            }
        }
        vector <char> n = arr;
        reverse(n.begin(),n.end());
        if(n==arr){
            return true;
        }
        return false;
        
    }
};
