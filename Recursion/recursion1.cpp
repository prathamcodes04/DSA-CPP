#include<bits/stdc++.h>
using namespace std;

void printName(string name, int N, int count){
  if(count == N) return; //base case

  cout << name << endl;
  printName(name, N, count + 1); //recursive call
}

void printonetoN(int N, int count){
  if(count > N) return;

  cout << count << endl;
  printonetoN(N, count + 1);
}

void printNtoone(int current){
  if(current < 1) return;
  cout << current << " ";
  printNtoone(current - 1); //recursive call with next small number

  //backward tracking
  // printNtoone(current - 1);
  // cout << current << " ";
}

//parameterized way
void sumNP(int sum, int n){
  if(n < 1){
    cout << sum << endl;
    return;
  }
  sumNP(sum + n, n - 1);
}

//functional way
int sumNF(int n) {
  if(n == 0) return 0;
  return n + sumNF(n-1);
}

//functional way
int factorialF(int n){
  if(n == 0) return 1;
  return n * factorialF(n-1);
}

void reverseOnePointer(int arr[], int n, int i){
  if(i >= n/2) return;
  swap(arr[i], arr[n-i-1]);
  reverseOnePointer(arr, n, i + 1);
}

void reverseTwoPointer(int arr[], int l, int r){
  if(l >= r) return;
  swap(arr[l], arr[r]);
  reverseTwoPointer(arr, l+1, r-1);
}

bool checkStringPalindrome(int i, string &name){
  if(i >= name.size() / 2) return true;
  if(name[i] != name[name.size() - i - 1]) return false;
  return checkStringPalindrome(i+1, name);
}

int main(){
  // string name = "Pratham";
  // int N = 3;
  // printName(name, N, 0);
  // printonetoN(N, 1);
  // printNtoone(N);
  // sumN(0, N);
  // cout << sumNF(N);
  // cout << factorialF(N);

  // int arr[] = {1,2,3,4,5};
  // int n = sizeof(arr)/sizeof(arr[0]);
  // reverseOnePointer(arr, n, 0);
  // reverseTwoPointer(arr, 0, n-1);
  // for(int x : arr) cout << x << " ";  

  string name = "madam";
  // string name = "hello";
  cout << checkStringPalindrome(0, name);
  return 0;
}