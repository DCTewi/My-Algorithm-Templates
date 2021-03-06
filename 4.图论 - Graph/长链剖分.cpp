#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, cost, next;
} edges[MAXN << 2] ;
int head[MAXN];

const int MAXN = 1e6 + 5;

int fa[MAXN]; // 节点父亲
int dep[MAXN]; // 节点深度
int len[MAXN]; // 节点子树节点个数
int son[MAXN]; // 节点长儿子
int top[MAXN]; // 所在长链的顶部节点

// For son, siz, dep, fa
void dfs1(int x)
{
    dep[x] = dep[fa[x]] + 1; len[x] = dep[x];
    for (int i = head[x]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[x])
        {
            fa[v] = x;
            dfs1(v);
            len[x] += max(len[v], len[x]);
            if (len[v] > len[son[x]])
            {
                son[x] = v;
            }
        }
    }
}
// For top
void dfs2(int x, int tp) // dfs2(root, root)
{
    top[x] = tp;
    if (son[x])
    {
        dfs2(son[x], tp);
    }
    for (int i = head[x]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[x] && v != son[x])
        {
            dfs2(v, v);
        }
    }
}

int main()
{
    return 0;
}