class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<string> st;
        stack<int> at;
        long long len = 0;
        string tmp = "";
        for(auto x : s){
            if(x > '0' && x <= '9'){
                int a = x - '0';

                if(tmp.size() > 0){
                    at.push(a);
                    st.push(tmp);
                    tmp = "";
                }
                else{
                    int xx = at.top(); at.pop();
                    at.push(xx * a);
                }
                len = len * a;
                if(len >= k)break;
                continue; 
            }
            tmp = tmp + x;
            ++len;
        }
        if(tmp.size() > 0){
            st.push(tmp); at.push(1);
        }
        --k;
        while(at.size() > 0){
            int a = at.top(); at.pop();
            auto x = st.top(); st.pop();
            long long xlen = len / a;
            len = xlen - x.size();
            k = k % xlen;
            if(k >= len)return string(1, x[(int)k - len]);
        }

        return "x";
    }
};
