#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, A, B, ans = 0x3f3f3f3f;
inline void money(int p, int m, int d) {
    while (m < A) {
        m += p * a;
        d++;
    }
    while (m - a >= A) {
        B -= b;
        m -= a;
    }
    while (B > 0) {
        B -= p * b;
        d++;
    }
    ans = min(ans, d);
}
inline void dfs(int p, int m, int d) {//人 钱 天
    if (p > n + 15)
        return;
    money(p, m, d);
    while (m < c) {
        m += p * a;
        d++;
    }
    m += p * a * 3;
    d += 3;
    m -= c;
    dfs(p + 1, m, d);
}
int main() {
    scanf("%d%d%d%d%d%d", &n, &a, &b, &c, &A, &B);
    dfs(n, 0, 0);
    cout << ans;
    return 0;
}
