#include <stdio.h>

int binsearch(int x, char v[], int n);

main()
{
    int x = 'a';
    char v[] = "bac";
    int n = 3;
    int ans;
    ans = binsearch(x, v, n);
    printf("%d\n", ans);
}

/* Binary search - find position of 'x' in v[0] -> v[n-1] */
int binsearch(int x, char v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid+1;
        else
            low = mid+1;
        mid = (low+high)/2;
    }
    if (x == v[mid])
        return mid;         /* if match */
    else
        return -1;          /* if no match */
}
