#include<bits/stdc++.h>
using namespace std;
//find largest element in an array
int largestElement(int arr[], int n){
  int largest = arr[0]; 
  for(int i = 0; i < n; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  return largest;
}

//find second largest element in an array
int secondLargest(int arr[], int n){
  //brute force
  // sort(arr, arr + n);
  // return arr[n-2];

  //better
  // int largest = INT_MIN;
  // int slargest = INT_MIN;
  // for(int i = 0; i < n; i++){
  //    if(arr[i] > largest){
  //       largest = arr[i];
  //    }
  // }
  // for(int i = 0; i < n; i++){
  //    if(arr[i] > slargest && arr[i] != largest){
  //       slargest = arr[i];
  //    }
  // }
  // return slargest;

  //optimal
  int largest = INT_MIN;
  int slargest = INT_MIN;
  for(int i = 1; i < n; i++){
    if(arr[i] > largest){
      slargest = largest;
      largest = arr[i];
    }
    else if(arr[i] < largest && arr[i] > slargest){
      slargest = arr[i];
    }
  }
  return slargest;
}

//find second smallest elemnt
int secondSmallest(int arr[], int n){
  //edge case:  not enough elements eg - [5]
  if(n < 2) return -1;

  int smallest = INT_MAX;
  int ssmallest = INT_MAX;
  for(int i = 0; i < n; i++){
    if(arr[i] < smallest){
      ssmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] > smallest && arr[i] < ssmallest){
      ssmallest = arr[i];
    }
  }

  //no distinct second element
  if(ssmallest == INT_MAX) return -1;
  return ssmallest;
}

//check if the array is sorted
int checkSorted(int arr[], int n){
  for(int i = 1; i < n; i++){
    if(arr[i] < arr[i-1]){
      return false;
    }
  }
  return true;
}

