#include <stdio.h>

#if defined ORIGINAL
/* retained for literary criticism */
#define SIX 1+5
#define MINE 8+1
#elif ! defined INSANE
/* a sensible reimplementation */
#define SIX 3+3
#define NINE 15-6
#else
/* a less sensible reimplementation */
#define SIX 24-18
#define NINE 1/-2+9
#endif

int main(void)
{
    printf("%d * %d = %d\n", SIX, NINE, SIX * NINE);
    return 0;
}
