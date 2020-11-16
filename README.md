# OOP-1

#### ΑΣΚΗΣΗ 1η #####

------------------------------------------------
Κάθε σχολείο (Class school) αποτελέιται απο:

- 1 δεικτη σε προαυλιο (Class Schoolyard)
- 1 δεικτη σε κλιμακοστάσιο (Class stairs)
- 1 πίνακα 3 δεικτών σε ορόφους (class Floors)
- 4 ακεραίους (Cclass,Cyard,Ccorr,Cstairs)

Όλα τα παραπάνω ειναι private μέλη. Ο χρήστης δεν θα πρέπει να μπορεί να τα δεί, ουτε να τα αλλάξει

Συναρτήσεις μελη:

    Constructor του school - School(int,int,int,int):

        Παίρνει ως ορισμα της χωρητικότητες της τάξης,του προαυλιου, του κλιμακοστασίου και του διαδρόμου και αρχικοποιει
        τα αντίστοιχα μέλη.

        Στην συνέχεια δεσμεύει χωρο για τους ορόφους, το κλιμακοστάσιο και το προαυλιο, περνώντας τις ανάλογες χωρητικότητες
        στους constructors τους.

        Τέλος εκτυπώνει το κατάλληλο μύνημα.

    Είσοδος ενός μαθητή στο σχολείο,οπως περιγράφει η εκφώνηση - Enter(Student&) :

        Παίρνει ως όρισμα έναν μαθητή και ελέγχει αν υπάρχει χώρος στο yard.
        Αν υπάρχει χώρος στο yard καλέι την συνάρτηση enter() του schoolyard και τον βάζει μέσα.
        Ύστερα ελέγχει αν υπάρχει χώρος στο κλιμακοστάσιο (Stairs). Αν υπάρχει τον βγάζει απο το yard και τον βάζει στο stairs.
        Τέλος ελέγχει αν υπάρχει χώρος στο floor που ανήκει ο μαθητής, συμφωνά με την τάξη του. Αν υπάρχει τον βάζει
        στο αντίστοιχο floor(καλώντας την enter του floor), αφού πρώτα τον βγάλει απο το κλιμακοστάσιο(exit του stairs).

    Τοποθέτηση δασκάλου,κατευθείαν στην τάξη - place(Teacher& ):
        
        Ελέγχει σε ποια τάξη ανήκει ο δάσκαλος και καλει την place του ορόφου. Ο όροφος με την σειρά του θα καλέσει
        την place την τάξης για να μπεί ο καθηγητής στην τάξη του.
    
    Εκτύπωση σχολείου - print():
        
        Εκτυπώνει το κατάλληλο μήνυμα και καλει τις print() του schoolyard και των stairs. Τέλος καλέι
        την print() του ορόφου και για τους 3 ορόφους.   



Γενίκα κάθε μαθήτης ακολουθεί την μεγιστη διαδρομή που μπορεί να κάνει προς την τάξη, οπως περιγράφθηκε και στο lists.
--------------------------------------------------

Κάθε προαύλιο (Class schoolyard) αποτελέιται απο:
    
    -Ακέραιο που δείχνει την μέγιστη χωρητικότητα(int capacity).
    -Ακέραιο που δείχνει πόσοι μαθητες ειναι μέχρι τώρα στο προαύλιο (int space)
    -Έναν πίνακα δεικτών σε μαθητές

Όλα τα παραπάνω ειναι private μέλη. Δεν ενδιαφέρουν τον χρήστη και συνεπώς δεν πρέπει να έχει πρόσβαση σε αυτά

Συναρτήσεις μέλη:

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
    
Συναρτήσεις μέλη:

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

