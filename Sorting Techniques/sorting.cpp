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

void recursive_bubble_sort(int n, int arr[]){
  //base case
  if(n == 1) return;
  bool swapped = false;

  for(int i = 0; i < n; i++){
    if(arr[i] > arr[i + 1]){
      swap(arr[i], arr[i+1]);
      swapped = true;
    }
  }
  //if no swap array already sorted
  if(!swapped) return;
  // cout << "runs\n";

  //recursive call
  recursive_bubble_sort(n-1, arr);
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

void recursive_insertion_sort(int n, int arr[]){
  //base case
  if(n <= 1) return;

  //recursively sort n-1 elements
  recursive_insertion_sort(n-1, arr);

  int last = arr[n-1];
  int j = n-2;

  while(j >= 0 && arr[j] > last){
    swap(arr[j+1], arr[j]);
    j--;
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
  // recursive_bubble_sort(n , arr);
  // insertion_sort(n , arr);
  recursive_inerstion_sort(n , arr);
  // merge_sort(arr, 0, n-1);
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
