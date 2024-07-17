 int maxChunksToSorted(vector<int>& arr) {
      int count = 0;
        int max1 = -1;
        int idx = 0;
        while (idx<arr.size()) {
            max1 =max(max1, arr[idx]);  //just find the max
            if (max1==idx){  //if max equal to the length of the array then increament the count
               count++;
            } 
            idx++;
        }
        return count; //return the count
    }