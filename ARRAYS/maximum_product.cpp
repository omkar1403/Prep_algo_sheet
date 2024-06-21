/*isme IMPORTANT ye hai ki we have to traverse from both the sides to get the maximum product*/


 int maxProduct(vector<int>& nums) {
        long long maxi=INT_MIN;
        long long product=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(product*nums[i]>=INT_MAX || product*nums[i]<=INT_MIN){   //if it is crossing maximum limit then then make it 1
                product=1;
            }
            product*=nums[i];
            maxi=max(maxi,product); 
            if(product==0){   //if it is 0 then make it 1
                product=1;
            }
        }
        product=1;  //initialize the product again
        for(int i=n-1;i>=0;i--){  //traverse from right to left also and made it 1
             if(product*nums[i]>=INT_MAX || product*nums[i]<=INT_MIN){ //if it is 1 exceding limit then make it one
                product=1;
            }
            product*=nums[i];
            maxi=max(maxi,product);
            if(product==0){
                product=1;
            }
        }

   
return maxi;