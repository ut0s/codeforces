#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
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

#ifdef _DEBUG
#define DEBUG(x) cerr << #x << " : " << x << "\n"
#define DEBUG2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n";
#define DEBUG4(w, x, y, z) cerr << "(" << #w << ", " << #x << ", " << #y << ", " << #z << ") = (" << w << ", " << x << ", " << y << ", " << z << ")\n";
#define DEBUG5(v, w, x, y, z) cerr << "(" << #v << ", " << #w << ", " << #x << ", " << #y << ", " << #z << ") = (" << v << ", " << w << ", " << x << ", " << y << ", " << z << ")\n";
#define DEBUG_VEC(vec)                           \
  do {                                           \
    std::cerr << #vec << " = [";                 \
    for (size_t i = 0; i < vec.size(); ++i) {    \
      std::cerr << vec[i];                       \
      if (i < vec.size() - 1) std::cerr << ", "; \
    }                                            \
    std::cerr << "]" << std::endl;               \
  } while (0)

#define DEBUG_VEC_2D(vec)                          \
  do {                                             \
    std::cerr << #vec << " = [" << std::endl;      \
    for (const auto& row : vec) {                  \
      std::cerr << "  [";                          \
      for (size_t i = 0; i < row.size(); ++i) {    \
        std::cerr << row[i];                       \
        if (i < row.size() - 1) std::cerr << ", "; \
      }                                            \
      std::cerr << "]" << std::endl;               \
    }                                              \
    std::cerr << "]" << std::endl;                 \
  } while (0)
#else
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(w, x, y, z)
#define DEBUG5(v, w, x, y, z)
#define DEBUG_VEC(vec)
#define DEBUG_VEC_2D(vec)
#endif

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

const int MOD = 1e9 + 7;
#pragma endregion

#pragma region Main
void iostream_init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  // cout.fill('0');
  // cout.width(3);
}

#ifdef _DEBUG
void test() {
  DEBUG("TEST");
  assert(true);
}
#endif

int main() {
  ::iostream_init();

#ifdef _DEBUG
  test();
#endif

  LL T;
  cin >> T;

  REP(_, T) {
    LL N;
    cin >> N;

    vector<int> A(N, 0);
    REP(i, N) {
      cin >> A[i];
    }
    OUT("");
  }

  return 0;
}
#pragma endregion
