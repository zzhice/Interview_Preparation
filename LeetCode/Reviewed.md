### Reviewed sections
+ 1\. Two Sum [E]
	+ Use set or hash table to store result of (target-num[index]). 
	+ Time complexity: O(n) Space complexity: O(n)
+ Keyword: easy, hash table

 ```cpp
 class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
        int numToFind = target - nums[i];
        if(hash.find(numToFind) != hash.end()){
            result.push_back(hash[numToFind]);
            result.push_back(i);
            return result;
        }
        hash[nums[i]] = i;
    }   
        return result;
    }
}; 
```

+ 2\. Add Two Numbers [M]
	+ Define a root pointer and an integer to store extra.
	+ Time: O(max(m,n)). Space O(max(m,n))
+ Keyword: medium, linked list

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode* p = &root;
        int extra = 0;
        while(l1 || l2 || extra){
            if(l1){
                extra += l1->val;
                l1 = l1->next;
            }
            if(l2){
                extra += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(extra % 10);
            extra /= 10;
            p = p->next;
        }
        return root.next;
    }
};
```

+ 3\. Longest Substring Wihtout Repeating Characters [M]
	+ Sliding window method: Set or hash table(faster). 
	+ Time: O(n). Space: O(min(m, n))
+ Keyword: medium, sliding window, hash table

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for(int i = 0; i != s.length(); i++){
            if(dict[s[i]] >= start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
```

+ 4\. Median of Two Sorted Arrays [H]
	+ The idea is to divide elements into two parts equally where max(left) <= min(right), carefully deal with boundary cases.
	+ Time: O(log(min(m, n))). Space: O(1)
+ Keyword: hard, median

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size(), l = 0, r = m;
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        while (l <= r) {
            int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
            if (i && nums1[i - 1] > nums2[j]) {
                r = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                l = i + 1;
            } else {
                int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]));
                if ((m + n) % 2) {
                    return lmax;
                }
                int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));
                return 0.5 * (lmax + rmin);
            }
        }
        return 0.0;
    
    }
};
```

+ 5\. Longest Palindromic Substring [M]
+ Expand palindrome from its center. 
	+ Time: O($n^2$. Space: O(1).
+ Use dynamic programming. 
	+ Time: O($n^2$). Space: O($n^2$).
+ Keyword: medium, palindrome, dynamic programming

```cpp
// Expand from center
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while(i < s.size()) {
        int r_ptr = i; 
        int l_ptr = i;
        //find the middle of a palindrome
        while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
        i = r_ptr+1;
        //expand from the middle out
        while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
            r_ptr++;
            l_ptr--;
        }
        int new_len = r_ptr - l_ptr + 1;
        if(new_len > max_len) {
            start_idx = l_ptr;
            max_len = new_len;
        }
    }
    return s.substr(start_idx, max_len);
    }
};
```

+ 11\. Container With Most Water [M]
	+ Maintain two pointers to get close to each other.
	+ Time: O(n). Space: O(1)
+ Keyword: medium, two pointer

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxSize = 0;
        while(l <= r){
            maxSize = max(maxSize, min(height[l], height[r])*(r - l));
            if(height[l]<=height[r])
            {
                    l += 1;
            }           
            else
            {
                    r -= 1;
            }
        }
        return maxSize;
    }
};
```

+ 15\. 3Sum [M]
+ Set one number as constant and traverse the rest to conduct two sum method.
+ Or Sort the array, set one number as constant and traverse the rest to conduct two pointer method.
	+ Time: O($n^2$). Space: O(n)
+ Keyword: medium, two pointer

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        
        vector<vector<int>> res;
        std::sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++){
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            if(target < 0) break;
            while(front < back){
                int sum = num[front] + num[back];
                if(sum < target)
                    front += 1;
                else if(sum > target)
                    back -= 1;
                else{
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    while(front < back && num[front] == triplet[1]) front += 1;
                    while(front < back && num[back] == triplet[2]) back -= 1;
                }
                while(i + 1 < num.size() && num[i + 1] == num[i])
                    i++;
            }
        }
        return res;
    }
}; 
```

+ 17\. Letter Combinations of a Phont Number [M]
+ dfs, backtracking
	+ Time: O($3^N$*$4^M$). Space: O($3^N$\*$4^M$)
+ Keyword: medium, dfs, backtracking

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits == "")
            return res;
        dfs(digits, 0, "", res);
        
        return res;
    }
    
    void dfs(string digits, int i, string tmp, vector<string> &res){
        if(i == digits.size()){
            res.push_back(tmp);
            return;
        }
        for(int j = 0; j < digToChar[digits[i]].size(); j++){
            dfs(digits, i+1, tmp+digToChar[digits[i]][j], res);
        }
    }
private:
    std::unordered_map<char, string> digToChar = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};
```

