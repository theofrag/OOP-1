# OOP-1

#### ΑΣΚΗΣΗ 1η #####

Εντολή μεταγλώττισης: g++ -std=c++11 infrastructures.cpp student.cpp  main.cpp -o main
Όταν δωθεί η εντολη για να τρεξει το προγραμμα, θα πρεπει να δωθουν και 4 ακεραιοι ως ορίσματα απο την γραμμη εντολων(πχ main ./10 10 10 10)


Χρειάστηκε η c++11 μονο για την συναρτηση to_string() στην main.

Σημειωση: Το valgrind στα μηχανηματα της σχολης βγαζει οτι υπάρχουν 72.704 bytes που δεν εχουν γίνει free. 
Υστερα απο ψαξιμο στο internet κατέληξα στο οτι ειναι bug της εκδοσης του compiler και οχι προβλημα του προγραμματος μου

------------------------------------------------
Κάθε σχολείο (Class school) αποτελέιται απο:

- 1 δεικτη σε προαυλιο (Class Schoolyard)
- 1 δεικτη σε κλιμακοστάσιο (Class stairs)
- 1 πίνακα 3 δεικτών σε ορόφους (class Floors)
- 4 ακεραίους (Cclass,Cyard,Ccorr,Cstairs)

Όλα τα παραπάνω ειναι private μέλη. Ο χρήστης δεν θα πρέπει να μπορεί να τα δεί, ουτε να τα αλλάξει, διαφορετικα μπορει να προκαλέσει
ανεπιθυμητες λειτουργιες.

Συναρτήσεις μελη-public:

    Constructor του school - School(int,int,int,int):

        Παίρνει ως ορισμα της χωρητικότητες της τάξης,του προαυλιου, του κλιμακοστασίου και του διαδρόμου και αρχικοποιει
        τα αντίστοιχα μέλη.

        Στην συνέχεια δεσμεύει χωρο για τους ορόφους, το κλιμακοστάσιο και το προαυλιο, περνώντας τις ανάλογες χωρητικότητες
        στους constructors τους.

        Τέλος εκτυπώνει το κατάλληλο μύνημα δημιουργίας του σχολείου.

    Είσοδος ενός μαθητή στο σχολείο,οπως περιγράφει η εκφώνηση - Enter(Student&) :

        Παίρνει ως όρισμα έναν μαθητή και ελέγχει αν υπάρχει χώρος στο yard.
        Αν υπάρχει χώρος στο yard καλέι την συνάρτηση enter() του schoolyard και τον βάζει μέσα.
        Ύστερα ελέγχει αν υπάρχει χώρος στο κλιμακοστάσιο (Stairs). Αν υπάρχει τον βγάζει απο το yard και τον βάζει στο stairs.
        Τέλος ελέγχει αν υπάρχει χώρος στο floor που ανήκει ο μαθητής, συμφωνά με την τάξη του. Αν υπάρχει τον βάζει
        στο αντίστοιχο floor(καλώντας την enter του floor), αφού πρώτα τον βγάλει απο το κλιμακοστάσιο(exit του stairs).
        Αν εξ' αρχής δεν υπήρχει χώρος στο yard, απλα επιστρέφει η συνάρτηση.

    Enter(Student**, int):
        Δεχεται ως όρισμα έναν πίνακα μαθητων και το μεγεθος του πινακα. Για καθε μαθητη καλει την Enter(Student& )
        

    Τοποθέτηση δασκάλου,κατευθείαν στην τάξη - place(Teacher& ):
        
        Ελέγχει σε ποια τάξη ανήκει ο δάσκαλος και καλει την place του ορόφου. Ο όροφος με την σειρά του θα καλέσει
        την place την τάξης για να μπεί ο καθηγητής στην τάξη του.
    
    Εκτύπωση σχολείου - print():
        
        Εκτυπώνει το κατάλληλο μήνυμα και καλει τις print() του schoolyard και των stairs. Τέλος καλέι
        την print() του ορόφου και για τους 3 ορόφους.   



Γενίκα κάθε μαθήτης ακολουθεί την μεγιστη διαδρομή που μπορεί να κάνει προς την τάξη, οπως περιγράφθηκε και στο lists σύμφωνα με το 
σεναριο Β.
Όλες οι παραπάνω συναρτήσεις είναι ορατές, γιατί είναι χρησιμες για τον χρηστη.
--------------------------------------------------

