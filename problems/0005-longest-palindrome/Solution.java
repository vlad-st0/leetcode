class Solution {
    public static String longestPalindrome(String s) {
        String longestPalindromeString = new String();

        for (int startIndex = 0; startIndex < s.length(); startIndex++) {
            for (int endIndex = s.length() - 1; endIndex >= startIndex; endIndex--) {
                if (s.charAt(endIndex) == s.charAt(startIndex)) {
                    if (palindromeExists(s, startIndex, endIndex)
                            && ((endIndex + 1) - startIndex) > longestPalindromeString.length()) {
                        longestPalindromeString = s.substring(startIndex, endIndex + 1);
                    }
                }
            }
            if (longestPalindromeString.length() > s.length() - startIndex) {
                break;
            }
        }

        return longestPalindromeString;

    }

    public static boolean palindromeExists(String string, int startIndex, int endIndex) {
        while (startIndex <= endIndex) {
            if (string.charAt(startIndex) != string.charAt(endIndex)) {
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
}
