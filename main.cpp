#include <iostream>
#include <iomanip>
#include <string>
#include "antarmuka.hpp"
#include "struct.hpp"
#include "linked_list.hpp"
#include "queue.hpp"
#include "case_petugas.hpp"


int main(int argc, char const *argv[]){
	int pilihan, banyak_buku = 0;
    char cek;
    std::string key;
    
    pointer pBuku = nullptr, pBaru = nullptr;
	pointer head = sentinel_node();

        buat_node(pBaru, "A124", "Hujan", "Tere Liye", "2002");
        tambah_buku(head, pBaru);
        buat_node(pBaru, "B123", "Hujan", "Andre", "2002");
        tambah_buku(head, pBaru);
        buat_node(pBaru, "A125", "Hujan", "Tere Liye", "2002");
        tambah_buku(head, pBaru);

    buat_queue(Q);

	do{
		clear_screen();
		menu_utama();
		input<int>(pilihan);

    	switch(pilihan){
        	case 1:
        		clear_screen();
                katalog(head);
            	break;

            case 2:
                cek = 'y';
                while(cek == 'y' || cek == 'Y'){
                    clear_screen();
                    header("CARI BUKU");
                    cek_batal();
                    print<teks>("Cari [Judul/Penulis/Tahun Terbit] buku: ");
                    input_string(key);

                    if(key == "0") break;

                    pBuku = cari_buku(head, key);
                    
                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk mencari buku lain.\n");

                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);
                        kembali();
                        break;
                    }
                }  
                break;

            case 3:
                cek = 'y';
                while(cek == 'y' || cek == 'Y'){
                    clear_screen();
                    header("PINJAM BUKU");
                    cek_batal();
                    print<teks>("Kode/Judul buku yang akan dipinjam: ");
                    input_string(key);

                    if(key == "0") break;

                    pBuku = cari_buku(head, key);

                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk meminjam buku lain.\n");
                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);

                        if(banyak_buku > 1){
                            input_kode_buku:
                            print<teks>("Input Kode Buku Pada Tabel di Atas : ");
                            std::getline(std::cin, key);

                            if(key == "0") break;

                            pBuku = cari_buku(head, key);

                            if(pBuku == nullptr || key != pBuku->kode){
                                print_endl<teks>("Input Salah!");
                                goto input_kode_buku;
                            }
                        }

                        konfirmasi(cek, "untuk meminjam.\n");
        

                        if(cek =='y' || cek == 'Y'){
                            pointer pPinjam = nullptr;
                            //dibuat node baru karena supaya bisa konfirmasi
                            buat_node(pPinjam, pBuku->kode, pBuku->judul, pBuku->penulis, pBuku->tahun);

                            header2("Mohon Input Identitas Anda");
                            
                            print<teks>("Nama      : "); input_string(pPinjam->peminjam);
                            print<teks>("Alamat    : "); std::getline(std::cin, pPinjam->alamat);
                            print<teks>("\nPrioritas : \n1. Express \n2. Regular\n\nPilihan : "); 
                            
                            prioritas:
                            input<int>(pBuku->prioritas);

                            if(pBuku->prioritas != 1 && pBuku->prioritas != 2 ){ 
                                error(); goto prioritas;
                            }

                            clear_screen();
                            header2("Konfirmasi Peminjaman."); endl();
                            identitas_buku_peminjam(pPinjam); endl();
                            konfirmasi(cek, "untuk meminjam.\n");
                            
                            if(cek =='y' || cek == 'Y'){
                                pBuku->peminjam = pPinjam->peminjam;
                                pBuku->alamat = pPinjam->alamat;
                                enqueue(Q, pPinjam);
                            }else{ 
                                break;
                            }

                            print_endl("\n-Buku dalam proses pengiriman-");
                            kembali();
                            std::cin.get();
                            break;
                        }
                    }
                }
                break;
            
            case 4:
                cek = 'y';
                while(cek == 'y' || cek == 'Y'){
                    clear_screen();
                    header("KEMBALIKAN BUKU");
                    cek_batal();
                    print<teks>("Kode buku yang akan dikembalikan: ");
                    input_string(key);

                    if(key == "0") break;
                    
                    pBuku = cari_buku(head, key); //cari graph

                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk mengembalikan buku lain.\n");
                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);

                        if(banyak_buku > 1){
                            
                            input_kode_buku2:
                            print<teks>("Input Kode Buku : ");
                            std::getline(std::cin, key);

                            if(key == "0") break;

                            pBuku = cari_buku(head, key);

                            if(pBuku == nullptr || key != pBuku->kode){
                                print_endl<teks>("Input Salah!");
                                goto input_kode_buku2;
                            }
                        }

                        konfirmasi(cek, "untuk mengembalikan.\n");

                        //hapus dari graph "dipinjam"
                        print_endl("\n-Buku Dikembalikan-");
                        kembali();
                        break;
                    }
                }
                break;
            
            case 5:
                cek = 'y';
                while(cek == 'y' || cek == 'Y'){ 
                    clear_screen();
                    header("BUKU DIPINJAM");
                    print<teks>("Peminjam : ");
                    input_string<teks>(key);
                    //print<teks>(pBuku->peminjam);
                    pBuku = cari_buku(head, key);
                    //print<teks>(pBuku->peminjam);
                    if(key == "0") break;
                    
                    if(pBuku == nullptr){
                        header2("PEMINJAM TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk mengembalikan buku lain.\n");
                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        kembali();
                        break;
                    }
                }
                break;

            case 9:
                clear_screen();
                header("LOGIN PETUGAS");
                cek_batal();

                std::string username, password;
                print("Username : "); input<teks>(username);
                print("Password : "); input<teks>(password);

                if(username == "0" || password == "0") break;
                //username == "PetugasPerpustakaan" && password == "PJJ123"
                if(true){
                    enqueue(Q, pBaru);
                    clear_screen();
                    
                    
                    case_petugas(pilihan, cek, head);

                }else{
                    print_endl("\n[Username Atau Password Salah!]\n");
                    kembali();
                    std::cin.get();
                }
                break;
        }

            
	
	}while(pilihan != 0);
}
	
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