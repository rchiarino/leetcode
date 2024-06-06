class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int left = 0, right = 1, result;
        for (int i = 2; i <= n; i++)
        {
            result = left + right;
            left = right;
            right = result;
        }
        return result;
    }
};