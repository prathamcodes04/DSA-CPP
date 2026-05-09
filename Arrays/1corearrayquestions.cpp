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

//maximum product subarray
int maxProduct(vector<int>& nums) {
    //bruteforce approach
    // int maxsumarr = INT_MIN;
    // for(int i = 0; i < nums.size(); i++){
    //     for(int j = i; j < nums.size(); j++){
    //         int product = 1;
    //         for(int k = i; k <= j; k++){
    //             product *= nums[k];
    //         }
    //         maxsumarr = max(maxsumarr, product);
    //     }
    // }
    // return maxsumarr;

    //better approach
    // int maxsumarr = INT_MIN;
    // for(int i = 0; i < nums.size(); i++){
    //     int product = 1;
    //     for(int j = i; j < nums.size(); j++){
    //         product *= nums[j];
    //         maxsumarr = max(maxsumarr, product);
    //     }
    // }
    // return maxsumarr;

    //optimal approach
    int maxsumarr = nums[0];
    int maxprod = nums[0];
    int minprod = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < 0){
            swap(maxprod, minprod);
        }
        maxprod = max(nums[i], maxprod * nums[i]);
        minprod = min(nums[i], minprod * nums[i]);
        maxsumarr = max(maxsumarr, maxprod);
    }
    return maxsumarr;
}

//find the minimum in rotated sorted array
int findMin(vector<int>& nums) {
    // brute force - linear scan
    //  int mini = nums[0];
    //  for(int i = 0; i < nums.size(); i++){
    //      mini = min(mini, nums[i]);
    //  }
    //  return mini;

    // better approach - comparing adjacent elements
    //  for(int i = 1; i < nums.size(); i++){
    //      if(nums[i] < nums[i-1]){
    //          return nums[i];
    //      }
    //  }
    //  return nums[0];

    // optimal approach - binary search
    // After rotation:
    //  One half is always sorted.
    //  Minimum lies in the unsorted half.
    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        // already sorted
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }

        int mid = low + (high - low) / 2;
        // left half sorted
        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        // right half sorted
        else {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

//search in rotated sorted array
int search(vector<int>& nums, int target) {
    //brute force 
    // for(int i = 0; i < nums.size(); i++){
    //     if(nums[i] == target){
    //         return i;
    //     }
    // }
    // return -1;

    //better approach
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        //target found
        if(nums[mid] == target){
            return mid;
        }
        //left half sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        //right half sorted
        else{
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int a = 1;
    int b = 2;
    cout << sum(a, b);
    return 0;
}