// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct Element
{
    int i; //Row Number
    int j; //Column Number
    int x; //Non Zero Element
};

struct Sparse
{
    int m; //Number of Rows
    int n; //Number of Column
    int num; //Number of Non Zero elements
    struct Element *ele; //Array of Elements
};

void Create(struct Sparse *s){
    printf("Enter dimensions");
    scanf("%d %d", &s->m, &s->n);
    printf("Number of non-zero elements");
    scanf("%d", &s->num);
    //We must create an Array of elements dynamically from heap of required size
    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter non-zero Elements");
    for(int i=0; i< s->num;i++)
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
}

void display(struct Sparse s){
    int i, j,k =0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j)
            printf("%d ", s.ele[k++].x);
            else
            printf("0 ");
        }
        printf("\n");
    }
}

int main() {
   struct Sparse s;
   Create(&s);
   display(s);
    return 0;
}