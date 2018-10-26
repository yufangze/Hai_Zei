/*************************************************************************
	> File Name: 4281.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月25日 星期四 16时08分55秒
 ************************************************************************/
#include <stdio.h>
#define max_n 500000
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

int gas[max_n][max_k] = {0}, dep[max_n + 5] = {0};

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
    for (int i = max_k - 1; i >= 0; i--) {
        if (dep[gas[b][i]] >= dep[a]) b = gas[b][i];
        if (a == b) return a;
    }
    for (int i = max_k - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}

inline void check(int a, int b, int c, int x, int y, int *ans, int *k) {
    int t = dep[a] + dep[b] + dep[c] - dep[x] - 2 * dep[y];
    if (t < *ans) {
        *ans = t;
        *k = x;
    }
    return ;
}

int main() {
    int n, a, b, c, cnt;;
    scanf("%d%d", &n, &cnt);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    int x, y;
    for (int i = 0; i < cnt; i++) {
        int ans = 0x3f3f3f3f, k = 0;
        scanf("%d%d%d", &a, &b, &c);
        x = lca(a, b);
        y = lca(x, c);
        check(a, b, c, x, y, &ans, &k);
        x = lca(a, c);
        y = lca(x, b);
        check(a, b, c, x, y, &ans, &k);
        x = lca(b, c);
        y = lca(x, a);
        check(a, b, c, x, y, &ans, &k);
        printf("%d %d\n", k, ans);
    }
    return 0;
}
