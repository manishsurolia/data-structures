/*
 * Microsoft Interview question.
 * you have been given N dices.
 * each one of them have some number of faces, lets says, 'faces' (1,2,3..faces)
 * you have to find that when you roll these dices, by how many ways, you can 
 * get a total of the dice numbers.
 *
 * for example, 
 * for dice = 1, faces = 6, and total = 4, its just 1 possibility.
 * for dice = 2, faces = 6, and total = 2, its just 1 possibility.
 * for dice = 2, faces = 6, and total = 3, there are 2 possibilities (1,2 and 2,1).
 */

#include <stdio.h>
int dice_roll(int N, int faces, int total)
{
    int res = 0;
    if (total < (N*1)) {
        /* N*1 is the minium we can get from N dices, and total should not be
         * lesser than that.
         */
        return 0;
    }

    if (N == 1) {
        if (total > faces)
            return 0;
        else
            return 1;
    }

    for (int i=1; i<=faces; i++) {
        res = res + dice_roll(N-1, faces, (total-i));
    }

    return res;
}

int main(int argc, char **argv)
{
    printf("result = %d\n",dice_roll(3, 6 ,7));
    return 0;
}

