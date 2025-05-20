#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * twice.c
 * 
 * Trains a model that tries to predict some number based on the input number.
 * Would respond to the following mathematical formula:
 *                  y = x * w
 * where w is some parameter that the model is trying to predict.
 * 
 * In our case, we start with 1 parameter. GPT-4 has something like a trillion (1 * 10^12 parameters).
 * 
*/

// Training data.
float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};
#define train_count (sizeof(train)/sizeof(train[0]))

// y = x * w

float rand_float() 
{
    return (float) rand() / (float) RAND_MAX;
}


int main(void) 
{
    //srand(time(0));
    srand(69);

    float w = rand_float() * 10000.0f;
    printf("%f\n", w);

    // Cost function.
    float variance = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        // Getting input from training data.
        float x = train[i][0];

        // Applying the model.
        float y = x * w;

        // Calculating variance (distance between values squared).
        float d = y - train[i][1];
        variance += d * d;

        // Compare the two.
        printf("Actual: %f, Expected: %f\n", y, train[i][1]);
    }
    variance /= train_count;

    printf("Variance: %f\n", variance);

    return 0;
}
