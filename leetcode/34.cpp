// Code Golf :)
struct Solution{vector<int>searchRange(vector<int>&n,int t){auto b=n.begin(),e=n.end(), x=lower_bound(b,e,t);if(x==e||*x!=t)return{-1,-1};return{x-b,upper_bound(b,e,t)-b-1};}};
