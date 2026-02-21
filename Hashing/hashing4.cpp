#include<bits/stdc++.h>
using namespace std;
//function to count frequency of each element in the array using unordered_map
void frequency(int arr[], int n){
  unordered_map<int, int> mpp;

  for(int i = 0; i < n; i++){
    mpp[arr[i]]++;
  }

  for(auto it : mpp){
    cout << it.first << "->" << it.second << endl;
  }
}

//function to count highest and lowest frequency element in an array using unordered map
void frequency1(int arr[], int n){
  unordered_map<int, int> mpp;
  
  for(int i = 0; i < n; i++){
    mpp[arr[i]]++;
  }

  int maxFreq = 0, minFreq = n;
  int maxEle = 0, minEle = 0;

  // find highest and lowest frequency
  for(auto it : mpp){
    if(it.second > maxFreq){
      maxFreq = it.second;
      maxEle = it.first;
    }
    if(it.second < minFreq){
      minFreq = it.second;
      minEle = it.first;
    }
  }

  cout << "Highest Frequency Element: " << maxEle << " (Frequency: " << maxFreq << ")" << endl;cout << "Lowest Frequency Element: " << minEle << " (Frequency: " << minFreq << ")" << endl;
}

int main(){
  int arr[] = {1,2,1,3,4};
  int n = 5;
  // frequency(arr, n);
  frequency1(arr, n);
  return 0;
}