	//https://www.youtube.com/watch?v=H7tshfFTSvw          refer this video
    
    ll countStrings(int n) {
	   if(n<=0){
	       return 0;
	   }
	  int oneend=1;
	  int zeroend=1;
	  int sum=oneend+zeroend;
	  if(n==1){
	      return sum;
	  }
	  int i=2;  
	  while(i<=n){
	      oneend=(zeroend)%1000000007; //onend ko zeroend kar do becuase zeroend me lagne pe hame vo series mil jati hai
	      zeroend=(sum)%1000000007;  //aur previous sum ko zero kar do because 0's ko add karne me last me vo bhi previous sum ke equal ban jate hai
	      sum=(oneend+zeroend)%1000000007;
	      i++;
	  }
	  return (sum)%1000000007;   //return the sum
	}