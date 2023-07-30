Hi, I'll be pushing my code here.
// set matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m,-1);
        vector<int> cols(n,-1);
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(rows[i] == 0 or cols[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// move Zeroes 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =0;
        vector<int> a;
        for(auto it: nums){
            if(it==0){
                n++;
            }
            else{
                a.push_back(it);
            }
        }
        while(n--){
            a.push_back(0);
        }
        for(int i= 0;i<nums.size() ;i++) {
            nums[i] = a[i];
        }
    }
};

// best time for sell and buy stocks 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, ans = 0;
        for (int p : prices) {
            minVal = min(minVal, p);
            ans = max(ans, p - minVal);
        }
        return ans;
    }
};

// find duplicate number 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> ans(nums.size(),0);
        for(int i=0 ; i<nums.size();i++){
            if(!ans[nums[i]]) ans[nums[i]] = 1;
            else return nums[i];
        }
        return 0;
    }
};

// sort colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>> pq;
        for(auto it: nums){
            pq.push(it);
        }
        nums.clear();
        while(!pq.empty()){
            nums.push_back(pq.top());
            pq.pop();
        }
    }
};

// remove duplicates from sorted arrays

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> p(nums.begin() , nums.end());
        nums.clear();
        for(auto it:p) nums.push_back(it);
        return nums.size();
    }
};

// two sum 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int numl = nums.size();
        for(int i=0; i<numl ;i++){
            for(int j =i+1;j<numl;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if(result.size()!=0){
                break;
            }
        }
        return result;
    }
};

//  best time for sell and buy stocks 2 

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() +1, vector<int> (2, -1) );
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int index = prices.size()-1 ; index>=0; index--){
            for(int buy = 0 ; buy<=1 ;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0] , dp[index+1][1] );
                }
                else{
                    profit = max(prices[index] + dp[index+1][1] , dp[index+1][0] );
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//  subarray sum divisible by k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        partial_sum(nums.begin() , nums.end() , nums.begin());
        unordered_map<int,int> map;
        map[0] = 1;
        int count = 0;
        for(auto it : nums){
            if(map.find((it%k+k)%k) != map.end()) count += map[(it%k+k)%k];
            map[(it%k+k)%k]++;
        }

        return count;
    }
};

//  find all duplicates in an array 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1, 0);
        for(auto it : nums) ans[it]++;
        vector<int> result;
        for(int i=1; i<=n;i++){
            if(ans[i] == 2) result.push_back(i);
        }
        return result;
    }
};

//  containing most water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int f = 0;
        int s = height.size()-1;
        int value = 0;
        while(f<s){
            value = max(value, min(height[f] , height[s]) * (s-f));
            if(height[f] <= height[s]){
                f++;
            }
            else{
                s--;
            }
        }
        return value;
    }
};

//  3 sum problem 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> vec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] < 0) left++;
            else if (nums[i] + nums[left] + nums[right] > 0) right--;
            else {
                vector<int> temp;
                temp.insert(temp.begin() , {nums[i] , nums[left] , nums[right]});
                vec.insert(temp);
                left++;right--;
            }
        }
        }
        vector<vector<int>> v;
        for(auto it:vec) v.push_back(it);
        return v;
    }
};


//  4 sum problem 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};
