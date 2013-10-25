#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "largest float = " << numeric_limits<float>::max() << endl
         << "smallest float = " << numeric_limits<float>::min() << endl
         << "min exponent in library = " << numeric_limits<float>::min_exponent
         << endl << "min exponent in decimal = " <<
         numeric_limits<float>::min_exponent10 << endl
         << "max exponent in binary = " << numeric_limits<float>::max_exponent
         << endl << "max exponent in decimal = " <<
         numeric_limits<float>::max_exponent10 << endl
         << "# of binary digits in mantissa: " <<
        numeric_limits<float>::digits << endl <<
        "# of decimal digits in mantissa: " << numeric_limits<float>::radix
         << endl <<
        "base of exponent in float: " << numeric_limits<float>::digits10
         << endl << "infinity in float: " << numeric_limits<float>::infinity()
         << endl << "float epsilong = " << numeric_limits<float>::epsilon()
         << endl << "float rounding error = " <<
        numeric_limits<float>::round_error() << endl <<
        "float rounding style = " << numeric_limits<float>::round_style
         << endl;

    return 0;
}
