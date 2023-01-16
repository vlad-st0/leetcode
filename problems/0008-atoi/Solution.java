class Solution {
    public static int myAtoi(String s) {
        long output = 0;
        s = s.trim();

        if (s.length() == 0) {
            return 0;
        }

        boolean isPositive = true;
        int index = 0;
        final int len = s.length();

        if (s.charAt(0) == '-') {
            isPositive = false;
            index++;
        } else if (s.charAt(0) == '+') {
            index++;
        }

        while (index < len) {
            final int digit = s.charAt(index) - '0';
            if (digit < 0 || digit > 9) {
                break;
            }
            output = output * 10 + digit;
            if (output > Integer.MAX_VALUE) {
                return isPositive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            index++;
        }

        return isPositive ? (int) output : (int) output * -1;

    }
}
