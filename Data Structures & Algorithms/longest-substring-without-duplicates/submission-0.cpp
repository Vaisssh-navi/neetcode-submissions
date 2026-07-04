class Solution {
public:

// brute force check all subsstring by generating all O(n^3)


    int lengthOfLongestSubstring(string s) {
        // int n=s.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     unordered_set<int> st;
        //     for(int j=i;j<n;j++){
        //         if(st.count(s[j])) break;
        //         st.insert(s[j]);
        //         ans=max(ans,j-i+1);
        //     }
        // }
        // return ans;

        // above is for O(n^2)

    //     int n=s.size();
    //     int l=0;
    //     int ans=0;
    //     unordered_set<int> st;
    //     for(int r=0;r<n;r++){
    //         while(st.count(s[r])){
    //             st.erase(s[l]);
    //             l++;
    //         }
    //         st.insert(s[r]);
    //         ans=max(ans,r-l+1);
    //     }
    //     return ans;
    //     // O(n) but its 2n

    int n=s.size();
    int l=0;
    int ans=0;
    unordered_map<char,int> mp;
    for(int r=0;r<n;r++){
        if(mp.count(s[r])){
            l=max(l,mp[s[r]]+1);
        }
        mp[s[r]]=r;
        ans=max(ans,r-l+1);
    }
    return ans;
    //O(n) exactly n
    }
};
