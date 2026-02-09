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

void printSubsequencesSumK(int i, int arr[], int n, vector<int> &ds, int sum, int k){
  if(i == n){
    if(sum == k){
      for(auto it : ds) cout << it << " ";
      cout << endl;
    }
    return;
  }
  ds.push_back(arr[i]);
  sum += arr[i];
  printSubsequencesSumK(i + 1, arr, n, ds, sum, k); //pick

  sum -= arr[i];
  ds.pop_back(); 
  printSubsequencesSumK(i + 1, arr, n, ds, sum, k); //not pick
}

//to print any one sequence
//using boolean
bool printSubsequencesSumKcase2(int i, int arr[], int n, vector<int> &ds, int sum, int k){
  if(i == n){
    //condtion satisfied
    if(sum == k){
      for(auto it : ds) cout << it << " ";
      cout << endl;
      return true;
    }
    //condition not satisfied
    return false;
  }
  ds.push_back(arr[i]);
  sum += arr[i];
  if(printSubsequencesSumKcase2(i + 1, arr, n, ds, sum, k) == true){ //pick element
    return true;
  }

  sum -= arr[i];
  ds.pop_back(); 
  if(printSubsequencesSumKcase2(i + 1, arr, n, ds, sum, k) == true){ //not pick(backtrack)
    return true;
  }

  return false;
}


int main(){
  // cout << fibonaci(5);
  // cout << fibonaci(0);
  // int arr[] = {3,1,2};
  int arr[] = {1,2,1};
  int n = 3;
  vector<int> ds;
  // printSubsequences(0, ds, arr, n);
  int k = 2;
  // printSubsequencesSumK(0, arr, n, ds, 0, k);
  printSubsequencesSumKcase2(0, arr, n, ds, 0, k);
  return 0;
}