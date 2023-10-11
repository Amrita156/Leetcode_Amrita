class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        unordered_map<int,int> mp;// no ordering
        vector<int> mp_key;
        #pragma unroll
        for(int a: people){
            if (mp.count(a)==0){
                mp[a]=0;
                mp_key.push_back(a);
            }   
        }
        #pragma unroll
        for(auto& fl: flowers){
            int s=fl[0], t=fl[1]+1;
            if (mp.count(s)) mp[s]++;
            else {
                mp[s]=1;
                mp_key.push_back(s);
            }
            if (mp.count(t)) mp[t]--;
            else{
                mp[t]=-1;
                mp_key.push_back(t);
            } 
        }

        sort(mp_key.begin(), mp_key.end());

        int bloom = 0;
        #pragma unroll
        for(int k : mp_key){//Compute bloom according to sorted mp_key
           mp[k]+= bloom;
           bloom = mp[k];
        }
        
        int n = people.size();
        vector<int> ans(n);
        #pragma unroll
        for(int i= 0; i < n; i++){
           ans[i]= mp[people[i]];
        }
        return ans;
    }
};