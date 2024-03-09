## You can find the [Leetcode](https://leetcode.com/) problems with the Links Here 


# Minimum Common Value

### [Problem Link](https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question envId=2024-03-09)

</hr>

## Coding Question

 Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1. Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

</hr>

## Thought Process
    - Point to be noted ** arrays are in sorted order **
    - take two pointers pointing to each array
    ** Cases : **
        ` if both has common element then this must be the first and minimum element ` ** return it **
        ` if a[i] < b[j] and not matched, there may be common element in the later part which matches with the b[j] `  
               ** increment i - keep j as it is **
        ` if b[i] < a[i] and not matched, there may be common element in the later part which matches with a[i] `
               ** increment j - keep i as it is **

## PseudoCode
```bash

    Set n = size of array a
    Set m = size of array b

    ** Pointers **

    Set i = 0
    Set j = 0

    While i < n and j < m
        If  a[i] == b[j]
            Return a[i] or b[j]
        Else  a[i] < b[j]
            Increment i
        Else
            Increment j

    Return -1

```

</hr>

## Time Complexity
    ** Time complexity: **  O(min(n, m))
    ** Space complexity: ** O(1)

</hr>

## Thought Process

    - Create a map and push elements of any array
    - iterate the other to find if it matched with any of the element in the map, if yes its count must be > 0
        ** if found return it **

```bash
    
    Create unordered_map mpp of keys and their counts
    For each integer i in array a
        Increment  i in the unordered_map mpp

    For each integer i in array b
        If the count of i > 0
            Return i
    Return -1

```

</hr>

## Time Complexity
    ** Time complexity: **  O(n + m)
    ** Space complexity: ** O(n)

## Code Of languages

    ### C++

``` C++
    
    class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) 
    {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(a[i] == b[j])
                return a[i];
            else if(a[i] < b[j])
                i++;
            else if(b[j] < a[i])
                j++;
        }
        return -1; 

        // Second Approach 
        
        unordered_map<int, int> mpp;
        for(int i : a)
            mpp[i]++;
        
        for(int i : b)
            if(mpp[i] > 0)
                return i;
        
        return -1;
    }
};

```


``` Java 

    import java.util.HashMap;

class Solution {
    public int[] getCommon(int[] a, int[] b) {
        // Approach 1 - Two Pointers
        int[] result = new int[2];
        int n = a.length, m = b.length;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                result[0] = a[i];
                break;
            } else if (a[i] < b[j]) {
                i++;
            } else if (b[j] < a[i]) {
                j++;
            }
        }

        if (result[0] == 0) return new int[]{-1};

        // Approach 2 - HashMap
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : a)
            map.put(num, map.getOrDefault(num, 0) + 1);

        for (int num : b)
            if (map.containsKey(num)) {
                result[1] = num;
                return result;
            }

        return new int[]{-1};
    }
}


```

``` Python

    from typing import List

class Solution:
    def getCommon(self, a: List[int], b: List[int]) -> List[int]:
        # Approach 1 - Two Pointers
        result = [0, 0]
        n, m = len(a), len(b)
        i, j = 0, 0

        while i < n and j < m:
            if a[i] == b[j]:
                result[0] = a[i]
                break
            elif a[i] < b[j]:
                i += 1
            elif b[j] < a[i]:
                j += 1

        if result[0] == 0:
            return [-1]

        # Approach 2 - HashMap
        map_a = {}
        for num in a:
            map_a[num] = map_a.get(num, 0) + 1

        for num in b:
            if num in map_a:
                result[1] = num
                return result

        return [-1]


```

``` JavaScript

    class Solution {
    getCommon(a, b) {
        // Approach 1 - Two Pointers
        const result = [0, 0];
        let i = 0, j = 0;
        const n = a.length, m = b.length;

        while (i < n && j < m) {
            if (a[i] === b[j]) {
                result[0] = a[i];
                break;
            } else if (a[i] < b[j]) {
                i++;
            } else if (b[j] < a[i]) {
                j++;
            }
        }

        if (result[0] === 0) return [-1];

        // Approach 2 - HashMap
        const map = new Map();
        for (const num of a)
            map.set(num, (map.get(num) || 0) + 1);

        for (const num of b)
            if (map.has(num)) {
                result[1] = num;
                return result;
            }

        return [-1];
    }
}

```