+ 19\.Remove Nth Node From End of List [M]
+ Keyword: medium, two pointer

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = head;
        ListNode* prev = head;
        for(int i = 0; i < n; i++){
            head = head->next;
            if(head==NULL)return root->next;
        }
        while(1){
            head = head->next;
            if(head==NULL){
                prev->next = prev->next->next;
                break;
            }
            prev = prev->next;
        }
        return root;
    }
};
``` 

+ 20\.Valid Parentheses [E]
	+ Use stack, if remain empty(), return true
+ Keyword: easy, stack

```cpp
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack_set1;
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == ')'){
                if(stack_set1.size()==0) return false;
                if(stack_set1[stack_set1.size()-1] == '(')
                    stack_set1.pop_back();
                else
                    return false;
            }
            else if(s[i] == '}'){
                if(stack_set1.size()==0) return false;
                if(stack_set1[stack_set1.size()-1] == '{')
                    stack_set1.pop_back();
                else
                    return false;
            }
            else if(s[i] == ']'){
                if(stack_set1.size()==0) return false;
                if(stack_set1[stack_set1.size()-1] == '[')
                    stack_set1.pop_back();
                else
                    return false;
            }else
                stack_set1.push_back(s[i]);
        }
        if(stack_set1.size() == 0)
            return true;
        else
            return false;
        
    }
};
```

+ 21\. Merge Two Sorted Lists [E]
	+ Time: O(max(n, m)). Space: O(1) 
+ Keyword: easy, linked lists
	

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* root = head;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                if(l1->val <= l2->val){
                    head->next = l1;
                    head = head->next;
                    l1 = l1->next;
                }else{
                    head->next = l2;
                    head = head->next;
                    l2 = l2->next;
                }
            }
            if(l1 && !l2)
            {
                head->next = l1;
                    head = head->next;
                    l1 = l1->next;
            }
            if(!l1 && l2)
            {
                head->next = l2;
                    head = head->next;
                    l2 = l2->next;
            }
        }
        return root->next;
    }
};
```

+ 22\. Generate Parentheses [M]
+ Keyword: medium, backtracking

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};
```

+ 23\. Merge k Sorted Lists [H]
+ Use priority queue to optimize the comparison process.
	+ Time: O(Nlogk). Space: O(max(n, k)), where N is the number of nodes and k is the number of linked lists.
+ Keyword: hard, priority queue

```cpp
class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists.front();
    }
};
```
+ 31\. Next Permutation [M]
+ The key is to understand what is permutation. Let's say, if the numbers are stored in descending order, then reverse the array. Otherwise, we do the swapping and reverse the array. See code below to get better understanding.
	+ Time: O(n). Space: O(1) 
+ Keyword: medium, permutation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
```

+ 32\. Longest Valid Parentheses [H]
+ Use stack to store index of invalid parenthesis. Calculate the maxLength starting from the end of string.
	+ Time: O(n). Space: O(n) 
+ Use two counters left and right to conduct left to right scan and right to left scan.
	+ Time: O(n). Space: O(1)
+ Keyword: hard, stack

```cpp
// stack method
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else
            {
                if(!st.empty())
                {
                    if(s[st.top()] == '(') st.pop();
                    else st.push(i);
                }else st.push(i);
            }
        }
        if(st.empty()) longest = n;
        else{
            int a = n, b = 0;
            while(!st.empty()){
                b = st.top();
                st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
        
    }
};
```  

+ 33\. Search in Rotated Sorted Array [M]
+ Use binary search method, and list all possible cases when separating the array.
	+ Time: O(log(N)). Space O(1).
+ Keyword: medium, binary search

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0]==target? 0:-1;
        if(nums.size()==2){
            if(nums[0]==target) return 0;
            if(nums[1]==target) return 1;
            return -1;
        }
        return bsearch(0, nums.size()-1, nums, target);
        
    }
    int bsearch(int l, int r, vector<int>& nums, int target){
        std::cout<<l<<r<<endl;
        if(target==nums[(l+r)/2]) return (l+r)/2;
        if(l==r) return -1;
        if((r-l)==1){
        if(nums[r]==target) return r;
            else return -1;
        }
        if(target>nums[(l+r)/2] && nums[(l+r)/2] > nums[r])
            return bsearch((l+r)/2, r, nums, target);
        else if(target>nums[(l+r)/2] && nums[(l+r)/2] < nums[r]){
            if(target > nums[r])
                return bsearch(l, (l+r)/2, nums, target);
            else return bsearch((l+r)/2, r, nums, target); 
        }
        else if(target<nums[(l+r)/2] && nums[(l+r)/2] > nums[r]){
            if(target > nums[r])
                return bsearch(l, (l+r)/2, nums, target);
            else return bsearch((l+r)/2, r, nums, target); 
        }
        else if(target<nums[(l+r)/2] && nums[(l+r)/2] < nums[r])
            return bsearch(l, (l+r)/2, nums, target);
        return -1;
        // int l = 0, r = nums.size()-1;
        // while (l <= r) {
        //     int mid = (l+r) / 2;
        //     if (target == nums[mid])
        //         return mid;
        //     // there exists rotation; the middle element is in the left part of the array
        //     if (nums[mid] > nums[r]) {
        //         if (target < nums[mid] && target >= nums[l])
        //             r = mid - 1;
        //         else
        //             l = mid + 1;
        //     }
        //     // there exists rotation; the middle element is in the right part of the array
        //     else if (nums[mid] < nums[l]) {
        //         if (target > nums[mid] && target <= nums[r])
        //             l = mid + 1;
        //         else
        //             r = mid - 1;
        //     }
        //     // there is no rotation; just like normal binary search
        //     else {
        //         if (target < nums[mid])
        //             r = mid - 1;
        //         else
        //             l = mid + 1;
        //     }
        // }
        // return -1;
    }
};
``` 

+ 34\. Find First and Last Position of Element in Sorted Array [M]
+ We can find the left and right position of target by switching the calculation of mid value.
	+ Time: O(log(n)). Space: O(1)
+ Keyword: medium, binary search

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res(2, -1);
        // find the left one
        while(l < r){
            int mid = (r+l)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums.size() !=0 && nums[l] == target) res[0] = l;
        else return res;
        
        r = nums.size() - 1;
        while(l < r){
            int mid = (r+l)/2 + 1;
            if(nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        res[1] = l;
        return res;
    }
};
```   

