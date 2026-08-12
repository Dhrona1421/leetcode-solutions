#include <stdlib.h>

int* sumOfDistancesInTree(int n, int** edges, int edgesSize,
                          int* edgesColSize, int* returnSize) {

    int *ans = calloc(n, sizeof(int));
    int *cnt = malloc(n * sizeof(int));
    int *parent = malloc(n * sizeof(int));
    int *order = malloc(n * sizeof(int));
    int *stack = malloc(n * sizeof(int));

    int **graph = malloc(n * sizeof(int *));
    int *degree = calloc(n, sizeof(int));
    int *pos = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        cnt[i] = 1;
        parent[i] = -1;
    }

    for (int i = 0; i < edgesSize; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++)
        graph[i] = malloc(degree[i] * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][pos[u]++] = v;
        graph[v][pos[v]++] = u;
    }

    /* Build parent and order */
    int top = 0;
    int size = 0;

    stack[top++] = 0;
    parent[0] = -2;

    while (top > 0) {
        int u = stack[--top];
        order[size++] = u;

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i];

            if (v == parent[u])
                continue;

            parent[v] = u;
            stack[top++] = v;
        }
    }

    /* Bottom-up */
    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
        int p = parent[u];

        cnt[p] += cnt[u];
        ans[p] += ans[u] + cnt[u];
    }

    /* Top-down */
    for (int i = 1; i < n; i++) {
        int u = order[i];
        int p = parent[u];

        ans[u] = ans[p] - cnt[u] + (n - cnt[u]);
    }

    *returnSize = n;

    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(degree);
    free(pos);
    free(cnt);
    free(parent);
    free(order);
    free(stack);

    return ans;
}