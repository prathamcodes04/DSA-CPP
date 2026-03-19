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

int majorityelement(int n, int arr[]){
   //brute force
   // for(int i = 0; i < n; i++){
   //    int cnt = 0;
   //    for(int j = 0; j < n; j++){
   //       if(arr[j] == arr[i]){ //count only matching elements
   //          cnt++;
   //       }
   //    }
   //    if(cnt > n/2){
   //       return arr[i];
   //    }
   // }
   // return -1; //if no majority element found

   //better approach (hashing)
   // unordered_map<int, int> mp;
   // for(int i = 0; i < n; i++){ //count frequency
   //    mp[arr[i]]++;
   // }
   // //check for majority element
   // for(auto it : mp){
   //    if(it.second > n/2){
   //       return it.first;
   //    }
   // }

   //optimal approach (moore's voting algorithm)
   int cnt = 0; 
   int el;
   for(int i = 0; i < n; i++){
      if(cnt == 0){
         cnt = 1;
         el = arr[i];
      }
      else if(arr[i] == el){
         cnt++;
      }
      else{
         cnt--;
      }
   }
   int cnt1 = 0;
   for(int i = 0; i < n; i++){
      if(arr[i] == el) cnt1++;
   }
   if(cnt1 > n/2){
      return el;
   }
   return -1;
}

int main(){
   int n = 7;
   int arr[n] = {2,2,3,3,1,2,2};
   cout << majorityelement(n, arr);
   // int arr[n] = {0,1,2,0,1,2,1,2,0,0,0,1};
   // sort0s1s2s(n, arr);
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