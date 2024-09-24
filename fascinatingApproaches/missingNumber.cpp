// https://leetcode.com/problems/kth-missing-positive-number/
// https://www.naukri.com/code360/problems/kth-missing-element_893215?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse
// https://www.geeksforgeeks.org/problems/k-th-missing-element3635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-missing-element

 int findKthPositive(vector<int>& a, int k) {
        int n = a.size();
        for(int i = 0; i < n; i++)
            if(a[i] <= k)
                k++;
            else
                return k;
        return k;
    }
