#include <stdio.h>
#include <stdlib.h>
/*This lab is titled: Combining 1D and 2D Arrays for Matrix Row Operations. I worked with both 1D & 2D arrays, 3 * 3,
and used 1D array to store the sum of elements from each row of a 2D array. I have shown how 1D and 2D arrays
can be used together to manipulate and store related data*/

int main()
{
    int arr[9];  // Declaring 1D array to store 9 numbers
    int matrix[3][3];  // Declaring 2D array to store the numbers in 3 x 3 matrix
    int rowSum[3];  // Declaring 1D array to store the sum of each row

    // Prompt the user to enter 9 numbers that will be used to form the 2D array
    printf("Enter 9 integers consecutive to represent 3 rows of 3 digits:\n");

    // Input the numbers into the 1D array using for loop that will enable us input 9 numbers
    for (int i = 0; i < 9; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the 1D array
    printf("\n1D Array: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Convert the 1D array into a 2D array
    int k = 0;  // Index for the 1D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = arr[k++];
        }
    }

    // Display the 2D array
    printf("\n2D Array (3x3 Matrix):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");  // Newline after each row
    }

    // Calculate the sum of each row and store in rowSum array using nested for loop.
    for (int i = 0; i < 3; i++) {
        rowSum[i] = 0;  // Initialize the sum for the current row to 0
        for (int j = 0; j < 3; j++) {
            rowSum[i] += matrix[i][j];  // Add the element of the current row to the sum
        }
    }

    // Display the sum of each row
    printf("\nSum of each row:\n");
    for (int i = 0; i < 3; i++) {
        printf("Sum of row %d: %d\n", i + 1, rowSum[i]);
    }

    return 0;

}
