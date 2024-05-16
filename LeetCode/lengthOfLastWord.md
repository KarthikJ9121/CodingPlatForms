# Length of Last Word

### [Problem Link](https://leetcode.com/problems/length-of-last-word/?envType=daily-question&envId=2024-04-01)
</hr>

## Question
Given a string s consisting of words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

</hr>

## Thought Process and Approaches
To find the length of the last word in a string, we can iterate through the string from right to left until we encounter a non-space character. We then count the characters until we encounter a space or reach the beginning of the string.

### Approach
Initialize a counter variable c to store the length of the last word.
Iterate through the string from right to left.
Count the characters until we encounter a space or reach the beginning of the string.
PseudoCode
``` cpp
int lengthOfLastWord(string s):
    int c = 0;
    int n = length(s);
    for(int i = n - 1; i >= 0; i--):
        if(s[i] == ' ' and c == 0):
            continue;
        else if(c > 0 and s[i] == ' '):
            break;
        c++;
    return c; 
```
### Complexity Analysis
**Time complexity:** O(n) - We iterate over the string once.
**Space complexity:** O(1) - We use only a constant amount of extra space.

</hr>

## Codes

### CPP
``` cpp
int lengthOfLastWord(string s):
    int c = 0;
    int n = length(s);
    for(int i = n - 1; i >= 0; i--):
        if(s[i] == ' ' and c == 0):
            continue;
        else if(c > 0 and s[i] == ' '):
            break;
        c++;
    return c;
```

### Java
``` Java
public class Solution {
    public int lengthOfLastWord(String s) {
        int c = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ' && c == 0) {
                continue;
            } else if (c > 0 && s.charAt(i) == ' ') {
                break;
            }
            c++;
        }
        return c;
    }
}
```

### Python
``` Python
def lengthOfLastWord(s):
    c = 0
    n = len(s)
    for i in range(n - 1, -1, -1):
        if s[i] == ' ' and c == 0:
            continue
        elif c > 0 and s[i] == ' ':
            break
        c += 1
    return c
```

### JavaScript
``` Javascript
function lengthOfLastWord(s) {
    let c = 0;
    let n = s.length;
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === ' ' && c === 0) {
            continue;
        } else if (c > 0 && s[i] === ' ') {
            break;
        }
        c++;
    }
    return c;
}
```
