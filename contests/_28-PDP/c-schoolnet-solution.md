---
layout: solution
codename: schoolnet
---

## Επεξήγηση εκφώνησης
Το πρόβλημα μας δίνει ένα γράφημα με $$N$$ κόμβους και $$N-1$$ ακμές, τέτοιο ώστε από κάθε κόμβο να υπάρχει μονοπάτι προς κάθε άλλο κόμβο. Ο κάθε κόμβος έχει και ένα βάρος. Θέλουμε να επιλέξουμε ένα σύνολο κόμβων με ελάχιστο άθροισμα βαρών έτσι ώστε κάθε ακμή να καλύπτεται, δηλαδή να έχει τουλάχιστον ένα από τα δύο της άκρα μέσα στο σύνολο. Το πρόβλημα αυτό είναι γνωστό και ως κάλυμμα κορυφών (vertex cover).

Για παράδειγμα, στον παρακάτω γράφο:

<center>
<img src="/assets/28-pdp-c-schoolnet-tree.svg" width="800" height="400">
</center>

το βέλτιστο vertex cover είναι το {1,3,4} ή το {2,3,4}, με βάρος 12. Ας παρατηρήσουμε ότι δεν υπάρχει πρόβλημα που στο {1,3,4} υπάρχουν ακμές που έχουν και τα δύο τους άκρα στο εν λόγω σύνολο. Το πρόβλημα θα ήταν να μην έχουν κανένα από τα δύο άκρα τους!

Η εκδοχή του vertex cover όπου δίνεται οποιοδήποτε γράφημα είναι NP-Hard. Αυτό, μεταξύ άλλων, σημαίνει ότι αν καταφέρνατε να το λύσετε αποδοτικά, θα παίρνατε αυτόματα $$1$$ εκατομμύριο δολλάρια. Βεβαίως αυτό δεν ισχύει με την απλή εκδοχή που δίνουμε εδώ.

### Δέντρο

Τι κάνει αυτή την εκδοχή απλή; Το γεγονός ότι η εκφώνηση δεν περιγράφει ένα γενικό γράφημα, αλλά ένα δέντρο (γράφημα χωρίς κύκλους). Aς σημειώσουμε εδώ ότι αυτός είναι ο πιο συνηθισμένος τρόπος να μας πει μία εκφώνηση ότι δίνεται δέντρο: $$N$$ κόμβοι, $$N-1$$ ακμές, και συνδεδεμένο γράφημα. Μάλιστα η σχέση ισχύει και από τις δύο κατευθύνσεις. Όλα τα δέντρα έχουν αυτές τις ιδιότητες, και αυτές οι ιδιότητες ορίζουν δέντρο!

Ας αποδείξουμε τον ισχυρισμό μας: Σκεφτείτε να έχετε ένα γράφο με τις ιδιότητες της εκφώνησης, και να ξεκινάτε μία DFS (Depth First Search) από τον κόμβο $$1$$. Κάθε ακμή που θα κοιτάτε, ή θα βλέπει ένα παλιό κόμβο (άρα θα κλείνει κύκλο) ή θα βλέπει ένα καινούργιο κόμβο. Πόσες όμως ακμές του δεύτερου τύπου υπάρχουν; Αφού πρέπει να ανακαλύψουμε άλλους $$N-1$$ κόμβους (όλους εκτός του $$1$$, από τον οποίο ξεκινήσαμε), άλλες τόσες ακμές δεύτερου τύπου θα υπάρχουν. Όμως η εκφώνηση μας λέει ότι το πλήθος των ακμών είναι ακριβώς $$N-1$$. Συνεπώς δεν υπάρχουν ακμές πρώτου τύπου, κι άρα δεν υπάρχουν κύκλοι. Αυτό σημαίνει ότι έχουμε δέντρο.

Η απόδειξη της ανάποδης πλευράς είναι πανομοιότυπη: Αν ξεκινήσουμε DFS από τον κόμβο $$1$$ ενός δέντρου, θα συναντήσουμε $$N-1$$ ακμές δεύτερου τύπου (αφού το δέντρο είναι συνδεδεμένο) και $$0$$ ακμές πρώτου τύπου (αφού το δέντρο δεν έχει κύκλους). Άρα πληρούνται οι προϋποθέσεις της εκφώνησης.

