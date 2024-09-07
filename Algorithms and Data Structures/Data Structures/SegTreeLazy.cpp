// Fear is freedom! Subjugation is liberation! Contradiction is truth!
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n"
const int N = 2e5 + 10;
const long long INF = 1e9;
const int MOD = 1e9 + 7;

long long st[4*N], lazy[4*N], a[N];

void build(int idx, int l, int r) {
    if (l == r) st[idx] = a[l];    
    else {
        int mid = (l + r) >> 1;
        build(2*idx, l, mid);
        build(2*idx + 1, mid + 1, r);
        st[idx] = max(st[2*idx], st[2*idx + 1]);
    }
}

void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        st[idx] += lazy[idx]; // Aplicar el cambio pendiente
        // Si no es hoja, propagar a los hijos
        if (l != r) {
            lazy[2*idx] += lazy[idx];      // Propagar al hijo izquierdo
            lazy[2*idx + 1] += lazy[idx];  // Propagar al hijo derecho
        }
        lazy[idx] = 0; // Limpiar el cambio pendiente
    }
}

void update(int idx, int l, int r, int i, int j, int value) {
    push(idx, l, r); // Aplicar cambios pendientes

    if (r < i || l > j) return;  // No intersección
    if (l >= i && r <= j) {      // El segmento está completamente dentro del rango
        lazy[idx] += value;      // Acumular el cambio
        push(idx, l, r);         // Aplicar inmediatamente
        return;
    }

    int mid = (l + r) >> 1;
    update(2*idx, l, mid, i, j, value);
    update(2*idx + 1, mid + 1, r, i, j, value);
    st[idx] = max(st[2*idx], st[2*idx + 1]); // Actualizar el nodo
}

long long query(int idx, int l, int r, int i, int j) {
    push(idx, l, r); // Asegurarse de que los cambios pendientes se hayan aplicado

    if (r < i || l > j) return -INF;  // No intersección
    if (l >= i && r <= j) return st[idx];  // Segmento completamente dentro del rango

    int mid = (l + r) >> 1;
    long long left = query(2*idx, l, mid, i, j);
    long long right = query(2*idx + 1, mid + 1, r, i, j);
    return max(left, right);  // Combinar los resultados
}


void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    while (m--) {
        int type, index, val; cin >> type;
        int l, r;
        if (type&1) {
            cin >> l >> r >> val;
            update(1, 0, n - 1, l - 1, r - 1, val);
        }
        else {
            cin >> index;
            cout << query(1, 0, n - 1, index - 1, index - 1) << "\n";
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt = 1; //cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}