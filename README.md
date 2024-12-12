# IF2111 - Alstrukdat STI 2024
> Tugas Besar - IF2111 Alstrukdat STI 2024

# About
PURRMART adalah sebuah aplikasi berbasis CLI ( Command-Line Interface ) yang dibuat dengan bahasa C dengan bantuan struktur data terkait list ( statis dan dinamis ), mesin karakter, mesin kata, dan queue. Tak hanya itu, user yang masuk tentunya terautentikasi dan dapat melakukan minigames lainnya selain melihat toko, seperti work dan work challenge. Yang spesial dari tugas besar ini adalah tantangan untuk murni menggunakan mesin kata serta mesin karakter dan tidak diperbolehkannya implementasi scanf dan fgets.

# Contributors
1. Mochamad Ikhbar A / 18223050
2. Derick Amadeus Budiono	/ 18223090
3. Indana Aulia Ayundazulfa	/ 18223100
4. Wilson	/ 18223012
5. Naila Selvira Budiana / 18223018

# ADT
array<br />
barang<br />
delay<br />
list<br />
list_dinamis<br />
mesinkarakter<br />
mesinkata<br />
queue<br />
random<br />
store<br />
boolean

# Features
LOAD<br />
REGISTER<br />
LOGIN<br />
LOGOUT<br />
WORK<br />
WORDL3<br />
QUANTUM WORDL3<br />
TEBAK ANGKA<br />
SAVE

# How to Run
- Pada terminal, pastikan current directory ada pada folder src
- Compile program menggunakan
```
gcc -o data main.c Feature/work.c Feature/wordl3.c Feature/tebak_angka.c ADT/random/random.c ADT/mesinkarakter/mesinkarakter.c ADT/mesinkata/mesinkata.c ADT/delay/delay.c Feature/auth.c Feature/save.c Feature/load.c Feature/user.c ADT/list/list.c ADT/queue/queue.c ADT/store/store.c ADT/barang/barang.c ADT/list_dinamis/list_dinamis.c Feature/quantumwordl3.c
```
- Jalankan program yang telah dicompile menggunakan
```
./data
```
