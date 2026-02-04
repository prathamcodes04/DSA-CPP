#include<bits/stdc++.h>
using namespace std;
//give the input is 5
void print1(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print2(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print3(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 0; j < n-i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void print7(int n){
    for(int i = 0; i < n; i++){
        //space
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        //star
        for(int j = 0; j < 2*i+1; j++){
            cout << "*";
        }
        //space
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n){
    for(int i = 0; i < n; i++){
        //space 
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        //star
        for(int j = 0; j < 2*n-(2*i+1); j++){
            cout << "*";
        }
        //space
        for(int j = 0; j < n; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n){
    for(int i = 0; i < n; i++){
        //space 
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        //star
        for(int j = 0; j < 2*i+1; j++){
            cout << "*";
        }
        //space
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        //space 
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        //star
        for(int j = 0; j < 2*n-(2*i+1); j++){
            cout << "*";
        }
        //space
        for(int j = 0; j < n; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n){
    for(int i = 1; i <= 2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j = 1; j <= stars; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print11(int n){
    for(int i = 0; i < n; i++){
        int start = 1;
        if(i % 2 == 0) start = 1; //even line starts with 1
        else start = 0; //odd line starts with 0
        for(int j = 0; j <= i; j++){ //basic triangle line
            cout << start; //starts the line from 1 int start = 1

            start = 1 - start; //this line will flip 1 to 0 and 0 to 1
        }
        cout << endl;
    }
}
void print12(int n){
    int space = 2* (n-1);
    for(int i = 1; i <= n; i++){
        //numbers
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        //space
        for(int j = 1; j <= space; j++){
            cout << " ";
        }

        //numbers
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout <<  endl;
        space -= 2; //mirro the spaces
    }
}
void print13(int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}
void print14(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch <= 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print15(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch <= 'A' + (n-i-1 ); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print16(int n){
    for(int i = 0; i < n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
int main(){
    int t; //t stores number of test cases
    cin >> t; //tells how many times program should run
    for(int i = 0; i < t; i++){
        int n; //n store the input which we wan to give
        cin >> n;
        print16(n);
    }
}
