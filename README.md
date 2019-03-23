# SoalShift_modul2_F10

## Jawaban Soal Shift Sistem Operasi 2019 

## Modul 2

Oleh: 

* 05111640000125 Fadhlan Aulia
* 05111740000019 Paramastri Ardiningrum

## 1. Mengganti Nama .png menjadi _grey.png
#### Penjelasan
##### Soal:
Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.

##### Solusi:
* soal ini diselesaikan dengan daemon, isi pada while(1) adalah berupa code yg mengubah format .png menjadi _grey.png.
* pertama, membuat code yg dimana dia akan membaca isi folder tersebut menggunakan library dirent yg lebih tepatnya menggunakan 
opendir() dan readdir().
* setelah dibaca semua kemudian mencari file yg berformat .png menggunakan strchr untuk mencari .png dan membandingkannya menggunakan strcmp yang apabila mereka sama dengan .png mereka akan bernilai 0.
* untuk mengubah .png menjadi _grey.png dilakukan sebuah "trade", dari membuat oldfile yg dimana dia adalah gabungan dari direktori letak direktori dan nama filenya menggunakan strcat, menjadi newfile yang dimana dia didapatkan filename sudah ditukar dan mendapatkan nama_grey.png.
* untuk mengubahnya nama file menggunakan library c yaitu rename(newfile,oldfile).

