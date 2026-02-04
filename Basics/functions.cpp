// #include<bits/stdc++.h>
// using namespace std;
//functions are set of code which performs something for you
//functions are used to modularise code
//functions are used to increase readability
//functions are used to use same code multiple times
//types of funcitons - void, return, parameterised and non-parameterised

// void printName(string name){  //heer name is a parameter
//     cout << "hey " << name << endl;
// }
// int main(){
//     string name;
//     cin >> name;
//     //void functions - does not return anything
//     printName(name);

//     //reuseability of code
//     string name2;
//     cin >>  name2;
//     printName(name2);
//     return 0;
// }


//take two numbers and print its sum

#include<bits/stdc++.h>
using namespace std;

// int sum(int num1, int num2){
//     int num3 = num1 + num2; // 4 + 5
//     return num3;
// }

// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     int res = sum(num1, num2); //calling function
//     cout << res;
//     return 0;
// }

//using void
// void sum(int num1, int num2){
//     int num3 = num1 + num2;
//     cout << num3;
// }
// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     sum(num1, num2);
//     return 0;
// }

// //inbuilt funcitons max and min
// int minn(int num1, int num2){
//     if(num1 >= num2) return num1;
//     // else return num2;
// }

// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     int minimum = minn(num1, num2);  //max <-> min
//     cout << minimum;
//     return 0;
// }

//pass by value - orginal remains same at one place, but its copies are
//forwaded to execute the progam 
// void modify(int a) {
//     a = a + 10;
// }

// int main() {
//     int x = 5;
//     modify(x);
//     cout << x << endl; // Output: 5
//     return 0;
// }

//pass sby reference - get orginal  
#include <iostream>
using namespace std;

void modify(int &a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; // Output: 15
    return 0;
}