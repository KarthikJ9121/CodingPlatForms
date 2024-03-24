# Insert Element at Bottom of Stack

[Problem Link](https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1)
</hr>

## Question
Implement a function to insert an element at the bottom of a given stack.

</hr>

## Thought Process and Approaches
To insert an element at the bottom of a stack, we can use two approaches: using an auxiliary stack and using recursion.

**First Approach: Using Auxiliary Stack**
Transfer all elements from the original stack to an auxiliary stack.
Push the new element onto the original stack.
Transfer all elements back from the auxiliary stack to the original stack.

## PseudoCode
``` bash
Function insertAtBottomRecursive(stack st, integer x):
    if st is empty:
        st.push(x)
        return st

    topElement = st.top()
    st.pop()
    st = insertAtBottomRecursive(st, x)
    st.push(topElement)
    return st
 ```

## Complexity Analysis
**Time complexity:** O(n) - We iterate over all elements in the stack twice.
**Space complexity:** O(n) - We use an auxiliary stack to store elements temporarily.

</hr>

## Second Approach: Using Recursion
Recursively remove all elements from the stack.
Insert the new element at the bottom of the stack when the stack becomes empty.
Push back all elements.

## PseudoCode
``` bash
Function insertAtBottomRecursive(stack st, integer x):
    if st is empty:
        st.push(x)
        return st

    topElement = st.top()
    st.pop()
    insertAtBottomRecursive(st, x)
    st.push(topElement)
    return st
```
## Complexity Analysis
**Time complexity: O(n)** - We recursively iterate over all elements in the stack.
**Space complexity:** O(n) - We use function call stack space due to recursion.

</hr>

## Codes
### C++
``` C++
std::stack<int> insertAtBottom(std::stack<int> st, int x) {
    std::stack<int> st2;
    while (!st.empty()) {
        st2.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!st2.empty()) {
        st.push(st2.top());
        st2.pop();
    }
    return st;
}
``` 

### Java
``` Java
import java.util.Stack;
public class Solution {
    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        Stack<Integer> st2 = new Stack<>();
        while (!st.isEmpty()) {
            st2.push(st.pop());
        }
        st.push(x);
        while (!st2.isEmpty()) {
            st.push(st2.pop());
        }
        return st;
    }
}
```

### Python
``` Python
def insertAtBottom(st, x):
    st2 = []
    while st:
        st2.append(st.pop())
    st.append(x)
    while st2:
        st.append(st2.pop())
    return st
``` 

### JavaScript
``` JavaScript
function insertAtBottom(st, x) {
    let st2 = [];
    while (st.length > 0) {
        st2.push(st.pop());
    }
    st.push(x);
    while (st2.length > 0) {
        st.push(st2.pop());
    }
    return st;
}
```