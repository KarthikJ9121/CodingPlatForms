# Implement Atoi

[Problem Link](https://www.geeksforgeeks.org/problems/implement-atoi/1)
</hr>

## Question
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.
**Note:**
- Only the space character ' ' is considered a whitespace character.
- Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 - 1) or INT_MIN (-2^31) is returned.

</hr>

## Thought Process and Approaches

**1. Normal Approach:**
We iterate through the string, ignoring leading whitespace characters. Once we encounter the first non-whitespace character, we determine the sign and start parsing digits. If we encounter a non-digit character, we return -1. We continue parsing digits until we reach the end of the string or encounter a non-digit character. We accumulate the result as we parse the digits, taking care not to exceed the 32-bit integer range. Finally, we return the result with the appropriate sign.

**2. Exception Handling Approach:**
We try to convert the string to an integer directly using the `int()` function (in Python). If successful, we return the integer value. If an exception occurs, indicating that the string is not a valid integer, we return -1.

**3. One-Liner Approach:**
We attempt to convert the string to an integer using the `int()` function(in Python). If the string represents a valid integer, we return the integer value. Otherwise, we return -1.

</hr>

## Codes
### C++
``` Cpp
int atoi(string s) {
    int n = s.length();
    int sign;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 && s[i] == '-') {
            sign = s[0];
            continue;
        }
        if(s[i] >= '0' and s[i] <= '9')        
            res = res * 10 + (s[i] - '0');
        else
            return -1;
    }
    if(sign == '-')
        return (-1 * res);
    return res;
    }
 ```


### Java
``` Java
public class Solution {
    public int atoi(String s) {
        int n = s.length();
        int sign = 1; 
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 && s.charAt(i) == '-') {
                sign = -1; 
                continue;
            }
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                res = res * 10 + (s.charAt(i) - '0');
            } else {
                return -1; 
            }
        }
        return sign * res;
    }
}
```

### Python
``` Python
def atoi(s: str) -> int:
    n = len(s)
    sign = 1  
    res = 0
    for i in range(n):
        if i == 0 and s[i] == '-':
            sign = '-'
            continue
        if '0' <= s[i] <= '9':
            res = res * 10 + (ord(s[i]) - ord('0'))
        else:
            return -1
    if sign == '-':
        return -1 * res
    return res

# Exception Handling Approach
def atoi(s: str) -> int:
    try:
        return int(s)
    except:
        return -1

# One-Liner Approach
def atoi(s: str) -> int:
    return int(s) if (s[0] == '-' and s[1:].isdigit()) or (s.isdigit() and s[0] != '-') else -1
```

### JavaScript
``` JavaScript
function atoi(s) {
    const n = s.length;
    let sign;  
    let res = 0;

    for (let i = 0; i < n; i++) {
        if (i === 0 && s[i] === '-') {
            sign = -1;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') 
            res = res * 10 + (s[i] - '0');
        else 
            return -1;
    }

    if(sign === -1  && res !== 0)
        return (-1) * res;
    return res;
}
 ```