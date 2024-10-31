#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);

// Penamaan pin button switchnya
const int kiri = 2, kanan = 5, ok = 3, back = 6, penjumlahan = 3, perkalian = 1 , pembagian = 2,pengurangan = 4, blank = 5;

int page = 0, cursor = 0,angka_penyebut,angka_pembilang,baris,hasil;
bool nsw_kiri = false, nsw_kanan = false, nsw_ok = false, nsw_back = false,state_kiri,state_kanan,state_ok,state_back,nsw1;
bool kunci = false,kunci1 = false;














void setup() {
  lcd.init();        // Inisialisasi LCD
  lcd.backlight();   // Menghidupkan lampu latar LCD

  // Inisiasi mode pin sebagai input
  pinMode(kiri, INPUT);
  pinMode(kanan, INPUT);
  pinMode(ok, INPUT);
  pinMode(back, INPUT);

  // Greeting
  lcd.setCursor(5, 0);
  lcd.print("KALKULATOR");
  lcd.setCursor(0, 3);
  lcd.print("author:@anxxre_z");

  // Delay 2 detik lalu masuk ke task utama 
  delay(2000);
  lcd.clear();
}

void loop() {
   state_kiri = digitalRead(kiri);
  state_kanan = digitalRead(kanan);
  state_ok = digitalRead(ok);
  state_back = digitalRead(back);

  if (page == 0) tampilan_main();

  if (page == penjumlahan)tampilan_penjumblahan();
  if (page == perkalian)tampilan_perkalian();
if (page == pembagian)tampilan_pembagian();
if (page == pengurangan)tampilan_pengurangan();
if (page == blank){
  lcd.setCursor(0,0);
  lcd.print("please");
lcd.setCursor(0,1);
  lcd.print("press reset button");


  
}

if(state_back == 1 && nsw_back == 0)nsw_back = 1;
if(state_back == 0 && nsw_back == 1){nsw_back = 0;

if(kunci1 == 0){
  kunci1 = 1;
  lcd.clear();
page = blank;
}

}

}

void tampilan_main() {
  //press release algoritma button kiri 
if(state_kiri == 1&& nsw_kiri ==0){
  nsw_kiri=1;
}
if(state_kiri ==0 && nsw_kiri ==1){
  nsw_kiri =0;
  cursor--;
  lcd.clear();
  if(cursor < 0 ){
    cursor=1;
  }
}

if(state_ok == 1 && nsw1 == 0 && page == 0){
nsw1 = 1;
}

if(state_ok == 0 && nsw1 == 1 && page == 0){
nsw1 = 0;


// page selector
switch(cursor){


case 0: page = perkalian;
break;

case 1: page = pembagian;
break;


case 2: page = penjumlahan;
break;

case 3: page = pengurangan;
break;

default: 
break;
}
}


  // Press release algoritma untuk tombol kanan
  if (state_kanan == 1 && nsw_kanan == false) {
    nsw_kanan = true; // Deteksi tombol ditekan
  }
  if (state_kanan == 0 && nsw_kanan == true) {
    cursor++;
    if (cursor > 3) {
      cursor = 0;
      }
    nsw_kanan = false; // Reset saat tombol dilepaskan
    lcd.clear();
  }

  // Menampilkan pilihan di LCD
  
  switch (cursor){
case 0: 
lcd.setCursor(0,1);
lcd.print("-");
break;

case 1:
lcd.setCursor(6,1);
lcd.print("-");
break;

case 2:
lcd.setCursor(12,1);
lcd.print("-");
break;


case 3:
lcd.setCursor(19,1);
lcd.print("-");

default: break;

  }

  lcd.setCursor(0, 0);
  lcd.print("X");

  lcd.setCursor(6, 0);
  lcd.print("/");

  lcd.setCursor(12, 0);
  lcd.print("+");

  lcd.setCursor(19, 0); // Sesuaikan posisi dengan ukuran LCD
  lcd.print("-");

  lcd.setCursor(1, 3);
  lcd.print("Pilih jenis operasi");
  
}

void tampilan_pengurangan(){
  
if (baris == 2) {
    hasil = angka_penyebut - angka_pembilang; // Hitung hasil
  }
if(kunci == 0){
  kunci = 1;
    lcd.clear();
}
lcd.setCursor(0,0);
lcd.println(angka_penyebut);

lcd.setCursor(0,1);
lcd.println(angka_pembilang);

lcd.setCursor(0,2);
lcd.println("----");

lcd.setCursor(5,2);
lcd.print("-");

lcd.setCursor(0,3);
lcd.println(hasil);


// PRESS REALESE PENGURANGAN

//penyebut
if(nsw_kanan == 0 && state_kanan == 1 && baris == 0)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 0){
  nsw_kanan = 0;
  angka_penyebut++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 0)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 0){
  nsw_kiri = 0;
  angka_penyebut--;
}