//remove duplicates in sorted array
int removeDuplicates(int arr[], int n){
  if(n == 0) return 0;
  int i = 0; //first unique element
  for(int j = 1; j < n; j++){
    if(arr[j] != arr[i]){
      //take first position
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;//length of unique elements
}

//left rotate the array by one
void rotateleft(int arr[], int n){
  int temp = arr[0]; //storing first element in temp
  for(int i = 1; i < n; i++){
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp; //placing temp at last index
}

//left rotate the array by k places - bruteforce
void leftrotatekplaces(int arr[], int n, int k){
  //to avoid unnecessary rotations
  k = k % n;

  vector<int> temp;

  //storing k elements
  for(int i = 0; i < k; i++){
    temp.push_back(arr[i]);
  }
  //shifting remaining elements to left
  for(int i = k; i < n; i++){
    arr[i - k] = arr[i];
  }
  //copy temp to end
  for(int i = 0; i < k; i++){
    arr[n - k + i] = temp[i];
  }
}

//left rotate the array by K places - optimal solution
void rotateKplaces(int arr[], int n, int k){
  k = k % n;
  reverse(arr, arr + k);
  reverse(arr + k, arr + n);
  reverse(arr, arr + n);
}

//right rotate array by k places
//brute force
// k = k % n;
// vector<int> temp;
// for(int i = n-k; i < n; i++){
//    temp.push_back(arr[i]);
// }
// for(int i = n-k-1; i >= 0; i--){
//    arr[i+k] = arr[i];
// }
// for(int i = 0; i < k; i++){
//    arr[i] = temp[i];
// }
// for(int i = 0; i < n; i++){
//    cout << arr[i] << " ";
// }   
//optimal
// k = k%n;
// reverse(arr, arr+n);
// reverse(arr, arr+k);
// reverse(arr+k, arr+n);
// for(int i = 0; i < n; i++){
//   cout << arr[i] << " ";
// }


//move all zeros to the end of the array 
void moveallzerostoend(int arr[], int n){
  // brute force

  // vector<int> temp;

  // //pick non zero number and put it in temp 
  // for(int i = 0; i < n; i++){
  //   if(arr[i] != 0){
  //     temp.push_back(arr[i]);
  //   }
  // }
  // //put non zero elements in front
  // int nz = temp.size();
  // for(int i = 0; i < nz; i++){
  //   arr[i] = temp[i];
  // }
  // //replacing empty indexes with 0
  // for(int i = nz; i < n; i++){
  //   arr[i] = 0;
  // }

  //optimal solution

  //solution - 1
  //two pointer approach
  // int j = 0;
  // for(int i = 0; i < n; i++){
  //   if(arr[i] != 0){
  //     swap(arr[i], arr[j]);
  //     j++;
  //   }
  // }

  //solution - 2
  //avoid unnecessary swaps which above code does not
  //to store index of 0 element
  int j = -1;

  //finding first 0 element
  for(int i = 0; i < n; i++){
    if(arr[i] == 0){
      j = i;
      break;
    }
  }
  //if their is no zero in array
  if(j == -1) return;

  //moving non zero element forward
  for(int i = j + 1; i < n; i++){
    if(arr[i] != 0){
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

//linear search
int linearsearch(int arr[], int n, int num){
  for(int i = 0; i < n; i++){
    if(arr[i] == num){
      return i;
    }
  }
  return -1; //element not found
}

//union of two arrays
void unionoftwoarrays(int arr1[], int arr2[], int n1, int n2){
  //brute force 

  //define set data structure
  // set<int> st;
  // //inserting first array
  // for(int i = 0; i < n1; i++){
  //   st.insert(arr1[i]);
  // }
  // //insert second array
  // for(int i = 0; i < n2; i++){
  //   st.insert(arr2[i]);
  // }
  // //print union
  // for(auto it : st){
  //   cout << it << " ";
  // }

  //optimal approach
  int i = 0; //pointer for arr1
  int j = 0; //pointer for arr2
  vector<int> unionarr; //storing union elements
  while(i < n1 && j < n2){ //run untill one array finishes
    //pass smaller element first and check for duplicates
    if(arr1[i] <= arr2[j]){
      //to avoid duplicates
      //if vector is empty insert
      //it last inserted element is not equal insert
      //if equal skip
      if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
        unionarr.push_back(arr1[i]);
      }
      i++;
    }
    else{
      if(unionarr.size() == 0 || unionarr.back() != arr2[j]){
        unionarr.push_back(arr2[j]);
      }
      j++;
    }
  }
  //remaining elements of arr1 if arr2 gets exhausted
  while(i < n1){
    if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
      unionarr.push_back(arr1[i]);
    }
    i++;
  }
  //remaining elements of arr2 if arr1 gets exhausted
  while(j < n2){
    if(unionarr.size() == 0 || unionarr.back() != arr2[j]){
      unionarr.push_back(arr2[j]);
    }
    j++;
  }
  //printing union array
  for(auto it : unionarr){
    cout << it << " ";
  }
}

//intersection of two arrays
void intersectionoftwoarrays(int arr1[], int arr2[], int n1, int n2){
  //bruteforce
  // vector<int> ans;
  // int vis[n2] = {0};
  // for(int i = 0; i < n1; i++){
  //   for(int j = 0; j < n2; j++){
  //     if(arr1[i] == arr2[j] && vis[j] == 0){
  //       ans.push_back(arr1[i]);
  //       vis[j] = 1;
  //       break;
  //     }
  //     if(arr2[j] > arr1[i]) break;
  //   }
  // }
  // for(auto it : ans){
  //   cout << it << " ";
  // }

  //optimal solution
  int i = 0; 
  int j = 0;
  vector<int> ans;

  while(i < n1 && j < n2){
    if(arr1[i] < arr2[j]){
      i++;
    }
    else if(arr2[j] < arr1[i]){
      j++;
    }
    else{
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  for(auto it : ans){
    cout << it << " ";
  }
}

//finding missing number in an array
int missingnum(int arr[], int n){
  //brute force

  //check every number from 0 to n-1
  // for(int i = 0; i < n; i++){
    // //assumng if current i number is not found
    // int flag = 0;
    // //traversing entire array 
    // for(int j = 0; j < n; j++){
    //   //checking if i exists
    //   if(arr[j] == i){
    //     //marking it found if exists
    //     flag = 1;
    //     break;
    //   }
    // }
    // //if not exists reutrn i
    // if(flag == 0) return i;
  // }

  //better approach
  //using hashing 
  
  //create a hash array
  // int hash[n+1] = {0};

  // //traverse original array
  // for(int i = 0; i < n; i++){
  //   //marking present number as 1
  //   hash[arr[i]] = 1;
  // }

  // //now checking 0 to n in hash array
  // for(int i = 0; i <= n; i++){
  //   //checking if number not marked
  //   if(hash[i] == 0){
  //     return i;
  //   }
  // }

  //optimal solution

  //using XOR

  // int xor1 = 0; //to store xor of elements from 0 to n
  // int xor2 = 0; //to store xor of array elements
  // for(int i = 0; i < n-1; i++){ //array has one missing element so n-1
  //   xor2 = xor2 ^ arr[i]; //xor of all array elements
  //   xor1 = xor1 ^ (i+1); //xor of numbers from 0 to n
  // }
  // xor1 = xor1 ^ n; //include n in xor
  // return xor1 ^ xor2; //return missing number

  //using sum

  int totalsum = (n*(n+1))/2;
  int arrsum = 0;
  for(int i = 0; i < n; i++){
    arrsum += arr[i];
  }
  return totalsum - arrsum;
}

//mamximum consecutive ones
int maxones(int arr[], int n){
  int maxi = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] == 1){
      cnt++;
      maxi = max(maxi, cnt);
    }else{
      cnt = 0;
    }
  }
  return maxi;
}

//find the number that appears once, and the other numbers twice
int oncetwice(int arr[], int n){
  //brute force

  // for(int i = 0; i < n; i++){
  //   int number = arr[i];
  //   int cnt = 0;
  //   for(int j = 0; j < n; j++){
  //     if(arr[j] == number){
  //       cnt++;
  //     }
  //   }
  //   if(cnt ==  1) return number;
  // }

  //better approach
  //using hashing

  //finding maximum value in array
  // int maxi = arr[0];
  // for(int i = 0; i < n; i++){
  //   maxi = max(maxi, arr[i]);
  // }
  // //initialize hash array and counting frequencies of each element
  // vector<int> hash(maxi + 1, 0);
  // for(int i = 0; i < n; i++){
  //   hash[arr[i]]++;
  // }
  // //find element that occurs exactly once
  // for(int i = 0; i < n; i++){
  //   if(hash[arr[i]] == 1){
  //     return arr[i];
  //   }
  // }
  // //return -1 if element not found
  // return -1;

  //optimal solution - using XOR

  int xr = 0;
  for(int i = 0; i < n; i++){
    xr = xr ^ arr[i];
  }
  return xr;
}

//longest subarray with sum k (positives)
int longestSubarray(int arr[], int n, int k){
  //brute force
  // int maxLength = 0;
  // for(int i = 0; i < n; i++){
  //   for(int j = i; j < n; j++){
  //     int sum = 0;
  //     for(int l = i; l <= j; l++){
  //       sum += arr[l];
  //     }
  //     if(sum == k){
  //       maxLength = max(maxLength, j - i + 1);
  //     }
  //   }
  // }
  // return maxLength;

  //second brute force approach we reduce 1 loop and improve time complexity to o(n^2)

  // int maxlength = 0;
  // for(int i = 0; i < n; i++){
  //   int sum = 0;
  //   for(int j = i; j < n; j++){
  //     sum += arr[j];
  //     if(sum == k){
  //     maxlength = max(maxlength, j - i + 1);
  //     }
  //   }
  // }
  // return maxlength;

  //better solution using hashing
  // unordered_map<int, int> mp;
  // int sum = 0;
  // int maxlen = 0;
  // for(int i = 0; i < n; i++){
  //   sum += arr[i];
  //   //from 0 to i index
  //   if(sum == k){
  //     maxlen = i + 1;
  //   }
  //   //subarray in middle
  //   if(mp.find(sum - k) != mp.end()){
  //     int len = i - mp[sum - k];
  //     maxlen = max(maxlen, len);
  //   }
  //   //store first occurence only
  //   if(mp.find(sum) == mp.end()){
  //     mp[sum] = i;
  //   }
  // }
  // return maxlen;

  //optimal solution - two pointer approach
  int left = 0;
  int right = 0;
  int sum = arr[0];
  int maxlen = 0;
  while(right < n){
    while(left <= right && sum > k){
      sum -= arr[left];
      left++;
    }
    if(sum == k){
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
    if(right < n) sum += arr[right];
  }
  return maxlen;
}


int main(){
  int n = 10;
  int arr[10] = {1,2,3,1,1,1,1,4,2,3};
  int k = 6;
  // int arr[7] = {1,1,2,3,3,4,4};
  // cout << oncetwice(arr, n);
  cout << longestSubarray(arr, n, k);
  // int arr[9] = {1,1,0,1,1,1,0,1,1};
  // cout << maxones(arr, n);
  // int arr[5] = {1,2,4,5};
  // cout << missingnum(arr, n);
  // int n1 = 6;
  // int n2 = 6;
  // int arr1[n1] = {1,1,2,3,4,5};
  // int arr2[n2] = {2,3,4,4,5,6};
  // unionoftwoarrays(arr1, arr2, n1, n2);
  // intersectionoftwoarrays(arr1, arr2, n1, n2);

  // int n = 5;
  // int arr[5] = {6,7,8,4,1};
  // int num = 4;
  // cout << linearsearch(arr, n, num);
  // int n = 10;
  // int arr[10] = {1,0,2,3,2,0,0,4,5,1};
  // moveallzerostoend(arr, n);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  // int n = 7;
  // int arr[7] = {1,2,3,4,5,6,7};
  // int k = 3;
  // leftrotatekplaces(arr, n, k);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  // int n = 5; 
  // int n = 7; 
  // int n = 4;
  // int n = 1;
  // int arr[5] = {1,2,3,4,5}; 
  // int arr[5] = {5,3,1,2,4}; 
  // int arr[7] = {1,1,2,2,2,3,3}; 
  // int arr[4] = {1,1,1,1}; 
  // int arr[1] = {1};
  // cout << largestElement(arr, n);
  // cout << secondLargest(arr, n);
  // cout << secondSmallest(arr, n);
  // cout << checkSorted(arr, n);
  // int len = removeDuplicates(arr, n);
  // cout << "Length of array after removing duplicated: " << len;
  // cout << endl;
  // rotateleft(arr, n);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }

  //for rotate by k places
  // int n;
  // cin >> n;
  // int arr[n];
  // for(int i = 0; i < n; i++){
  //   cin >> arr[i];
  // }
  // int k;
  // cin >> k;
  // rotateKplaces(arr, n, k);t
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  return 0;
}