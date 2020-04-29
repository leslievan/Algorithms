/**
 * Created by Leslie
 * 2020-03-28
 */

#include <string>
#include <algorithm>

//#define __01_ADD_TWO_NUMBERS_MAIN_
#ifdef __01_ADD_TWO_NUMBERS_MAIN_

#include <iostream>
using namespace std;

#endif

/**
 * Add two big decimal numbers
 * @param a string of a big number
 * @param b string of a big number
 * @return string of the result
 */
std::string AddTwoNumbers(std::string a, std::string b) {
    int x, y, sum, carry = 0;
    std::string result;
    auto iter_a = a.rbegin(), iter_b = b.rbegin();

    while (iter_a != a.rend() || iter_b != b.rend()) {
        x = iter_a != a.rend() ? *iter_a - '0' : 0;
        y = iter_b != b.rend() ? *iter_b - '0' : 0;
        sum = x + y + carry;
        carry = sum / 10;
        result += char(sum % 10 + '0');

        if (iter_a != a.rend()) {
            iter_a++;
        }
        if (iter_b != b.rend()) {
            iter_b++;
        }
    }

    if (carry == 1) {
        result += char(carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

#ifdef __01_ADD_TWO_NUMBERS_MAIN_

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << AddTwoNumbers(s1, s2);

    return 0;
}

#endif