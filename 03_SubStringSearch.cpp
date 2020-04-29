/**
 * @file 03_SubStringMatch.cpp
 * @author leslie
 * @date 2020-04-10
 */

#include <cstring>

//#define __03_SUBSTRING_MATCH_MAIN_
#ifdef __03_SUBSTRING_MATCH_MAIN_

#include <iostream>

using namespace std;

#endif

#define MAX_SIZE 1024
int PMT[MAX_SIZE];

/**
 * Calculate partial match table according to rules
 * No optimization for time
 * @param sub The substring
 * @return
 * @TODO Do some time optimization
 */
int *CalPMT(const char *sub) {
    /* 初始化参数 */
    int i, j;
    memset(PMT, 0, MAX_SIZE * sizeof(int));
    PMT[0] = -1;

    /* i为已匹配串的下标，j为匹配串的前后缀长度
     * 对子串`abababca`，
     * | i | j | prefix | suffix | PMT |
     * | 0 | 1 |  null  |  null  | 0   |    a
     * | 1 | 1 |   a    |   b    | 0   |    ab
     * | 2 | 1 |   a    |   a    |  1  |    aba
     * | 2 | 2 |   ab   |   ba   |  0  |    aba
     * | 3 | 1 |   a    |   b    |  0  |    abab
     * | 3 | 2 |   ab   |   ab   |  2  |    abab
     * | 3 | 3 |   aba  |   bab  |  0  |    abab
     * 故PMT={ 0, 0, 1, 2...}
     */
    for (i = 0; i < strlen(sub); i++) {
        for (j = 1; j <= i; j++) {
            if (strncmp(sub, sub + i - j + 1, j) == 0) {
                PMT[i + 1] = PMT[i + 1] > j ? PMT[i + 1] : j;
            }
        }
    }

    return PMT;
}

/**
 * Knuth-Morris-Pratt algorithm
 * For searching the index of the substring appears in the input string
 * @param str The input string
 * @param sub The substring to search
 * @return
 */
int KMPSearch(char *str, char *sub) {
    int len1 = strlen(str), len2 = strlen(sub);
    if (len1 < len2) {
        return -1;
    }

    CalPMT(sub);
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (str[i] == sub[j] || j == -1) {
            i++, j++;
        } else {
            j = PMT[j];
        }
    }

    if (j == len2) {
        return i - j;
    } else {
        return -1;
    }
}

#ifdef __03_SUBSTRING_MATCH_MAIN_

/**
 * A test case
 */
int test() {
    char a[128], b[16];

    do {
        cout << "Please input a long string (no longer than 128 characters):\n";
        cin >> a;
        cout << "Please input a short string (no longer than 16 characters):\n";
        cin >> b;

        cout << "The subscript where " << b << " appears in " << a << " is: " << KMPSearch(a, b) << endl;
    } while (cin.peek() != EOF && cin.peek() != '\n');

    return 0;
}

/**
 * Exercises:
 * http://acm.hdu.edu.cn/showproblem.php?pid=2087
 */
int hdu_oj_2087() {
    char str[1000], sub[1000];
    int key = 0, result = 0;
    char *p;

    while (cin.peek() != EOF && cin.peek() != '#') {
        p = str;
        cin >> str >> sub;
        do {
            key = KMPSearch(p, sub);
            p += key + strlen(sub);
            result += key >= 0 ? 1 : 0;
        } while (key >= 0);
        cout << result << endl;
        result = 0;
        cin.ignore();
    }

    return 0;
}

int main() {

    hdu_oj_2087();

    return 0;
}

#endif