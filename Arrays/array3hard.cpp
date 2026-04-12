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

//three sum
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
        //skip duplicates for first element 
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

//four sum
vector<vector<int>> foursum(int nums[], int n){

    //brute force
    // set<vector<int>> st;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             for(int l = k + 1; l < n; l++){
    //                 long long sum = arr[i] + arr[k];
    //                 sum += arr[k];
    //                 sum += arr[l];
    //                 if(arr[i] + arr[j] + arr[k] + arr[l] == 0){
    //                     vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
    //                     sort(temp.begin(), temp.end());
    //                     st.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //better approach - hashing
    // set<vector<int>> st;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         set<int> hashset;
    //         for(int k = j + 1; k < n; k++){
    //             int fourth = - (arr[i] + arr[j] + arr[k]);
    //             if(hashset.find(fourth) != hashset.end()){
    //                 vector<int> temp = {arr[i], arr[j], arr[k], fourth};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //             hashset.insert(arr[k]);
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //optimal approach using two pointers
    sort(nums, nums + n);
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        //skipping duplicates for first element
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < n; j++){
            //skipping duplicates for 2nd element
            if(j != i + 1 && nums[j] == nums[j-1]) continue;
            int left = j + 1;
            int right = n - 1;
            while(left < right){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];
                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
    }
    vector<vector<int>> ans(result.begin(), result.end());
    return ans;

}

//largest subarray with sum 0
int largestsubarraysum(int nums[], int n){
    //return length
    //brute force
    int max_len = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == 0){
                int len = j - i + 1;
                max_len = max(max_len, len);
            }
        }
    }
    return max_len;
}

int main(){
    //majority element
    int n = 6;
    int nums[n] = {9,-3,3,-1,6,-5};
    cout << largestsubarraysum(nums, n);
    // vector<vector<int>> result = threesum(arr, n);
    // vector<vector<int>> result = foursum(nums, n);
    
    // for(auto vec : result){
    //     for(auto x : vec){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

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