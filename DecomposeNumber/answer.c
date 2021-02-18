#include<stdio.h>

int is_24(int input_number)
{
    while (input_number)
    {
        int temp = input_number%10;
        if (temp==2 || temp==4)
        {
            return 1;
        }
        input_number /= 10;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int src_number = 0;
    int ans = 0;
    printf("Input number: ");
    scanf("%d", &src_number);

    for (int i = 1; i < src_number/3+1; i++)
    {
        if (is_24(i))
        {
            continue;
        }
        for (int j = i+1; j < (src_number-i)/2+1; j++)
        {
            if (is_24(j))
            {
                continue;
            }
            int k = src_number-i-j;
            if (i<j && j<k && !is_24(k))
            {
                //printf("%d+%d+%d\n", i, j, k);
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
