// T.C - O(lon n)
//........................Leetcode Hard Question.....................//

//    sort(nums.begin(),nums.end());
    //    int count =0;
    //    for(int i=0; i<nums.size()-1; i++) {
    //        if(nums[i] + 1 != nums[i+1]){
    //            count += nums[i+1] - nums[i] -1;
    //        }
           
    //   }

 int  s = nums.size()-1; //max size of sliding window is the target gap between min and max elements
    sort(nums.begin(), nums.end()); //sorting o(n log n) time so that we can remove duplicates over the array
    int newlen = unique(nums.begin(), nums.end()) - nums.begin(); // remove adjacent duplicates with STL unique
    int l =0, r=0, fin = 1; // initialize leftand right pointers and the minimize elements in the window 
    while( r < newlen){  // iterate over the unique array
        if( l == r)
            r++; // if the window is closed, open it
        else if (nums[r] - nums[l] > s)
            l++;  // if  window becomes bigger than allowed size, shrink it
        else{
            fin = max(fin, r- l+1); //if window is in allowed size, maximize the number of elements in the winow
            r++; // slide the right side
        }
    }
    return s - fin +1; // return the missing eleemts in that window
    }
};
