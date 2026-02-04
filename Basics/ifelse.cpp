#include <bits/stdc++.h>
using namespace std;
int main(){
    //wap that takes input of an age
    //and prints if you are adult or not

    // int age;
    // cin >> age;
    // if(age >= 18){
    //     cout<<"You are an adult";
    // }else if(age < 18){
    //     cout<<"You are not an adult";
    // }else{
    //     cout << "alien";
    // }
    // return 0;

    /*
    A school has follwing rules for grading systems
    a. below 25 - F
    b. 25 to 44 - E
    c. 45 to 49 - D
    d. 50 to 59 - C
    e. 60 to 79 - B
    f. 80 to 100 - A
    Ask user to enter marks and print the corresponding grade.
    */
    // int marks;
    // cin >> marks;
    // if(marks < 25){
    //     cout << "F";
    // }else if(marks >= 25 && marks <= 44){
    //     cout << "E";
    // }else if(marks >= 45 && marks <= 49){
    //     cout << "D";
    // }else if(marks >= 50 && marks <= 59){
    //     cout << "C";
    // }else if(marks >= 60 && marks <= 79){
    //     cout << "B";
    // }else if(marks >= 80 && marks <= 100){
    //     cout << "A";
    // }

    //efficient way of writing above code
    // int marks;
    // cin >> marks;
    // if(marks < 25){
    //     cout << "F";
    // }else if(marks <= 44){
    //     cout << "E";
    // }else if(marks <= 49){
    //     cout << "D";
    // }else if(marks <= 59){
    //     cout << "C";
    // }else if(marks <= 79){
    //     cout << "B";
    // }else if(marks <= 100){
    //     cout << "A";
    // }

    /*
    take age from the user and then decide accordingly
    1. if age < 18
       print -> not eligible for job
    2. if age >= 18 and age <= 54
       print -> eligible for job
    3. if age >= 55 and age <= 57
       print -> eligiblE for job, but retirement soon.
    4. if age > 57
       print -> retirement time
    */
    int age;
    cin >> age;
    if(age < 18){
        cout << "not eligible for job";
    }
    //NESTED IF >= 18
    else if(age <= 57){
        cout << "eligible for job";
        if(age >= 55){
        cout << " ,but retirement soon";
    }
    }
    else if(age > 57){
        cout << "retirement time";
    }
    return 0;
   
}

