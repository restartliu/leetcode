#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_useful_number(int input_number)
{
    int temp = input_number;
    do
    {
        if (temp%10 == 2 || temp%10 == 4)
            return -1;
    }
    while (temp /= 10);
    return input_number;
}

int binary_search(int search_number, int *input_buffer, int max_index)
{
    int left  = 0;
    int right = max_index-1;
    int mid   = 0;
    
    while (left <= right)
    {
        mid = left+(right-left)/2;
        if (input_buffer[mid] > search_number)
        {
            right = mid-1;
        }
        else if (input_buffer[mid] < search_number)
        {
            left  = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int src_number = 0;
    int ans = 0;
    printf("Input number: ");
    scanf("%d", &src_number);

    int *p_buffer = (int *)malloc(src_number*sizeof(int));

    int buffer_size = 0;
    for (int i = 0; i < src_number+1; i++)
    {
        int temp = get_useful_number(i);
        if (temp != -1)
            p_buffer[buffer_size++] = temp;
    }

    /* for (int i = 1; i < buffer_size; i++)
    {
        for (int j = i+1; j < buffer_size; j++)
        {
            if ( (p_buffer[i]+p_buffer[j]) < src_number )
            {
                for ( int k = buffer_size-1; (p_buffer[i]+p_buffer[j]+p_buffer[k]) >= src_number && k > j; k-- )
                    if ( (p_buffer[i]+p_buffer[j]+p_buffer[k]) == src_number )
                        printf("%d+%d+%d\n", p_buffer[i], p_buffer[j], p_buffer[k]);
            }
        }
    } */

    
    /* for (int i = 1; p_buffer[i] < src_number/3+1; i++)
    {
        for (int j = i+1; p_buffer[j] < (src_number-p_buffer[i])/2+1; j++)
        {
            int k = binary_search(src_number-(p_buffer[i]+p_buffer[j]), &p_buffer[j+1], buffer_size-j-1);
            if ( k!=-1 )
                //printf("%d+%d+%d\n", p_buffer[i], p_buffer[j], p_buffer[k+j+1]);
                ans++;
        }
    } */


    for (int i = 1; p_buffer[i] < src_number/3+1; i++)
    {
        int k = -1;
        for (int j = i+1; p_buffer[j] < (src_number-p_buffer[i])/2+1; j++)
        {
            if (k == -1)
            {
                k = binary_search(src_number-(p_buffer[i]+p_buffer[j]), p_buffer, buffer_size);
            }
            if (k != -1)
            {
                for (; k > j && (p_buffer[i]+p_buffer[j]+p_buffer[k]) > src_number; k--);
                if ((p_buffer[i]+p_buffer[j]+p_buffer[k]) == src_number && k > j)
                {
                    ans++;
                    //printf("%d+%d+%d\n", p_buffer[i], p_buffer[j], p_buffer[k]);
                }
            }
        }
    }

    printf("%d\n", ans);
   

    return 0;
}

//1472083164  65s     for my algorithm
//1472083164  500s    for answer algorithm
