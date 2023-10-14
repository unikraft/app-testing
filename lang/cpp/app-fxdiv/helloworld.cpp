#include <stdio.h>
#include <fxdiv.h>


/* Division of array by a constant: implementation with FXdiv */
void divide_array_fxdiv(size_t length, uint32_t array[], uint32_t divisor) {
  const struct fxdiv_divisor_uint32_t precomputed_divisor =
    fxdiv_init_uint32_t(divisor);
  for (size_t i = 0; i < length; i++) {
    array[i] = fxdiv_quotient_uint32_t(array[i], precomputed_divisor);
  }
}

int main() {
    // Define your array and divisor
    uint32_t myArray[] = {10, 20, 30, 40, 50};
    uint32_t myDivisor = 5;

    // Calculate the length of the array
    size_t arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    // Call the divide_array_fxdiv function to perform division
    divide_array_fxdiv(arrayLength, myArray, myDivisor);

    // Print the result
    printf("Resulting Array: ");
    for (size_t i = 0; i < arrayLength; i++) {
        printf("%u ", myArray[i]);
    }
    printf("\n");

    return 0;
}