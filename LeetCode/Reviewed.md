### Reviewed sections
+ 1\. Two Sum [E]
	+ Use set or hash table to store result of (target-num[index]). 
	+ Time complexity: O(n) Space complexity: O(n)
+ Keyword: easy, hash table

 ```
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

```
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

```
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

```
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

```
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

```
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

+ 15\. 3Sum
+ Set one number as constant and traverse the rest to conduct two sum method.
+ Or Sort the array, set one number as constant and traverse the rest to conduct two pointer method.
	+ Time: O($n^2$). Space: O(n)

```
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

+ 10\. Regular Expression Matching

+ 44\. Wildcard Matching

+ 97\. Interleaving String 

