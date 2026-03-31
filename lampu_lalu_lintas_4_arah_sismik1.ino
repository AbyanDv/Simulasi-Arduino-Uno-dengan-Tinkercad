int utara[]   = {13,12,11}; // merah, kuning, hijau
int barat[]   = {10,9,8};
int selatan[] = {7,6,5};
int timur[]   = {4,3,2};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(utara[i], OUTPUT);
    pinMode(timur[i], OUTPUT);
    pinMode(selatan[i], OUTPUT);
    pinMode(barat[i], OUTPUT);
  }
} //setupnya

// fungsi merah di awal loop
void semuaMerah() {
  digitalWrite(utara[0], HIGH);
  digitalWrite(timur[0], HIGH);
  digitalWrite(selatan[0], HIGH);
  digitalWrite(barat[0], HIGH);
}

// fungsi lampu kuning kedip 3x
void lampuKedip(int lampuKuning) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(lampuKuning, HIGH);
    delay(300);
    digitalWrite(lampuKuning, LOW);
    delay(300);
  }
}

// buat manggil di loop
void lampuBagian(int signal[]) {
  semuaMerah();
  delay(1700); //merah nyala semua 1,7 detik
  
  digitalWrite(signal[0], LOW); //matiin warna merah
  digitalWrite(signal[2], HIGH); //nyalain warna ijo
  delay(5000); //ijo nyala 5 detik

  digitalWrite(signal[2], LOW); //matiin warna ijo
  lampuKedip(signal[1]); // kuning kedip 3x
}

void loop() {
  lampuBagian(utara);
  lampuBagian(timur);
  lampuBagian(selatan);
  lampuBagian(barat);  
}