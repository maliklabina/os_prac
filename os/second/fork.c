#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#define SIZE 5


int i;
void sort_array (int *arr, int size) {
int temp; 
for (int i = 0; i < size - 1; i++) {
for (int j= i + 1; j< size; j++) {
if (arr[i] > arr[j]) {
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
} 
}   


int main() {
    int n, i;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork(); // Create child process

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child Process
        printf("\n[Child] Process ID: %d\n", getpid());
        printf("[Child] Parent ID: %d\n", getppid());
        printf("[Child] Sorting using Selection Sort...\n");

        bubble_sort(arr, n);

        printf("[Child] Sorted Array: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        // Uncomment below sleep to create **orphan**
         sleep(5);
         printf("[Child] Now my parent terminated, I am orphan adopted by init.\n");
        
        exit(0);
    } 
    else {
        // Parent Process
        printf("\n[Parent] Process ID: %d\n", getpid());
        printf("[Parent] Child Process ID: %d\n", pid);
        printf("[Parent] Sorting using Bubble Sort...\n");

        bubble_sort(arr, n);

        printf("[Parent] Sorted Array: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        // Demonstrate Zombie: comment wait() temporarily
        // wait(NULL); // Uncomment to remove zombie

        printf("[Parent] Waiting for child to finish...\n");
        wait(NULL);

        printf("[Parent] Child finished execution.\n");
    }
    return 0;
}
