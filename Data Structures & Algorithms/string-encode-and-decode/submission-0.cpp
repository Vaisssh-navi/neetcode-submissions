class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string s:strs){
            ans+=to_string(s.size());
            ans+='#';
            ans+=s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int l=stoi(s.substr(i,j-i));
            j++;
            ans.push_back(s.substr(j,l));
            i=j+l;
        }
        return ans;

    }
};