Κάθε προαύλιο (Class schoolyard) αποτελέιται απο:
    
    -Ακέραιο που δείχνει την μέγιστη χωρητικότητα(int capacity).
    -Ακέραιο που δείχνει πόσοι μαθητες ειναι μέχρι τώρα στο προαύλιο (int space)
    -Έναν δείκτη σε πίνακα δεικτών σε μαθητές

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά.
Οι συναρτήσεις μέλη, είναι  public, γιατί είναι χρήσιμες στον χρήστη

Συναρτήσεις μέλη-public:

    Constructor του schoolyard- Schollyard(int)

        Παίρνει ως όρισμα την χωρητικότητα του προαυλιού. Αρχικοποιεί τα αντίστοιχα μέλη που σχετίζονται με την χωρητικότητα.
        Αρχικοποιεί τον πίνακα των μαθητών να δείχνει NULL.
        Εκτυπώνει το ανάλογο μήνυμα.

    Είσοδος ενός μαθητή στο προαύλιο - enter(student& s) :
        Παίρνει ως όρισμα έναν μαθητη. Ελέγχει αν υπάρχει ηδη δεσμευμένος χώρος  στον πίνακα των μαθητών
        του μέλους this->students. Αν δεν υπάρχει, δεσμεύει τον ανάλογο χώρο.
        Ελέγχει αν υπάρχει χώρος να μπει και άλλος μαθητής. Αν δεν υπάρχει απλά επιστρέφει η συνάρτηση.
         Τέλος τοποθετεί τον μαθήτη στο τέλος του πίνακα και εκτυπώνει το ανάλογο μήνυμα. 
    
    Έξοδος ενός μαθητή στο προαύλιο - exit() :
        Βγάζει έναν μαθητή απο το τέλος του πίνακα και μειώνει τον αντίστοιχο μετρήτη space.
        Τέλος ορίζει την κατάσταση του μαθήτη ως : "exited_from_schoolYard" . Αυτό ώστε ένας μαθητής να μπορεί
        να προχωρήσει και να μπεί στο Stairs, μόνο αν  είχε βγει απο το προαυλιο σε προηγούμενη στιγμή.
        Κάτι τέτοιο αποτρέπει τον χρήστη απο το να βάζει έναν μαθητή σε δυο μερή ταυτοχρονα ή σε ένα μερος κατευθειαν.
    
    Διαθέσιμος χώρος - get_available_space():
        Απλα ελέγχει αν υπάρχει διαθέσιμος χώρος στο προαυλιο, και επιστρεφει πόσοι μαθητές χωράνε ακόμα.
    
    Εκτύπωση schoolyard - print():
        Eκτυπώνει το καταλληλο μήνυμα και τους μαθήτες που υπάρχουν στο προαύλιο.

----------------------------------------------------

Κάθε κλιμακοστάσιο (Class stairs) αποτελέιται απο:

    -Ακέραιο που δείχνει την μέγιστη χωρητικότητα(int capacity).
    -Ακέραιο που δείχνει πόσοι μαθητες ειναι μέχρι τώρα στο προαύλιο (int space)
    -Έναν πίνακα δεικτών σε μαθητές

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά

Οι συναρτήσεις μέλη έχουν την ίδια συμπεριφορά με αυτες του schoolyard, προσαρμοσμένες όμως στο κλιμακοστάσιο.

-----------------------------------------------------

Κάθε όροφος (Class floor) αποτελέιται απο:
    - 2 ακεραίους που δείχνουν την χωρητικότητα του διαδρόμου και των τάξεων του ορόφου.
    - 1 δείκτη σε διάδρομο (Class corridor)
    - Πίνακα 6 δεικτών σε τάξεις (Class classrooms)
    - 1 ακέραιο που παίρνει τιμες 0,1,2 και δείχνει ποιος όροφος είναι

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά

