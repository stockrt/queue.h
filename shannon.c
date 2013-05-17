/*
 * Created: May 15, 2013
 * Author: Rogério Carvalho Schneider <stockrt@gmail.com>
 */

#include <limits.h>

long int I_SEED = 123456789;

// Shannon random number generator.
// Random number between 0.0 and 1.0.
double randshannon(void)
{
    double random=0;
    long int i=0, j=0;

    I_SEED = 16807 * I_SEED;

    if (I_SEED < 0) {
        I_SEED += LONG_MAX;
    }

    i = I_SEED / 32767;
    j = I_SEED - i * 32767;

    random = j / 32767.;

    return random;
}
