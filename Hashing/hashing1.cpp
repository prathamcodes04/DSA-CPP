#include<bits/stdc++.h>
using namespace std;

int countDup(int num, int arr[], int n){
  int count = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] == num){
      count = count + 1;
    }
  }
  return count;
}

int main(){
  int num = 1;
  int arr[] = {1,2,1,3,2};
  int n = 5;
  cout << countDup(num, arr, n);
  return 0;
}