Συναρτήσεις μέλη:

    Constructor του floor- Floor(int,int,int)
        Παίρνει ως όρισμα την χωρητικότητα του διαδρομου και της ταξης που ανήκουν στον όροφο και 
        ένας αριθμό που συμβολίζει ποιος όροφος είναι.
        Αρχικοποιέι τις αντίστοιχες μεταβλητές (this->Ccorr,this->Cclass) και φτιάνει τον δίαδρομο και τις τάξεις.
        Τέλος εκτυπώνει το ανάλογο μύνημα.

    Είσοδος ενός μαθητή στον όροφο - enter(student& s) :   
        
        Ελέγχει αν υπάρχει διαθέσιμος χώρος στον διάδρομο και αν υπάρχει τον τοποθετεί στον διάδρομο καλώντας την enter του corridor,
        μόνο αν είχε βγει απο το κλιμακοστάσιο σε προηγόυμενη στιγμή, για τους λόγους που αναφέρθηκαν και παραπάνω.
        Ύστερα ελέγχει αν υπάρχει διαθέσιμος χώρος στην τάξη που ανήκει ο μάθητης ή αν έχει μπει δασκαλος. Ανάλογα το αποτέλεσμα
        βάζει τον μαθητη στην τάξη του καλώντας την enter του classroom, αφου τον βγάλει απο τον διάδρομο, καλώντας την 
        exit του διαδρόμου.
    
    Διαθέσιμος χώρος - get_available_space():
        Απλα ελέγχει αν υπάρχει διαθέσιμος χώρος στον διάδρομο, καλώντας την αντίστοιχη συνάρτηση του διαδρόμου.

    Τοποθέτηση δασκάλου,κατευθείαν στην τάξη - place(Teacher& ):
        Ελέγχει σε ποια τάξη ανήκει ο δάσκαλος και καλει την place της τάξης.
    
    Εκτύπωση ορόφου - print():
        Eκτυπώνει το καταλληλο μήνυμα και καλει την print του corridor και την print των τάξεων.
    


--------------------------------------------------------

Κάθε διάδρομος (Class Corridor) αποτελέιται απο:
    -Ακέραιο που δείχνει την μέγιστη χωρητικότητα(int capacity).
    -Ακέραιο που δείχνει πόσοι μαθητες ειναι μέχρι τώρα στο προαύλιο (int space)
    -Έναν πίνακα δεικτών σε μαθητές

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά

Οι συναρτήσεις μέλη έχουν την ίδια συμπεριφορά με αυτες του schoolyard/stairs, προσαρμοσμένες όμως στον corridor.


---------------------------------------------------------

Κάθε τάξη (Class Corridor) αποτελέιται απο:
    -2 ακεραίους που συμβολίζουν τον αριθμό της τάξης. Καθε τάξη χαρακτηρίζεται απο τον αριθμό
        του ορόφου στον οποίο ανήκει και ένας αριθμό απο το 1 εως το 6. Κάθε τάξη έχει μοναδικό
        αριθμό. (Π.χ η τάξη 2.4 είναι η 5η τάξη(η μέτρηση αρχίζει απο το 0) του 3ου ορόφου(η μέτρηση αρχίζει απο το 0) ).
    -Ακέραιο που δείχνει την μέγιστη χωρητικότητα(int capacity).
    -Ακέραιο που δείχνει πόσοι μαθητες ειναι μέχρι τώρα στην τάξη (int space)
    -Ένα πίνακα δεικτών σε μαθητές
    -Μια boolean τιμή που επιστρέφει 'true' αν υπάρχει δάσκαλος στην τάξη, αλλίως 'false'.
    -Έναν δείκτη σε δάσκαλο.

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά. Μπορει να  αλλαξει
    μονο όσα επιτρεπεται με public συναρτησεις
    
Συναρτήσεις μέλη-public:

    Constructor του Classroom- Clasroom(int,int,int):

        Παίρνει ως όρισμα την χωρητικότητα της τάξης, τον αρθμό του ορόφου και τον αριθμό της τάξης.
        Αρχικοποιεί τα ανάλογα μέλη του αντικειμένου και εκτυπώνει το ανάλογο μήνυμα.
    
    Είσοδος ενός μαθητή στην τάξη - enter(student& s) :
        Ίδια συμπεριφορά με τις ανάλογες enter των schoolyard/stairs/corridor
    
    Διαθέσιμος χώρος - get_available_space():
        Απλα ελέγχει αν υπάρχει διαθέσιμος χώρος στο προαυλιο, και επιστρεφει πόσοι μαθητές χωράνε ακόμα.
    
    Δάσκαλος στην τάξη - get_teacher_in():
        Επιστρέφει 'true' αν είναι δάσκαλος στην τάξη, 'false' αλλίως.
    
    Τοποθέτηση δασκάλου στην τάξη - place(Teacher& )
        Άπλα βάζει τον δάσκαλο στην τάξη και ορίζει το μέλος "teacheIn" ως "true".
    
    Εκτύπωση τάξης - print():
        Eκτυπώνει το καταλληλο μήνυμα και ύστερα εκτυπώνει τους μαθητές και τον καθηγητή.

---------------------------------------------------------
Κάθε μαθητης(class Student) αποτελείται απο:

    -2 stings, ενα για την τοποθεσία του και ένα για το όνομα του.
    -2 ακεραίους που συμβολίζουν την τάξη του

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά.
Πχ δεν πρεπει να μπορει να αλλάξει το όνομα του μαθητή αργότερα στο προγραμμα του. Το όνομα του μαθητή δίνεται
    απο την αρχή και δεν αλλαζει, το ιδιο και η ταξη του.

