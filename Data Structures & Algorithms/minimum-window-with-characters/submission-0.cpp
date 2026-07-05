class Solution {
public:
    string minWindow(string s, string t) {
        // int n=s.size();
        // vector<int> need(128,0);
        // for(char c:t){
        //     need[c]++;
        // }
        // int mini=INT_MAX;
        // int start=-1;
        // for(int i=0;i<n;i++){
        //     vector<int> freq(128,0);
        //     for(int j=i;j<n;j++){
        //         freq[s[j]]++;
        //         bool ok=true;
        //         for(int c=0;c<128;c++){
        //            if(freq[c]<need[c]){
        //            ok=false;
        //            }
        //         }
        //         if(ok){
        //             if(j-i+1<mini){
        //                 mini=j-i+1;
        //                 start=i;
        //             }
        //             break;
        //         }
        //     }
        // }
        // if(start==-1) return "";
        // return s.substr(start,mini);
        // //n^2*128
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(char c:t){
            need[c]++;
        }
        int have=0;
        int req=need.size();
        int l=0;
        int mini=INT_MAX;
        int start=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(need.count(c) && window[c]==need[c]) have++;
            while(have==req){
                if(r-l+1<mini){
                    mini=r-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(need.count(s[l])&& window[s[l]]<need[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(mini==INT_MAX) return "";
        return s.substr(start,mini);
    }
};
