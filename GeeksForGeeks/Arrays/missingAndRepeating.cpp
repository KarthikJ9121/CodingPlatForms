// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& v) {
        // int n = v.size();
        // int a = -1;
        // int b = -1;
        
        // for(int i = 0; i < n; i++)
        // {
        //     int ind = abs(v[i]) - 1;
        //     if(v[ind] < 0)
        //         a = abs(v[i]);
        //     else
        //         v[ind] = -v[ind];        //Using the self Visited Array
        // }
        
        // for(int i = 0; i < n; i++)
        // {
        //     if(v[i] > 0)
        //     {
        //         b = i + 1;
        //         break;
        //     }
        // }
        
        // return {a, b};
        
        
        long long n = v.size();
        
        long long actSum = (n * (n + 1)) / 2;
        long long actSqSum = (n * (n + 1) * (2 * n + 1)) / 6;
        
        long long sum = 0;
        long long sqSum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (v[i]);
            sqSum += (((long long)v[i] * (long long)v[i]));    //using the Maths
        }
        
        long long delSum = sum - actSum;         // B - A
        long long delSqSum = sqSum - actSqSum;   // B^2 - A^2
        
        long long sumBplusA = delSqSum / delSum; // B + A
        long long b = (delSum + sumBplusA) / 2;  // Solving for B
        long long a = b - delSum;                // Solving for A
        
        return {(int)b, (int)a};
    }
};
