class Solution {
    public static int lengthOfLongestSubstring(String s) {
        final int n = s.length();
        int len = 0;
        int[] repeat = new int[128]; // array for memorizing characters of string
        for (int c = 0, j = 0, i = 0; j < n; j++) {
            c = s.charAt(j); // character parsed to int
            i = Math.max(repeat[c], i); // index of repetition (starting point for substring)
            len = Math.max(len, j - i + 1); // length of longest substring (current index - starting
                                            // index + 1 position in current loop)
            repeat[c] = j + 1; // position of character in our array
        }
        return len;
    }

    public static int lengthOfLongestSubstringSimple(String s) {
        int max = 0;
        String tempSubstring = new String();

        for (int i = 0; i < s.length(); i++) {
            if (tempSubstring.indexOf(s.charAt(i)) == -1) {
                tempSubstring += s.charAt(i);
            } else {
                if (tempSubstring.length() > max) {
                    max = tempSubstring.length();
                }
                int index = tempSubstring.indexOf(s.charAt(i));
                tempSubstring =
                        tempSubstring.substring(index + 1, tempSubstring.length()) + s.charAt(i);
            }
        }

        return Math.max(tempSubstring.length(), max);
    }
}