+ 39\. Combination Sum [M]
+ dfs, backtracking
	+ Time: O($2^n$). Space: O($2^n$)
+ Keyword: medium, dfs, backtracking

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        if(candidates.empty()){
            vector<vector<int>> res;
            return res;
        }
        sort(candidates.begin(), candidates.end());
        find_comb(0, candidates, target, res, tmp);
        return res;
    }
    
    void find_comb(int index, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> tmp)
    {
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        for(int i = index; i < candidates.size(); ++i)
        {
            if(candidates[i] > target) return;
            else{
                vector<int> new_tmp = tmp;
                new_tmp.push_back(candidates[i]);
                find_comb(i, candidates, target-candidates[i], res, new_tmp);
            }
        }
    }
};
```
 
+ 10\. Regular Expression Matching [H]
	+ Time: O($n^2$). Space: O($n^2$) 
+ Keyword: hard, dynamic programming

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        row = len(p) + 1
        col = len(s) + 1
        dp = [ [False for i in range( col ) ] for j in range( row ) ]
        dp[0][0] = True # dp[0][0] 
        for i in range( 1, row):
            dp[i][0] = ( i > 1 ) and p[ i - 1 ] == "*" and dp[ i - 2 ][0]

        for i in range( 1, row ) :
            for j in range( 1, col ):
                
                if p[ i - 1 ] =="*":
                    dp[i][j] = dp[ i - 2 ][j] or ( p[ i - 2  ] == s[ j - 1 ] or p[ i - 2 ] == ".") and  dp[i][j-1]

                else:
                    dp[i][j] = ( p[ i - 1 ] == "."  or p[ i - 1 ]  == s[ j - 1 ]) and dp[i-1][j-1]

        return dp[row-1][col-1]
```

+ 44\. Wildcard Matching [H]
	+ Time: O($n^2$). Space: O($n^2$) 
+ Keyword: dynamic programming

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        row = len(p) + 1
        col = len(s) + 1
        dp = [ [False for i in range( 0, col )] for j in range( 0, row ) ]

        dp[0][0] = True
        for j in range(1, col ):
            dp[0][j] = False
        for i in range( 1, row):
            if p[i-1] == "*":
                dp[i][0] = dp[i-1][0]

        for i in range( 1, row ):
            for j in range( 1, col ):
                if p[i-1] == "*":
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else:
                    dp[i][j] = (s[j-1] == p[i-1] or p[i-1] == "?") and dp[i-1][j-1]
        return dp[row-1][col-1]
```

+ 97\. Interleaving String [H]
	+ Time: O($n^2$). Space: O($n^2$) 
+ Keyword: dynamic programming

```python
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        row = len(s1) + 1
        col = len(s2) + 1
        t = len(s3)
        if row + col -2 !=t :
            return False
        dp = [ [False for j in range(col)] for j in range(row) ]
        dp[0][0] = True
        for j in range(1,col):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
        for i in range(1,row):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]

        for i in range(1,row):
            for j in range(1,col):
       
                dp[i][j] = ( dp[i-1][j] and s1[i-1] == s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1])
        return dp[row-1][col-1]
```


+ 41\. First Missing Positive [H]
	+ Time: O($n$). Space: O($1$) 
+ Keyword: uncategorized

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
        
    }
};
```

+ 62\. Unique Paths [M]
    + Time: O($nxn$). Space: O($nxm$) 
+ Keyword: dynamic programming

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> mtx(n, vector<int>(m,0));
        for(int i = 0; i < m; i++)
            mtx[0][i] = 1;
        for(int i = 0; i < n; i++)
            mtx[i][0] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                mtx[i][j] = mtx[i-1][j] + mtx[i][j-1];
            }
        }
        return mtx[n-1][m-1];
    }
};

```