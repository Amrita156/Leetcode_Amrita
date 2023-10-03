class Solution {
public:
    int numIdenticalPairs(vector<int>& q) {
        int i,p=0;

        unordered_map<int,int>map;

        for(i=0;i<q.size();i++){
            if(map.find(q[i])!=map.end())
            p+=map[q[i]];
                
            map[q[i]]++;
        }
        return p;
    }
};