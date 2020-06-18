class Solution
{
public:
    double myPow(double x, int n)
    {

        if (n == 1) return x;
        if (n == 0) return 1;

        if (n == INT_MIN)
        {
            if (x != 0)  
                return 1 / (myPow(x, INT_MAX) * x);
            else 
                return 0;
        }

        if (n < 0)  return 1 / myPow(x, -n);
         
        double result = myPow(x, n >> 1);
        return result * result * ((n % 2 == 0) ? 1 : x);
    }
};