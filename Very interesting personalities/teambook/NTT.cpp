const int gen = 5;

 
int pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % MOD;
    if (step & b) x = (long long)x * a % MOD;
    step >>= 1;
  }
  return x;
}
 
void fft(vector <int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int j = 0;
    int x = i, y = n - 1;
    while (y > 0) {
      j = (j << 1) + (x & 1);
      x >>= 1;
      y >>= 1;
    }
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 1; len < n; len *= 2) {
    int root = pw(gen, (MOD - 1) / (2 * len));
    for (int i = 0; i < n; i += 2 * len) {
      int w = 1;
      for (int j = 0; j < len; j++) {
        int u = a[i + j];
        int v = (long long)a[i + j + len] * w % MOD;
        a[i + j] = u + v;
        if (a[i + j] >= MOD) a[i + j] -= MOD;
        a[i + j + len] = u - v;
        if (a[i + j + len] < 0) a[i + j + len] += MOD;
        w = (long long)w * root % MOD;
      }
    }
  }
}
 
vector <int> multiply(vector <int> a, vector <int> b) {
  int an = a.size();
  int bn = b.size();
  int need = an + bn - 1;
  int nn = 1;
  while (nn < 2 * an || nn < 2 * bn) nn <<= 1;
  a.resize(nn);
  b.resize(nn);
  fft(a);
  fft(b);
  for (int i = 0; i < nn; i++) a[i] = (long long)a[i] * b[i] % MOD;
  reverse(++a.begin(), a.end());
  fft(a);
  int inv = pw(nn, MOD - 2);
  for (int i = 0; i < nn; i++) a[i] = (long long)a[i] * inv % MOD;
  a.resize(need);
  return a;
}
