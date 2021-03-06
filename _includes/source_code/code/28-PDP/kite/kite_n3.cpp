#include <cstdio>

const size_t MAXN = 2000000;

long N, K;
long M[MAXN + 1]; // Πίνακας με το μήκος των κομματιών

int main () {
    // Διάβασμα αρχείου εισόδου
    freopen("kite.in", "r", stdin);
    scanf("%ld %ld", &N, &K);
    for (long i = 1; i <= N; ++i) { scanf("%ld", &M[i]); }
    
    // Αρχική μέγιστη τιμή: Ν + 1
    // Αν στο τέλος της επανάληψης η τιμή 
    // είναι ακόμα Ν + 1 σημαίνει ότι 
    // κανένα κομμάτι καλούμπας δεν είχε άθροισμα 
    // ίσο με Κ και άρα στην απάντηση πρέπει να τυπώσουμε 0
    long minPieces = N + 1;
    // Για κάθε ζεύγος (i, j), 1 <= i <= j <= N
    for (long i = 1; i <= N; ++i) {
        for (long j = i; j <= N; ++j) {
            // Υπολογισμός αθροίσματος
            long sum = 0;
            for (long k = i; k <= j; ++k) { sum += M[k]; }
            
            // Ανανέωση του ελάχιστου άμα το άθροισμα
            // είναι ίσο με Κ και το μήκος είναι μικρότερο του ελάχιστου
            if (sum == K && j - i + 1 < minPieces) {
                minPieces = j - i + 1;
        	}
        }
    }
    freopen("kite.out", "w", stdout);
    if (minPieces == N + 1) {
        // Δεν βρέθηκε κομμάτι με μήκος Κ
        printf("0\n");
        return 0;
    }
    // Αλλιώς έχουμε βρει κομμάτι
    printf("%ld\n", minPieces);
    return 0;
}

