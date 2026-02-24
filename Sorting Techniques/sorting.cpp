#include<bits/stdc++.h>
using namespace std;
void selection_sort(int n, int arr[]){
  //traverse the array
  for(int i = 0; i <= n-2; i++){
    int mini = i; //assuming current index holds minimum value

    //find index of the smallest element in the remaining array
    for(int j = i; j <= n-1; j++){
      if(arr[j] < arr[mini]){
        mini = j; //update mini if smaller element is found
      }
    }
    //swapping
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

void bubble_sort(int n, int arr[]){
  for(int i = 0; i < n; i++){
    bool swapped = false;
    for(int j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(!swapped) break;
    cout << "runs\n";
  }
}

void insertion_sort(int n, int arr[]){
  for(int i = 0; i < n; i++){
    int j = i;
    while(j > 0 && arr[j-1] > arr[j]){
      //swap
      swap(arr[j-1], arr[j]);

      j--; //as we are checking elements backwards
    }
  }
}

void merge(int arr[], int low, int mid, int high){
  //defining temporary array to store elements
  vector <int> temp;
  int left = low;
  int right = mid + 1;

  while(left <= mid && right <= high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      right++;
    }
  }
  while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

  while(right <= high){
      temp.push_back(arr[right]);
      right++;
  }

  //to print the sorted array
  for(int i = low; i <= high; i++){
    arr[i] = temp[i - low];
  }
}

void merge_sort(int arr[], int low, int high){
  if(low >= high) return; //base case
  int mid = (high + low) / 2;

  //recursive calls
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);

  //calling merge function to combine final array
  merge(arr, low, mid, high);
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  // selection_sort(n , arr);
  // bubble_sort(n , arr);
  // insertion_sort(n , arr);
  merge_sort(arr, 0, n-1);
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
