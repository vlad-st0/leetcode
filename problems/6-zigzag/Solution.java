class Solution {
    public static String convert(String s, int numRows) {
        if (numRows == 1){
            return s;
        }
        if (numRows > s.length()){
            numRows = s.length();
        }

        int row = 0;
        boolean asc = false;

        String[] rows = new String[numRows];

        for (int i = 0; i < s.length(); i++) {
            final String letter = s.substring(i, i + 1);

            if (rows[row] == null){
                rows[row] = "";
            }
            rows[row] += letter;

            if (asc == false) {
                row++;
            } else {
                row--;
            }

            if (row >= numRows) {
                asc = true;
                row -= 2;
            } else if (row < 0) {
                asc = false;
                row = 1;
            }
        }

        return String.join("", rows);
    }
}
