
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
    newBuku->peminjam = " ";
    newBuku->alamat = " ";
    newBuku->next = nullptr;
    newBuku->prev = nullptr;
}

pointer cari_buku(pointer head, std::string key){
	pointer pCari = head;
	if(head->next != nullptr){
  		while(pCari->next != head){
  			pCari = pCari->next;
  			if(pCari->kode == key || pCari->judul == key || pCari->penulis == key || pCari->tahun == key) break; 
  		}	
	}

  	
  	if(pCari->kode == key || pCari->judul == key || pCari->penulis == key || pCari->tahun == key) return pCari;
  	else return nullptr;
}

void tambah_buku(pointer head, pointer newBuku){
	pointer unik = cari_buku(head, newBuku->kode);
	if(unik != nullptr){
		print<teks>("Buku ");
		print<teks>(newBuku->judul);
		print_endl<teks>(" tidak dapat ditambahkan. Kode Buku Harus Unik");
	}else{
		pointer pRev = cari_buku(head, newBuku->penulis);
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
		 	  << "| " << std::left << std::setw(13) << buku->tahun << "|"
		      << std::endl;
}

void traversal_semua_buku(pointer head){
	pointer buku = new Perpustakaan;
	buku = head->next;
    
    if(head->next != nullptr){
    	while(buku != head){
			identitas_buku(buku);
			buku = buku->next;
		}
    }else{
    	print_endl("\nBuku Masih Kosong.");
    }

}

void traversal_buku(pointer head, std::string key){
	pointer buku = new Perpustakaan;
	buku = head->next;
	pointer pCari;

    if(head->next != nullptr){
		while(buku != head){
			pCari = cari_buku(buku, key);
			if(pCari != nullptr) identitas_buku(buku); 
			buku = buku->next;
		}
	}
}