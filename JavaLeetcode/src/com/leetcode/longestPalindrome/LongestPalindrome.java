package com.leetcode.longestPalindrome;

public class LongestPalindrome {
    public static void main(String[] args) {
        LongestPalindrome longestPalindrome = new LongestPalindrome();
        System.out.println(longestPalindrome.longestPalindrome("ccccccccccccccccccccccccccccccc"));
    }

    public String longestPalindrome(String s) {

        char[] chars = s.toCharArray();
        int start, end;
        start = end = 0;

        for (int i = 0; i + 1 < chars.length; i++) {
            int increase = this.getMedianIncrease(chars, i);
            int j = 0;
            for (; i - j >= 0 && i + j + increase < chars.length && chars[i - j] == chars[i + j + increase]; j++) ;
            j--;
            if ((i + j + increase - (i - j)) >= end - start) {
                start = i - j;
                end = i + j + increase;
            }
            i += increase;
        }

        return s.substring(start, end + 1);
    }

    public int getMedianIncrease(char[] chars, int position) {
        if (chars[position] == chars[position + 1]) {
            int start = position;
            for (; chars.length > position + 1 && chars[position] == chars[position + 1]; position++) ;
            return position - start;
        } else {
            return 0;
        }
    }
}
