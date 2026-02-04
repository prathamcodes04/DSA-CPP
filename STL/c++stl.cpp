// #include<bits/stdc++.h>
// using namespace std;
// void print(){
//   cout << "raj";
// }
// int sum(int a, int b){
//   return a+b;
// }
// int main(){
//   print();
//   int s = sum(3,4);
//   cout << s;+
//   return 0;
//}

#include<bits/stdc++.h>
using namespace std;

void startwithpairs(){
  // storing two integers
  // pair<int, int> p = {1,3};
  // cout << p.first << " " << p.second;

  // storing three integers
  // pair<int, pair<int, int>> q = {1, {3, 4}};
  // print 1, 3 and 4
  // cout << q.first << " " << q.second.first << " " << q.second.second;

  // storing an array
  // pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
  // print 1 4 5
  // cout << arr[0].first << " " << arr[1].second << " " << arr[2].first;
}
void explainvectors(){
  //vectors are dynmaic in nature, we can always increase the size of vector even we have
  //predefined the size
  // vector<int> v; //creates an empty container {}
  // v.push_back(1); //pushing 1 in empty conatiner
  // v.emplace_back(2); //pusher 2 at the back and emplace is fast than push_back

  // vector<pair<int, int>> v; //pairs
  // v.push_back({1,2});
  // v.emplace_back(1,2);

  //declaring a container of size 5 with all values as 100 {100,100,100,100,100}
  // vector<int> v(5, 100);

  //defining container with size 5 
  // vector<int> v(5); {5 instances of any garbage value}

  // vector<int> v1(5, 20); //{20,20,20,20,20}
  // vector<int> v2(v1); //creating a new container using v1 container

  //printing entire vector
  // vector<int> v1 = {1,2,3,4,5};
  // cout << "v1: ";
  // for(int i = 0; i < v1.size(); i++){
  //   cout << v1[i] << " ";
  // }

  //iterators
  //basic iterator syntax
  //vector<int> v = {1,2,3,4,5};
  //printing first value
  //vector<int>::iterator it = v.begin(); //output - 1
  
  //printing second value
  // vector<int>::iterator it = v.begin();
  // it++; //moving to next index
  // cout << *(it) << " "; //output - 2

  //printing third value
  // vector<int>::iterator it = v.begin();
  // it+=2; //pointing i to 2
  // cout << *(it) ;

  //printing last value
  // vector<int>::iterator it = v.end();
  // vector<int>::iterator it = v.rend(); //points before first element
  // vector<int>::iterator it = v.rbegin(); //points to last element
  // cout << *(it);
  // it--;
  // cout << *(it);

  //printing first element
  // cout << v[0] << " " << v.at(0) << endl;
  // cout << v.back() << " ";

  //new vector
  // vector<int> v = {1,2,3,4,5};

  //printing entire vector using iterator
  // for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
  //   cout << *(it) << " ";
  // }

  //shortcut for above
  // for(auto it = v.begin(); it != v.end(); it++){
  //   cout << *(it) << " "; 
  // }
  
  //best way to print enitre vector than above methods using auto
  // for(auto it : v){
  //   cout << it << " ";
  // }

  //deletion in a vector
  // vector<int> v = {10,20,30,40,50,60};
  // v.erase(v.begin()); //20 30
  // v.erase(v.begin()+1); //10 30 - removes 2nd element 20 
  // for(int i = 0; i < v.size(); i++){
  //   cout << v[i] << " ";
  // }

  //to remove multiple elememts we can use range
  // v.erase(v.begin()+2, v.begin()+4); //removes 30 & 40
  //.erase(start(30), end(50)) - removed 30, 40

  //another method of printing
  // for(int x : v){  //here x is a temporary variable
  //   cout << x << " "; 
  // }


  //insertion funciton
  // vector<int> v(2, 100); //vector of two values {100,100}
  // v.insert(v.begin(), 300); //inserting element at start
  // v.insert(v.begin() + 1, 2); //inserting 2 
  // v.insert(v.begin() + 1, 2, 3); //inserting two 3s {100,3,3,100} 

  // vector<int> copy(2, 50);
  // v.insert(v.begin(), copy.begin(), copy.end());

  // cout << v.size(); //size of the vector



  // for(int x : v){
  //   cout << x << " ";
  // }

}
void explainList(){
  // list<int> ls; //empty list
  // ls.push_back(2);
  // ls.emplace_back(4);
  // ls.push_front(5);
  // ls.emplace_front(2);

  // //rest functions same as vector
  // //begin, end, rbegin, rend, clear, insert, size, swap

  // for(int x : ls){
  //   cout << x << " ";
  // }
}
void explainDeque(){
  deque<int> dq;
  dq.push_back(1);
  dq.emplace_back(2);
  dq.push_front(4);
  dq.emplace_front(3);

  dq.pop_back();
  dq.pop_front();

  dq.back();
  dq.front();

  for(int x : dq){
    cout << x << " ";
  }
}
void explainStack(){
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(3);
  st.emplace(5);

  // cout << st.top() << " ";
  st.pop();
  // cout << st.size();
  // cout << st.empty();

  // stack<int> st1, st2;
  // st1.swap(st2);


  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  //cant use this as stack follows LIFO
  // for(int x : st){
  //   cout << x << " ";
  // }
} 
void explainQueue(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.emplace(4);
  q.back() += 5; //adding 5 to last element 4+5
  // cout << q.back();
  // cout << q.front();
  q.pop();
  // cout << q.front();
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
}
void explainPQ(){
  // priority_queue<int> pq;
  //maximum heap - highest value at top
  // pq.push(5);
  // pq.push(2);
  // pq.push(8);
  // pq.emplace(10);
  // pq.pop();
  // cout << pq.top();
  //size and swap same as stack and queue

  //minimum heap - minimum value at top
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(5);
  pq.push(2);
  pq.push(8);
  pq.push(10);

  // cout << pq.top();

  while(!pq.empty()){
    cout << pq.top() << " ";
    pq.pop();
  }
}
void explainSet(){
  set<int>st;
  // st.insert(1);
  // st.emplace(2);
  // st.insert(2);
  // st.insert(4);
  // st.insert(3);

  //to find a particular value
  // set<int> st1 = {1,2,3,4,5};
  // auto it = st1.find(3);
  // if (it != st1.end()) {
  //   cout << *it;
  // } else {
  //   cout << "Not found";
  // }

  //to erase a value
  // st.erase(5);

  // for(int x : st){
  //   cout << x << " ";
  // }

  //multiset
  multiset<int>ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  // ms.erase(1); //removes all 1s
  // ms.count(1);
  // ms.erase(ms.find(1)); //removes only single 1
  // ms.erase(ms.find(1), ms.find(1)+2);
  for(int x : ms){
    cout << x << " ";
  }
}
void unorderedSet(){
  unordered_set<int>st;

}
void explainMap(){
  map<int, int>mpp;
  // map<int, pair<int, int>>mpp; //key is 1 integer and values is two integer
  // map<pair<int, int>, int>mpp; //key is 2 integer and value is 1 integer
  mpp[1] = 2;
  mpp.insert({3,1});
  mpp.emplace(2,4);

  // for(auto it : mpp){
  //   cout << it.first << " " << it.second << endl;
  // }

  // cout << mpp[2];

  //find
  auto it = mpp.find(2);
  cout << (*it).second;

}
bool comp(pair<int, int>p1, pair<int, int>p2){
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false;
  //they are same
  if(p1.first > p2.first) return true;
  return false;
}
void explainExtra(){
  //sorting
  //sorting in ascending order
  vector<int> v = {1,4,3,5,2};
  // sort(v.begin(), v.end());
  // sort(v.begin(), v.end(), greater<int>);


  int arr[] = {1,5,4,3,2};
  // sort(arr, arr+5);
  // sort(arr, arr+5, greater<int>());
  // sort(arr, arr+5);
  // reverse(arr, arr+5);


  // for(int x : arr){
  // // for(int x : v){
  //   cout << x << " ";
  // }

  //permutation
  string s = "123";
  do{
    cout << s << endl;
  }while(next_permutation(s.begin(), s.end()));
}
int main(){
  // explainExtra();
  // explainMap();
  // startwithpairs();
  // explainvectors();
  // explainList();
  // explainDeque();
  // explainStack();
  // explainQueue();
  // explainPQ();
  // explainSet();
  // unorderedSet();
  return 0;
}