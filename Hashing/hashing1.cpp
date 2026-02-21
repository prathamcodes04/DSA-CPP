#include<bits/stdc++.h>
using namespace std;

// int countDup(int num, int arr[], int n){
//   int count = 0;
//   for(int i = 0; i < n; i++){
//     if(arr[i] == num){
//       count = count + 1;
//     }
//   }
//   return count;
// }

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  //precompute
  int hash[13] = {0};
  for(int i = 0; i < n; i++){
    hash[arr[i]] += 1;
  }

  int q;
  cin >> q;
  while(q--){
    int number;
    cin >> number;
    //fetch
    cout << hash[number] << endl;
  }
  
  return 0;
}