from typing import List




class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        # import numpy as np

        # matrix = np.array(matrix)

        # # Find the rows and columns that contain 0
        # rows, cols = np.where(matrix == 0)

        # # Set the entire row to 0
        # for row in rows:
        #     matrix[row] = 0
        
        # # Set the entire column to 0
        # for col in cols:
        #     matrix[:, col] = 0

        # matrix = matrix.tolist()
        

        # # Find the rows and columns that contain 0
        rows, cols = set(), set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
        
        # Set the entire row to 0
        for row in rows:
            matrix[row] = [0] * len(matrix[0])
        
        # Set the entire column to 0
        for col in cols:
            for i in range(len(matrix)):
                matrix[i][col] = 0

        return matrix
    



if __name__ == "__main__":
    matrix = [[1,1,1],[1,0,1],[1,1,1]]
    print(Solution().setZeroes(matrix))  # Output: [[1,0,1],[0,0,0],[1,0,1]]
    # Explanation: The entire row of 0 is set to 0.