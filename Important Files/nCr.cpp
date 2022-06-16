#define NCR
const ll N = 200043;
ll MOD = 1e9 + 7;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
ll fact[N];
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
// a**(p - 1) % p == 1
// a*(a**(p - 2)) % p == 1
// a**(p - 2) % p == 1 / a
ll inv(ll a, ll mod) { return modpow(a, mod - 2, mod); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv(fact[b], MOD)), inv(fact[a - b], MOD));
}