Κάτι καινούργιο: Οι ακμές του δέντρου μας δεν έχουν κατευθύνσεις. Παρόλα αυτά βολεύει *πάντα* να φανταζόμαστε ότι κάποιος κόμβος (πχ ο $$1$$) είναι η ρίζα του δέντρου. Για να έχουμε μια οπτική αναπαράσταση, σκεφτείτε ότι ο κάθε κόμβος είναι μία πολύ μικρή μπαλίτσα, και οι ακμές είναι σχοινιά μήκους $$1$$ μέτρου που συνδέουν δύο μπάλες. Αν κρατήσετε την μπάλα $$1$$ ψηλά, κι αφήσετε τη βαρύτητα να δράσει, οι υπόλοιποι κόμβοι θα πέσουν προς τα κάτω. Τα παιδιά της ρίζας θα απέχουν απόσταση $$1$$ μέτρο, τα παιδιά των παιδιών απόσταση $$2$$ μέτρων, κ.λπ.

Στην παρακάτω εικόνα βλέπουμε ότι το ίδιο δέντρο (αριστερό δέντρο) μπορεί να ριζωθεί με διάφορους τρόπους (κεντρικό και δεξιό δέντρο). Αυτό δεν αλλάζει τίποτα για τον υπολογιστή, αφού έχει να κάνει μόνο με το πώς βλέπουμε εμείς το δέντρο.

<center>
<img src="/assets/28-pdp-c-schoolnet-tree.svg" width="400" height="400">
<img src="/assets/28-pdp-c-schoolnet-rooted-tree-1.svg" width="100" height="400">
<img src="/assets/28-pdp-c-schoolnet-rooted-tree-3.svg" width="100" height="400">
</center>

## Λύση με αναδρομή - $$\mathcal{O}(N)$$
Τι το καλό έχουν τα δέντρα (δηλαδή η έλλειψη κύκλων); Ότι κάνουν την αναδρομή πολύ εύκολη.

Ας πούμε λοιπόν ότι $$VC_{with}(v)$$ είναι μία συνάρτηση που μας δίνει το ζητούμενο vertex cover, για το υπόδεντρο που ξεκινάει από τον κόμβο $$v$$ και εκτείνεται προς τα κάτω. Επιβάλλουμε επιπλέον την έξτρα προϋπόθεση ότι οπωσδήποτε θα διαλέξουμε τον κόμβο $$v$$ στο vertex cover. Aντίστοιχα, ορίζουμε το $$VC_{without}(v)$$ όπου οπωσδήποτε *δε* θα διαλέξουμε τον κόμβο $$v$$ στο vertex cover. Προφανώς το ζητούμενο δίνεται από το

$$min\bigg\{VC_{with}(1),VC_{without}(1)\bigg\}$$

Πώς θα υπολογίσουμε το $$VC_{without}(v)$$; Αφού δε θα συμπεριλάβουμε τον $$v$$, αλλά πρέπει να καλυφθούν όλες οι ακμές του, πρέπει να συμπεριληφθούνε όλα τα παιδιά του. Προφανώς και πρέπει να λυθούν και τα υπόδεντρά τους. Συνεπώς σε ψευδοκώδικα:

```
VC_without(v):
  ans = 0;
  for (x in children(v))
    ans += VC_with(x);
  return ans;
```

Πώς θα υπολογίσουμε το $$VC_{with}(v)$$; Αφού θα συμπεριλάβουμε τον $$v$$, αυτός καλύπτει όλες τις ακμές του. Συνεπώς τα παιδιά του μπορούν είτε να συμπεριληφθούν, είτε να μη συμπεριληφθούν, κι αυτό δε θα αλλάξει τίποτα. Προφανώς και πρέπει να λυθούν και τα υπόδεντρά τους. Συνεπώς σε ψευδοκώδικα:

```
VC_with(v):
  ans = weight[v];
  for (x in children(v))
    ans += min(VC_with(x),VC_without(x));
  return ans;
```

Τι πολυπλοκότητα έχει αυτός ο αλγόριθμος; Στην ουσία θα τρέξει και τις δύο συναρτήσεις, από μία φορά για κάθε κόμβο. Η κάθε συνάρτηση παίρνει χρόνο όσο το πλήθος των παιδιών κάθε κόμβου, δηλαδή περίπου όσο οι ακμές κάθε κόμβου. Καταλήγουμε ότι ο συνολικός χρόνος είναι όσο το πλήθος των ακμών όλου του δέντρου. Ένα δέντρο έχει $$N-1$$ ακμές, και συνεπώς ο συνολικός χρόνος είναι $$\mathcal{O}(N)$$.

Aναλυτικά, ο κώδικας για το πρόβλημα δίνεται παρακάτω:

{% include code.md solution_name='schoolnet.cc' %}