#include <stdio.h>

int h, w, n;

int main()
{
    int H = 0, W = 0, T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d %d %d", &h, &w, &n);
        H = n % h;
        W = n / h + 1;
        if (H == 0)
        {
            H = h;
            W -= 1;
        }
        if (W < 10)
            printf("%d0%d\n", H, W);
        else
            printf("%d%d\n", H, W);
    }
    return 0;
}