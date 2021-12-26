#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n = 0, num = 0;
char com[20] = {0};
queue<int> q;

int main()
{
    scanf("%d", &n);
    fgetc(stdin);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", com);
        fgetc(stdin);
        if (!strcmp(com, "push"))
        {
            scanf("%d", &num);
            fgetc(stdin);
            q.push(num);
        }
        else if (!strcmp(com, "pop"))
        {
            if (q.size() == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (!strcmp(com, "size"))
        {
            printf("%d\n", q.size());
        }
        else if (!strcmp(com, "empty"))
        {
            printf("%d\n", q.empty());
        }
        else if (!strcmp(com, "front"))
        {
            if (q.size() == 0)
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else
        {
            if (q.size() == 0)
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }
    return 0;
}