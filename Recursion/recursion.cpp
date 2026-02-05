#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
void print(){
  if(cnt == 3) return;  //base condition
  cout << cnt << endl;
  cnt++;
  print(); //recursive call
}
