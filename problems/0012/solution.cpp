#include <string>

using std::string;

/** 12. Integer to Roman */
class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        for (int i = 0; i < num / 1000; i++)
            result += "M";
        num %= 1000;
        for (int i = 0; i < num / 900; i++)
            result += "CM";
        num %= 900;
        for (int i = 0; i < num / 500; i++)
            result += "D";
        num %= 500;
        for (int i = 0; i < num / 400; i++)
            result += "CD";
        num %= 400;
        for (int i = 0; i < num / 100; i++)
            result += "C";
        num %= 100;
        for (int i = 0; i < num / 90; i++)
            result += "XC";
        num %= 90;
        for (int i = 0; i < num / 50; i++)
            result += "L";
        num %= 50;
        for (int i = 0; i < num / 40; i++)
            result += "XL";
        num %= 40;
        for (int i = 0; i < num / 10; i++)
            result += "X";
        num %= 10;
        for (int i = 0; i < num / 9; i++)
            result += "IX";
        num %= 9;
        for (int i = 0; i < num / 5; i++)
            result += "V";
        num %= 5;
        for (int i = 0; i < num / 4; i++)
            result += "IV";
        num %= 4;
        for (int i = 0; i < num; i++)
            result += "I";
        return result;
    }
};