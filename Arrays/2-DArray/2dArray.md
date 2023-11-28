# 2-D Array

## Method-1 
```
int A[3][4] = {
    {1,2,3,4},
    {2, 9,6,8},
    {3,5,7,9}
}
```

```
A[1][2] = 15;
```

|        | 0           | 1             | 2          | 3          |
| :---:  |    :----:   |         :---: |   :----:   |  :----:   |
| 0      |  200/1      | 2/3           |  4/5       | 6/7      |
| 1      |  8/9        | 10/11         | 12/13 (15) |         |
| 2      |             |               |            |         |


## Method-2
```
int *A[3];
A[0] = new int[4];
A[1] = new int[4];
A[2] = new int[4];
```

OR

```
int **A;
A = new int*[3];
A[0] = new int[4];
A[1] = new int[4];
A[2] = new int[4];

```

## Accessing the 2-D array

```
for(i = 0; i < 3; i++){  //for changing the rows
    for(j = 0; j < 4; j++){ //for accessing all the elements in a row
        A[i][j] = i*j;
    }
}
```

