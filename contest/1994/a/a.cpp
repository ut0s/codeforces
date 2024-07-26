#include <bits/stdc++.h>
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
#define DEBUG3(x, y, z) cerr << "(" << #x << ", " << #y ", " << #z << ") = (" << x << ", " << y ", " << z << ")\n";
#define DEBUG4(x, y, z, w) cerr << "(" << #x << ", " << #y << ", " << #z << ", " << #w << ") = (" << x << ", " << y << ", " << z << ", " << w << ")\n";

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

int main() {
  int t;
  cin >> t;
  REP(_, t) {
    int m, n;
    cin >> m >> n;

    std::random_device rd;                           // obtain a random number from hardware
    std::mt19937 gen(rd());                          // seed the generator
    std::uniform_int_distribution<> distr(1, m * n); // define the range

    vector<vector<LL>> A;
    vector<vector<LL>> B;
    REP(i, n) {
      vector<LL> a;
      vector<LL> b;
      REP(j, m) {
        LL x;
        cin >> x;
        a.PB(x);

        while (true && (m * n) == 1 && x != 1) {
          LL rand_num = distr(gen);
          if (rand_num != x) {
            b.PB(rand_num);
            break;
          }
        }
      }
      A.PB(a);
      B.PB(b);
    }
    // output
    if ((m * n) == 1 && A[0][0] == 1) {
      OUT(-1);
    } else {
      REP(i, n) {
        REP(j, m) {
          OUT(B[i][j]);
        }
      }
    }
  }
  return 0;
}
