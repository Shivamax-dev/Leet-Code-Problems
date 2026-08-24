class Solution {
public:
    int fib(int n) {
        // Base Case
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive Calls / Trust Step
    int ans1 = fib(n - 1);
    int ans2 = fib(n - 2);

    return ans1 + ans2;
    }
};