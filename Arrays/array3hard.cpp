#include<bits/stdc++.h>
using namespace std;

//pascal's triangle
vector<vector<int>> generate(int n){
    vector<vector<int>> ans;
    for(int i = 0; i <= n; i++){
        vector<int> row;
        long long val = 1;
        for(int j = 0; j <= i; j++){
            row.push_back(val);
            val = val * (i - j) / (j + 1);
        }
        ans.push_back(row);
    }
    return ans;
}
long long ncr(int n, int r){
    long long res = 1;
    if(r > n - r){
        r = n - r;
    }
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

//majority element - 2
vector<int> majorityelement(int arr[], int n){
    //brute force
    // vector<int> res;
    // for(int i = 0; i < n; i++){
    //     if(res.size() == 0 || res[0] != arr[i]){
    //         int cnt = 0;
    //         for(int j = 0; j < n; j++){
    //             if(arr[i] == arr[j]){
    //                 cnt++;
    //             }
    //         }
    //         if(cnt > n/3){
    //             res.push_back(arr[i]);
    //         }
    //         if(res.size() == 2) break;
    //     }
    // }
    // return res;

    //better - hashing
    // vector<int> result;
    // unordered_map<int, int> mpp;
    // int mini = int(n/3) + 1;
    // for(int i = 0; i < n; i++){
    //     mpp[arr[i]]++;
    //     if(mpp[arr[i]] == mini){
    //         result.push_back(arr[i]);
    //     }
    //     if(result.size() == 2) break;
    // }
    // return result;

    //optimal - modification of moore's voting algo
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && el2 != arr[i]){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && el1 != arr[i]){
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else{cnt1--, cnt2--;}
    }
    vector<int> result;
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(el1 == arr[i]) cnt1++;
        if(el2 == arr[i]) cnt2++;
    }
    int mini = int(n/3) + 1;
    if(cnt1 >= mini) result.push_back(el1);
    if(cnt2 >= mini && el1 != el2) result.push_back(el2);
    return result;
}

vector<vector<int>> threesum(int arr[], int n){

    //brute force
    // set<vector<int>> st;
    // for(int i = 0; i < n ; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             if(arr[i] + arr[j] + arr[k] == 0){
    //                 vector<int> temp = {arr[i], arr[j],arr[k]};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //better approach
    // set<vector<int>> st;
    // for(int i = 0; i < n; i++){
    //     set<int> hashset;
    //     for(int j = i + 1; j < n; j++){
    //         int third = -(arr[i] + arr[j]);
    //         if(hashset.find(third) != hashset.end()){
    //             vector<int> temp = {arr[i], arr[j], third};
    //             sort(temp.begin(), temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(arr[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //optimal approach - two pointer
    vector<vector<int>> ans;
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        //skip duplicates for first element nnnn
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum < 0){
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                ans.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
                //skippig duplicates
                while(left < right && arr[left] == arr[left - 1]) left++;
                while(left < right && arr[right] == arr[right + 1]) right--;
            }
        }
    }
    return ans;
}

int main(){
    //majority element
    int n = 6;
    int arr[n] = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threesum(arr, n);
    
    for(auto vec : result){
        for(auto x : vec){
            cout << x << " ";
        }
        cout << endl;
    }

    // vector<int> result = majorityelement(arr, n);
    // for(auto it : result){
    //     cout << it << " ";
    // }


    //pascal's triangle
    // int n = 5; //row
    // int r = 3; //column
    // cout << ncr(n, r);
    // cout << endl;
    // long long ans = 1;
    // cout << ans << " ";
    // for(int i = 1; i <= n; i++){
    //     ans = ans * (n - i + 1);
    //     ans = ans / i;
    //     cout << ans << " ";
    // }
    // cout << endl;
    // vector<vector<int>> triangle = generate(n);
    // for(auto row : triangle){
    //     for(auto val : row){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}