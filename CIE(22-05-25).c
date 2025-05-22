#include<stdio.h>

int main(){
    int i, j, k, n, frames, hits = 0, pagef = 0;
    char pages[100];
    printf("Enter no. of pages:");
    scanf("%d", &n);
    printf("Enter page strings:");
    scanf("%s", pages);
    printf("Enter no. of pages:");
    scanf("%d", &frames);
    int mem[frames], used[frames];
    for (i = 0; i < frames;i++)
    {
        mem[i] = -1;
        used[i] = -1;
    }
    //LRU
    for (i = 0; i < n;i++)
    {
        int page = pages[i] - '0';
        int found = 0;
        for (j = 0; j < frames;j++)
        {
            if(mem[j]==page)
            {
                hits++;
                found = 1;
                used[j] = i;
                break;
            }
        }
        if(!found){
            int lru = 0;
            for (j = 1; j < frames;j++)
            {
                if(used[j]<used[lru])
                {
                    lru = j;
                }
            }
            mem[lru] = page;
            used[lru] = i;
            pagef++;
        }
        for (j = 0; j < frames;j++)
        {
            printf("%d\t", mem[j]);
        }
        printf("\n");
    }
    printf("The hit:%d and Miss:%d", hits, pagef);
}
