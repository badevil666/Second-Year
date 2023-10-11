class matrix
{
    private int[][] m;
    private int row;
    private int col;
    matrix()
    {

    }
    matrix(int[][] m, int row, int col)
    {
        this.m = m;
        this.row = row;
        this.col = col;
    }
    matrix(matrix mat)
    {
        this.m = mat.m;
        this.row = mat.row;
        this.col = mat.col;
    }
    void displayMatrix()
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                System.out.print(m[i][j] + " ");
            System.out.println("");
        }   
    }
    public matrix multiply(matrix mat)
    {
            int[][] temp = new int[this.row][mat.col];
            for(int i = 0; i < this.row; i++)
            {
                for(int j = 0; j < mat.col; j++)
                {
                    temp[i][j] = 0;
                    for(int k = 0; k < this.col; k++)
                        temp[i][j] += this.m[i][k] * mat.m[k][j];
                }
            }
            matrix obj = new matrix(temp, this.row, mat.col);
            return obj;
    }
}
public class MatrixMultiplication
{
    public static void main(String[] args)
    {
        int[][] m1 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
        int[][] m2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        int row1 = 4, col1 = 3, row2 = 3, col2 = 4;
        matrix matrix1, matrix2;
        matrix1 = new matrix(m1, row1, col1);
        System.out.println("The first matrix :");
        matrix1.displayMatrix();
        System.out.println("The second matrix :");
        matrix2 = new matrix(m2, row2, col2);
        matrix2.displayMatrix();
        matrix product = new matrix();
        product = matrix1.multiply(matrix2);
        System.out.println("The product matrix :");
        product.displayMatrix();
    }

}