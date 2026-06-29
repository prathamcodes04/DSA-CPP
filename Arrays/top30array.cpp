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

//second largest element in an array
int secondLargestElement(vector<int>& arr){
    //brute force - sorting
    // sort(arr.begin(), arr.end());
    // return arr[arr.size() - 2];

    //better solution - first find largest then find second largest
    // int largest = INT_MIN;
    // int slargest = INT_MIN;
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] > largest){
    //         largest = arr[i];
    //     }
    // }
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] > slargest && arr[i] != largest){
    //         slargest = arr[i];
    //     }
    // }
    // return slargest;

    //optimal solution using else if, one pass 
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    vector<int> arr = {2,5,1,3,0};
    cout << secondLargestElement(arr);
    return 0;
}