#include<bits/stdc++.h>
using namespace std;

//largest element in an array
int largestElement(vector<int>& arr){
    // burteforce 
    // sort(arr.begin(), arr.end()); //o(n logn)
    // return arr[arr.size() - 1];

    //optimal solution - traversing
    // int largest = arr[0];
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] > largest){
    //         largest = arr[i];
    //     }
    // }
    // return largest;
}

int main(){
    vector<int> arr = {2,5,1,3,0};
    cout << largestElement(arr);
    return 0;
}