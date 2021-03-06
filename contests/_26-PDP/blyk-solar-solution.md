---
layout: solution
codename: solar
---

## Brute force λύση

Κοιτάμε για κάθε αριθμό $$A[i]$$ αν ικανοποιεί τις συνθήκες:
 1. Όλοι οι προηγούμενοι αριθμοί είναι μικρότεροι από $$A[i]$$.
 2. Όλοι οι επόμενοι αριθμοί είναι μεγαλύτεροι από $$A[i]$$.

Για να ελέγξουμε τη συνθήκη 1), διατρέχουμε τις τιμές $$Α[0], ... , A[i-1]$$ και κοιτάμε αν όλες είναι μικρότερες από $$A[i]$$. Για να ελέγξουμε τη συνθήκη 2), διατρέχουμε τις τιμές $$A[i+1], ... , A[N-1]$$ και κοιτάμε αν όλες είναι μεγαλύτερες από $$A[i]$$.

Κρατάμε στην μεταβλητή $$answer$$ τη μεγαλύτερη τιμή που ικανοποιεί τις συνθήκες 1) και 2). Αρχικά θέτουμε την τιμή ως $$-1$$ (τιμή μικρότερη από όλες τις άλλες), και αν παραμείνει ως το τέλος, τυπώνουμε `"NOT FOUND"`.

Η πολυπλοκότητα του αλγορίθμου είναι $$\mathcal{O}(N^2)$$ και χρειάζεται $$\mathcal{O}(N)$$ μνήμη, που δεν είναι αρκετό για να περάσει όλα τα testcases.

{% include code.md solution_name='solar_slow.cc' %}


## Βέλτιση Λύση
Μπορούμε να επιταγχύνουμε την παραπάνω λύση με τις εξής παρατηρήσεις:
 * Έστω $$\mathit{mx}[i] = \max(A[0], .. , A[i-1])$$.
 * Η συνθήκη 1) είναι ισοδύναμε με $$\mathit{mx}[i] < A[i]$$.
 * Μπορούμε να υπολογίσουμε το $$\mathit{mx}[i]$$ χρησιμοποιώντας $$\mathit{mx}[i] = \max(\mathit{mx}[i-1], A[i-1])$$ για $$i>0$$ και $$\mathit{mx}[0] = -1$$.

Αντίστοιχα, η συνθήκη 2) ισοδυναμεί με $$\mathit{mn}[i] = \min(A[i+1], .. , A[N-1]) > A[i]$$ και μπορούμε να το υπολογίσουμε χρησιμοποιώντας $$\mathit{mn}[i] = \min(\mathit{mn}[i+1], A[i+1])$$ για $$i < N-1$$ και $$\mathit{mn}[N-1] = \mathit{MAXK} + 1$$ (μεγαλύτερο από τη μέγιστη δυνατή τιμή).

Η πολυπλοκότητα του αλγορίθμου είναι $$\mathcal{O}(Ν)$$ και χρειάζεται $$\mathcal{O}(Ν)$$ μνήμη.

{% include code.md solution_name='solar_efficient.cc' %}
