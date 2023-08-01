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


//  subarray sum equals k 

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n,0);         
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; 
        
        int total = 0; 
        
        for(int i = 0; i < n; i++) 
        {
            if(prefix[i] == k)
                total ++;
            if(mp.find(prefix[i] - k) != mp.end())
            {
                total += mp[prefix[i] - k]; 
            }
            
            mp[prefix[i]]++; 
        }
        
        return total; 
    }
};

//  spiral matrix 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top = 0, bottom = matrix.size()-1 , right = matrix[0].size()-1, left = 0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
                left++;
            }
        }
        return ans;
    }
};


//  word search problem 

class Solution {
public:
    bool exist(vector<vector<char>>& b, string w) {
        int n = b.size();
        
        int m = b[0].size();
        
        int i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(b[i][j] == w[0]){
                    char t = b[i][j];
                    b[i][j] = '1';
                    
                    if(solve(i,j,n,m,1,w,b))
                        return true;
                    
                    b[i][j] = t;
                }
            }
        }
        
        return false;
    }
    
    bool solve(int i, int j, int n, int m, int in, string w, vector<vector<char>>& b){
        if(in == w.size())
            return true;
        
        int a[] = {0,0,1,-1};
        int x[] = {1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int r = i+a[k];
            int c = j+x[k];
            
            if(r<0 || c<0 || r>=n || c>=m || b[r][c]=='1' || b[r][c]!=w[in])
                continue;
            
            char t = b[r][c];
            b[r][c] = '1';
            if(solve(r,c,n,m,in+1,w,b))
                return true;
            
            b[r][c] = t;
        }
            
        return false;
    }
};

//  jump game - greedy and dynamic programming problem 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if(i > reach || reach >= n-1)
                break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n-1;
    }
};

//  merge sorted array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = nums1.size() - m;
        while(len--){
            nums1.pop_back();
        }
        for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin() , nums1.end());
    }
};


//  largest Rectangle 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int i=0;
        int n=heights.size();
        int maxArea = 0;
        while(i < n)
            {   

    if(stk.empty() or( heights[stk.top()] <= heights[i] ))
            {
                stk.push(i++);
            }
            else
            {
                int minBarIndex = stk.top();
                stk.pop();
                int width = i;
                if(!stk.empty())  width = i - 1 - stk.top();
                int area = heights[minBarIndex] * width;
                maxArea = max(maxArea , area);
            }
        }

        while(!stk.empty())
        {
            int minBarIndex = stk.top();
            stk.pop();
            int width = i;
            if(!stk.empty())  width = i - 1 - stk.top();
            int area = heights[minBarIndex] * width;
            maxArea = max(maxArea , area);
        }
        return maxArea;
    }
};

// majority element 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int num = nums.size();
        return nums[num/2];
    }
};

//  reverse pairs 

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};

//  game of life 

class Solution {
public:
    bool isValid(int i, int j , int n , int m , vector<vector<int>> temp_board){
        return (i>=0 and i<n and j>=0 and j<m and temp_board[i][j]) ;
    }

    int counting(int i , int j , vector<vector<int>> temp_board , int n , int m){
        int count = 0;
        for(int k = -1 ; k<=1 ;k++){
            for(int l = -1; l<=1 ;l++){
                if(k==0 and l==0) continue;
                else if(isValid(i+k , j+l, n, m , temp_board)) count++;
            }
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<int>> temp = board;
        for(int i=0; i<n;i++){
            for(int j=0 ; j<m;j++){
                int count = counting(i,j,board,n,m);
                if(board[i][j] == 0) {
                    if(count == 3) temp[i][j] = 1;
                }
                else if(board[i][j] == 1){
                    if(count < 2 or count > 3) temp[i][j] = 0;
                } 
            }
        }
        board = temp;
    }
};

//  max value of equation 

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int result =INT_MIN ;

        priority_queue<pair<int,int>> pq;

        for(auto it : points){
            while(pq.size() and (it[0] - pq.top().second > k)) pq.pop();
            if(pq.size()) result = max(result , it[1] + it[0] + pq.top().first );
            pq.push({it[1]- it[0] , it[0]}); 
        }

        return result;
    }
};
