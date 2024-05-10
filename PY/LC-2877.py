import pandas as pd
from typing import List


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    cols = ["student_id", "age"]
    return pd.DataFrame(student_data, columns=cols)

if __name__ == "__main__":
    student_data = [[1, 20], [2, 21], [3, 22]]
    print(createDataframe(student_data)) 
    # Output: 
    #    student_id  age
    # 0           1   20
    # 1           2   21
    # 2           3   22