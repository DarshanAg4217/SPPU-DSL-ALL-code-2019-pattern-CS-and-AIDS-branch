def get_matrix_dimensions():
    return int(input("Enter the number of rows: ")), int(input("Enter the number of columns: "))

def get_matrix_elements(rows, columns):
    return [[int(input(f"Enter element at position ({i+1}, {j+1}): ")) for j in range(columns)] for i in range(rows)]

def print_matrix(matrix):
    [print(row) for row in matrix]

def perform_matrix_operation(matrix1, matrix2, operation):
    result = operation(matrix1, matrix2)
    if result is not None:
        print(result)
        return input("Do you want to continue (yes/no): ").lower() == "yes"
    return False

def matrix_addition(matrix1, matrix2):
    return [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def matrix_subtraction(matrix1, matrix2):
    return [[matrix1[i][j] - matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def matrix_multiplication(matrix1, matrix2):
    return [[sum(matrix1[i][k] * matrix2[k][j] for k in range(len(matrix2))) for j in range(len(matrix2[0]))] for i in range(len(matrix1))]

def matrix_transpose(matrix):
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

# Get dimensions for matrices
matrix1_rows, matrix1_columns = get_matrix_dimensions()
matrix2_rows, matrix2_columns = get_matrix_dimensions()

# Get matrix elements
matrix1 = get_matrix_elements(matrix1_rows, matrix1_columns)
matrix2 = get_matrix_elements(matrix2_rows, matrix2_columns)

flag = True
while flag:
    print("\n\n--------------------MENU--------------------\n")
    print("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n")
    ch = int(input("Enter your Choice (from 1 to 5): "))

    operations = [matrix_addition, matrix_subtraction, matrix_multiplication, matrix_transpose, exit]
    if 1 <= ch <= 4:
        flag = perform_matrix_operation(matrix1, matrix2, operations[ch - 1])
    elif ch == 5:
        flag = False
        print("Thanks for using this program!")
    