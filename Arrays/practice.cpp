#include<bits/stdc++.h>
using namespace std;
/*
void practice(int arr[], int n){
   //largest element

   //brute force
   // sort(arr, arr + n);
   // return arr[n-1];

   //optimal
   // int largest = INT_MIN;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] > largest){
   //       largest = arr[i];
   //    }
   // }
   // return largest;


   //second largest element
   
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
   // int largest = INT_MIN;
   // int slargest = INT_MIN;
   // if(n < 2) return -1;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] > largest){    
   //       slargest = largest;
   //       largest = arr[i];
   //    }
   //    else if(arr[i] > slargest && arr[i] < largest){
   //       slargest = arr[i];
   //    }
   // }
   // if(slargest == INT_MIN) return -1;
   // return slargest;


   //second smallest

   //optimal
   // int smallest = INT_MAX;
   // int ssmallest = INT_MAX;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] < smallest){
   //       ssmallest = smallest;
   //       smallest = arr[i];
   //    }
   //    else if(arr[i] > smallest && arr[i] < ssmallest){
   //       ssmallest = arr[i];
   //    }
   // }
   // return ssmallest;


   //check if array is sorted or not

   //optimal
   // for(int i = 0; i < n; i++){
   //    if(arr[i] < arr[i-1]){
   //       return false;
   //    }
   // } 
   // return true;

   
   //remove duplicates if array is sorted
   
   //brute force
   // set<int> st;
   // for(int i = 0; i < n; i++){
   //    st.insert(arr[i]);
   // }
   // int index = 0;
   // for(auto it : st){
   //    arr[index] = it;
   //    index++;
   // }
   // for(int i = 0; i < index; i++){
   //    cout << arr[i] << " ";
   // }

   //optimal
   // int i = 0;
   // for(int j = 1; j < n; j++){
   //    if(arr[j] != arr[i]){
   //       arr[i+1] = arr[j];
   //       i++;
   //    }
   // }
   // for(int k = 0; k <= i; k++){
   //    cout << arr[k] << " ";
   // }


   //left rotate the array by one place

   //optimal
   // int temp = arr[0];
   // for(int i = 1; i < n; i++){
   //    arr[i-1] = arr[i];
   // }
   // arr[n-1] = temp;
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }


   //left rotate array by k places
   
   //brute force
   // k = k % n;
   // vector<int> temp;
   // //put k elements in temp
   // for(int i = 0; i < k; i++){
   //    temp.push_back(arr[i]);
   // }
   // //shift remianing elements to left 
   // for(int i = k; i < n; i++){
   //    arr[i-k] = arr[i];
   // }
   // //put back elements into array from temp
   // for(int i = 0; i < k; i++){
   //    arr[n-k+i] = temp[i];
   // }
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

   //optimal
   // k = k%n;
   // reverse(arr, arr+k);
   // reverse(arr+k, arr+n);
   // reverse(arr, arr+n);
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

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
   //    cout << arr[i] << " ";
   // }

   //move all zeros to the end of the array

   //brute force

   // vector<int> temp;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] != 0){
   //       temp.push_back(arr[i]);
   //    }
   // }
   // for(int i = 0; i < temp.size(); i++){
   //    arr[i] = temp[i];
   // }
   // for(int i = temp.size(); i < n; i++){
   //    arr[i] = 0;
   // }
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

   //optimal solution

   // int j = 0; 
   // for(int i = 0; i < n; i++){
   //    if(arr[i] != 0){
   //       swap(arr[i], arr[j]);
   //       j++;
   //    }
   // }
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

   //solution 2
   // int j = -1;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] == 0){
   //       j = i;
   //       break;
   //    }
   // }
   // if(j == -1) return;
   // for(int i = j+1; i < n; i++){
   //    if(arr[i] != 0){
   //       swap(arr[i], arr[j]);
   //       j++;
   //    }
   // }
   // for(int i = 0; i< n; i++){
   //    cout << arr[i] << " ";
   // }

   //union of two arrays

}
*/
/*
int practice(int arr1[], int n1){
   //linear search
   // for(int i = 0; i < n; i++){
   //    if(arr[i] == num){
   //       return i;
   //    }
   // }
   // return -1;

   //finding the missing number
   
   //brute force
   // for(int i = 0; i < n1; i++){
   //    int flag = 0;
   //    for(int j = 0; j < n1; j++){
   //       if(arr1[j] == i){
   //          flag = 1;
   //          break;
   //       }
   //    }
   //    if(flag == 0) return i;
   // }

   //better 
   //using hashing
   // int hash[n1+1] ={0};
   // for(int i = 0; i < n1; i++){
   //    hash[arr1[i]] = 1;
   // }
   // for(int i = 0; i < n1; i++){
   //    if(hash[i] == 0){
   //       return i;
   //    }
   // }

   //optimal 
   // //using xor
   // int xor1 = 0;
   // int xor2 = 0;
   // for(int i = 0; i < n1 - 1; i++){
   //    xor2 = xor2 ^ arr1[i]; // 2
   //    xor1 = xor1 ^ i+1;
   // }
   // xor1 = xor1 ^ n1; // 1
   // return xor1 ^ xor2;
}
*/
/*
void practice(int n1, int n2, int arr1[], int arr2[]){
   //union of two arrays

   //brute force
   // set<int> st;
   // for(int i = 0; i < n1; i++){
   //    st.insert(arr1[i]);
   // }
   // for(int i = 0; i < n2; i++){
   //    st.insert(arr2[i]);
   // }
   // for(auto it : st){
   //    cout << it << " ";
   // }

   //optimal 
   //two pointer approach
   // int i = 0;
   // int j = 0;
   // vector<int> unionarr;
   // while(i < n1 && j < n2){
   //    if(arr1[i] < arr2[j]){
   //       if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
   //          unionarr.push_back(arr1[i]);
   //       }
   //       i++;
   //    }
   //    else{
   //       if(unionarr.size() == 0 || unionarr.back() != arr2[j]){
   //          unionarr.push_back(arr2[j]);
   //       }
   //       j++;
   //    }
   // }
   // while(i < n1){
   //    if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
   //          unionarr.push_back(arr1[i]);
   //       }
   //    i++;
   // }
   // while(j < n2){
   //    if(unionarr.size() == 0 || unionarr.back() != arr2[j]){
   //          unionarr.push_back(arr2[j]);
   //       }
   //    j++;
   // }
   // for(auto it : unionarr){
   //    cout << it << " ";
   // }
}
*/

