void katalog(pointer head){
	header_tabel("KATALOG");
    tabel();
	traversal_semua_buku(head);
    batas_akhir_tabel();
	kembali();
    std::cin.get();
}

void case_petugas(int& pilihan, char& cek, pointer& head){
	int pilihan_petugas;
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
					identitas_buku_peminjam(front(Q));
					konfirmasi(cek, "apabila selesai dikirim.\n");
					if(cek == 'y' || cek == 'Y'){
						dequeue(Q, front(Q));
						print_endl("\n-Buku Selesai Dikirim-");
						kembali();
						std::cin.get();
						break;
					}
				}
				break;
			
			case 2:
        		clear_screen();
                katalog(head);
            	break;

           	case 3:
           		break;

           	// case 4:
           	// 	buat_node(pBaru, kode, judul, penulis, tahun);
		}
	}while(pilihan_petugas != 0);

	pilihan = 0;
}