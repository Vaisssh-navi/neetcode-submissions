class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums){
            if(freq.find(i)!=freq.end()) return true;
            freq[i]++;
        }
        return false;
        
    }
};