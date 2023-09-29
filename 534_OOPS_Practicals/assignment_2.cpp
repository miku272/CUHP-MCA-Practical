#include <iostream>
#include <cmath>

// Question 9.1
// int main(int argc, char const *argv[])
// {
//     float a, b, c, d, e, f, x, y, z;

//     float expression1 = (a * x + b) / (a * x - b);
//     float expression2 = (2 * x + 3 * y) / (x - 6);
//     float expression3 = pow(x, 5) + 10 * pow(x, 4) + 8 * pow(x, 3) + 4 * x + 2;
//     float expression4 = (4 * x + 3) * (2 * y + 2 * z - 4);
//     float expression5 = ((a * x + b) / c) + ((d * y + e) / (2 * f)) - (a / (b * d));
//     float expression6 = (a / (b * (b - a)));

//     return 0;
// }

// Question 9.2
// int main(int argc, char const *argv[])
// {
//     float b;
//     int i;

//     b = 2.56;
//     b = (b + 0.05) * 10;

//     i = b;
//     b = i;

//     b = b / 10.0;

//     std::cout << b;

//     return 0;
// }

// Question 9.3
// int main(int argc, char const *argv[])
// {
//     int i, j = 3, k = 6;

//     // (i)
//     // i = j * 2 / 3 + k / 4 + 6 - j * j * j / 8;
//     // std::cout << i;

//     // (ii)
//     // float a = 1.5, b = 3.0;
//     // i = b / 2.0 + b * 4.0 / a - 8.0;
//     // std::cout << i;

//     // (iii)
//     // i = j / 2 * 4 + 3 / 8 + j * j * j % 4;
//     // std::cout << i;

//     return 0;
// }

// Question 9.4
// int main(int argc, char const *argv[])
// {
//     int k = 5, i = 3, j = 252, m;

//     m = i * 1000 + j * 10;
//     k = m / 1000 + k;
//     k = m % k++;

//     std::cout << k;

//     return 0;
// }

// Question 9.5
// int main(int argc, char const *argv[])
// {
//     float a = 2.5, b = 2.5;

//     // (i)
//     std::cout << a + 2.5 / b + 4.5 << "\n";

//     // (ii)
//     std::cout << (a + 2.5) / b + 4.5 << "\n";

//     // (iii)
//     std::cout << (a + 2.5) / (b + 4.5) << "\n";

//     // (iv)
//     std::cout << a / 2.5 / b << "\n";

//     // (v)
//     std::cout << b++ / a + b-- << "\n";

//     return 0;
// }

// Question 9.6
// int main(int argc, char const *argv[])
// {
//     int i = 3, j = 4, k = 2;

//     // (i)
//     // std::cout << i++ - j-- << "\n";

//     // (ii)
//     // std::cout << i-- % j++ << "\n";

//     // (iii)
//     // std::cout << j++ / i-- << "\n";

//     // (iv)
//     // std::cout << ++k % --j << "\n";

//     // (v)
//     // std::cout << k++ * --i << "\n";

//     // (vi)
//     // std::cout << j + 1 / i - 1 << "\n";

//     // (vii)
//     // std::cout << i - 1 % j + 1 << "\n";

//     // (viii)
//     // i = j *= k = 4;
//     // std::cout << i << " " << j << " " << k << "\n";

//     // (ix)
//     // i *= k = ++j + i;
//     // std::cout << i << " " << j << " " << k << "\n";

//     // (x)
//     // i = j /= k + 4;
//     // std::cout << i << " " << j << " " << k << "\n";

//     return 0;
// }

// Question 9.8
// int main(int argc, char const *argv[])
// {
//     int i = 5, j = 5, k = 7;
//     float a = 3.5, b = 5.5, c = 2.5;

//     // (i)
//     // a = b - i / j + c / j;

//     // (ii)
//     // a = (b - i) / (j - c) / j;

//     // (iii)
//     // a = b - ((i + j) / (k + i)) * c;

//     // (iv)
//     // a = b - i + j / k + i * c;

//     // (v)
//     // a = b + 1 % 1 + c;

//     // (vi)
//     // a = (b + 1) % (1 + c); // Showing wrong syntax

//     std::cout << a;

//     return 0;
// }
