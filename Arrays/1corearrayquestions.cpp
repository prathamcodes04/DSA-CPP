#include<bits/stdc++.h>
using namespace std;

//two sum - 1
vector<int> twoSum(vector<int>& nums, int target) {
    //brute force
    // for(int i = 0; i < nums.size(); i++){
    //     for(int j = i+1; j < nums.size(); j++){
    //         if(nums[i] + nums[j] ==  target){
    //             return {i, j};
    //         }
    //     }
    // }
    // return {};

    //better solution - hashing
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        int num = nums[i]; //current element
        int needed = target - num; //required element
        if(mp.find(needed) != mp.end()){ //check if required num already exist
            return {mp[needed], i};
        }
        mp[num] = i; //store current num in map
    }
    return {-1, -1};
}

//best time to buy and sell stock - 121
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }else{
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

//contains duplicate - 217
bool containsDuplicate(vector<int>& nums) {
    //brute force
    // for(int i = 0; i < nums.size(); i++){
    //     for(int j = i + 1; j < nums.size(); j++){
    //         if(nums[j] == nums[i]){
    //             return 1;
    //         }
    //     }
    // }
    // return 0;

    //better solution  - sorting
    //     sort(nums.begin(), nums.end());
    //     for(int i = 1; i < nums.size(); i++){
    //         if(nums[i] == nums[i-1]){
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }

    //optimal solution using hashing
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        int num = nums[i];
        if(mp.find(num) != mp.end()){
            return 1;
        }
        mp[num] = i;
    }
    return 0;
}

//maximum subarray - 53
int maxSubArray(vector<int>& nums) {
    //brute force
    // int maxsum = INT_MIN;
    // for(int i = 0; i < nums.size(); i++){
    //     for(int j = i; j < nums.size(); j++){
    //         int sum = 0;
    //         for(int k = i; k <= j; k++){
    //             sum += nums[k];
    //         }
    //         maxsum = max(maxsum, sum);
    //     }
    // }
    // return maxsum;

    //better approach - remove k loop
    // int maxsum = INT_MIN;
    // for(int i = 0; i < nums.size(); i++){
    //     int sum = 0;
    //     for(int j = i; j < nums.size(); j++){
    //         sum += nums[j];
    //         maxsum = max(maxsum, sum);
    //     }
    // }
    // return maxsum;

    //optimal approach - kadanes algorithm
    int maxsum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        maxsum = max(maxsum, sum);
        if(sum < 0){
            sum = 0; //reset sum when it becomes < 0
        }
    }
    return maxsum;
}

int main(){
    int a = 1;
    int b = 2;
    cout << sum(a, b);
    return 0;
}