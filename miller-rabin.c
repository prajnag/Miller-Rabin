#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
long long multmod(long long a, long long b, long long mod)
{
    return (a*b) % mod;
}
long long modulo(long long x, long long y, long long p)
{
    long long res = 1;      
    x = x % p; 
    while (y > 0) 
    { 
        if (y %2==1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}
int miller_rabin(long long p,int k)
{
    int i;
    long long s=p-1;
    if (p < 2 || (p != 2 && p % 2==0))
    {
        return 0;
    }
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (i = 0; i < k; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp <= p - 1 && mod != 1 && mod != p - 1)
        {
            mod = multmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
            return 0;
    }
    return 1;
}
long long isPrime(long long n)
{
    int flag;
    long long i=n+1;
    while(miller_rabin(i,4)==0)
    {
        i++;
    }
    return i;
}
int main()
{
    // clock_t t;
    // t=clock();
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        long long num;
        scanf("%lld", &num);
        printf("%lld\n", isPrime(num));
    }
    // t = clock() - t; 
    // double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    // printf("foo() took %f seconds to execute \n", time_taken); 
    return 0;
}
