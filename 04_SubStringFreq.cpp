/**
 * @file 04_SubStringFreq.cpp
 * @author leslie
 * @date 2020-04-11
 */

#include <cstring>

//#define __04_SUBSTRING_FREQ_MAIN_
#ifdef __04_SUBSTRING_FREQ_MAIN_

#include <iostream>

using namespace std;

#endif

/**
 * Count the frequency of the substring appear in the input string
 * No optimization for time
 * @param str The input string
 * @param sub The substring to count
 * @return The number of occurrences of the substring
 * @TODO Use KMP algorithm to optimize time for SubStringFreq
 */
int SubStringFreq(char *str, char *sub) {
    int i, j;
    int flag = 1;
    int result = 0;

//    for (i = 0; i <= strlen(str) - strlen(sub); i++) {
//        result += strncmp(str, sub, strlen(sub)) == 0 ? 1 : 0;
//    }

    for (i = 0; i <= strlen(str) - strlen(sub); i++) {
        for (j = 0; j < strlen(sub); j++) {
            if (str[i + j] != sub[j]) {
                flag = 0;
                break;
            }
        }
        result += flag;
    }

    return result;
}
