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

int main(){
  string name = "Pratham";
  int N = 3;
  // printName(name, N, 0);
  // printonetoN(N, 1);
  // printNtoone(N);
  // sumN(0, N);
  cout << sumNF(N);
  return 0;
}