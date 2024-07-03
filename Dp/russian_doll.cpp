static bool comp(vector<int> &a,vector<int>&b){
        if(a[0]==b[0]){   //agar width same hai to fir check karo ki height me difference hai kya else 
            return a[1]>b[1];
        }
        else{  //width same nahi hai to width se push kar do
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
     sort(envelopes.begin(),envelopes.end(),comp);//here we pass the function
        vector<int> temp;
        temp.push_back(envelopes[0][1]);//here we pass the height on which we have to apply LIS
        for(int i=1;i<envelopes.size();i++){
            if(temp.back()<envelopes[i][1]){
                temp.push_back(envelopes[i][1]);//here we have push if it is greater
            }
            else{
                auto ind=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();//else we will find the lowerbound index in which the number can be fit
                temp[ind]=envelopes[i][1];   //here we push the element into the index
            }
        }
        return temp.size();  //return the size
    }