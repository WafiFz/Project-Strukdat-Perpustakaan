void katalog(pointer& head){
	int banyak_buku=0;
	header_tabel("KATALOG");
    tabel();
	traversal_semua_buku(head, banyak_buku);
    batas_akhir_tabel();
    cetak_banyak_buku(banyak_buku);
	kembali();
    std::cin.get();
}

void case_petugas(pointer& head){
	int pilihan_petugas; 
	int banyak_buku = 0;
	char cek;
	std::string key, kode, judul, penulis, tahun;
	pointer pBuku = nullptr, pBaru = nullptr;

	do{
		clear_screen();
        menu_petugas();
        input<int>(pilihan_petugas);

		switch(pilihan_petugas){
			case 1:
				cek = 'y';
	            while(cek == 'y' || cek == 'Y'){
	            	clear_screen(); 
					header2("PRIORITAS SAAT INI");
					if(isEmpty(queue)){
						print_endl("\nTidak Ada.");
					}else{
						identitas_buku_peminjam(front(queue));
						konfirmasi(cek, "apabila selesai dikirim.\n");
						
						if(cek == 'y' || cek == 'Y'){
							dequeue(queue, front(queue));
							//buku masuk ke graph "Dipinjam"
							print_endl("\n-Buku Selesai Dikirim-");
							kembali();
							std::cin.get();
							break;
						}else{
							break;
						}
					}
					kembali();
					std::cin.get();
					break;
				}
				break;
			
			case 2:
        		clear_screen();
                katalog(head);
            	break;

           	case 3:
           		//traversal print semua data di graph "Dipinjam"
           		break;

           	case 4:
           		clear_screen(); 
				header("TAMBAH BUKU");
          
           		cek_batal();
           		print("Kode         : "); input_string(kode);
           		if(kode == "0") break;
           		print("Judul        : "); std::getline(std::cin, judul);
           		print("Penulis      : "); std::getline(std::cin, penulis);
           		print("Tahun Terbit : "); std::getline(std::cin, tahun);
           		buat_node(pBaru, kode, judul, penulis, tahun, "NULL", "NULL");
           		tambah_buku(head, pBaru);
           		print_endl("\n-Buku Ditambahkan-");
           		kembali();
           		break;


           	case 5:
	           	cek = 'y';
                while(cek == 'y' || cek == 'Y'){
                    clear_screen();
                    header("HAPUS BUKU");
                    cek_batal();
                    print<teks>("Kode/Judul buku yang akan dihapus: ");
                    input_string(key);

                    if(key == "0") break;

                    pBuku = cari_buku(head, key);

                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk menghapus buku lain.\n");
                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);

                        if(banyak_buku > 1){
                            input_kode_buku2:
                            print<teks>("Input Kode Buku Pada Tabel di Atas : ");
                            std::getline(std::cin, key);

                            if(key == "0") break;

                            pBuku = cari_buku(head, key);

                            if(pBuku == nullptr || key != pBuku->kode){
                                print_endl<teks>("Input Salah!");
                                goto input_kode_buku2;
                            }
                        }

                        clear_screen();
                        header2("Konfirmasi Hapus Buku."); endl();
                        identitas_buku_peminjam(pBuku); endl();
                        konfirmasi(cek, "untuk menghapus.\n");

                        if(cek =='y' || cek == 'Y'){
                        	hapus_buku(head, key);
                        	print_endl("\n-Buku Dihapus-");
                        }else{
                        	break;
                        }

                        kembali();
                        std::cin.get();
                        break;
                    }
           		}
           		break;
		}
	}while(pilihan_petugas != 0);
}