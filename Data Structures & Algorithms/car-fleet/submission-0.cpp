class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        // stack<double> st;
        // for(auto c:cars){
        //     double time=(double)(target-c.first)/c.second;
        //     st.push(time);
        //     if(st.size()>=2){
        //         double top=st.top(); st.pop();
        //         if(top<=st.top()) {}
        //         else st.push(top);
        //     }
        // }
        // return st.size();

        //O(nlong n) nlogn + n but space O(n)

        int f=0;
        double prev=0;
        for(auto c:cars){
            double time=(double)(target-c.first)/c.second;
            if(time>prev){
                f++;
                prev=time;
            }
        }
        return f;
        //(nlog n) + O(1) space
    }
};
