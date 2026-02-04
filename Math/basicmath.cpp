#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
  //the number of times the digit is divisible by 10 the number of times the digit are

  //method - 1
  // int count = 0;
  // while(n > 0){
  //   count = count + 1;
  //   n = n / 10; //removes the last digit
  // }
  // return count;

  //method - 2
  int count = int(log10(n) + 1);
  return count;
}
int reverseNumber(int n){
  // int revNum = 0;
  // while(n > 0){
  //   int lastDigit = n % 10;
  //   revNum = (revNum * 10) + lastDigit;
  //   n = n / 10;
  // }
  // return revNum;

  //better format for above code
  int revN = 0;
  while(n > 0){
    int ld = n % 10;
    revN = (revN * 10) + ld;
    n = n / 10;
  }
  return revN;
}
void checkPalindrome(int n){
  int revN = 0;
  int dupN = n;
  while(n > 0){
    int ld = n % 10;
    revN = (revN * 10) + ld;
    n = n / 10;
  }
  if(dupN == revN) cout << "True";
  else cout << "False";
}
void checkArmstrong(int n){
  int sum = 0;
  int dupN = n;
  while(n > 0){
    int ld = n % 10;
    sum = sum + (ld * ld * ld);
    n = n / 10;
  }
  if(dupN == sum) cout << "True";
  else cout << "False";
}
void printAllDivisors(int n){
  // for(int i = 1; i <= n; i++){
  //   if(n % i == 0){
  //     cout << i << " ";
  //   }
  // }

  //another approach for better time complexity
  vector<int> ls;
  for(int i = 1; i <= sqrt(n); i++){
    if(n % i == 0){
      ls.push_back(i);
      if((n/i) != i){
        ls.push_back(n/i);
      }
    }
  }
  sort(ls.begin(), ls.end());
  for(auto it : ls) cout << it << " "; 
}
void checkPrime(int n){
  int cnt = 0;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      cnt++;
      if((n / i) != i) cnt++;
    }
  }
  if(cnt == 2) cout << "True";
  else cout << "False";
}
int gcd(int a, int b){
  while(a > 0 && b > 0){
    if(a > b) a = a % b;
    else b = b % a;
  }
  if(a == 0) return b;
  return a;
}

int main(){
  int a = 20;
  int b = 40;
  // int n = 371;
  // cout << countDigits(n);
  // cout << reverseNumber(n);
  // checkPalindrome(n);
  // checkArmstrong(n);
  // printAllDivisors(n);
  // checkPrime(n);
  cout << gcd(a, b);
  return 0;
}