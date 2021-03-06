---
layout: statement
codename: hydrocarbons
---

Σε εκτεταμένες περιοχές των Ελληνικών θαλασσών (θαλάσσια οικόπεδα) εκτιμάται ότι υπάρχουν τεράστιες ποσότητες υδρογονανθράκων. Η άντληση υδρογονανθράκων από μεγάλα βάθη (μέχρι $$3000m$$ κάτω από την επιφάνεια της θάλασσας και μέχρι $$6000m$$ μέσα στον πυθμένα της) μπορεί να γίνει μόνο από ελάχιστες πολύ μεγάλες πολυεθνικές εταιρίες. Η άντληση συμφέρει να πραγματοποιηθεί σε συνάρτηση με έναν πολύ μεγάλο αριθμό παραμέτρων: Η απολήψιμη ποσότητα (και αυτή συνάρτηση πολλών παραμέτρων), το βάθος εξόρυξης, ο αριθμός των απαιτούμενων φρεατίων και η εκτίμηση για σταθερότητα η αύξηση των αντιστοίχων τιμών είναι μερικές από τις βασικές παραμέτρους που πρέπει να εκτιμηθούν.

Εάν η απολήψιμη ποσότητα είναι $$a$$, το βάθος $$b$$ και ο αριθμός φρεατίων $$c$$, μία υπολογιστική σχέση της αποδοτικότητας της επένδυσης που θα μπορούσε να οριστεί για σταθερή τιμή υδρογονανθράκων είναι:

$$a-a(b/3000)-a(c/40)$$

Είναι φανερό ότι η εξόρυξη μπορεί να επιχειρηθεί μόνο εφόσον η υπολογιζόμενη τιμή αποδοτικότητας είναι θετική. Για προφανείς λόγους μεταξύ περισσοτέρων του ενός «θαλασσίων οικοπέδων» η εξόρυξη ξεκινά από αυτό με τη μεγαλύτερη τιμή αποδοτικότητας.
a
## Πρόβλημα

Να αναπτύξετε ένα πρόγραμμα σε μια από τις γλώσσες του IOI (PASCAL, C, C++, Java) το οποίο, αφού διαβάσει τον αριθμό των οικοπέδων και την τριάδα των ακεραίων τιμών $$a, b, c$$ για καθένα από αυτά, θα επιστρέφει σε φθίνουσα σειρά αποδοτικότητας τους αριθμούς των οικοπέδων όπου είναι αποδοτικό να επιχειρηθεί γεώτρηση.

## Αρχεία Εισόδου:
Τα αρχεία εισόδου με όνομα hydrocarbons.in είναι αρχεία κειμένου με την εξής δομή: Στην πρώτη γραμμή υπάρχει ένας ακέραιος αριθμός $$N (1 \leq N \leq 100.000)$$, ο αριθμός των θαλάσσιων οικοπέδων. Θεωρούμε ότι τα οικόπεδα είναι αριθμημένα από $$1$$ έως και $$N$$ με τη σειρά που εμφανίζονται στην είσοδο. Σε κάθε μία από τις επόμενες $$N$$ γραμμές υπάρχει μία τριάδα ακεραίων αριθμών $$a_i, b_i, c_i$$, χωρισμένοι μεταξύ τους με ένα κενό διάστημα. Οι αριθμοί αυτοί δίνουν τις παραμέτρους αποδοτικότητας του $$i$$-οστού οικοπέδου, όπως περιγράφεται παραπάνω. Υποθέστε $$1 \leq a_i \leq 1.000.000.000, 1 \leq b_i \leq 3.000$$ και $$1 \leq c_i \leq 40$$.

## Αρχεία Εξόδου:
Τα αρχεία εξόδου με όνομα hydrocarbons.out είναι αρχεία κειμένου με την εξής δομή. Η πρώτη γραμμή τους περιέχει έναν ακέραιο αριθμό $$M$$: το πλήθος των οικοπέδων στα οποία είναι αποδοτικό να επιχειρηθεί γεώτρηση. Η επόμενη γραμμή περιέχει ακριβώς $$M$$ αριθμούς μεταξύ $$1$$ και $$N$$, χωρισμένους μεταξύ τους με ένα κενό διάστημα: τους αύξοντες αριθμούς των οικοπέδων στα οποία είναι αποδοτικό να επιχειρηθεί γεώτρηση. Τα οικόπεδα θα πρέπει να δίνονται κατά φθίνουσα σειρά της αποδοτικότητάς τους (δηλαδή της τιμής που υπολογίζεται από τον τύπο που δίνεται παραπάνω). Αν δύο οικόπεδα έχουν την ίδια τιμή αποδοτικότητας, τότε θα πρέπει να προηγείται αυτό με τον μικρότερο αύξοντα αριθμό.

Τα αρχεία εξόδου με όνομα sch.out είναι αρχεία κειμένου με την εξής δομή: Έχουν ακριβώς μία γραμμή με τρεις αριθμούς που χωρίζονται μεταξύ τους με έναν κενό χαρακτήρα. Τους αύξοντες αριθμούς των web servers με τη μεγαλύτερη επισκεψιμότητα όπως αυτή προκύπτει από την επεξεργασία του αρχείου καταγραφής.

## Παραδείγματα Αρχείων Εισόδου - Εξόδου:

**1<sup>o</sup>**

| **hydrocarbons.in**      | **hydrocarbons.out** |
| :--- | :--- |
| 4 <br> 45000000 2000 10 <br> 150000000 2000 10 <br> 45000000 2500 20 <br> 90000000 2500 5 | 3 <br> 2 1 4 |

Τα οικόπεδα κατά σειρά έχουν αποδοτικότητα $$3.75*10^6, 12.5*10^6, -15*10^6$$ και $$3.75*10^6$$.

**2<sup>o</sup>**

| **hydrocarbons.in**      | **hydrocarbons.out** |
| :--- | :--- |
| 2 <br> 40000000 2700 30 <br> 30000000 2800 18 | 0 |


## Παρατηρήσεις:

**Μορφοποίηση**: Στην είσοδο αλλά και στην έξοδο, κάθε γραμμή τερματίζει με έναν χαρακτήρα newline.

**Μέγιστος χρόνος εκτέλεσης**: $$1$$ sec.

**Μέγιστη διαθέσιμη μνήμη**: $$64$$ MB.
