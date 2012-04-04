#include <iostream>
#include "decimal"

extern void std_decimal_test_decimal32 (void);
extern void std_decimal_test_decimal64 (void);
extern void std_decimal_test_decimal128 (void);

int main (void)
{
  using namespace std::decimal;

  std_decimal_test_decimal32 ();
  std_decimal_test_decimal64 ();
  std_decimal_test_decimal128 ();

  return 0;
}
