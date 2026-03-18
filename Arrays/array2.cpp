#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(int n, int arr[], int target){
   //brute force
   // for(int i = 0; i < n; i++){
   //    for(int j = i + 1; j < n; j++){
   //       if(arr[i] + arr[j] == target){
   //          return {i, j};
   //       }
   //    }
   // }
   // return {};

   //better solution
   // unordered_map<int, int> mp;
   // for(int i = 0; i < n; i++){
   //    int num = arr[i];
   //    int moreNeeded = target - num;
   //    if(mp.find(moreNeeded) != mp.end()){
   //       return {mp[moreNeeded], i};
   //    }
   //    mp[num] = i;
   // }
   // return {-1, -1};

   //optimal
}

void sort0s1s2s(int n, int arr[]){
   //brute force using sorting
   // sort(arr, arr + n);
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

   //better approach using counting
   // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] == 0) cnt0++;
   //    else if(arr[i] == 1) cnt1++;
   //    else cnt2++;
   // }
   // int i = 0; //reset index to overwrite array
   // while(cnt0--) arr[i++] = 0;
   // while(cnt1--) arr[i++] = 1;
   // while(cnt2--) arr[i++] = 2;
   // for(int i = 0; i < n; i++){
   //    cout << arr[i] << " ";
   // }

   //optimal solution using dutch national flag algorithm
   int low = 0, mid = 0, high = n - 1;
   while(mid <= high){
      if(arr[mid] == 0){
         swap(arr[mid], arr[low]);
         low++;
         mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{
         swap(arr[mid], arr[high]);
         high--;
      }
   }
   for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
   }
}

int main(){
   int n = 12;
   int arr[n] = {0,1,2,0,1,2,1,2,0,0,0,1};
   sort0s1s2s(n, arr);
   // int arr[n] = {2,6,5,8,11};
   // int target = 14;
   // vector<int> result = twosum(n, arr, target);
   // if(result.size() == 2){
   //    cout << result[0] << " " << result[1];
   // }else{
   //    cout << "No solution found";
   // }
   return 0;
}