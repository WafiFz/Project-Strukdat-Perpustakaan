void backup_file(const pointer head){
	std::string kode, judul, penulis, tahun, peminjam, alamat;
	pointer pBaru=nullptr;

	std::fstream file ("Database_Perpustakaan.txt");
	if(file.is_open()){

		while(!file.eof()){
			getline(file, kode);
			getline(file, judul);
			getline(file, penulis);
			getline(file, tahun);
			getline(file, peminjam);
			getline(file, alamat);

			buat_node(pBaru, kode, judul, penulis, tahun, peminjam, alamat, 0);
			tambah_buku(head, pBaru);
		}
		file.close();
	}
}

void backup_order(){
	std::string kode, judul, penulis, tahun, peminjam, alamat, string_prioritas;
	int prioritas=0;
	pointer pBaru=nullptr;

	std::fstream file2 ("Database_Order.txt");
	if(file2.is_open()){

		while(!file2.eof()){
			getline(file2, kode);
			getline(file2, judul);
			getline(file2, penulis);
			getline(file2, tahun);
			getline(file2, peminjam);
			getline(file2, alamat);
			getline(file2, string_prioritas);

			
			std::stringstream ubah(string_prioritas);
			ubah >> prioritas;	

			buat_node(pBaru, kode, judul, penulis, tahun, peminjam, alamat, prioritas);
			if(pBaru->kode != ""){
				enqueue(qkembali, pBaru);
			}	
		}
		file2.close();
	}
}

bool kondisi(){
	std::ifstream ifile("Database_Perpustakaan.txt");
	if (ifile){
		return true;
	}else{
		return false;
	}
}

void buat_file(){
	std::fstream file;
	file.open("Data_Perpustakaan.txt", std::ios::out);
	file.close();

	std::fstream file2;
	file2.open("Database_Perpustakaan.txt", std::ios::out);
	file2.close();

	std::fstream file3;
	file2.open("Database_Order.txt", std::ios::out);
	file2.close();
}

void cek_file(const pointer head){
	if(kondisi()){
		backup_file(head);
		backup_order();
	}else{
		buat_file();
	}
}

void save_order(pointer buku){
	std::fstream file;
	file.open("Database_Order.txt", std::ios::in | std::ios::out | std::ios::trunc);
	while(buku != nullptr){
		file  << buku->kode 	<< std::endl
			  << buku->judul 	<< std::endl
			  << buku->penulis  << std::endl
			  << buku->tahun 	<< std::endl
			  << buku->peminjam << std::endl
			  << buku->alamat 	<< std::endl
			  << buku->prioritas;

		if(buku->next != nullptr) file << std::endl;

		buku = buku->next;
	}
	file.close();

}

void save_data(const pointer head){
	pointer buku = head->next;
	print_endl<teks>("\nData disimpan!");
	print_endl<teks>("-Menutup Program-");
	std::fstream file, file2;
	file.open("Data_Perpustakaan.txt", std::ios::in | std::ios::out | std::ios::trunc);
	file << "+======================================================================================================+" << std::endl
	 	 << "|                                            DATA PERPUSTAKAAN                                         |" << std::endl
	 	 << "+======+=====================+===================+=====================================================+" << std::endl
	 	 << "| Kode | Judul               | Penulis           | Tahun Terbit | Peminjam            | Alamat         |" << std::endl
	 	 << "+======+=====================+===================+=====================================================+" << std::endl;
 	
	 while(buku != head){
	 	file  << "| " << std::left << std::setw(5)  << buku->kode
		 	  << "| " << std::left << std::setw(20) << buku->judul 
		 	  << "| " << std::left << std::setw(18) << buku->penulis  
		 	  << "| " << std::left << std::setw(13) << buku->tahun
		 	  << "| " << std::left << std::setw(20) << buku->peminjam
		 	  << "| " << std::left << std::setw(15) << buku->alamat
		 	  << "| " << std::endl;

		buku = buku->next;
	}

	file << "+------+---------------------+-------------------+--------------+---------------------+----------------+" << std::endl;
	file.close();

	buku = head->next;
	file2.open("Database_Perpustakaan.txt", std::ios::in | std::ios::out | std::ios::trunc);
	while(buku != head){
		file2 << buku->kode 	<< std::endl
			  << buku->judul 	<< std::endl
			  << buku->penulis  << std::endl
			  << buku->tahun 	<< std::endl
			  << buku->peminjam << std::endl
			  << buku->alamat;

			  if(buku != head->prev) file2 << std::endl;

		buku = buku->next;
	}

	file2.close();		  
}