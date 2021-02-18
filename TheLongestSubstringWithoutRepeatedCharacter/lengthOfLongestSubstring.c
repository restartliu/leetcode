#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CharSize 8
#define TotalCharacter 128

void print_binary(char *s)
{
    for (int i = 0; i < TotalCharacter / CharSize; i++)
    {
        char temp = s[i];
        for (int j = 0; j < 8; j++, temp >>= 1)
        {
            printf("%c", (temp & 1) ? '1' : '0');
        }
    }
}

void set_bit(char *buffer, int set)
{
    int index = set / CharSize;
    int offset = set % CharSize;
    buffer[index] |= (1 << offset);
}

int if_in(char *buffer, char set)
{
    int index = set / CharSize;
    int offset = set % CharSize;
    return buffer[index] & (1 << offset) ? 1 : 0;
}

void clear_bit(char *buffer, int set)
{
    int index = set / CharSize;
    int offset = set % CharSize;
    buffer[index] &= ~(1 << offset);
}

int lengthOfLongestSubstring(char *s)
{
    int length = strlen(s);
    int max, start, end;
    max = start = end = 0;
    char *bit_judge = (char *)malloc(TotalCharacter / CharSize);
    set_bit(bit_judge, s[end]);

    while (s[end] != '\0')
    {
        max = max < end - start + 1 ? end - start + 1 : max;
        end++;
        while (if_in(bit_judge, s[end]))
        {
            clear_bit(bit_judge, s[start]);
            start++;
        }
        set_bit(bit_judge, s[end]);
    }

    return max;
}

int main(int argc, char const *argv[])
{
    printf("%d", lengthOfLongestSubstring("bhhoejpnsoqioadvynqrbotrdhreashtutlyli8y967i45443qes67#%^56red5yt#%^6666867tfjhlkjlhfjhgdhdstrskuykjgckhilihliughgchtsgse}+*_*_*+))+*)iu;oiy;oi;kyufytdrtewazztrytdkuyfkufgliugytdreqr23q5437878i[hliufvn4598*+*-+++5469jhfgfxhtxfuyhftrsreawrewaegulihih;oi"));
    return 0;
}