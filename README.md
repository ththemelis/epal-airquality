# Μετρητής ποιότητας αέρα στο σχολικό περιβάλλον

![](images/epalair.jpg){width="5.315716316710411in"
height="5.364583333333333in"}

## Σύντομη περιγραφή

Η συσκευή μέτρησης ποιότητας αέρα είναι μια συσκευή η οποία έχει την
δυνατότητα να λαμβάνει και να καταγράφει τις μετρήσεις που επηρεάζουν
την ποιότητα του αέρα που αναπνέουμε. Η συσκευή είναι τοποθετημένη μέσα
στο σχολικό κτίριο του ΕΠΑΛ Καστοριάς και πραγματοποιεί τις μέτρηση κάθε
ένα λεπτό. Παρακάτω μπορούμε να δούμε τα χαρακτηριστικά του αέρα που
έχει τη δυνατότητα να μετρήσει η συσκευή.

-   Θερμοκρασία του αέρα

-   Υγρασία του αέρα

-   Συγκέντρωση του μονοξειδίου του άνθρακα

-   Συγκέντρωση του διοξείδιο του αζώτου

-   Συγκέντρωση σωματιδίων μεγέθους 1μm, 2.5μm και 10μm

Για κάθε ένα από τα παραπάνω χαρακτηριστικά του αέρα, έχουν θεσπιστεί
όρια μέσω των οποίων μπορούμε να αξιολογήσουμε την ποιότητά του. Στους
παρακάτω συνδέσμους, μπορούμε να δούμε περισσότερες πληροφορίες για
διάφορους δείκτες ποιότητας του αέρα.

-   <https://ec.europa.eu/environment/air/quality/standards.htm>

-   <https://www.airlab.edu.gr/index.php?option=com_content&view=article&id=74&Itemid=104&lang=el>

-   <https://www.airnow.gov/aqi/aqi-basics/>

Οι μετρήσεις αποθηκεύονται σε βάση δεδομένων και προβάλλονται, με την
μορφή διαγραμμάτων, στη διεύθυνση
<https://clnt-2gym-kastor.kas.sch.gr:3000/d/LPjZPh8nz/poioteta-aera?orgId=1&refresh=1m>

## Εφαρμογές και υλικά που χρησιμοποιήθηκαν

Για την δημιουργία της συσκευής χρησιμοποιήθηκαν τα παρακάτω υλικά:

-   ESP8266 (WeMos Mini)

-   Grove - Laser PM2.5 Sensor (HM3301)

-   Grove - Multichannel Gas Sensor

-   Raspberry Pi 4

-   Breadboard και καλώδια σύνδεσης

-   Τροφοδοτικό 5V

Για την αποθήκευση και προβολή των δεδομένων χρησιμοποιήθηκαν τα
παρακάτω λογισμικά:

-   Προγραμματισμός του ESP8266 με το Arduino IDE

-   Αποθήκευση των μετρήσεων στην βάση δεδομένων InfluxDB

-   Προβολή γραφημάτων με το Grafana

-   Τα παραπάνω λογισμικά εγκαταστάθηκαν και παραμετροποιήθηκαν
    κατάλληλα στο Raspberry Pi 4

## Περίοδος υλοποίησης

Το έργο υλοποιήθηκε κατά την διάρκεια του δεύτερου τετραμήνου του
σχολικού έτους 2021-2022.

## Μέλη της ομάδας

Τα μέλη της ομάδας ανήκουν στο ΕΠΑΛ Καστοριάς και είναι τα παρακάτω:

  -----------------------------------------------------------------------
  Ονοματεπώνυμο                       Τάξη
  ----------------------------------- -----------------------------------
                                      

  -----------------------------------------------------------------------

## Σχολική μονάδα

ΕΠΑΛ Καστοριάς

Εργατικές κατοικίες

52100, Καστοριά

Τηλέφωνο: 2467028206

Email: [mail@1epal-kastor.kas.sch.gr](mail@1epal-kastor.kas.sch.gr)
