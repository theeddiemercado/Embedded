int main(void) {
  unsigned int a = 0xdeefefac;  // what is the decimal value of a?
  unsigned int b = 0xffffffff;  // what is the decimal value of b?

  // Use a calculator to multiply decimal values of a and b and compare the
  // result to c
  unsigned long long int c = (unsigned long long int)a * b;

  signed int x = a;  // what is the decimal value of x?
  signed int y = b;  // what is the decimal value of y?

  // compare z to what you expect x * y should be
  signed int z = x * y;

}
