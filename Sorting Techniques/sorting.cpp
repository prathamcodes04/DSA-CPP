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

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  selection_sort(n , arr);
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}