int practice(int arr1[], int n1, int k){

   //longest subarray

   //brute force

   // int maxlength = 0;
   // for(int i = 0; i < n1; i++){
   //    for(int j = i; j < n1; j++){
   //       int sum = 0;
   //       for(int l = i; l <= j; l++){
   //          sum += arr1[l];
   //       }
   //       if(sum == k){
   //          maxlength = max(maxlength, j - i + 1);
   //       }
   //    }
   // }
   // return maxlength;

   //brute force - 2
   // int maxlength = 0;
   // for(int i = 0; i < n1; i++){
   //    int sum = 0;
   //    for(int j = i; j < n1; j++){
   //       sum += arr1[j];
   //       if(sum == k){
   //          maxlength = max(maxlength, j-i+1);
   //       }
   //    }
   // }
   // return maxlength;

   //better - using hashing
   // unordered_map<int, int> mp;
   // int sum = 0;
   // int maxlen = 0;
   // for(int i = 0; i < n1; i++){
   //    sum += arr1[i];
   //    if(sum == k){
   //       maxlen = i+1;
   //    }
   //    if(mp.find(sum-k) != mp.end()){
   //       int len = i - mp[sum-k];
   //       maxlen = max(maxlen, len);
   //    }
   //    if(mp.find(sum) == mp.end()){
   //       mp[sum] = i;
   //    }
   // }
   // return maxlen;

   //optimal - two pointer approach
   int left = 0;
   int right = 0;
   int sum = arr1[0];
   int maxlen = 0;
   while(right < n1){
      while(left <= right && sum > k){
         sum -= arr1[left];
         left++;
      }
      if(sum == k){
         maxlen = max(maxlen, right - left + 1);
      }
      right++;
      if(right < n1){
         sum += arr1[right];
      }
   }
   return maxlen;
}

int main(){
   int n1 = 10;
   // int n2 = 6;
   int arr1[n1] = {1,2,3,1,1,1,1,4,2,3};
   int k = 3;
   // int arr2[n2] = {2,3,4,4,5,6};
   // int n = 7;
   // int arr[5] = {2,3,5,4,1};
   // int arr[7] = {1,1,2,2,2,3,3};
   // int arr[7] = {1,1,2,2,2,3,3};
   // // int arr[7] = {1,0,2,3,0,4,0};
   // int k = 10;
   // int num = 4;
   // int arr[1] = {5};
   // int arr[4] = {1,1,1,1};
   cout << practice(arr1, n1, k);
   // practice(n1, n2, arr1, arr2);
   return 0;
}