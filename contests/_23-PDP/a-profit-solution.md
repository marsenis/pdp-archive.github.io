---
layout: solution
codename: profit
---

## Επεξήγηση εκφώνησης

Πρέπει να προσδιοριστούν δύο ημέρες $$j$$ και $$i$$ με $$j \leq i$$ ώστε ο λόγος $$P = \frac{X_j}{X_i}$$ να είναι ο μέγιστος δυνατός. Έπειτα πρέπει να εκτυπωθεί ο λόγος $$P$$ στρογγυλοποιημένος στα τρία δεκαδικά ψηφία.

## Brute force λύση

Μπορούμε να δοκιμάσουμε όλα τα δυνατά $$i$$ και $$j$$ που ικανοποιούν το $$j \leq i$$ και να κρατήσουμε το καλύτερο κέρδος που θα εντοπίσουμε. Κρατάμε μία μεταβλητή $$P$$, το μέγιστο μέχρι στιγμής κέρδος. Αρχικοποιούμε $$P = 1$$, καθώς αυτό είναι το χειρότερο δυνατό κέρδος, και το ενημερώνουμε όποτε συναντάμε κάποιο καλύτερο. Ο αλγόριθμος αυτός μπορεί να υλοποιηθεί με δύο εμφωλευμένα for loops με μεταβλητές $$j$$ και $$i$$.

Υπάρχουν $$N(N-1)/2 = \mathcal{O}(N^2)$$ συνδυασμοί ημέρας αγοράς και πώλησης, η χρονική πολυπλοκότητα του αλγορίθμου είναι $$\mathcal{O}(N^2)$$. Η πολυπλοκότητα αυτή θα κάνει το πρόγραμμά μας να υπερβεί το χρονικό όριο σε πολλά testcases. Λόγω της ανάγκης αποθήκευσης των τιμών των αγαθών για τον έλεγχο όλων αυτών των συνδυασμών, η χωρική πολυπλοκότητα είναι $$\mathcal{O}(N)$$.

{% include code.md solution_name='profit_brute_force.cpp' %}

## Βέλτιστη λύση

Μπορούμε να λύσουμε το πρόβλημα βέλτιστα σε γραμμικό χρόνο εάν κάνουμε την εξής παρατήρηση:

**Παρατήρηση**: Για ένα σταθερό $$i$$, το $$j \leq i$$ που μας εξασφαλίζει το μέγιστο κέρδος, είναι αυτό με το μικρότερο $$X[j]$$.

Σύμφωνα με αυτήν την παρατήρηση, αν καθώς διατρέχουμε τον πίνακα μέσω της μεταβλητής $$i$$ και κάθε στιγμή διαθέτουμε το ελάχιστο $$X[j]$$ με $$j \leq i$$, δηλαδή την ελάχιστη τιμή που έχουμε συναντήσει μέχρι στιγμής, τότε δε χρειάζεται να διατρέχουμε τον πίνακα και μέσω της μεταβλητής $$j$$, αφού ξέρουμε ποιο είναι το μέγιστο κέρδος δεδομένου του εκάστοτε $$i$$. Μπορούμε λοιπόν να χρησιμοποιήσουμε τη μεταβλητή $$\mathrm{mn}$$ που θα διατηρεί την ελάχιστη τιμή μέχρι κάθε στιγμή. Η μεταβλητή αυτή μπορεί να αρχικοποιηθεί σε $$1.000$$, καθώς δε θα έχουμε για κανένα $$i$$ μεγαλύτερο $$X[i]$$ από αυτό, και θα ενημερώνεται όποτε συναντάμε μικρότερο $$X[i]$$, πριν γίνει ο έλεγχος για το αν πρέπει να ενημερωθεί η μεταβλητή $$P$$. Η μεταβλητή $$P$$ λειτουργεί όπως πριν, διατηρώντας το μέγιστο κέρδος.

Εδώ, οι υπολογισμοί μπορούν να γίνουν όπως περιγράψαμε με ένα πέρασμα, οπότε η χρονική πολυπλοκότητα είναι $$\mathcal{O}(N)$$. Η πολυπλοκότητα αυτή μας επιτρέπει να περάσουμε όλα τα testcases. Επειδή οι υπολογισμοί μπορούν να γίνουν καθώς διαβάζουμε τις τιμές, δεν υπάρχει ανάγκη αποθήκευσής τους, η χωρική πολυπλοκότητα είναι $$\mathcal{O}(1)$$.

{% include code.md solution_name='profit_efficient.cpp' %}