Συναρτήσεις μέλη:

    Constructor του Student- Student(string,int,int):
        Παίρνει ως όρισμα ενα string για να αρχικοποιήσει το όνομα του και δύο ακεραιους για να
            αρχικοποιήσει την τάξη του.
        Ορίζει την αρχική του τοποθεσία ως NULL, δηλαδή οτι δεν βρίσκεται στο σχολείο.
    
    Επιστροφή ονόματος μαθητή- get_name():
        Επιστρέφει το όνομα του μαθητή.
    
    Επιστροφη αριθμου ταξης μαθητη - get_class(): 
        ΟΧΙ ID ΤΑΞΗΣ, αλλα αριθμος ταξης στον οροφο (0,1,2,3,4,5)
        Καθε ταξη χαρακτηρίζεται απο 2 ακεραιους (Ένας για τον όροφο της τάξης - 0->πρωτο,1->δευτερο, 2->τριτο- και 
            ένας για τον αριθμό της τάξης - 0 έως 5-)
    
    Επιστροφη αριθμού ορόφου που ανήκει η τάξη του μαθητή- get_floor:
        Επιστρέφει τον όροφο της τάξης που ανήκει ο μαθητής.
    
    Εκτύπωση μαθητή- print():
        Έκτυπώνει τον μαθητή

--------------------------------------------------------------
Κάθε καθηγητής (class Teacher) αποτελείται απο:
    -string με το όνομα του
    -2 ακεραιους για το μοναδικο ID της τάξης του
    -μια boolean τιμη που είναι true αν ο καθηγητής είναι στην τάξη του

Οι συναρτήσεις μέλη έχουν την ιδια λειτουργια με αυτή του μαθητή (Class Student)


### Main συνάρτηση της 1ης άσκησης ###

    1) Δημιουργεί το σχολικό κτήριο με τις τιμές που δίνονται απο την γραμμή εντολης.
    2) Δημιουργεί μαθητές και δασκάλους. Δημιουργέι 18 καθηγητές(όσοι και οι τάξεις) και
        μαθητές πλήθους 18*Cclass.
    3) Διαλέγει τύχαιο πλήθος μαθητών(απο 0 εως Cclass*N) και για κάθε επανάληψη μεχρι τον αριθμο (Cclass*N) διαλέγει έναν τυχαίο μαθητή.
        Για να εξασφαλιστεί ότι κάθε φορά διαλέγεται μαθητής που δεν έχει μπει στο σχολικό κτήριο εναλλάσεται
        η θέση του μάθητη που διαλέχθηκε με τον τελευταίο μαθητή στον πίνακα και μειώνεται το διάστημα των αριθμών 
        που βγάζει η rand,ετσι ώστε να μην διαλέγει μαθητές που είναι στο τέλος του πίνακα. Δηλαδή μαθητές που έχουν ήδη
        επιλεχθεί.

        Αφου γίνει το προηγούμενο βήμα, διαλέγει τυχαία αν θα τοποθετηθεί δάσκαλος σε αυτη την επανάληψη.
        Αν επιλαγεί να τοποθετηθεί, ξανα επιλέγεται τυχαία το πόσοι δασκάλοι θα μπουν.

        Η επαναλήψεις τελείωνουν είτε όταν μπουν όλοι οι μαθητές στις τάξεις τους ή όταν δεν μπορεί να μπεί άλλος μαθητής
        στην τάξη του.
        Ένας μαθητής δεν μπορεί να μπει στην τάξη του όταν στην τάξη αυτή υπάρχει ήδη δάσκαλος, ή όταν δεν μπορεί να
        προχωρήσει απο τον ένα χώρο στον άλλον, λόγω συνωστισμού.

        Για λόγους απλότητας, επέλεξα να σταματάει η επανάληψη όταν εξαντληθόυν οι μαθητές απο τον πίνακα. Έτσι και αλλίως
        αν δεν χωράει ο μαθητής απλα δεν θα μπεί πουθενα ή θα σταματησει σε ενα χωρο και δεν θα ξαναεπιλεχθεί απο την rand. 
        Άρα ειναι σίγουρο οτι η main τελειώνει με το επιθυμητό αποτέλεσμα, δήλαδη ή οταν όλοι οι μαθητές έχουν μπει στις τάξεις τους
        ή οταν δεν μπορει να μπει άλλος μαθητης.



