#include<bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define rep(i, a, n) for(int i = a ; i < n ; i++)
#define per(i, n, a) for(int i = n - 1 ; i >= a ; i--)
#define FOR(i, a, n) for(int i = a ; i <= n ; i++)
#define ROF(i, n, a) for(int i = n ; i >= a ; i--)
#define ins insert
#define CASE(POINTER) cout << "Case #" << POINTER << ": ";
#define BOOST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define readFile freopen("a.in", "w", stdout);
#define debug(n) cout << #n << " = " << n << endl;
#define VI vector < int >
#define VVI vector < VI >
#define VLL vector < ll >
#define VVLL vector < VLL >

using namespace std;

const int N = 4e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

VI a(N);
VI tree(N);
void build(int v, int l, int r) {
    if(l == r) {
        tree[v] = a[l];
        return;
    }
    build(2 * v, l, (l + r) / 2);
    build(2 * v + 1, (l + r) / 2 + 1, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int sum(int v, int l, int r, int x, int y) {
    if(l >= x && r <= y) {
        return tree[v];
    }
    if(l > y || r < x) {
        return 0;
    }
    return sum(2 * v, l, (l + r) / 2, x, y) + sum(2 * v + 1, (l + r) / 2 + 1, r, x, y);
}

void upd(int v, int l, int r, int id, int val) {
    cout << v _ l _ r _ id _ val << endl;
    if(l == r) {
        tree[v] = val;
        return;
    }
    if(id >= l && id <= r) {
        tree[v] += val - a[id];
        upd(2 * v, l, (l + r) / 2, id, val);
        upd(2 * v + 1, (l + r) / 2 + 1, r, id , val);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    int t, x, y;
    rep(i, 0, m) {
        cin >> t >> x >> y;
        if(t == 1) {
            x--; y--;
            cout << sum(1, 0, n - 1, x, y) << endl;
        } else {
            x--;
            upd(1, 0, n - 1, x, y);
        }
    }
}