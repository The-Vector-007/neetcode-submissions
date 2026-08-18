class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        // n = 4 2 0123 i < n/2
        // n = 5 2 01234 i < n/2
        //i = 0, n-i = 5 - 0 = 5
        string clean_string = "";
        for(int i = 0; i < n; i++){
            if(isalnum(s[i])){
                if(isalpha(s[i])){
                    clean_string += tolower(s[i]);
                }
                else{
                    clean_string += s[i];
                }
            }
        }

        int m = clean_string.size();

        for(int i = 0; i < m/2; i++){
            if(clean_string[i] != clean_string[m-1-i]){
                //cout << clean_string[i] << " " << clean_string[n-1-i] << " ";
                return false;
            }
        }

        return true;
    }
};
