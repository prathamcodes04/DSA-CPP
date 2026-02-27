#include<bits/stdc++.h>
using namespace std;
//find largest element in an array
int largestElement(int arr[], int n){
  int largest = arr[0]; //assume
  for(int i = 0; i < n; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  return largest;
}

//find second largest element in an array
int secondLargest(int arr[], int n){
  int largest = arr[0];
  int slargest = -1;
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

int main(){
  int n = 5; 
  // int n = 4;
  // int n = 1;
  int arr[5] = {1,2,3,4,5}; 
  // int arr[4] = {1,1,1,1}; 
  int arr[1] = {1};
  // cout << largestElement(arr, n);
  // cout << secondLargest(arr, n);
  cout << secondSmallest(arr, n);
  return 0;
}