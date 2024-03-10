# Intersection Of Two Arrays

### [Problem Link](https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10)

</hr>

## Question
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

</hr>

## Thought Process and Approaches

### Approach
- given to find Intersect with no duplicates
- two sets - for two arrays with no duplicates
- new set - common elements from both arrays

### PseudoCode

```bash

function intersection(nums1, nums2):
    set1 = create a new empty Set
    for each integer i in nums1:
        add i to set1
    
    set2 = create a new empty Set
    for each integer i in nums2:
        add i to set2
    
    Main_Set = create a new empty Set
    for each integer var in set1:
        if var exists in set2:
            add var to Main_Set
    
    create an array arr of size Main_Set.size()
    j = 0
    for each integer val in Main_Set:
        arr[j] = val
        increment j
    
    return arr

```

### Complexity Analysis

**Time complexity:** O(n1 + n2)  </br>
**Space complexity:** O(n1 + n2 + m)

</hr>

## Codes

### C++

``` C++

#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> mainSet;
        for (int var : set1) {
            if (set2.count(var)) {
                mainSet.push_back(var);
            }
        }
        
        return mainSet;
    }
};

```

### Java

``` Java 

 public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for (int i : nums1) {
            set1.add(i);
        }
        Set<Integer> set2 = new HashSet<>();
        for (int i : nums2) {
            set2.add(i);
        }
        //Removed Duplicates using Hashset
        Set<Integer> Main_Set = new HashSet<>();
        for (Integer var : set1) {
            if (set2.contains(var)) {
                Main_Set.add(var);
            }
        }
        int[] arr = new int[Main_Set.size()];
        int j = 0;
        for (Integer val : Main_Set) {
            arr[j] = val.intValue();
            j++;
        }
        return arr;

```

### Python

``` Python

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)
        
        main_set = set()
        for var in set1:
            if var in set2:
                main_set.add(var)
        
        return list(main_set)


```

### JavaScipt


``` JavaScript

class Solution {
    intersection(nums1, nums2) {
        const set1 = new Set(nums1);
        const set2 = new Set(nums2);
        
        const mainSet = new Set();
        for (const var of set1) {
            if (set2.has(var)) {
                mainSet.add(var);
            }
        }
        
        return Array.from(mainSet);
    }
}


```

