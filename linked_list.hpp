
pointer sentinel_node() {
  pointer sentinel = new Perpustakaan;
  sentinel->next = nullptr;
  sentinel->prev = nullptr;
  return sentinel;
}

void buat_node(pointer& newBuku, std::string kode, std::string judul, std::string penulis, std::string tahun){
    newBuku = new Perpustakaan;
    newBuku->kode = kode;
    newBuku->judul = judul;
    newBuku->penulis = penulis;
    newBuku->tahun = tahun;
    newBuku->prioritas = 0;
    newBuku->peminjam = "";
    newBuku->alamat = "";
    newBuku->next = nullptr;
    newBuku->prev = nullptr;
}

pointer cari_buku(pointer head, std::string key){
	bool kondisi = false;
	pointer pCari = head->next;
	
	
	if(head->next != nullptr){
  		while(pCari != head){
  			
  			if(key == pCari->kode || key == pCari->judul || key == pCari->penulis || key == pCari->tahun || key == pCari->peminjam){
  				kondisi = true;
  				break;
  			} 
  			pCari = pCari->next;
  			
  		}	
	}

  	
  	if(kondisi) return pCari;
  	else return nullptr;
}

void tambah_buku(pointer& head, pointer& newBuku){
	pointer unik = cari_buku(head, newBuku->kode);
	if(unik != nullptr){
		print<teks>("Buku ");
		print<teks>(newBuku->judul);
		print_endl<teks>(" tidak dapat ditambahkan. Kode Buku Harus Unik");
	}else{
		pointer pRev = nullptr;
		pRev = cari_buku(head, newBuku->penulis);
		if(pRev != nullptr){
			  	newBuku->next = pRev->next;
	  			newBuku->prev = pRev;
	  			pRev->next = newBuku;
		}else{
			if(head->next == nullptr){
	  			newBuku->next = head;
	 			newBuku->prev = head;
	  			head->next = newBuku;
	  			head->prev = newBuku;
	  		}else{
	  			pointer temp = head->next;
				while(temp != head->prev){
		  			temp = temp->next;
				}
				temp->next = newBuku;
				newBuku->prev = temp;
				newBuku->next = head;
				head->prev = newBuku;
	  		} 
		}
	}
}

void hapus_buku(pointer head, std::string key){
	pointer pHapus = cari_buku(head, key);
	
  	pointer pHelp = pHapus;
  	if(pHapus != head){
  		pHapus->prev->next = pHelp->next;
  		pHapus->next->prev = pHelp->prev;
 		delete pHelp;
 	}	
}

void identitas_buku(pointer buku){
	std::cout << "| " << std::left << std::setw(5) << buku->kode
		 	  << "| " << std::left << std::setw(20) << buku->judul 
		 	  << "| " << std::left << std::setw(18) << buku->penulis  
		 	  << "| " << std::left << std::setw(13) << buku->tahun
		 	  << "| ";
		 	  if(buku->peminjam != "") print_endl("Dipinjam");
		 	  else endl();
}

void identitas_buku_peminjam(pointer buku){
	print<teks>("Kode Buku    : "); print_endl(buku->kode);
	print<teks>("Judul        : "); print_endl(buku->judul);
	print<teks>("Penulis      : "); print_endl(buku->penulis);
	print<teks>("Tahun Terbit : "); print_endl(buku->tahun);
	endl();
	print<teks>("Nama Peminjam: "); print_endl(buku->peminjam);
	print<teks>("Nama Alamat  : "); print_endl(buku->alamat);
	print<teks>("Prioritas    : "); 
	if(buku->prioritas == 1) print_endl("Express");
	else print_endl("Regular");
}

void traversal_semua_buku(const pointer head){
	pointer buku = head->next;
    
    if(buku != nullptr){
    	while(buku != head){
			identitas_buku(buku);
			buku = buku->next;
		}
    }else{
    	print_endl("\nBuku Masih Kosong.");
    }

}

void traversal_buku(const pointer head, std::string key, int& banyak_buku){
	pointer buku = head->next;
	pointer traversal = head;
	banyak_buku = 0;

    if(buku != nullptr){
		while(traversal != head->prev){

			buku = cari_buku(traversal, key);
			if(buku != nullptr) {identitas_buku(buku); banyak_buku++;}
			if(key == buku->kode) {break;} 
			
			traversal = traversal->next;
			
		}
	}
}