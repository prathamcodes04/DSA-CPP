#include<bits/stdc++.h>
using namespace std;
//find largest element in an array
int largestElement(int arr[], int n){
  int largest = arr[0]; //assume
  for(int i = 0; i < n; i++){
    if(arr[i] > largest){
      largest = arr[i];
    }
  }
  return largest;
}

//find second largest element in an array
int secondLargest(int arr[], int n){
  int largest = arr[0];
  int slargest = -1;
  for(int i = 1; i < n; i++){
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

//find second smallest elemnt
int secondSmallest(int arr[], int n){
  //edge case:  not enough elements eg - [5]
  if(n < 2) return -1;

  int smallest = INT_MAX;
  int ssmallest = INT_MAX;
  for(int i = 0; i < n; i++){
    if(arr[i] < smallest){
      ssmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] > smallest && arr[i] < ssmallest){
      ssmallest = arr[i];
    }
  }

  //no distinct second element
  if(ssmallest == INT_MAX) return -1;
  return ssmallest;
}

//check if the array is sorted
int checkSorted(int arr[], int n){
  for(int i = 1; i < n; i++){
    if(arr[i] < arr[i-1]){
      return false;
    }
  }
  return true;
}

//remove duplicates in sorted array
int removeDuplicates(int arr[], int n){
  if(n == 0) return 0;
  int i = 0; //first unique element
  for(int j = 1; j < n; j++){
    if(arr[j] != arr[i]){
      //take first position
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;//length of unique elements
}

//left rotate the array by one
void rotateleft(int arr[], int n){
  int temp = arr[0]; //storing first element in temp
  for(int i = 1; i < n; i++){
    arr[i-1] = arr[i];
  }
  arr[n-1] = temp; //placing temp at last index
}

//left rotate the array by k places - bruteforce
void leftrotatekplaces(int arr[], int n, int k){
  //to avoid unnecessary rotations
  k = k % n;

  vector<int> temp;

  //storing k elements
  for(int i = 0; i < k; i++){
    temp.push_back(arr[i]);
  }
  //shifting remainin elements to left
  for(int i = k; i < n; i++){
    arr[i - k] = arr[i];
  }
  //copy temp to end
  for(int i = 0; i < k; i++){
    arr[n - k + i] = temp[i];
  }
}

//left rotate the array by K places - optimal solution
void rotateKplaces(int arr[], int n, int k){
  k = k % n;
  reverse(arr, arr + k);
  reverse(arr + k, arr + n);
  reverse(arr, arr + n);
}

//move all zeros to the end of the array 
void moveallzerostoend(int arr[], int n){
  // brute force

  // vector<int> temp;

  // //pick non zero number and put it in temp 
  // for(int i = 0; i < n; i++){
  //   if(arr[i] != 0){
  //     temp.push_back(arr[i]);
  //   }
  // }
  // //put non zero elements in front
  // int nz = temp.size();
  // for(int i = 0; i < nz; i++){
  //   arr[i] = temp[i];
  // }
  // //replacing empty indexes with 0
  // for(int i = nz; i < n; i++){
  //   arr[i] = 0;
  // }

  //optimal solution
  //two pointer approach
  // int j = 0;
  // for(int i = 0; i < n; i++){
  //   if(arr[i] != 0){
  //     swap(arr[i], arr[j]);
  //     j++;
  //   }
  // }

  //or
  //to store index of 0 element
  int j = -1;

  //finding first 0 element
  for(int i = 0; i < n; i++){
    if(arr[i] == 0){
      j = i;
      break;
    }
  }
  //if their is no zero in array
  if(j == -1) return;

  //moving non zero element forward
  for(int i = j + 1; i < n; i++){
    if(arr[i] != 0){
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

//linear search
int linearsearch(int arr[], int n, int num){
  for(int i = 0; i < n; i++){
    if(arr[i] == num){
      return i;
    }
  }
  return -1; //element not found
}

int main(){
  int n = 5;
  int arr[5] = {6,7,8,4,1};
  int num = 4;
  cout << linearsearch(arr, n, num);
  // int n = 10;
  // int arr[10] = {1,0,2,3,2,0,0,4,5,1};
  // moveallzerostoend(arr, n);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  // int n = 7;
  // int arr[7] = {1,2,3,4,5,6,7};
  // int k = 3;
  // leftrotatekplaces(arr, n, k);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  // int n = 5; 
  // int n = 7; 
  // int n = 4;
  // int n = 1;
  // int arr[5] = {1,2,3,4,5}; 
  // int arr[5] = {5,3,1,2,4}; 
  // int arr[7] = {1,1,2,2,2,3,3}; 
  // int arr[4] = {1,1,1,1}; 
  // int arr[1] = {1};
  // cout << largestElement(arr, n);
  // cout << secondLargest(arr, n);
  // cout << secondSmallest(arr, n);
  // cout << checkSorted(arr, n);
  // int len = removeDuplicates(arr, n);
  // cout << "Length of array after removing duplicated: " << len;
  // cout << endl;
  // rotateleft(arr, n);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }

  //for rotate by k places
  // int n;
  // cin >> n;
  // int arr[n];
  // for(int i = 0; i < n; i++){
  //   cin >> arr[i];
  // }
  // int k;
  // cin >> k;
  // rotateKplaces(arr, n, k);
  // for(int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
  return 0;
}