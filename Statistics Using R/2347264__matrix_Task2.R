#1. CREATE TWO MATRICES , matrix_A and matrix_B

matrix_A <- matrix(c(1,2,3,4), 2, 2 , T)
print(matrix_A)
matrix_B <- matrix(c(5,6,7,8), 2 , 2 , T)
print(matrix_B)

#2. CALCULATE THE SUM OF matrix_A AND matrix_B
#   AND STORE THE RESULT IN A NEW MATRIX matrix_sum.

matrix_sum <- matrix_A + matrix_B
print(matrix_sum)

#3. CALCULATE THE DIFFERENCE BETWEEN matrix_A and matrix_B
#   STORE THE RESULT IN A NEW MATRIX NAMED matrix_diff.

matrix_diff <- matrix_A - matrix_B
print(matrix_diff)


#4. MULTIPLY matrix_A BY A SCALAR VALUE OF 2 AND 
#   STORE THE RESULT IN A NEW MATRIX NAMED matrix_mult.

matrix_mult <- 2*matrix_A
print(matrix_mult)


#5. CALCULATE THE PRODUCT OF matrix_A and matrix_B
#   AND STORE THE RESULT IN A NEW MATRIX NAMED matrix_product.

matrix_prod <- matrix_A * matrix_B
print(matrix_prod)


#6. FIND THE TRANSPOSE OF matrix_A AND
#   STORE THE RESULT IN A NEW MATRIX NAMED matrix_A_transpose.

matrix_A_transpose <- t(matrix_A)
print(matrix_A_transpose)


#7. CALCULATE THE DETERMINANT OF matrix_B AND STORE
#   IT IN A VARIABLE NAMED determinant_B.

determinant_B <- det(matrix_B)
print(determinant_B)


#8. INVERT matrix_B AND STORE IT IN matrix_B_inverse.

matrix_B_inverse <- solve(matrix_B)
print(matrix_B_inverse)


#9. CHECK IF matrix_B is orthogonal.
#   (transpose == inverse)

transpose_B <- t(matrix_B)

if(all.equal(transpose_B ,matrix_B_inverse) == TRUE) 
{
  print("Orthogonal")
} else {
  print("NO")
}

#10. CALCULATE THE ELEMENT WISE SQ.ROOT OF matrix_A
#    AND STORE IT IN matrix_A_sqrt.

matrix_A_sqrt <- matrix(c(0,0,0,0),2,2,T)
print(matrix_A_sqrt)

for(i in 1:2) 
{
  for(j in 1:2)
  {
    matrix_A_sqrt[i,j] = sqrt(A[i,j])
  }
}
print(matrix_A_sqrt)
A_sqrt <- sqrt(A)
print(A_sqrt)
 

#11. CALCULATE THE MEAN OF ALL ELEMENTS in matrix_B.

mean_B <- mean(B)
print(mean_B)


#12. CALCULATE THE SUM OF EACH COLUMN IN matrix_A.

col_sum_A <- colSums(matrix_A)
print(col_sum_A)



#13. CALCULATE THE ROW MEANS OF matrix_B.

row_means_B <- rowMeans(matrix_B)
print(row_means_B)

#14. EXTRACT THE SECOND ROW OF matrix_A AND
#   STORE IT IN A VECTOR NAMED second_row_A

second_row_A <- matrix_A[2,]
print(second_row_A)


#15. EXTRACT THE THIRD COLUMN OF matrix_B AND 
#    STORE IT IN A VECTOR NAMED third_column_B.

matrix_B <- matrix(c(1,2,3,4,5,6,7,8,9), 3 , 3, T)
print(matrix_B)

third_column_B <- matrix_B[,3]
print(third_column_B)





