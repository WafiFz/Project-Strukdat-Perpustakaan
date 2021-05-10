
pointer sentinel_node() {
  pointer sentinel = new Perpustakaan;
  sentinel->next = nullptr;
  sentinel->prev = nullptr;
  return sentinel;
}

void buat_node(pointer& buku, std::string kode, std::string judul, std::string penulis, std::string tahun, std::string peminjam, std::string alamat){
    buku = new Perpustakaan;
    buku->kode = kode;
    buku->judul = judul;
    buku->penulis = penulis;
    buku->tahun = tahun;
    buku->peminjam = peminjam;
    buku->alamat = alamat;
    buku->prioritas = 0;
    buku->next = nullptr;
    buku->prev = nullptr;
}

pointer cari_buku(const pointer head, std::string key){
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

void tambah_buku(const pointer head, pointer& newBuku){
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
				pRev->next->prev = newBuku;
	  			pRev->next = newBuku;
		}else{
			if(head->next == nullptr){
	  			newBuku->next = head;
	 			newBuku->prev = head;
	  			head->next = newBuku;
	  			head->prev = newBuku;
	  		}else{
				newBuku->next = head;
				newBuku->prev = head->prev;
				head->prev->next = newBuku;
				head->prev = newBuku;
	  		} 
		}
	}
}

void hapus_buku(const pointer head, std::string key){
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
		 	  if(buku->peminjam != "NULL") print_endl("Dipinjam");
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
	else if(buku->prioritas == 2) print_endl("Regular");
	else print_endl(buku->prioritas);
}

void traversal_semua_buku(const pointer head, int& banyak_buku){
	pointer buku = head->next;
    
    if(buku != nullptr){
    	while(buku != head){
			identitas_buku(buku);
			banyak_buku++;
			buku = buku->next;
		}
    }else{
    	print_endl("\nBuku Masih Kosong.");
    }

}

void traversal_buku(const pointer head, std::string key, int& banyak_buku){
	pointer buku;
	pointer traversal = head->next;
	banyak_buku = 0;

    if(traversal != nullptr){
		while(traversal != head){
			
			if(key == traversal->kode || key == traversal->judul || key == traversal->penulis || key == traversal->tahun || key == traversal->peminjam) {
				identitas_buku(traversal);
				banyak_buku++;
			}
			if(key == traversal->kode) {break;} 			
			traversal = traversal->next;
		}
	}
}