class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string sr=s;
            sort(sr.begin(),sr.end());
            mp[sr].push_back(s);
        }
        vector<vector<string>> res;
        for(auto str:mp){
            res.push_back(str.second);
        }
        return res;
    }
};
