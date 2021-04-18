/*
 * 1832. Check if the Sentence Is Pangram
 * 
 * A pangram is a sentence where every letter of the English alphabet appears
 * at least once.
 *
 * Given a string sentence containing only lowercase English letters, return
 * true if sentence is a pangram, or false otherwise.
 * 
 * Example 1:
 * 
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the English
 * alphabet.
 * Example 2:
 * 
 * Input: sentence = "leetcode"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 */

#include <stdio.h>
#include <string.h>

#define SET(x, bit) x |= (1 << bit)

int checkIfPangram(char * sentence)
{
    int len = strlen(sentence);
    unsigned long output = 0;
    for (int i=0; i<len; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            SET(output, (sentence[i]-'a'));
            if (output == 0x3FFFFFF) /* All, 0 t0 25 bits are set */
                return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    printf("res : %d\n",checkIfPangram("abc"));
    printf("res : %d\n",checkIfPangram("abcdefghijklmnopqrstuvwxyz"));
    printf("res : %d\n",checkIfPangram("abc1"));
    printf("res : %d\n",checkIfPangram("34"));
    printf("res : %d\n",checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));
    return 0;
}
