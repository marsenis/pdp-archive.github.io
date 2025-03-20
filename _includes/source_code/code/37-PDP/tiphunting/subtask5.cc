#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ll = pair<long, long>;
using vvll = vector<vector<ll>>;

long long positive_part(long long x) { return max(0LL, x); }

// Πρώτη διαπέραση η οποία υπολογίζει το `subtree_loop_opt` για την κορυφή `u`
// κι όλους τους απογόνους της.
//
// subtree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// και καταλλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει
// η κορυφή `u` -- με άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει
// τον δρόμο `(u, parent)`.
void compute_subtree_loop_opt(vector<long long>& subtree_loop_opt, const vvll& tree, const vector<long>& tip, long u, long parent) {
  subtree_loop_opt[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    compute_subtree_loop_opt(subtree_loop_opt, tree, tip, v, u);
    subtree_loop_opt[u] += positive_part(subtree_loop_opt[v] - 2*w);
  }
}

// Δεύτερη διαπέραση η οποία υπολογίζει το `supertree_root_opt` για την κορυφή
// `u` κι όλους τους απογόνους της, χρησιμοποιώντας τις τιμές
// `subtree_loop_opt` που υπολογίσαμε ήδη στην πρώτη διαπέραση.
//
// supertree_root_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// από την κορυφή `u`, καταλλήγει στη ρίζα τους δέντρου και
// μένει πάντα ΕΚΤΟΣ του υποδέντρου που ορίζει η `u`. Το φιλοδώρημα της κορυφής
// `u` ΔΕΝ προσμετράται.
void compute_supertree_root_opt(vector<long long>& supertree_root_opt, const vector<long long>& subtree_loop_opt, const vvll& tree, long u, long parent, long w) {
  assert(0 <= u && u < tree.size());
  assert(-1 <= parent && parent < (long long)tree.size());

  supertree_root_opt[u] = 0;

  if (parent != -1)
    supertree_root_opt[u] = subtree_loop_opt[parent] + supertree_root_opt[parent] - positive_part(subtree_loop_opt[u] - 2*w) - w;

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, v, u, w);
}

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 5);

  long n, q;
  scanf("%li%li", &n, &q);
  
  vector<long> tip(n);
  for (long i = 0; i < n; ++i)
    scanf("%li", &tip[i]);

  // Αναπαράσταση του δέντρου με adjacency list:
  // To `tree[u]` περιέχει ένα vector με pairs `(v, w)` για κάθε κορυφή `v` που
  // συνδέεται με τη `u` με κόστός `w`.
  vvll tree(n);
  for (long i = 0; i < n-1; ++i) {
    long u, v, w;
    scanf("%li%li%li", &u, &v, &w);
    assert(1 <= u && u <= n);
    assert(1 <= v && v <= n);

    tree[u-1].push_back({v-1, w});
    tree[v-1].push_back({u-1, w});
  }

  long src, dst;
  scanf("%li%li", &src, &dst);
  src -= 1;
  dst -= 1;

  vector<long long> subtree_loop_opt(n), supertree_root_opt(n);
  compute_subtree_loop_opt(subtree_loop_opt, tree, tip, src, -1);
  compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, src, -1, -1);

  // Απάντηση στο πρώτο ερώτημα.
  printf("%lli\n", subtree_loop_opt[dst] + supertree_root_opt[dst]);

  // Απάντηση στα υπόλοιπα `q-1` ερωτήματα.
  for (long i = 1; i < q; ++i) {
    scanf("%li%li", &src, &dst);
    src -= 1;
    dst -= 1;
    printf("%lli\n", subtree_loop_opt[dst] + supertree_root_opt[dst]);
  }

  return 0;
}
