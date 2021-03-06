## PJJ (Perpustakaan Jarak Jauh)

Anggota Kelompok:
* Alfadli Maulana Siddik	            (140810200005)
* Wafi Fahruzzaman                      (140810200009)
* Abraham Javier Sebastian Situmorang   (140810200067)
---
## Latar Belakang
Perpustakaan merupakan kumpulan bahan informasi yang terdiri dari buku dan non-buku yang disusun dengan sistem tertentu, diperuntukkan kepada pengguna jasa perpustakaan untuk dapat dimanfaatkan, akan tetapi tidak untuk dijadikan hak milik baik sebagian maupun keseluruhan (Saiful I. Huda, 2007). 

Dari satu konsep tersebut, maka dapat diiintrpretasikan bahwa perpustakaan menjadi sebuah tempat berbagai macam ilmu dan informasi penting bagi banyak orang. Oleh karena itu diperlukan sebuah sistem pengelolaan yang baik dan fasilitas yang memadai untuk menunjang kualitas pelayanan perpustakaan itu sendiri.

Upaya untuk meningkatkan pelayanan perpustakaan adalah dengan membuat sistem manajemen perpustakaan yang sederhana menggunakan konsep-konsep dari struktur data. Selain itu, terkadang menjadi rumit untuk datang ke perpustakaan untuk meminjam/mengembalikan buku. Oleh karena itu, aplikasi ini memungkinkan orang untuk meminjam/mengembalikan buku dari rumah atau dimana saja.


## Tujuan dan Manfaat
Tujuan :
* Membuat aplikasi sistem manajemen perpustakaan dengan struktur data yang sesuai
* Mengimplementasikan materi dari pembelajaran struktur data

Manfaat :
* Meningkatkan efisiensi dan efektivitas pada setiap aktivitas (Menelusuri/meminjam/ mengembalikan buku) yang terjadi di dalam perpustakaan



## Penjelasan Aplikasi
Aplikasi PJJ dapat melakukan beberapa hal, antara lain sebagai beikut:

-User-
* Menampilkan seluruh daftar buku (katalog buku)
* Mencari buku (Berdasarkan judul/penulis/tahun terbit)
* Meminjam buku
* Mengembalikan buku
* Menampilkan buku yang sedang dipinjam

-Petugas-
* Mengirim buku (Lihar Order)
* Menampilkan seluruh daftar buku (katalog buku) 
* Tambah buku
* Hapus Buku

[Skema menampilkan seluruh daftar buku]:
```shell
Traversal linkedlist
```

[Skema Mencari buku (Berdasarkan judul/penulis/tahun  terbit)]:
```shell
User meng-input judul/penulis/tahun terbit buku. Apabila ditemukan, buku ditampilkan
```

[Skema meminjam buku]:
```shell
User meng-input judul buku yang akan dipinjam (Melakukan Search Linkedlist). 
Apabila ditemukan, user diminta konfirmasi akan meminjam? ya/tidak. Jika ya, user diminta identitas. 
Kemudian, diberi pilihan prioritas pengiriman (express/regular). 
Identitas user dan Buku akan di-enqueu ke "Dikirim". 
(Buku telah sampai di user) Identitas user dan Buku akan diberi tanda "Dipinjam oleh ....".
```

[Skema mengembalikan buku]:
```shell
User meng-input judul buku yang akan dikembalikan (Melakukan Search Linked list "Dipinjam"). 
Apabila ditemukan, tanda "Dipinjam hapus". di-enqueu ke "Dijemput"
```

[Skema Menampilkan buku yang sedang dipinjam]:
```shell
Traversal linkedlist yang terdapat tanda "Dipinjam"
```
[Skema Menambah buku]:
```shell
Petugas meng-input identitas buku yang akan ditambahkan. Kemudian akan di-insert ke linkedlist 
```

[Skema Hapus buku]:
```shell
Petugas meng-input judul buku yang akan dihapus (Melakukan search Linkedlist). 
Apabila ditemukan, akan di-insert ke linkedlist 
```

## Gambar Rancangan Antar Muka
Rancangan Antar Muka Mohon Akses: 
https://www.figma.com/file/7jOEUD22KLWapaXcJ8cI3M/UI-Library


## Rencana Pengerjaan Projek
Pengerjaan proyek dilakukan dengan menggunakan software online yang memungkinkan untuk berkolaborasi, dan melakukan pekerjaan secara bersama-sama. Berikut software dan aplikasi yang digunakan:

* replit.com
* Line
* Discord
* Figma
* Dll.

Pekerjaan juga dilakukan dengan membagi pekerjaan pada masing-masing anggota


## Lisensi

MIT License 2021