/*Soo isme hamne first index and prev_index liya agar hamne take kiya then prev becomes index and index=index+1
if nottake then prev remain same and index+1 and current value should be greater than previous and id there is starting
index that means prev=-1 then we can take and we IMPORATNT:- "if we start from -1 then we have to take the dp[ind][prev+1] to avoid runtime
ERROR and we have to take the extra range of (n+1) because we are considering -1 as 0 that's why!"    */







class Solution {
int maxi(vector<int>& nums,int ind,int prev,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int len=maxi(nums,ind+1,prev,n,dp);     //NOT_TAKE
    if(prev==-1 || nums[ind]>nums[prev]){
        len=max(len,1+maxi(nums,ind+1,ind,n,dp));       //TAKE
    }
    return dp[ind][prev+1]=len;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<vector<int>>dp(n,vector<int>(n+1,-1)); //here we took n+1 range for prev as i mentioned
     return maxi(nums,0,-1,n,dp);
    }
};



// 2nd Tabulation approach 

 int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(dp[i],maxi);
        } 
        return maxi;   
    }



//approach 3
int longestSubsequence(int n, int a[])
    {
      if(n==0){
          return 0;
      }
      vector<int>ans;
      ans.push_back(a[0]);
      for(int i=1;i<n;i++){
          if(a[i]>ans.back()){
              ans.push_back(a[i]);
          }else{
              int ind=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
              ans[ind]=a[i];
          }
      }
      return ans.size();
    }