//pembilang
if(nsw_kanan == 0 && state_kanan == 1 && baris == 1)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 1){
  nsw_kanan = 0;
  angka_pembilang++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 1)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 1){
  nsw_kiri = 0;
  angka_pembilang--;
}


// oenambah baris 
if(nsw_ok == 0 && state_ok == 1 && baris <= 3)nsw_ok = 1;
if(nsw_ok == 1 && state_ok == 0 && baris <= 3){
  nsw_ok = 0;
  baris++;
}
}

















void tampilan_perkalian(){
  
if (baris == 2) {
    hasil = angka_penyebut * angka_pembilang; // Hitung hasil
  }
if(kunci == 0){
  kunci = 1;
    lcd.clear();
}
lcd.setCursor(0,0);
lcd.println(angka_penyebut);

lcd.setCursor(0,1);
lcd.println(angka_pembilang);

lcd.setCursor(0,2);
lcd.println("----");

lcd.setCursor(5,2);
lcd.print("x");

lcd.setCursor(0,3);
lcd.println(hasil);


// PRESS REALESE PERKALIAN

//penyebut
if(nsw_kanan == 0 && state_kanan == 1 && baris == 0)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 0){
  nsw_kanan = 0;
  angka_penyebut++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 0)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 0){
  nsw_kiri = 0;
  angka_penyebut--;
}


//pembilang
if(nsw_kanan == 0 && state_kanan == 1 && baris == 1)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 1){
  nsw_kanan = 0;
  angka_pembilang++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 1)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 1){
  nsw_kiri = 0;
  angka_pembilang--;
}


// oenambah baris 
if(nsw_ok == 0 && state_ok == 1 && baris <= 3)nsw_ok = 1;
if(nsw_ok == 1 && state_ok == 0 && baris <= 3){
  nsw_ok = 0;
  baris++;
}
}







void tampilan_pembagian(){
  
if (baris == 2) {
    hasil = angka_penyebut / angka_pembilang; // Hitung hasil
  }
if(kunci == 0){
  kunci = 1;
    lcd.clear();
}
lcd.setCursor(0,0);
lcd.println(angka_penyebut);

lcd.setCursor(0,1);
lcd.println(angka_pembilang);

lcd.setCursor(0,2);
lcd.println("----");

lcd.setCursor(5,2);
lcd.print("/");

lcd.setCursor(0,3);
lcd.println(hasil);


// PRESS REALESE PEMBAGIAN

//penyebut
if(nsw_kanan == 0 && state_kanan == 1 && baris == 0)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 0){
  nsw_kanan = 0;
  angka_penyebut++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 0)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 0){
  nsw_kiri = 0;
  angka_penyebut--;
}

//pembilang
if(nsw_kanan == 0 && state_kanan == 1 && baris == 1)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 1){
  nsw_kanan = 0;
  angka_pembilang++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 1)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 1){
  nsw_kiri = 0;
  angka_pembilang--;
}

// oenambah baris 
if(nsw_ok == 0 && state_ok == 1 && baris <= 3)nsw_ok = 1;
if(nsw_ok == 1 && state_ok == 0 && baris <= 3){
  nsw_ok = 0;
  baris++;
}
}















void tampilan_penjumblahan(){

 if (baris == 2) {
    hasil = angka_penyebut + angka_pembilang; // Hitung hasil
  }
  // algoritma agar code ini hanya dibaca sebanyak 1 kali dalam program ini
if(kunci == 0){
  kunci = 1;
    lcd.clear();
}
lcd.setCursor(0,0);
lcd.println(angka_penyebut);

lcd.setCursor(0,1);
lcd.println(angka_pembilang);

lcd.setCursor(0,2);
lcd.println("----");

lcd.setCursor(5,2);
lcd.print("+");

lcd.setCursor(0,3);
lcd.println(hasil);

// PRESS REALESE PENJUMBLAHAN

//penyebut
if(nsw_kanan == 0 && state_kanan == 1 && baris == 0)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 0){
  nsw_kanan = 0;
  angka_penyebut++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 0)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 0){
  nsw_kiri = 0;
  angka_penyebut--;
}


//pembilang
if(nsw_kanan == 0 && state_kanan == 1 && baris == 1)nsw_kanan = 1;
if(nsw_kanan == 1 && state_kanan == 0 && baris == 1){
  nsw_kanan = 0;
  angka_pembilang++;
}

if(nsw_kiri == 0 && state_kiri == 1 && baris == 1)nsw_kiri = 1;
if(nsw_kiri == 1 && state_kiri == 0 && baris == 1){
  nsw_kiri = 0;
  angka_pembilang--;
}

// oenambah baris 
if(nsw_ok == 0 && state_ok == 1 && baris <= 3)nsw_ok = 1;
if(nsw_ok == 1 && state_ok == 0 && baris <= 3){
  nsw_ok = 0;
  baris++;
}

















}












//author: @anxxre_z
// project ini dibuat untuk bahan pembelajaran XI TAV Smkn 2 Manokwari 
//project ini bersifat open source