

 int maxSubArray(vector<int>& nums) {
    int maxi=INT_MIN;
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
       sum=sum+nums[i];
       maxi=max(maxi,sum);
       if(sum<0){  //if negative number is there then sum=0
        sum=0;
       }
    }
      return maxi;  
    }