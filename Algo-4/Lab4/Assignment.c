#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

#define N 10 // maximum number of workers and tasks

int n; // number of workers and tasks
int c[N][N]; // cost matrix
int perm[N]; // current permutation of assignments
int best_perm[N]; // best permutation of assignments
int min_cost = 0xffffff; // minimum cost found so far

void generate_permutations(int k) {
    int i, j, cost;
    if (k == n) { // all workers have been assigned a task
        cost = 0;
        for (i = 0; i < n; i++) {
            cost += c[i][perm[i]];
        }
        if (cost < min_cost) { // found a better assignment
            min_cost = cost;
            for (i = 0; i < n; i++) {
                best_perm[i] = perm[i];
            }
        }
    } else { // assign worker k to each task and generate permutations recursively
        for (j = 0; j < n; j++) {
            if (perm[j] == -1) { // task j is not yet assigned
                perm[j] = k;
                generate_permutations(k+1);
                perm[j] = -1;
            }
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of workers and tasks (up to %d): ", N);
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        perm[i] = -1;
    }
    generate_permutations(0);
    printf("Minimum cost assignment:\n");
    for (i = 0; i < n; i++) {
        printf("Worker %d assigned to task %d\n", i+1, best_perm[i]+1);
    }
    printf("Minimum cost: %d\n", min_cost);
    return 0;
}