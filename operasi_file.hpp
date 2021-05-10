void backup_file(const pointer head){
	std::fstream file2 ("Database_Perpustakaan.txt");
	if(file2.is_open()){
		std::string kode, judul, penulis, tahun, peminjam, alamat;
		pointer pBaru=nullptr;

		while(!file2.eof()){
			getline(file2, kode);
			getline(file2, judul);
			getline(file2, penulis);
			getline(file2, tahun);
			getline(file2, peminjam);
			getline(file2, alamat);

			buat_node(pBaru, kode, judul, penulis, tahun, peminjam, alamat);
			tambah_buku(head, pBaru);
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
}

void cek_file(const pointer head){
	if(kondisi()){
		backup_file(head);
	}else{
		buat_file();
	}
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