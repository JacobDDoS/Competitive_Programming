#include <bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x * x) - 5;
}

double findRootBisectionMethod(double a, double b, double (*func)(double), double e = 1e-6)
{
    int cnt = 1;
    while (a != b)
    {
        double c = (a + b) / 2;
        cout << "iteration " << cnt << ": " << c << ": " << func(c) << endl;
        if (abs(func(c)) < e)
        {
            return c;
        }
        else if (func(c) < 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        cnt++;
    }
    return 0;
}

int main()
{
    double a = 0, b = -4;
    double approxRoot = findRootBisectionMethod(a, b, func);
    cout << approxRoot << endl;
}