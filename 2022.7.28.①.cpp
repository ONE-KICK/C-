int Add(int num1, int num2)
{
    int sum, forward;
    do
    {
        sum = num1 ^ num2;
        forward = (num1 & num2) << 1;
        num1 = sum;
        num2 = forward;

    } while (num2 != 0);

    return num1;
}
