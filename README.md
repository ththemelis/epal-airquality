# Συσκευή μέτρησης ποιότητας αέρα

<img src="images/epalair.jpg" alt="Συσκευή μέτρησης ποιότητας αέρα">

Η συσκευή μέτρησης ποιότητας αέρα έχει την δυαντότητα λήψης και καταγραφής των παρακάτω μεγαθών του αέρα:
1. Θερμοκρασία αέρα
2. Υγρασία αέρα
3. Συγκέντρωση μονοξειδίου του άνθρακα
4. Διοξείδιο του αζώτου
5. Σωματίδια μεγέθους 1μm, 2.5μm και 10μm

Οι μετρήσεις αποθηκεύονται σε βάση δεδομένων και προβάλλονται, με την μορφή διαγραμμάτων, στη διεύθυνση https://clnt-2gym-kastor.kas.sch.gr:3000/d/LPjZPh8nz/poioteta-aera?orgId=1&refresh=1m

## Υλικό και λογισμικό που χρησιμοποιήθηκε
Για την δημιουργία της συσκευής χρησιμοποιήθηκαν τα παρακάτω υλικά:
1. <a href="https://www.wemos.cc/en/latest/d1/d1_mini.html">ESP8266 (WeMos Mini)</a>
2. <a href="https://wiki.seeedstudio.com/Grove-Laser_PM2.5_Sensor-HM3301/">Grove - Laser PM2.5 Sensor (HM3301)</a>
3. <a href="https://wiki.seeedstudio.com/Grove-Multichannel_Gas_Sensor/">Grove - Multichannel Gas Sensor</a>
4. <a href="https://www.raspberrypi.com/products/raspberry-pi-4-model-b/">Raspberry Pi 4 (Λειτουργεί ως διακομιστής αποθήκευσης και προβολής δεδομένων)</a>

Για την αποθήκευση και προβολή των δεδομένων χρησιμοποιήθηκαν τα παρακάτω λογισμικά:
1. Βάση δεδομένων (<a href="https://www.influxdata.com/" target="_blank">InfluxDB</a>)
2. Προβολή γραφημάτων (<a href="https://grafana.com/" target="_blank">Grafana</a>)

## Ομάδα μαθητών που συμμετείχε στο έργο
1.
