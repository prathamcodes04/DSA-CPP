//leetcode 
/*
912. Sort an Array
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high){
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  while(left <= mid && right <= high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left++]);
    }else{
      temp.push_back(arr[right++]);
    }
  }
  while(left <= mid){
    temp.push_back(arr[left++]);
  }
  while(right <= high){
    temp.push_back(arr[right++]);
  }
  for(int i = low; i <= high; i++){
    arr[i] = temp[i - low];
  }
}
void mergeSort(int arr[], int low, int high){
  if(low >= high) return;
  int mid = (low + high)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}
int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  mergeSort(arr, 0, n-1);
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}