/**
 * Created by Leslie
 * 2020-03-28
 */

#include <string>
#include <vector>
#include <algorithm>

//#define __02_BASE_CONVERT_MAIN_
#ifdef __02_BASE_CONVERT_MAIN_

#include <iostream>
using namespace std;

#endif

/**
 * Mapping a n-base number to a int number
 * @param c the n-base number
 * return the int number
 */
int GetValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'A') {
        return c - 'A' + 36;
    }
    return -1;
}

/**
 * Convert a big num between different base.
 * @param a the string of big num
 * @param src_base the base of origin number,
 * @param to_base
 * @return the string of big num in src_base
 */
std::string BaseConvert(std::string a, int src_base, int to_base = 10) {
    if (src_base < 2 || src_base > 62 || to_base < 2 || to_base > 62) {
        return reinterpret_cast<const char *>(1);
    }

    char num_alpha[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int temp = 0;
    std::vector<int> number, quotient, result;
    std::string s;

    /* 将字母映射为数字 */
    for (char &c : a) {
        number.push_back(GetValue(c));
    }
    auto iter = number.begin();

    while (!number.empty()) {
        /* 得到余数和商 */
        while (iter != number.end()) {
            temp *= src_base;
            temp += *iter++;
            if (temp < to_base) {
                quotient.push_back(0);
                continue;
            } else {
                quotient.push_back(temp / to_base);
                temp %= to_base;
            }
        }
        /* 得到余数，存入result */
        result.push_back(temp);

        /* 清空商的前置0 */
        auto i = quotient.begin();
        while (*i == 0 && i != quotient.end()) { i++; }
        if (i != quotient.begin()) {
            quotient.erase(quotient.begin(), i);
        }

        /* 将商作为下一次的运算数，重置商数组和temp */
        number = quotient;
        quotient.clear();
        iter = number.begin();
        temp = 0;
    }

    /* 逆序余数位 */
    reverse(result.begin(), result.end());
    /* 将数字映射为字母 */
    for (int &i:result) {
        s += num_alpha[i];
    }

    return s;
}

#ifdef __02_BASE_CONVERT_MAIN_

int main() {
    cout << BaseConvert("147872543966327731985114897369993890532825839884071006223621", 10, 2) << endl;

    return 0;
}

#endif