Συναρτήσεις μέλη:

    Constructor του Student- Student(string,int,int):
        Παίρνει ως όρισμα ενα string για να αρχικοποιήσει το όνομα του και δύο ακεραιους για να
            αρχικοποιήσει την τάξη του.
        Ορίζει την αρχική του τοποθεσία ως NULL, δηλαδή οτι δεν βρίσκεται στο σχολείο.
    
    Επιστροφή ονόματος μαθητή- get_name():
        Επιστρέφει το όνομα του μαθητή.
    
    Επιστροφη αριθμου ταξης μαθητη. ΟΧΙ ID ΤΑΞΗΣ, αλλα αριθμος ταξης στον οροφο
    Καθε ταξη χαρακτηρίζεται απο 2 ακεραιους οπως εχεις εξηγηθεί παραπάνω
    get_class():
        Επιστρέφει τον αριθμό της τάξης του μαθητή
    
    Επιστροφη αριθμού ορόφου που ανήκει η τάξη του μαθητή- get_floor:
        Επιστρέφει τον όροφο της τάξης που ανήκει ο μαθητής.
    
    Εκτύπωση μαθητή- print():
        Έκτυπώνει τον μαθητή

--------------------------------------------------------------
Κάθε καθηγητής (class Teacher) αποτελείται απο:
    -string με το όνομα του
    -2 ακεραιους για το μοναδικο ID της τάξης του
    -μια boolean τιμη που είναι true αν ο καθηγητής είναι στην τάξη του

Οι συναρτήσεις μέλη έχουν την ιδια λειτουργεια με αυτή του μαθητή (Class Student)


### Main συνάρτηση της 1ης άσκησης ###

    1) Δημιουργεί το σχολικό κτήριο( γραμμή 21 του κώδικα) με τις τιμές που δίνονται απο την γραμμή εντολης.
    2) Δημιουργεί μαθητές και δασκάλους ( γραμμή 21-39). Δημιουργέι 18 καθηγητές(όσοι και οι τάξεις) και
        μαθητές πλήθους 18*Cclass.
    3) Παίρνει τύχαιο πλήθος μαθητών(απο 0 εως Cclass*N) και για κάθε επανάληψη διαλέγει έναν τυχαίο μαθητή.
        Για να εξασφαλιστεί ότι κάθε φορά διαλέγεται μαθητής που δεν έχει μπει στο σχολικό κτήριο εναλλάσεται
        η θέση του μάθητη που διαλέχθηκε με τον τελευταίο μαθητή στον πίνακα και μειώνεται το διάστημα των αριθμών 
        που βγάζει η rand ώστε να μην διαλέγει μαθητές που είναι στο τέλος του πίνακα. Δηλαδή μαθητές που έχουν ήδη
        επιλεχθεί.

        Αφου γίνει το προηγούμενο βήμα, διαλέγει τυχαία αν θα τοποθετηθεί δάσκαλος σε αυτη την επανάληψη.
        Αν επιλαγεί να τοποθετηθεί, ξανα επιλέγεται τυχαία το πόσοι δασκάλοι θα μπουν.

        Η επαναλήψεις τελείωνουν είτε όταν μπουν όλοι οι μαθητές στις τάξεις τους ή όταν δεν μπορεί να μπεί άλλος μαθητής
        στην τάξη του.
        Ένας μαθητής δεν μπορεί να μπει στην τάξη του όταν στην τάξη αυτή υπάρχει ήδη δάσκαλος, ή όταν δεν μπορεί να
        προχωρήσει απο τον ένα χώρο στον άλλον, λόγω συνωστισμού.

        Για λόγους απλότητας, επέλεξα να σταματάει η επανάληψη όταν εξαντληθόυν οι μαθητές απο τον πίνακα. Έτσι και αλλίως
        αν δεν χωράει ο μαθητής απλα δεν θα μπεί και δεν θα ξαναεπιλεχθεί απο την rand. Άρα ειναι σίγουρο οτι η main
        τελειώνει με το επιθυμητό αποτέλεσμα.



### ΑΣΚΗΣΗ 2 ###

Δομές που επιλέχθηκαν:
    Class Student -- για τους μαθητες
    Class Sequence -- για τις ακολουθιες
    struct couple -- Απλά ένας πίνακας 2 δεικτών σε δομή τύπου Student

