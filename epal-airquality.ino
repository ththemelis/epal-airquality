// Συσκευή μέτρησης ποιοτικών χαρακτηριστικών του άερα
// ΕΠΑΛ Καστοριάς

#include <ESP8266WiFiMulti.h>
#include <Tomoto_HM330X.h>
#include "SparkFunBME280.h"
#include "MutichannelGasSensor.h"
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>
#include "params.h"   // Πρέπει να γίνει μετονομασία του αρχείου params_sample.h σε params.h

BME280 bme280;  // Αντικείμενο αισθητήρα θερμοκρασίας/υγρασίας
Tomoto_HM330X pm25; // Αντικείμενο αισθητήρα σωματιδίων
ESP8266WiFiMulti wifiMulti; // Αντικείμενο πελάτη σύνδεσης WiFi

int pm1_0=0, pm2_5=0, pm10_0=0; // Μεταβλητές αποθήκευσης των μετρήσεων των αισθητήρα σωματιδίων
float temperature=0, humidity=0; // Μεταβλητές για την αποθήκευση της θερμοκρασίας και της υγρασίας
float co=0, no2=0, coug=0, no2ug=0;

InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);

// Data point
Point sensor("Air Quality");

void getData() {
  if (!pm25.begin()) {
    Serial.println("Υπάρχει πρόβλημα στον αισθητήρα σωματιδίων.");
    while (1);
  }
  else {
    if (pm25.readSensor()) {
      pm1_0=pm25.atm.getPM1();
      pm2_5=pm25.atm.getPM2_5();
      pm10_0=pm25.atm.getPM10();

      Serial.println();
      Serial.print("PM 1.0: ");
      Serial.println(String(pm1_0).c_str());
      Serial.print("PM 2.5: ");
      Serial.println(String(pm2_5).c_str());
      Serial.print("PM 10: ");
      Serial.println(String(pm10_0).c_str());
    }
  }

  if (bme280.beginI2C() == false)  {
    Serial.println("Υπάρχει πρόβλημα στον αισθητήρα θερμοκρασίας/υγρασίας.");
    while(1);
  } 
  else {
    temperature=bme280.readTempC();
    humidity=bme280.readFloatHumidity();
    Serial.print("Υγρασία: ");
    Serial.println(humidity, 2);  
    Serial.print("Θερμοκρασία: ");
    Serial.println(temperature, 2);
    delay(50);    
  }

  co=gas.measure_CO();
  coug=co * 0.0409 * 28.01; // Μετατροπή ppm σε μg/m3
  if (coug>=0) {
    Serial.print("Συγκέντρωση μονοξειδίου του άνθρακα ");
    Serial.print(coug);
    Serial.print(" μg/m3 - ");
    Serial.print(co);
    Serial.println(" ppm");
  }
  else {
    Serial.print("Σφάλμα μέτρησης CO");
  }  

  no2=gas.measure_NO2();
  no2ug=no2 * 0.0409 * 46.01; // Μετατροπή ppm σε μg/m3
  if(no2ug>=0) {
    Serial.print("Συγκέντρωση διοξειδίου του αζώτου ");    
    Serial.print(no2ug);
    Serial.print(" μg/m3 - ");
    Serial.print(no2);
    Serial.println(" ppm");    
  }
  else { 
    Serial.print("Σφάλμα μέτρησης NO2");
  }
}

void setup(){
  Serial.begin(115200);
  delay(500);

  // Σύνδεση στο δίκτυο WiFi
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
//  wifiMulti.addAP(WIFI_SSID1, WIFI_PASSWORD1);
//  wifiMulti.addAP(WIFI_SSID2, WIFI_PASSWORD2);

  Serial.print("Σύνδεση στο wifi ");
  Serial.print(WIFI_SSID);
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" ΟΚ");
  
  timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");

  // Έλεγχος της σύνδεσης στον διακομιστή InfluxDB
  if (client.validateConnection()) {
    Serial.print("Πραγματοποιήθηκε σύνδεση με την Βάση Δεδομένων: ");
    Serial.println(client.getServerUrl());
  } else {
    Serial.print("Η σύνδεση με τη Βάση Δεδομένων απέτυχε: ");
    Serial.println(client.getLastErrorMessage());
  }  
  
  sensor.addTag("device", "HX3301");

  timeSync(TZ_INFO, "0.gr.pool.ntp.org", "1.gr.pool.ntp.org");

  gas.begin(0x04);
  gas.powerOn();  
}

void loop(){
  sensor.clearFields();

  getData();
  if (pm1_0 != 0)
    sensor.addField("pm1.0", pm1_0);
  if (pm2_5 != 0)    
    sensor.addField("pm2.5", pm2_5);
  if (pm10_0 != 0)
    sensor.addField("pm10.0", pm10_0);
  
  sensor.addField("temperature", temperature);
  sensor.addField("humidity", humidity);
  sensor.addField("CO", co);
  sensor.addField("COug", coug);
  sensor.addField("NO2", no2);
  sensor.addField("NO2ug", no2ug);

  Serial.print("Δεδομένα προς την βάση δεδομένων: ");
  Serial.println(sensor.toLineProtocol());

  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("Η σύνδεση με το Wifi χάθηκε");
  }

  if (!client.writePoint(sensor)) {
    Serial.print("Σφάλμα εγγραφής δεδομένων στη βάση: ");
    Serial.println(client.getLastErrorMessage());
  }

  Serial.println("Επόμενη μέτρηση σε 1 λεπτό");
  delay(60000);
}
