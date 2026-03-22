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
/*
int maxsubarraysum(int n, int arr[]){
   //brute force
   // int max_num = INT_MIN;
   // for(int i = 0; i < n; i++){
   //    for(int j = i; j < n; j++){
   //       int sum = 0;
   //       for(int k = i; k <= j; k++){
   //          sum += arr[k];
   //       }
   //       max_num = max(sum, max_num);
   //    }
   // }
   // return max_num;

   //better approach -  remove k loop
   // int maxNum = INT_MIN;
   // for(int i = 0; i < n; i++){
   //    int sum = 0;
   //    for(int j = i; j < n; j++){
   //       sum += arr[j];
   //       maxNum = max(sum, maxNum);
   //    }
   // }
   // return maxNum;

   //optimal approach (kadane's algorithm)
   // int sum = 0;
   // int maxNum = INT_MIN;
   // for(int i = 0; i < n; i++){
   //    sum += arr[i];
   //    maxNum = max(sum, maxNum);
   //    if(sum < 0){
   //       sum = 0;
   //    }
   // }
   // return maxNum;
}
*/
vector<int> maxsubarraysum(int n, int arr[]){
   int sum = 0;
   int maxsum = INT_MIN;
   int start = 0;
   int ansStart = -1;
   int ansEnd = -1;

   for(int i = 0; i < n; i++){
      if(sum == 0) start = i;
      sum += arr[i];
      if(sum > maxsum){
         maxsum = sum;
         ansStart = start;
         ansEnd = i;
      }
      if(sum < 0){
         sum = 0;
      }
   }
   vector<int> result;
   for(int i = ansStart; i <= ansEnd; i++){
      result.push_back(arr[i]);
   }
   return result;
}

int buynsellstock(int n, int arr[]){
   
}

int main(){
   int n = 6;
   int arr[n] = {7,1,5,3,6,4};
   cout << buynsellstock(n, arr);
   // int arr[n] = {-2,-3,4,-1,-2,1,5,-3};
   // cout << majorityelement(n, arr);
   // cout << maxsubarraysum(n, arr);
   // vector<int> result = maxsubarraysum(n, arr);
   // for(auto it : result){
   //    cout << it << " ";
   // }
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