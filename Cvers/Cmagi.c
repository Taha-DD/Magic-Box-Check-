#include <stdio.h>
#include <stdlib.h>

int sum_line( int *line, int lineSize ){
    int sum = 0;
    
    for ( int *i = line; i < &lineSize[line]; ++i )
        sum += *i;
    
    return sum;
}

int sum_column( int **column, int columnSize, int columnRank ){
    int sum = 0;
    
    for ( int i = 0; i < columnSize; ++i )
        sum += column[i][columnRank];
    
    return sum;
}

int sum_diagonal ( int **diagonal, int matrix_rowSize ){
    int sum = 0;
    
    for ( int i = 0; i < matrix_rowSize; ++i )
        sum += diagonal[i][i];
    
    return sum;
}

int sum_antiDiagonal ( int **anti_diagonal, int matrix_rowSize ){
    int sum = 0;
    
    for ( int i = 0; i < matrix_rowSize; ++i )
        sum += anti_diagonal[i][matrix_rowSize - i - 1];
    
    return sum;
}

int is_magic ( int **box, int num_rows, int num_cols ){
    int magicalNum = sum_line(box[0], num_cols),
        boxSize = num_rows;
    if ( num_rows != num_cols )
        return 0;
    
    for( int i = 0; i < boxSize; ++i ){
        if ( sum_line(box[i], boxSize) != magicalNum )
            return 0;
        
        if ( sum_column( box, boxSize, i ) != magicalNum )
            return 0;
    }
    
    if (sum_diagonal(box, boxSize) == magicalNum && sum_antiDiagonal(box, boxSize) == magicalNum)
        return 1;

    return 0;
}

int is_normal(int **box, int num_rows, int num_cols ){
    return !is_magic( box, num_rows, num_cols );
}

int main() {
    int matrix[][3] = {{2, 7, 6},
                       {9, 5, 1}, 
                       {4, 3, 8}};


    //you can use these two variables to take your input here i tested directly 
    int num_rows = sizeof(matrix) / sizeof(matrix[0]),
        num_cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    
    int **box = malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; ++i)
        box[i] = malloc(num_cols * sizeof(int));

    for (int i = 0; i < num_rows; ++i)
        for (int j = 0; j < num_cols; ++j)
            box[i][j] = matrix[i][j];

    
    printf("%d\n%d", is_magic( box, num_rows, num_cols ), is_normal( box, num_rows, num_cols ));

    return 0;
}
