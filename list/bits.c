/*
 * https://aticleworld.com/interview-questions-on-bitwise-operators-in-c/
 */
#include <stdio.h>

#define SET_BIT(x, y) (x |= (1<<y))
#define CLEAR_BIT(x, y) (x &= ~(1<<y))
#define TOGGLE_BIT(x, y) (x ^= (1<<y))

#define SIGN(x) ((x > 0) - (x <0))
#define OPPOSITE_SIGN(x, y) ((x^y) < 0)
#define SAME_SIGN(x, y) ((x^y) > 0)
#define IS_POWER_OF_2(x) ((x !=0) && !(x & (x-1)))
#define CHECK_BIT(x, y) (x & (1<<y))

int count_set_bits(int x)
{
    int count = 0;
    while(x) {
        count += (x & 1);
        x = x>>1;
    }
    return count;
}

int endian_swap(int var)
{
    int byte0, byte1, byte2, byte3;
    byte0 = (var & 0x000000FF);
    byte1 = (var & 0x0000FF00);
    byte2 = (var & 0x00FF0000);
    byte3 = (var & 0xFF000000);

    return ((byte0 << 24) | (byte1 << 8) | (byte2 >> 8) | (byte3 >> 24));

}

int main(void)
{
    int a,b, var = 0x12345678;
    printf("\nsign = %d, sign = %d\n",SIGN(-5000), SIGN(+5));

    a = 10;
    b = -20;
    printf("\nOPPOSITE_SIGN(%d, %d) = %d\n",a,b,OPPOSITE_SIGN(a,b));
    printf("\nSAME_SIGN(%d, %d) = %d\n",a,b,SAME_SIGN(a,b));
    a = 9;
    printf("\nIS_POWER_OF_2(%d) = %d\n",a, IS_POWER_OF_2(a));
    a=2;
    SET_BIT(a, 0);
    printf("\na after SET_BIT : %d\n",a);
    a=2;
    CLEAR_BIT(a,1);
    printf("\na after CLEAR_BIT : %d\n",a);
    a=2;
    printf("\nCHECK_BIT(%d, 1) = %d\n", a, CHECK_BIT(a,1));
    a = 2;
    TOGGLE_BIT(a, 0);
    printf("\na after TOGGLE_BIT : %d\n",a);
    printf("\ncount set bits(2) : %d\n",count_set_bits(9));

    printf("print before endianness change : 0x%x\n",var);
    var = endian_swap(var);
    printf("print after endianness change : 0x%x\n",var);

    return 0;
}
