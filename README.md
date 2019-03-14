# SoalShift_modul2_F10

## Jawaban Soal Shift Sistem Operasi 2019 

## Modul 2

Oleh: 

* 05111640000125 Fadhlan Aulia
* 05111740000019 Paramastri Ardiningrum

## 2. Menghapus elen.ku
#### Penjelasan
##### Soal: 
Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab
##### Solusi: 
* Menyelesaikan soal ini menggunakan daemon. Pada while(1), dibuat stat yang nantinya akan diisi dengan file yang sudah disimpan pada array path[100]. Yang disimpan adalah file elen.ku yang ada pada folder hatiku. 
* Setelah itu, dapatkan owner dan group dengan menggunakan struct passwd dan struct group. Inisialisasi sebuah char array own[100] yang dimana menyimpan “www-data” yang merupakan syarat file elen.ku supaya bisa dihapus.
* Lalu bandingkan owner dan group dari file elen.ku apakah “www-data” atau bukan. Membandingkannya dengan perintah strcmp. Apabila hasil dari strcmp itu 0 (yang menandakan owner dan group file tersebut adalah www-data), maka char path yang menyimpan file elen.ku tadi dihapus. 
* Beri perintah sleep(3) untuk menghapus file “elen.ku” setiap 3 detik.
