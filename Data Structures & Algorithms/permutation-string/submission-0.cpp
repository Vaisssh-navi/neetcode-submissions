class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // int n1=s1.size();
        // int n2=s2.size();
        // if(n2<n1) return false;
        // int l=0;
        // int r=n1-1;
        // sort(s1.begin(),s1.end());
        // while(l+n1<=n2){
        //     string str=s2.substr(l,n1);
        //     sort(str.begin(),str.end());
        //     if(str==s1){
        //         return true;
        //         break;
        //     }
        //     l++;
        // }
        // return false;

        // (n2-n1+1) * ( n1 + n1logn1 + n1) == O(n1n2logn1)

        // int n1=s1.size();
        // int n2=s2.size();
        // if(n2<n1) return false;
        // vector<int> target(26,0);
        // for(char c:s1){
        //     target[c-'a']++;
        // }
        // for(int i=0;i<=n2-n1;i++){
        //     vector<int> curr(26,0);
        //     for(int j=i;j<i+n1;j++){
        //         curr[s2[j]-'a']++;
        //     }
        //     if(curr==target) return true;
        // }
        // return false;
        // // (n2-n1+1) * (n1+26) = O(n1n2)

        //         int n1=s1.size();
        // int n2=s2.size();
        // if(n2<n1) return false;
        // vector<int> target(26,0);
        // vector<int> window(26,0);
        // for(char c:s1){
        //     target[c-'a']++;
        // }
        // for(int i=0;i<n1;i++){
        //     window[s2[i]-'a']++;
        // }
        // if(window==target) return true;
        // for(int i=n1;i<n2;i++){
        //     window[s2[i]-'a']++;
        //     window[s2[i-n1]-'a']--;
        //     if(target==window) return true;
        // }
        // return false;

        // // n1+n1+(n2-n1)*26 = O(n2)

                int n1=s1.size();
        int n2=s2.size();
        if(n2<n1) return false;
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int match=0;
        for(char c:s1){
            c1[c-'a']++;
        }
        for(int i=0;i<n1;i++){
            c2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(c1[i]==c2[i]){
                match++;
            }
        }
        int l=0;
        for(int r=n1;r<n2;r++){
            if(match==26) return true;
            int add=s2[r]-'a';
            c2[add]++;
            if(c2[add]==c1[add]) match++;
            else if(c2[add]==c1[add]+1) match--;
            int remove=s2[l]-'a';
            c2[remove]--;
            if(c2[remove]==c1[remove]) match++;
            else if(c2[remove]==c1[remove]-1) match--;
            l++;
        }
        return match==26;

// n1+n1+n2-n1 = O(n1+n2)
    }
};
