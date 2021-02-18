#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)s[start]] = 1;

    while (s[end] != 0)
    {
        maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
        ++end;
        while (0 != map[(int)s[end]]) //将要加入的新元素与map内元素冲突
        {
            map[(int)s[start]] = 0;
            ++start;
        }
        map[(int)s[end]] = 1;
    }

    return maxlen;
}

int main(int argc, char const *argv[])
{
    printf("%d", lengthOfLongestSubstring("bhhoejpnsoqioadvynqrbotrdhreashtutlyli8y967i45443qes67#%^56red5yt#%^6666867tfjhlkjlhfjhgdhdstrskuykjgckhilihliughgchtsgse}+*_*_*+))+*)iu;oiy;oi;kyufytdrtewazztrytdkuyfkufgliugytdreqr23q5437878i[hliufvn4598*+*-+++5469jhfgfxhtxfuyhftrsreawrewaegulihih;oi"));
    return 0;
}