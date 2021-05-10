using teks = std::string;

void header(std::string judul){
	int panjang = judul.length();
	int posisi = (25) + (panjang /2);
	print_endl<teks>("==================================================");
	std::cout << std::right << std::setw(posisi); 
	print<teks>(judul); endl(); 
	print_endl<teks>("==================================================");
}

void header2(std::string judul){
	endl();
	print<teks>("===============");
	print<teks>(judul);
	print<teks>("===============");
	endl();
}

void error(){
	print_endl<teks>("\n[Pilihan Tidak Ditemukan]");
	print_endl<teks>("Input Sesuai Intruksi!\n");
}

void konfirmasi(char& cek, std::string aksi){
	label_konfirmasi:
	print_endl<teks>("========================================");
	print<teks>("Input 'y' ");
	print<teks>(aksi);
	print_endl<teks>("Input 'n' untuk kembali ke menu.");
	print_endl<teks>("========================================");
	print<teks>("Pilihan : ");
	input<char>(cek);
	
	if (cek == 'y'|| cek == 'Y' || cek == 'n' || cek == 'N'){}	
    else {error(); goto label_konfirmasi;}
}

void cek_batal(){
	print_endl<teks>("\n[Input '0' untuk batal]\n");
}

void kembali(){
	print_endl<teks>("\nTekan Enter untuk kembali ke menu.");
	std::cin.get();
}

void verifikasi(char& cek){

}

void header_tabel(std::string judul){
	int panjang = judul.length();
	int posisi = (31) + (panjang /2);
	print_endl<teks>("+===============================================================+");
	std::cout << "|" << std::setw(posisi) << judul << "\t\t\t\t" << "|" << std::endl;   
}

void tabel(){
	print_endl<teks>("+======+=====================+===================+==============+");
    print_endl<teks>("| Kode | Judul               | Penulis           | Tahun Terbit |");
    print_endl<teks>("+======+=====================+===================+==============+"); 

}

void batas_akhir_tabel(){
	print_endl<teks>("+------+---------------------+-------------------+--------------+");
}

void cetak_banyak_buku(int banyak_buku){
	endl();
	print<teks>("Banyak Buku : ");
    print_endl<int>(banyak_buku);
    endl();
}

void menu_utama(){
	header("SELAMAT DATANG DI PERPUSTAKAAN JARAK JAUH (PJJ)");
    print_endl<teks>("1. Katalog Buku");
    print_endl<teks>("2. Cari Buku");
    print_endl<teks>("3. Pinjam Buku");
    print_endl<teks>("4. Kembalikan Buku");
    print_endl<teks>("5. Buku Dipinjam");

    print_endl<teks>("\n\n9. Login Sebagai Petugas");
    print_endl<teks>("0. Simpan & Keluar");
    print_endl<teks>("==================================================");
    print<teks>("Pilihan : ");
}

void menu_petugas(){
    header("SELAMAT DATANG DI MENU PETUGAS");
    print_endl<teks>("1. Lihat Order");
    print_endl<teks>("2. Katalog Buku");
    print_endl<teks>("3. Buku Dipinjam");
    print_endl<teks>("4. Tambah Buku");
    print_endl<teks>("5. Hapus Buku");

    print_endl<teks>("\n\n0. Simpan & Keluar");
    print_endl<teks>("==================================================");
    print("Pilihan : ");
}