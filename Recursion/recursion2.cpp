//multiple recursion calls

#include<bits/stdc++.h>
using namespace std;

int fibonaci(int n){
  if(n <= 1) return n;
  int last = fibonaci(n-1);
  int slast = fibonaci(n-2);
  return last + slast;
}

void printSubsequences(int idx, vector<int> &ds, int arr[], int n){
  if(idx == n){
    for(auto it : ds){
      cout << it << " ";
    }
    cout << endl;
    return;
  }
  //take the element
  ds.push_back(arr[idx]);
  printSubsequences(idx + 1, ds, arr, n);

  //not take the element
  ds.pop_back();
  printSubsequences(idx + 1, ds, arr, n);
}

int main(){
  // cout << fibonaci(5);
  // cout << fibonaci(0);
  int arr[] = {3,1,2};
  int n = 3;
  vector<int> ds;
  printSubsequences(0, ds, arr, n);
  return 0;
}