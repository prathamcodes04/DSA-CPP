#include<bits/stdc++.h>
using namespace std;

//two sum
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

//best time to buy and sell stock
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

int main(){
    int a = 1;
    int b = 2;
    cout << sum(a, b);
    return 0;
}