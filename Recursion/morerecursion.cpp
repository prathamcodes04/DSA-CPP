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

void printNtoone(int count){
  if(count < 1) return;
  cout << count << endl;
  printNtoone(count - 1);
}

int main(){
  string name = "Pratham";
  int N = 5;
  // printName(name, N, 0);
  // printonetoN(N, 1);
  printNtoone(N);
  return 0;
}