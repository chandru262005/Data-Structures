#include <stdio.h>
#include <stdlib.h>

void del(int *a, int *n, int ele) {
    int i = 0, j = 0, temp;
    for (i = 0; i < *n; i++) {
        if (a[i] != ele) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    *n = j;
}
int *split(int *a,int n,int k,int *re){
int *b=(int *)malloc(sizeof(int)*(n-k));
for(int i=k;i<n;i++){
    b[i-k]=a[i];
}
re[0]=n-k;
re[1]=k;
return b;
}
void sort(int *a, int n, int truth) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (truth == 0 ? (a[j] > a[j + 1]) : (a[j] < a[j + 1])) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insert(int *a, int *n, int ele, int index) {
    *n += 1;
    for (int i = *n - 2; i >= index; i--) {
        a[i + 1] = a[i];
    }
    a[index] = ele;
}

void update(int *a, int n, int to_, int from_) {
    for (int i = 0; i < n; i++) {
        if (a[i] == from_) {
            a[i] = to_;
        }
    }
}

void exchange(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int* left_shift(int *a, int n, int k) {
    int *now = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        now[i] = a[(i + k) % n];
    }
    return now;
}

int* right_shift(int *a, int n, int k) {
    int *now = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        now[i] = a[(i + n - k) % n];
    }
    return now;
}

int* merge(int *a, int *n) {
    printf("Enter the size of the second array: ");
    int m;
    scanf("%d", &m);
    int *b=(int*)malloc(sizeof(int)*m);
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
    }
    int *now = (int *)malloc((*n + m) * sizeof(int));
    for (int i = 0; i < *n; i++) {
        now[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        now[*n + i] = b[i];
    }
    *n+=m;
    return now;
}

void copy(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void display(int *a, int n) {
    printf("The array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int search(int *a, int n, int ele) {
    for (int i = 0; i < n; i++) {
        if (a[i] == ele) {
            printf("Element %d found at index %d\n", ele, i);
            return i;
        }
    }
    printf("Element %d not found\n", ele);
    return -1;
}
int *initilize(int *now){
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    *now=n;
    return a;
}
int main() {
    int choice, ele, from, i, j,re[2];
    int *b,*a;
    int n;
    printf("1. Delete\n2. Sorting\n3. Searching\n4. Updating\n5. Exchanging values\n6. Rotating left\n7. Rotating right\n8. Merging\n9. Traversing\n10. Display\n11. Copying\n12. Split array\n13.insert\n14.exit\n15.initialize");
    do {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to delete: ");
                scanf("%d", &ele);
                del(a, &n, ele);
                display(a, n);
                break;
            case 2:
                printf("In ascending order:\n");
                sort(a, n, 0);
                display(a, n);
                printf("In descending order:\n");
                sort(a, n, 1);
                display(a, n);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &ele);
                search(a, n, ele);
                break;
            case 4:
                printf("Enter the value to be changed: ");
                scanf("%d", &from);
                printf("Enter the element to replace %d with: ", from);
                scanf("%d", &ele);
                update(a, n, ele, from);
                display(a, n);
                break;
            case 5:
                printf("Enter the indices i and j to be exchanged: ");
                scanf("%d %d", &i, &j);
                exchange(a, i, j);
                display(a, n);
                break;
            case 6:
                printf("Enter k elements to be shifted: ");
                scanf("%d", &ele);
                b = left_shift(a, n, ele);
                free(a);
                a = b;
                display(a, n);
                break;
            case 7:
                printf("Enter k elements to be shifted: ");
                scanf("%d", &ele);
                b = right_shift(a, n, ele);
                free(a);
                a = b;
                display(a, n);
                break;
            case 8:
                free(b);
                int *merged = merge(a,&n);
                free(a);
                a = merged;
                display(a, n);
                free(b);
                break;
            case 9:
                display(a, n);
                break;
            case 10:
                display(a, n);
                break;
            case 11:
                copy(a, b, n);
                display(b, n);
                free(b);
                break;
            case 12:
                printf("Enter the index from where to be splited:");
                scanf("%d",&ele);
                b=split(a,n,ele,re);
                n=re[0];
                display(a,n);
                display(b,re[1]);
                break;
            case 13:
                printf("Enter the element to be inserted and the index:");
                scanf("%d %d",&ele,&i);
                insert(a,&n,ele,i);
                display(a,n);
                break;
            case 14:
                choice=0;
                break;
            case 15:
                a=initilize(&n);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);
    free(b);
    free(a);
    return 0;
}
