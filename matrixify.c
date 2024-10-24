#include <stdio.h>
#include <stdlib.h>

// Student name: Taniya Jones
// UCFID: 5317937

// Function to create a 1D array and print its contents
int* createOneDimensionalArray(int size) {
    int *array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        array[i] = 1; // Initialize all elements to 1
    }

    // Output: Size and array values
    printf("Array of size %d is created.\n", size);
    printf("Array values: {");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return array;
}

// Function to create a matrix (2D array) and print its contents
int** createMatrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1; // Initialize all elements to 1
        }
    }

    // Output: Matrix size and values
    printf("Matrix of size (%d, %d) is created.\n", rows, cols);
    return matrix;
}

// Function to read a file and create matrices
void readFile(char *fileName, int *rows1, int *cols1, int *rows2, int *cols2, int ***matrix2) {
    FILE *file = fopen(fileName, "r"); // Use the fileName parameter to open the file
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read dimensions of the two matrices
    if (fscanf(file, "%d %d %d %d", rows1, cols1, rows2, cols2) != 4) {
        printf("Error reading matrix dimensions.\n");
        fclose(file);
        return;
    }

    printf("Matrix of size (%d, %d) is found.\n", *rows1, *cols1);
    printf("Matrix of size (%d, %d) is found.\n", *rows2, *cols2);

    // Allocate memory for the second matrix and read its values from the file
    *matrix2 = (int**)malloc(*rows2 * sizeof(int*));
    for (int i = 0; i < *rows2; i++) {
        (*matrix2)[i] = (int*)malloc(*cols2 * sizeof(int));
        for (int j = 0; j < *cols2; j++) {
            if (fscanf(file, "%d", &(*matrix2)[i][j]) != 1) {
                printf("Error reading matrix values.\n");
            }
        }
    }

    fclose(file);
}

// Function to add two matrices and print the result
int** addMatrices(int **defaultMatrix, int **readInMatrix, int rows, int cols) {
    int **sumMatrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        sumMatrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            sumMatrix[i][j] = defaultMatrix[i][j] + readInMatrix[i][j];
        }
    }

    // Output: The resulting matrix after addition
    printf("Sum of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }

    return sumMatrix;
}

// Function to compute the diagonal sum of a matrix
int computeDiagonalSum(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("Matrix is not square. Cannot compute diagonal sum.\n");
        return -1;
    }

    int diagonalSum = 0;
    for (int i = 0; i < rows; i++) {
        diagonalSum += matrix[i][i]; // Main diagonal
    }

    // Output: The diagonal sum
    printf("Diagonal Sum is: %d\n", diagonalSum);
    return diagonalSum;
}

// Main function
int main() {
    // Hard-code the filename here
    char *filename = "matrixify_data.txt"; // Specify the filename directly

    int rows1, cols1, rows2, cols2;
    int **matrix2;

    // Call readFile with the hard-coded filename
    readFile(filename, &rows1, &cols1, &rows2, &cols2, &matrix2);

    // Create and print 1D arrays
    for (int i = 0; i < rows1; i++) {
        int *array = createOneDimensionalArray(cols1); // Create 1D array with size cols1
        free(array); // Free the allocated memory for the array
    }

    // Create a default matrix of size rows1 x cols1
    int **defaultMatrix = createMatrix(rows1, cols1);

    // Check if matrices can be added
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices are not the same size. Cannot add.\n");
        printf("Matrices were not able to be added together.\n");
    } else {
        int **sumMatrix = addMatrices(defaultMatrix, matrix2, rows1, cols1);
        // Compute diagonal sum of the resulting matrix
        computeDiagonalSum(sumMatrix, rows1, cols1);

        // Free sumMatrix memory
        for (int i = 0; i < rows1; i++) {
            free(sumMatrix[i]);
        }
        free(sumMatrix);
    }

    // Free memory of the matrices
    for (int i = 0; i < rows1; i++) {
        free(defaultMatrix[i]);
    }
    free(defaultMatrix);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}
