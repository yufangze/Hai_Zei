/*************************************************************************
	> File Name: 7.commen_father.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月23日 星期二 19时39分12秒
 ************************************************************************/
#include <stdio.h>
#define max_n 1000
#define max_k 20
struct Edge {
    int v, n;
} g[max_n << 1];

int head[max_n + 5] = {0}, cnt = 0;

inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}
//gas[i][j]->i点往上走2^j步， 所能到达的祖先节点的编号
int gas[max_n][max_k] = {0}, dep[max_n] = {0};

void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < max_k; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    //对齐
    for (int i = 0; i < max_k; i++) {
        if (l & (1 << i)) b = gas[b][i];
    }
    if (a == b) return a;
    //一起走 
    for (int i = max_k - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("lca(%d, %d) = %d, a->b = %d\n", a, b, lca(a, b), dep[a] + dep[b] - 2 * dep[lca(a, b)]);
    }
    return 0;
}
