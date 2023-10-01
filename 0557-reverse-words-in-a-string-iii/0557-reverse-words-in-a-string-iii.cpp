class Solution {
public:
    string reverseWords(string s) {
        string result = "", word;
        for(char p: s){
            if(p != ' ') word += p;
            else {
                reverse(word.begin(), word.end());
                result += word + " ";
                word = "";
            }
        }
        reverse(word.begin(), word.end());
        result += word;

        return result;
    }
};
