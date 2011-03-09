/** Find THE number of connected components in a rectangular integer matrix */
/** 2011 03-08 By Julian Yu-Chung Chen (julianyuchungchen@gmail.com)        */

package contComp;

public class FindNumOfContComp {
    private int [][] inputMatrix;
    private int numberOfRows = 0;
    private int numberOfCols = 0;

    public FindNumOfContComp(int [][] input) {
        super();
        inputMatrix = input;
    }

    // Check the matrix and find the number of rows and number of columns.
    // It could be avoided if using customized defined Matrix class.
    boolean isRectMatrix() {
        // Check null or empty input
        if( (inputMatrix == null) || (inputMatrix.length == 0) ) {
            System.err.println("Input matrix is either null or contains 0 row.");

            return false;
        }

        this.numberOfRows = inputMatrix.length;
        this.numberOfCols = inputMatrix[0].length;

        for(int i = 1; i < numberOfRows; ++i) {
            if(inputMatrix[i].length != numberOfCols) {
                return false;
            }
        }

        System.out.println("Input row: " + numberOfRows + ", col: " + numberOfCols);
        return true;
    }

    void doDFS(int r, int c) {
        // boundary check
        if( (r < 0) || (r >= this.numberOfRows) ||
            (c < 0) || (c >= this.numberOfCols) )
        {
            return;
        }

        // Ignore 0 cells
        if(0 == inputMatrix[r][c]) {
            return;
        } else { // Anything but 0
            // Mark this cell, do not need to visit again.
            inputMatrix[r][c] = 0;

            // check neighbors in 4 directions
            // left
            this.doDFS(r, c - 1);

            // up
            this.doDFS(r - 1, c);

            // right
            this.doDFS(r, c + 1);

            // below
            this.doDFS(r + 1, c);
        }
    }

    int getNumberOfContinousComponents() {
        // Support rectangle matrix only
        if(!isRectMatrix()) {
            System.err.println("Bad input matrix");

            return -1;
        }

        int numberOfConnectedComponents = 0;
        for(int r = 0; r < numberOfRows; ++r) {
            for(int c = 0; c < numberOfCols; ++c) {
                if(1 == inputMatrix[r][c]) {
                    numberOfConnectedComponents++;

                    // Do in-place DFS in 4 direction: left, up, right, down
                    doDFS(r, c);
                }
            }
        }

        return numberOfConnectedComponents;
    }

    public static void main(String[] args) {
        // Test cases given in the interview
        // Should do more tests with non-square matrices
        // And maybe more cases which will raise errors
        int [][] input1 = {{1, 0, 1}, {1, 0, 1}, {0, 1, 1}};
        int [][] input2 = {{1, 0, 1}, {0, 1, 1}, {1, 0, 1}};

        FindNumOfContComp f1 = new FindNumOfContComp(input1);
        FindNumOfContComp f2 = new FindNumOfContComp(input2);

        int output1 = f1.getNumberOfContinousComponents();
        int output2 = f2.getNumberOfContinousComponents();

        System.out.println("Output1: " + output1);
        System.out.println("Output2: " + output2);
    }
}
