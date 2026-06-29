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
    // int largest = INT_MIN;
    // int slargest = INT_MIN;
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] > largest){
    //         slargest = largest;
    //         largest = arr[i];
    //     }
    //     else if(arr[i] < largest && arr[i] > slargest){
    //         slargest = arr[i];
    //     }
    // }
    // return slargest;
}

//check if array is sorted
bool isSorted(vector<int>& arr){
    //bruteforce
    // for(int i = 0; i < arr.size(); i++){
    //     for(int j = i + 1; j < arr.size(); j++){
    //         if(arr[j] < arr[i]){
    //             return false;
    //         }
    //     }
    // }
    // return true;

    //optimal solution
    // for(int i = 1; i < arr.size(); i++){
    //     if(arr[i] < arr[i-1]){
    //         return false;
    //     }
    // }
    // return true;
}

//remove duplicates from sorted array
int removeDuplicates(vector<int>& arr){
    //bruteforce - using set
    // set<int>st;
    // //inserting element into set
    // for(int x: arr){
    //     st.insert(x);
    // }
    // //copying back into array
    // int index = 0;
    // for(int x: st){
    //     arr[index++] = x;
    // }    
    // return st.size();

    //optimal solution - two pointer approach
    // int i = 0;
    // for(int j = i + 1; j < arr.size(); j++){
    //     if(arr[j] != arr[i]){
    //         arr[i+1] = arr[j];
    //         i++;
    //     }
    // }
    // return i+1;
}

//left rotate array by one
void leftRotate(vector<int>& arr){
    //brute force - using dummy array
    // vector<int> temp(arr.size());
    // for(int i = 1; i < arr.size(); i++){
    //     temp[i - 1] = arr[i];
    // }
    // //placing 1 at last
    // temp[arr.size() - 1] = arr[0];
    // //printing array
    // for(int i = 0 ; i < temp.size(); i++){
    //     cout << temp[i] << " ";
    // }

    //optimal solution
    // int temp = arr[0];
    // for(int i = 1; i < arr.size(); i++){
    //     arr[i - 1] = arr[i];
    // }
    // arr[arr.size() - 1] = temp;
    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
}

//right rotate array by k places
void rightRotate(vector<int>& arr, int k){
    //bruteforce - rotate array 1 step to the right, k times
    // k = k % arr.size();
    // while(k--){
    //     int last = arr[arr.size()-1]; //saving last element
    //     for(int i = arr.size() - 1; i > 0; i--){
    //         arr[i] = arr[i-1];
    //     }
    //     arr[0] = last;.
    // }
    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }

    //optimal - using inbuilt reverse method
    int n = arr.size();
    k = k % n;

    //right rotate
    // reverse(arr.begin(), arr.end());
    // reverse(arr.begin(), arr.begin() + k);
    // reverse(arr.begin() + k, arr.end());

    //left rotate
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int k = 3;
    rightRotate(arr, k);
    // cout << removeDuplicates(arr);
    // vector<int> arr = {1,2,3,4,5};
    // cout << isSorted(arr);
    return 0;
}