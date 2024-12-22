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
boolean<br />
stack<br />
map<br />

# Features
LOAD<br />
REGISTER<br />
LOGIN<br />
LOGOUT<br />
PROFILE<br />
WORK<br />
WORDL3<br />
QUANTUM WORDL3<br />
TEBAK ANGKA<br />
CART ADD<br />
CART REMOVE<br />
CART PAY<br />
CART SHOW<br />
HISTORY<br />
WISHLIST ADD<br />
WISHLIST REMOVE<br />
WISHLIST SWAP<br />
WISHLIST CLEAR<br />
WISHLIST SHOW<br />
OPTIMASIRUTE<br />
SAVE<br />

# How to Run
- Run file dengan linux environment/mysys2 terminal :
```
make -C bin
```
- Run file menggunakan powershell
```
gcc -o data Src/main.c Src/Feature/work.c Src/Feature/wordl3.c Src/Feature/tebak_angka.c Src/ADT/random/random.c Src/ADT/mesinkarakter/mesinkarakter.c Src/ADT/mesinkata/mesinkata.c Src/ADT/delay/delay.c Src/Feature/auth.c Src/Feature/save.c Src/Feature/load.c Src/Feature/user.c Src/ADT/list/list.c Src/ADT/queue/queue.c Src/ADT/store/store.c Src/ADT/barang/barang.c Src/ADT/list_dinamis/list_dinamis.c Src/Feature/quantumwordl3.c Src/Feature/cart.c Src/Feature/history.c Src/Feature/profile.c Src/ADT/stack/stack.c Src/ADT/setmap/map.c Src/Feature/wishlist.c Src/ADT/linkedlist/linkedlist.c Src/Feature/hiasan.c Src/Feature/graph.c

```

- Jalankan program yang telah dicompile menggunakan
```
./Bin/Program.exe untuk wsl/msys2 
./Bin/Program
```

