---
layout: statement
codename: sound
---

Στην ψηφιακή καταγραφή του ήχου, ο ήχος περιγράφεται από μια ακολουθία $$N$$ ακέραιων αριθμών που αποτελούν μετρήσεις σε τακτά χρονικά διαστήματα. Κάθε τιμή της ακολουθίας λέγεται δείγμα. Σε πολλές εφαρμογές επεξεργασίας ήχου μάς ενδιαφέρουν οι σιωπές. Οι σιωπές είναι διαστήματα δειγμάτων μεγέθους $$M$$ στα οποία η διαφορά μεταξύ της ελάχιστης και της μέγιστης τιμής δεν ξεπερνάει μια τιμή κατώφλι $$C$$.

## Πρόβλημα

Nα αναπτύξετε ένα πρόγραμμα σε μία από τις γλώσσες του ΙΟΙ το οποίο: αφού διαβάσει τις τιμές των $$N$$, $$M$$ και $$C$$, καθώς και τους ακέραιους αριθμούς που αντιστοιχούν στην ψηφιακή καταγραφή ενός ήχου, να εντοπίζει τις σιωπές.

## Aρχεία εισόδου

Τα αρχεία εισόδου με όνομα **sound.in** είναι αρχεία κειμένου με την εξής δομή: Στην πρώτη γραμμή έχουν τους τρεις ακεραίους
αριθμούς $$N$$ ($$1 \leq N \leq 1.000.000$$), $$M$$ ($$1 \leq M \leq 10.000$$) και $$C$$ ($$0 \leq C \leq 10.000$$), χωρισμένους ανά δύο με ένα κενό διάστημα. Στη δεύτερη γραμμή έχουν διαδοχικά τους $$N$$ ακέραιους αριθμούς $$a[1], a[2], \ldots , a[N]$$, που αντιστοιχούν στα δείγματα της ψηφιακής καταγραφή του ήχου, χωρισμένους ανά δύο με ένα κενό διάστημα. Οι αριθμοί αυτοί θα είναι μεταξύ $$0$$ και $$1.000.000$$.

## Aρχεία εξόδου

Τα αρχεία εξόδου με το όνομα **sound.out** είναι αρχεία κειμένου με την εξής δομή: κάθε γραμμή τους θα περιέχει μία τιμή $$i$$ τέτοια ώστε

$$\max \lbrace a[i], ... a[i+M−1] \rbrace − \min \lbrace a[i], ... a[i+M−1] \rbrace \leq C$$

Οι τιμές των $$i$$ θα πρέπει να εμφανίζονται σε αύξουσα σειρά.

**Προσοχή:** θεωρούμε ότι η αρίθμηση των δειγμάτων αρχίζει από το $$1$$ (δηλαδή το πρώτο δείγμα είναι το $$a[1]$$ και το τελευταίο το $$a[N]$$). 

Αν δεν υπάρχει καμία τέτοια τιμή του $$i$$, το αρχείο εξόδου θα πρέπει να περιέχει μόνο μία γραμμή με τη λέξη «NULL».

## Παράδειγμα αρχείων εισόδου - εξόδου


| **sound.in**                         | **sound.out** |
| ------------------------------------ | ------------- |
| 7 2 0 <br> 0 1 1 2 3 2 2 | 2 <br> 6 |

*Εξήγηση:* Σε αυτό το παράδειγμα των $$N=7$$ δειγμάτων, σιωπή είναι μια σειρά από $$M=2$$ δείγματα που η ελάχιστη και η μέγιστη τιμή τους διαφέρει το πολύ $$C=0$$ (δηλαδή οι σιωπές είναι ζεύγη δειγμάτων με την ίδια τιμή). Υπάρχουν δύο σιωπές: $$1$$, $$1$$ (ξεκινώντας από τη θέση $$a[2]$$) και $$2$$, $$2$$ (ξεκινώντας από τη θέση $$a[6]$$).

**Mορφοποίηση:** Στην έξοδο, όλες οι γραμμές τερματίζουν με ένα χαρακτήρα newline. <br>
**Mέγιστος χρόνος εκτέλεσης:** $$1$$ sec. <br>
**Mέγιστη διαθέσιμη μνήμη:** $$64$$ MB.