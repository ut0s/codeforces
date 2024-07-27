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

string to_cell(LL num) {
  // DEBUG(num);

  string ret{""};
  vector<int> rems;

  rems.PB(num % 26);
  auto div = num / 26;

  while (div != 0) {
    rems.PB(div % 26);
    div = div / 26;
    // DEBUG3(num, div, rems.back());
  }
  // DEBUG_VEC(rems);

  REP(i, SZ(rems) - 1) {
    if (rems[i] == 0) {
      rems[i] = 26;
      rems[i + 1]--;
    } else if (rems[i] == -1) {
      rems[i] = 25;
      rems[i + 1]--;
    }
  }
  if (rems.back() == 0) {
    rems.pop_back();
  }
  reverse(ALL(rems));
  REP(i, SZ(rems)) {
    ret += (char)('A' + rems[i] - 1);
  }

  // DEBUG(ret);
  return ret;
}

LL to_num(string code) {
  LL ret{0};
  reverse(ALL(code));
  REP(i, SZ(code)) {
    ret += int(code[i] - 'A' + 1) * pow(26, i);
  }
  // DEBUG2(code, ret);
  return ret;
}

#ifdef _DEBUG
void test() {
  DEBUG("TEST to_cell");
  assert(to_cell(1) == "A");
  assert(to_cell(26) == "Z");
  assert(to_cell(27) == "AA");
  assert(to_cell(28) == "AB");
  assert(to_cell(52) == "AZ");
  assert(to_cell(53) == "BA");
  assert(to_cell(54) == "BB");
  assert(to_cell(702) == "ZZ");
  assert(to_cell(703) == "AAA");
  assert(to_cell(895) == "AHK");

  DEBUG("TEST to_num");
  assert(to_num("A") == 1);
  assert(to_num("Z") == 26);
  assert(to_num("AA") == 27);
  assert(to_num("AB") == 28);
  assert(to_num("AZ") == 52);
  assert(to_num("BA") == 53);
  assert(to_num("BB") == 54);
  assert(to_num("ZZ") == 702);
  assert(to_num("AAA") == 703);
  assert(to_num("AHK") == 895);
  assert(to_num("RC") == 471);
}
#endif

int main() {
  ::iostream_init();

#ifdef _DEBUG
  test();
#endif

  LL N;
  cin >> N;

  REP(i, N) {
    string S{""};
    cin >> S;
    if (S[0] == 'R' && S[1] >= '1' && S[1] <= '9' && S.find('C') != string::npos) {
      // convert RXCY to EXCELL(BC23)
      auto pos   = S.find('C');
      string row = S.substr(1, pos - 1);
      string col = S.substr(pos + 1, SZ(S));
      DEBUG2(row, col);
      OUT(to_cell(stoi(col)) + row);
    } else {
      // convert EXCELL to RXCY
      std::regex number_pattern("\\d+");
      auto number_begin_iter = std::sregex_iterator(ALL(S), number_pattern);
      string num             = number_begin_iter->str();

      string code = S.substr(0, SZ(S) - SZ(num));
      DEBUG2(code, num);
      OUT("R" + num + "C" + to_string(to_num(code)));
    }
  }

  return 0;
}
#pragma endregion
