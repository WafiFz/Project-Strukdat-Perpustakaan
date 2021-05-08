#include <iostream>
#include <iomanip>
#include "antarmuka.hpp"
#include "struct.hpp"
#include "linked_list.hpp"
#include "queue.hpp"


int main(int argc, char const *argv[]){
	int pilihan;
	pointer head = sentinel_node();

	do{
		clear_screen();
		menu_utama();
		input<int>(pilihan);

    	switch(pilihan){
        	case 1:
        		clear_screen();
            	header_tabel("KATALOG");
            	traversal_semua_buku(head);
            	kembali();
            	break;

            case 2:
            	clear_screen();
            	pointer pCari;
            	std::string key;
				char cek;

				header("CARI BUKU");
				batal();
				std::cout << "Cari [Judul/Penulis/Tahun Terbit] buku: ";
				std::getline(std::cin, key);
				std::getline(std::cin, key);
				
				//pCari = cari_buku(head, key);
				if(pCari != nullptr){
					header2("BUKU TIDAK DITEMUKAN");
					konfirmasi("untuk mencari buku lain\n");
					input<char>(cek);
				}else{
					header2("BUKU DITEMUKAN");
					traversal_buku(head, key);
					kembali();
				} 
					
				
            break;

        }
	
	}while(pilihan != 0);
	
        // case 3:
        //     cout << "========================================" << endl;
        //     cout << "               PINJAM BUKU              " << endl;
        //     cout << "========================================" << endl;

        //     cout << "[Input '0' untuk batal]" << endl;
        //     cout << "Judul Buku yang akan dipinjam: "; cin >> inputBuku;

        //     if(true){
        //         cout << "=============BUKU DITEMUKAN=============" << endl;
        //         cout << "+======+=================+=================+==============+" << endl;
        //         cout << "| Kode |      Judul      |     Penulis     | Tahun Terbit |" << endl;
        //         cout << "+======+=================+=================+==============+" << endl;

        //         cout << "========================================" << endl;
        //         cout << "Input 'y' untuk meminjam." << endl;
        //         cout << "Input 'n' untuk kembali ke menu." << endl;
        //         cout << "========================================" << endl;
        //         cout << "Pilihan : "; cin >> inputny;

        //         if(inputny == "y"){
        //             buatNodeBuku(newtr, "A01", inputBuku, "Tere", "2000"); 
        //             cout << "=======Mohon Input Identitas Anda=======" << endl;
        //             cout << "Nama   : "; cin >> newtr->peminjam;
        //             cout << "Alamat : "; cin >> newtr->alamat;
        //             cout << "\nPrioritas : \n1.express\n2.regular\n>> "; cin >> newtr->prioritas;

        //             cout << "\n-Buku dalam proses pengiriman-" << endl;
                    
        //             enQueue(Q, newtr);
        //             goto menu;

        //         }else if(inputny == "n"){
        //             goto menu;
        
        //         }else{
        //             cout << "Input salah. Mohon untuk masukkan input kembali (y/n)" << endl;
        //         }

        //     }else{

        //     }
        //     break;
        // case 4:
        //     cout << "========================================" << endl;
        //     cout << "             KEMBALIKAN BUKU            " << endl;
        //     cout << "========================================" << endl;

        //     cout << "[Input '0' untuk batal]" << endl;
        //     cout << "Judul Buku yang akan dikembalikan: " << endl;
        //     break;
        // case 5:
        //     cout << "+===========================================+" << endl;
        //     cout << "|               BUKU DIPINJAM               |" << endl;
        //     cout << "+===========================================+" << endl;

        //     cout << "Tekan Enter untuk kembali ke menu" << endl;
        //     break;
        // case 9:
        //     cout << "=========================================" << endl;
        //     cout << "               LOGIN PETUGAS             " << endl;
        //     cout << "=========================================" << endl;

        //     cout << "[Input '0' untuk batal]" << endl;

        //     cout << "Username : " << endl; cin >> inputUname;
        //     cout << "Password : " << endl; cin >> inputPass;
            
        //     if(inputUname == username && inputPass == password){
        //         menu_petugas();
        //         cin >> pilUser;
        //         Perpustakaan temp;
        //         switch (pilUser){
        //             case 1:
        //                 update :
        //                 cout << "========PRIORITAS SAAT INI========" << endl;
        //                 cout << "Nama    : " << front(Q)->peminjam << endl;
        //                 cout << "Alamat  : " << front(Q)->alamat << endl;
        //                 cout << "Judul   : " << front(Q)->judul << endl;
        //                 cout << "==================================" << endl;
        //                 dequeue(Q, pDel);
        //                 cout << "Input 'y' apabila selesai dikirim." << endl;
        //                 cout << "Input 'n' untuk kembali ke menu." << endl;
        //                 cout << "==================================" << endl;
        //                 cout << "Pilihan : "; cin >> inputny;

        //                 if(inputny == "y")
        //                     goto update;
        //                 else if(inputny == "n")
        //                     goto menu;
        //                 else   
        //                     cout << "Input salah";
        //                 break;
        //             case 2:
        //                 cout << "+=========================================================+" << endl;
        //                 cout << "|                      KATALOG BUKU                       |" << endl;
        //                 cout << "+======+=================+=================+==============+" << endl;
        //                 cout << "| Kode |      Judul      |     Penulis     | Tahun Terbit |" << endl;
        //                 cout << "+======+=================+=================+==============+" << endl;
        //                 break;
        //             case 3:
        //                 cout << "+=========================================================+" << endl;
        //                 cout << "|                      KATALOG BUKU                       |" << endl;
        //                 cout << "+======+=================+=================+==============+" << endl;
        //                 cout << "| Kode |      Judul      |     Penulis     | Tahun Terbit |" << endl;
        //                 cout << "+======+=================+=================+==============+" << endl;
        //                 break;
        //             case 4:
        //                 cout << "=========================================" << endl;
        //                 cout << "               TAMBAH BUKU               " << endl;
        //                 cout << "=========================================" << endl;
        //                 cout << "\n[Input '0' untuk batal]" << endl;

        //                 break;
        //             case 5:
        //                 cout << "=========================================" << endl;
        //                 cout << "                HAPUS BUKU               " << endl;
        //                 cout << "=========================================" << endl;

        //                 cout << "[Input '0' untuk batal]" << endl;
        //                 cout << "Judul Buku yang akan dihapus: " << endl;
        //                 break;
        //             case 0:
        //             default:
        //                 cout << "Input tidak sesuai." << endl;
        //                 break;
        //         }

        //     }else{
        //         cout << "Username atau Password anda salah. Mohon input kembali" << endl;
        //     }
        //     break;
        // case 0:
        //     break;
        // default:
        //     cout << "Input Tidak Sesuai." << endl;
        //     goto menu;
        //     break;
	//return 0;
}