![alt text](https://github.com/paramastri/SoalShift_modul2_F10/blob/master/1.PNG)

## 2. Menghapus elen.ku
#### Penjelasan
##### Soal: 
Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab
##### Solusi: 
* Menyelesaikan soal ini menggunakan daemon. Pada while(1), dibuat stat yang nantinya akan diisi dengan file yang sudah disimpan pada array path[100]. Yang disimpan adalah file elen.ku yang ada pada folder hatiku. Stat adalah panggilan sistem yang digunakan untuk menentukan informasi tentang file berdasarkan path file-nya.
* Setelah itu, dapatkan owner dan group dengan menggunakan struct passwd dan struct group. Inisialisasi sebuah char array own[100] yang dimana menyimpan “www-data” yang merupakan syarat file elen.ku supaya bisa dihapus.
* Lalu bandingkan owner dan group dari file elen.ku apakah “www-data” atau bukan. Membandingkannya dengan perintah strcmp. Apabila hasil dari strcmp itu 0 (yang menandakan owner dan group file tersebut adalah www-data), maka char path yang menyimpan file elen.ku tadi dihapus. 
* Beri perintah sleep(3) untuk menghapus file “elen.ku” setiap 3 detik.

![alt text](https://github.com/paramastri/SoalShift_modul2_F10/blob/master/2.PNG)

## 4. Makan Sehat
#### Penjelasan
##### Soal: 
Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.
##### Solusi: 
* Soal ini diselesaikan dengan daemon. Di luar kondisi while(1), pertama kita inisialisasi dulu sebuah variable urutan = 1, sebagai angka berurutan yang mengisi nama file makan_sehat#.txt nantinya. Kita inisialisasi juga char array path[100] untuk menyimpan file makan_enak.txt di dalamnya dengan strcpy.
* Dalam perulangan while(1), kita membuat struct stat ‘filenya’ yang menyimpan path makan_enak.txt tadi. Buat juga 2 variable dengan tipe data time_t. Dimana yang pertama dibuat variable time_t akses_file sebagai penanda waktu terakhir diaksesnya file makan_enak.txt. Kemudian variabel yang kedua adalah time_t akses_program sebagai penanda waktu diaksesnya program soal4.c ini (program akan dijalankan setiap 5 detik menggunakan sleep(5)). Variabel akses_file diinisialisasi dengan filenya.st_time yang berarti menandakan waktu terakhir akses dari stat filenya. Sementara akses_program diatur dengan time(NULL) supaya pengaksesan program ter-reset selalu dengan waktu saat ini (current time).
* Untuk menghitung rentang waktu, digunakan difftime yang dapat mengurangi waktu satu dan waktu yang lain. Disini yang dicari selisihnya adalah waktu program diakses dikurangi dengan waktu terakhir file makan_enak.txt diakses. Nah, apabila didapat selisihnya kurang dari atau sama dengan 30 yang dimana itu berarti file makan_enak.txt tekah dibuka setidaknya 30 detik yang lalu. 
Apabila memenuhi kondisi rentang 30 detik, dibuatlah file makan_sehat#.txt dengan # adalah bilangan berurutan dimulai dari 1. Dibuat file dipointerkan pada variabel buka, yang nantinya digunakan untuk membuka file baru (makan_sehat#.txt). Setelah itu dibuat array tipe data char filenya_baru[100] yang nantinya disalinkan dengan file /home/paramastri/Documents/makanan/makan_sehat. 
* Untuk melengkapi ketentuan nama file yang harus disertai dengan urutan angka yang urut dengan ekstensi .txt, maka digunakan strcat untuk menambahkannya. Setelah itu buka file dan write, lalu tutup kembali. Tidak lupa untuk meng-increment variabel urutan supaya integer yang telah di-strcat-kan bertambah dengan perulangan.

![alt text](https://github.com/paramastri/SoalShift_modul2_F10/blob/master/4.PNG)

## 5. Log
#### Penjelasan
##### Soal: 
Kerjakan poin a dan b di bawah:
Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
Per menit memasukkan log#.log ke dalam folder tersebut
‘#’: increment per menit. Mulai dari 1
Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.
##### Solusi: 
* Solusi dari soal ini adalah diselesaikan dengan menggunakan daemon. Kita dapatkan dulu waktu sekarang (current time) dengan mendeklarasikan variabel bertipe data time_t, misal waktu_log dan dimasukkan ke dalam fungsi time(). 
* Buat struct tm yang dipointerkan ke variabel waktu. Dimana struct ini akan mengonversi waktu yang raw menjadi terpisah-pisah hari, jam, bulan, tahun, dan lain-lain. Lalu deklarasi variabel waktu adalah mengambil waktu sekarang menggunakan variabel waktu_log yang dimasukkan ke dalam fungsi localtime().
* Langkah selanjutnya adalah deklarasi variabel array char guna mencetak waktu yang sudah terpisah-pisah formatnya. Kemudian cetak dengan sprintf format waktu tadi ke dalam path yang diinginkan untuk membentuk foldernya. Gunakan fungsi mkdir().
* Kemudian gunakan perulangan untuk menamai file log yang akan terbuat dalam folder dengan format jam tadi. Buat deklarasi file yang menunjuk pointer ke 2 file yaitu file syslog dan file baru .log yang akan dibuat. Variabel file_sys akan membaca file syslog. Buat variabel char array untuk memberi nama file .log nantinya. Kemudian sprintf variabel nama_file tadi diikuti dengan parameter path yang diinginkan.
* Lalu variabel file_baru yang tadi telah dideklarasi akan menulis nama file yang telah di sprintf tadi. Untuk memindah seluruh isi file ke log#.log digunakan perulangan fscanf variabel file_sys dan fprintf variabel file_baru. Jangan lupa tutup file yang telah dibuka.
* Sleep(60) digunakan supaya per menit memasukkan log#.log ke dalam folder format waktu. Jadi, apabila file dibuat setiap menit sementara perulangan i dimulai dari 1 sampai <30, maka akan terbuat 30 file dalam 30 menit. Ketika 30 menit pertama habis, pada menit selanjutnya akan dibuat folder baru yang nantinya akan melakukan hal yang sama.
* Untuk program yang menghentikan jalannya daemon ini, digunakan char array yang menyimpan variabel sebagai tempat mendapatkan proses id dari program soal5.c, dapatkan pidnya kemudian gunakan fungsi kill() untuk melakukan kill sebagai usaha menghentikan program.

![alt text](https://github.com/paramastri/SoalShift_modul2_F10/blob/master/5.PNG)
