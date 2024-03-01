int multiply_byvalue(int a, int b)
{
    return a*b;
}
int multiply_byref(int& a, int& b)
{
    return a*b;
}
int main(void) {
    int x{4}, y{3};
    multiply_byvalue(x,y);
    multiply_byref(x,y);
}