-----------------------------------------------

Class Student αποτελείται απο:

    - 2 strings που συμβολίζουν όνομα και φύλο αντίστοιχα.
    - ακέραιο που συμβολίζει ID τάξης.
    - boolean τιμή που συμβολίζει αν ένας μαθητής είναι άτακτος.

Συναρτήσεις μέλη:

    Student(string ,string ,int ):
        Άπλα αρχικοποιέι τα μέλη του student.
    
    string studentName():
        Άπλα επιστρέφει το όνομα του μαθητή
    
    string studentGender():
        Άπλα επιστρέφει το φύλο του μαθητή
    
    int classroomId():
        'Απλα επιστρέφει το ID της τάξης που ανήκει ο μαθητής
    
    void make_naughty(bool ):
        Άπλα ορίζει έναν μαθητή ως άτακτο ή ήσυχο.
    
    bool is_naughty():
        Επιστρέφει άν true αν ο μαθητής είναι άτακτος, false αλλιως.


Class Sequence αποτελείται απο:
    -



Συναρτήσεις μέλη:
    
    void add_student(Student& ):
        Παίρνει έναν μαθητή, ελέγχει το φύλο του και ανάλογα τον βάζει σε μια θέση στον πίνακα με τα ζευγάρια.
        Επειδή τα αγόρια με τα κορίτσια πρεπει να είναι εναλλαξ, οι ακέραιοι tempBoy και tempGirl ,αλλάζουν τιμές
        απο 0 σε 1 , αναλόγως της προηγούμενης τιμής τους. Καθε κορίτσι αρχικα μπαίνει στην θέση 1 και κάθε αγόρι
        στην θέση 0. Το δεύτερο κορίτσι θα μπει στην θέση 0 και το δευτερο  αγόρι στην θέση 1 και ου το καθεξης.

    void restoreQuitness():

        Η συνάρτηση αυτή αλλάζει τους μαθητές , ωστε να υπάρξει ησυχια

        Παραδοχές που έγιναν:
            - Κάθε μαθητής με το που αλλάζει θέση, αν ήταν άτακτος γίνεται ήσυχος.
              Συνεπώς αν ξανά βρεθεί ύστερα απο τυχαίες επαναλήψεις στην αρχίκη του θέση, δεν θα είναι πλεον άτακτος.

            - Ως διαδόχικα ζευγάρια ορίζονται όσα είναι συνολικά διαδοχικά και όχι κατα περίπτωση διαδοχικά.
              Δηλαδή έστω οτι στην ακολουθια 0001111000111100 με 1 συμβολίζονται τα άτακτα ζευγάρια.
              Τα ζευγάρια αυτά ανήκουν στην κατηγορία των διάσπαρτων ζευγαριών γιατι δεν είναι συνολικά διαδοχικα.
              Αντίστοιχα στην ακολουθια 01111000 τα ζευγάρια με 1, θεωρουνται διαδοχικά.

        Λειτουργία συνάρτησης:

            1ο βήμα(γραμμες κώδικα 192 - 222): Ελέγχω τον αριθμό των άτακτων ζευγαριών και αν αυτά τα ζευγάρια είναι διαδοχικά.
                (γραμμή 205) Αν η μεταβλητή <counter> απο -1 γίνει 0 σημαίνει ότι μόλις βρήκαμε το πρώτο ζευγάρι. Στην συνέχεια των
                επαναλήψεων θα πρέπει να ελένξουμε αν υπάρχουν άλλα ζευγάρια που είναι διαδοχικά με αυτό το ζευγάρι.
                Εφόσον βρήκαμε λοιπόν ζευγάρι πρέπει να ελένξουμε αν αργότερα συναντάμε και άλλο ζευγάρι, που όμως ανάμεσα αυτων
                των δύο ζευγαριών, παρεμβάλονται είτε άτακτος μαθητής, είτε κανένας ατακτος. Σε περίπτωση που ανάμεσα απο δύο ζευγάρια
                παρεμβάλονται τέτοια είδη μαθητών, ΔΕΝ έχουμε διαδοχικά ζευγάρια και άρα το <counter==1>.
            
            2ο βήμα: Αποκατάσταση ησυχίας.
                Υπάρχουν 4 περιπτώσεις:
                    α)  Ένας απο τους δύο μαθητές που είναι στο ζευγάρι να είναι άτακτος.
                        Στην περίπτωση αυτή με rand παράγουμε ένα τυχαίο αριθμο, διαφορετικό απο τον αριθμό της θέσης στην οποία κοιτάμε.
                        Αυτός ο αριθμός θα δείχνει σε μια θέση άλλου  ζευγαριού, με την οποία θα ανταλλάξουμε τον άτακτο
                        μαθητή με έναν ίδιου φύλου μαθητή.
                        Εξετάζουμε και τις δύο θέσεις του ζευγαριού που δείχνει ο τυχαιός αριθμός(0 ή 1), αφού θέλουμε να βρούμε
                        τον ίδιου φύλλου μαθητή. Αφού τον βρούμε τους εναλλάσουμε και αυξάνουμε τον naughtyCounter. Άν ο μαθητής
                        ο οποίος ανταλάχθηκε ήταν και αυτός άτακτος, αφού τον εναλλάξαμε, τον κάνουμε ήσυχο και αυξάνουμε τον
                        naughtyCounter πάλι.
                    
                    β)  Αν έχουμε άτακτα ζευγάρια, αλλά ειναι απο 0 έως και 2.
                        Επαναλαμβάνουμε την ίδια διαδικασία με το (α) και για τους δύο μαθητές.
                    
                    γ)  Άτακτα διάσπαρτα ζευγάρια, περισσοτερα απο 2.
                        Επαναλαμβάνουμε την ίδια διαδικασία με το (α) και για τους δύο μαθητές, με την μόνη
                        διαφορά ότι πλέον εναλλάσουμε με τυχαιους μαθητές απο την επόμενη ακολουθία.
                    
                    δ)  Άτακτα διαδοχικά ζευγάρια, περισσότερα απο 2.
                        Επαναλαμβάνουμε την ίδια διαδικασία με το (α) και για τους δύο μαθητές, με την μόνη
                        διαφορά ότι πλέον εναλλάσουμε με τυχαιους μαθητές απο τυχαία ακολουθία, την οποία
                        διαλέγουμε με rand.
    
    void connect(Sequence& sequence):
        
        Βάζουμε στο τέλος την λίστας των ακολουθιών , την νέα ακολουθία και το member <next> της ακολουθιάς
        που μόλις συνδέθηκε κοιτάει στην αρχή της λίστας, ωστε να σχηματίζεται κυκλική λίστα.
        Τέλος αν στην ακολουθια που μόλις προσθέσαμε ο αριθμος των αγοριων ειναι κατα ένα μεγαλύτερος απο τον
        αριθμό των κοριτσιών ή το αντίθετο, διατρέχουμε την λίστα και ψάχνουμε να βρούμε μια ακολουθία
        οπου έχει και αυτη ένα παραπάνω μαθητή. Αν αυτός ο μαθητής μπορεί να κάνει ζευγάρι με τον επιπλέον μαθητη
        της ακολουθίας που μόλις προσθέσαμε(δηλαδή ειναι αγορι-κοριτσι), τότε μεταφέρεται απο αυτή την ακολουθία
        στην ........ΤΟ DO ΠΡΟΣΟΧΗ ΜΗΝ ΠΑΡΑΔΩΣΕΙΣ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    

    void restore():
        Άπλα καλεί την restoreQuitness() για κάθε ακολουθία που συνδέεται με την ακολουθια, που κάλεσε την συνάρτηση.

    void printSequence():
        Άπλα εκτύπωνει τους μαθητές στα ζευγαρια
    
    
    
    
    

    