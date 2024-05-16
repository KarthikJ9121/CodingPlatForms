# Remove all duplicates from a given string

### [Problem Link](https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1)

</hr>

## Question
Given a string str which may contain lowercase and uppercase characters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

</hr>

## Thought Process and Approaches

### Approach
- Create a map to store count of each char, and a new string
- add every char to the mpp, if the count goes > 1. it means it was already added **Continue**
- else, add to the new char to the new string

### PseudoCode

```bash

function removeDuplicates(str):
    initialize an empty unordered_map mpp 
    initialize an empty string s
    initialize n = size of given string
    
    for each character i in str:
        ele = char at ith index of str
        increment the count of ele in mpp
        
        if count of ele in mpp is greater than 1:
            continue 
        else:
            append i to s
    
    return s

```

### Complexity Analysis

**Time complexity:**  O(n) </br>
**Space complexity:** O(n)

</hr>


## Codes

### C++

``` C++

string removeDuplicates(string str) 
	{
	    unordered_map<char, int> mpp;
	    string s = "";
	    int n = str.size();
	    
	    for(int i = 0; i < n; i++)
	    {
	        int ele = str[i];
	        mpp[ele]++;
	        
	        if(mpp[ele] > 1)
	            continue;
	        else
	            s += str[i];
	    }
	    return s;
	}

```

### Java

``` Java 

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String removeDuplicates(String str) {
        Map<Character, Integer> mpp = new HashMap<>();
        StringBuilder s = new StringBuilder();
        int n = str.length();

        for (int i = 0; i < n; i++) {
            char ele = str.charAt(i);
            mpp.put(ele, mpp.getOrDefault(ele, 0) + 1);

            if (mpp.get(ele) > 1)
                continue;
            else
                s.append(str.charAt(i));
        }
        return s.toString();
    }
}

```

### Python

``` Python

class Solution:
    def removeDuplicates(self, s: str) -> str:
        mpp = {}
        result = ""

        for char in s:
            mpp[char] = mpp.get(char, 0) + 1

            if mpp[char] > 1:
                continue
            else:
                result += char

        return result

```

### JavaScipt


``` JavaScript

class Solution {
    removeDuplicates(str) {
        const mpp = new Map();
        let s = "";

        for (let i = 0; i < str.length; i++) {
            const ele = str[i];
            mpp.set(ele, (mpp.get(ele) || 0) + 1);

            if (mpp.get(ele) > 1)
                continue;
            else
                s += str[i];
        }
        return s;
    }
}


```

