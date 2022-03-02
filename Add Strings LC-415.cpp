//Best Method
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int num1_size = num1.size() - 1;
        int num2_size = num2.size() - 1;

        int carry = 0, sum = 0, i, j;
        string res = "", extras;

        for (i = num1_size, j = num2_size; i >= 0 || j >= 0; i--, j--)
        {
            sum = 0;

            if (i >= 0)
                sum += num1[i] - '0';
            if (j >= 0)
                sum += num2[j] - '0';
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            res = to_string(sum) + res;
        }
        if (carry)
        {
            res = to_string(carry) + res;
        }

        return res;
    }
};

//Adding each number, if carry exists use recursion again(Own, dumb method)

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int num1_size = num1.size() - 1;
        int num2_size = num2.size() - 1;

        int carry = 0, sum = 0, i, j;
        string res = "", extras;

        for (i = num1_size, j = num2_size; i >= 0 && j >= 0; i--, j--)
        {
            sum = num1[i] - '0' + num2[j] - '0' + carry;
            carry = sum / 10;
            sum %= 10;
            res = to_string(sum) + res;
        }

        if (i != -1)
            extras = num1.substr(0, i + 1);
        else if (j != -1)
            extras = num2.substr(0, j + 1);

        if (carry)
            res = addStrings(extras, to_string(carry)) + res;
        else
            res = extras + res;

        return res;
    }
};
