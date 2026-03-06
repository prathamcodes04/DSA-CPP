#include<bits/stdc++.h>
using namespace std;

void practice(int arr[], int n, int k){
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
   k = k % n;
   vector<int> temp;
   //put k elements in temp
   for(int i = 0; i < k; i++){
      temp.push_back(arr[i]);
   }
   //shift remianing elements to left 
   for(int i = k; i < n; i++){
      arr[i-k] = arr[i];
   }
   //put back elements into array from temp
   for(int i = 0; i < k; i++){
      arr[n-k+i] = temp[i];
   }
   for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
   }
}

int main(){
   int n = 7;
   // int arr[5] = {2,3,5,4,1};
   int arr[7] = {1,1,2,2,2,3,3};
   int k = 10;
   // int arr[1] = {5};
   // int arr[4] = {1,1,1,1};
   // cout << practice(arr, n);
   practice(arr, n, k);
   return 0;
}