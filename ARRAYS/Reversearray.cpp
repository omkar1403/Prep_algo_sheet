
//APPROACH1 
void rotate(vector<int>& nums, int k) {
     k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
 }

//APPROACH2
  void rotate(vector<int>& nums, int k) {
    int n=nums.size();
     vector<int>ans;
    
    int j=0;
    k=k%n;
    for(int i=n-k;i<n;i++){
        ans.push_back(nums[i]);
    }
    for(int i=0;i<n-k;i++){
        ans.push_back(nums[i]);
    }
  
    for(int i=0;i<n;i++){
        if(i<n-k){
        nums[i+k]=ans[i+k];
        }else{
            nums[j]=ans[j];
            j++;
        }
    }
    

 }