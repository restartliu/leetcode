#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TotalCharacter 128

void set_appear_position(int *appear_buffer, int position, char character)
{
    appear_buffer[character] = position;
}

void init_buffer(int *appear_buffer)
{
    memset(appear_buffer, -1, TotalCharacter * sizeof(int));
}

int if_in(int *appear_buffer, char character)
{
    return (appear_buffer[character] != -1 ? appear_buffer[character] + 1 : 0);
}

int lengthOfLongestSubstring(char *s)
{
    int *appear_buffer = (int *)malloc(sizeof(int) * TotalCharacter);
    init_buffer(appear_buffer);
    int max, temp_length;
    max = temp_length = 0;

    int i = 0;
    while (i < strlen(s))
    {
        int position = if_in(appear_buffer, s[i]);
        if (position)
        {
            max = max < i - temp_length ? i - temp_length : max;
            temp_length = position;
            init_buffer(appear_buffer);
            i = position;
        }
        set_appear_position(appear_buffer, i, s[i]);
        i++;
    }
    max = max < i - temp_length ? i - temp_length : max;
    return max;
}

int main(int argc, char const *argv[])
{
    printf("%d", lengthOfLongestSubstring("bhhoejpnsoqioadvynqrbotrdhreashtutlyli8y967i45443qes67#%^56red5yt#%^6666867tfjhlkjlhfjhgdhdstrskuykjgckhilihliughgchtsgse}+*_*_*+))+*)iu;oiy;oi;kyufytdrtewazztrytdkuyfkufgliugytdreqr23q5437878i[hliufvn4598*+*-+++5469jhfgfxhtxfuyhftrsreawrewaegulihih;oi"));
    return 0;
}
