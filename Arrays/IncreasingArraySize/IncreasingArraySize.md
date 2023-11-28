# Dynamically Allocate memory for int arrays, copy values from one array to another.

```
int *p = new int[5]; // Dynamically allocate memory for int arrays of size 5
int *q = new int[10]; //Dynamically allocate memory for int arrays of size 10
```
## Assigned values for the individual elements of the 'p' array

```
p[0] = 1;
p[1] = 5;
p[2] = 7;
p[3] = 9;
p[4] = 11;
```

## Copies the value from the 'p' array to the 'q' array.

```
for (int i = 0; i < 5; i++) {
    q[i] = p[i];
}
```
 - Loop copies the values from the `p` array to the `q` array. 
 - Iterates over the index 0 to 4 (inclusive) and assigns the value of the corresponding index from `p` to the same index in `q`.

 ## Delete operator (to free the memory allocated for the 'p' array)

 ```
 delete[] p;
 ```
- This prevents memory leaks.
- This deallocates the memory that was previosly allocated using the `new` operator.

## Pointer "P" Reassigned to the same memory location as the "Q" pointer 
```
p = q;
q = NULL;
```
- This Effectively transfers ownership of the dynamically allocated memory from `q` to `p`.
- The pointer `q` is then set to `NULL` to avoid accidently accessing the memory it used to point to.

## Printing each element

```
for( int i = 0; i < 10; i++) {
    cout << p[i] << " ";
}
```
- This Loop iterates over the `p` array and it prints each element seperated by a space. Since `q` array was copied into the `p` array, the output will be "1 5 7 9 11 0 0 0 0 0 ".

## Deallocating teh memory that was allocated for the `p` array.

```
delete[] p;
```

- Most Important step to avoid memory leaks.
- Ensuring that the memory dynamically allocated with teh 'new' is properly released using `delete[]`.