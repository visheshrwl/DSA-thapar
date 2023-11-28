# Spiral Matrix

Given an ```m x n matrix```, return all elements of the matrix in ```spiral order```.

Example 1:

![Alt text](Assets/spiraln.jpg)

```
Input: n = 3
Output[[1,2,3], [8,9,4], [7,6,5]]
```

Example 2:
 ```
 Input: n = 1
 Output: [[1]]
 ```

 Constraints: 
 - ```1 <= n <= 20```

## Thought Process

```
top = 0
left = 0
down = N-1
right = N-1

int dir = 0;

dir = 0  ==>(Move Right) 
dir = 1 (Move Down)
dir = 2 <== (Move Left)
dir = 3 (Move Up)

while(top<= down && left <= right){
    if(dir == 0){
        for(i = left -> right){
            print(a[top][i]) //As the row will be constant 
        }
        top += 1;
    }
    else if(dir == 1){
        for(i = top -> down){
            print(a[i][Right]) //column is constant
        }
        right -= 1;
    }
    else if(dir == 2){
        for (i = right -> left){
            print(a[down][i]) //row is constant
        }
        down -= 1;
    }
    else if(dir == 3){
        for(i = down -> top){
            print(a[i][left]) //Column is constant
        }
        left += 1;
    }
    dir = (dir + 1) % 4;  // to create cycles
}
```