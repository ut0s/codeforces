#include <bits/stdc++.h>

#include <iostream>
using namespace std;

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long uLL;
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())

#define REPI(i, a, b) for (LL i = LL(a); i < LL(b); ++i)
#define REP(i, N) for (LL i = LL(0); i < LL(N); ++i)
#define REPS(i, N) for (int i = 1; i <= (int)(N); i++)
#define RREP(i, N) for (int i = ((int)(N)-1); i >= 0; i--)
#define RREPS(i, N) for (int i = ((int)(N)); i > 0; i--)

#define chmax(ret, x) ret = max(ret, x)
#define chmin(ret, x) ret = min(ret, x)

#define FILL(x, e) memset(x, e, sizeof(x))
#define ZEROS(x) fill(x, 0)

#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))

#define UNIQ(x) x.erase(unique(ALL(x)), x.end());

#define BIT(n) (1LL << (n))

#define OUT(x) cout << (x) << "\n"
#define DEBUG(x) cerr << #x << " : " << x << "\n"
#define DEBUG2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n";
#define DEBUG4(x, y, z, w) cerr << "(" << #x << ", " << #y << ", " << #z << ", " << #w << ") = (" << x << ", " << y << ", " << z << ", " << w << ")\n";

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

const int MOD = 1e9 + 7;

void iostream_init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  // cout.fill('0');
  // cout.width(3);
}

int main() {
  ::iostream_init();

  LL T;
  cin >> T;

  REP(_, T) {
    int N, K;
    cin >> N >> K;

    DEBUG2(N, K);
    if (K == 0) {
      OUT(0);
      continue;
    }
    int ans = 0;
    int c   = 1;

    int diagnal_point = N;
    while (K > 0 && diagnal_point > 0) {
      if (K >= diagnal_point) {
        K -= diagnal_point;
        ans++;
      }

      if (c == 0) {
        c++;
      } else {
        diagnal_point--;
        // reset count
        c = 0;
      }
    }
    OUT(ans);
  }

  return 0;
}
