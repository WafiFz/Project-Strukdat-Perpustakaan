#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "antarmuka.hpp"
#include "struct.hpp"
#include "linked_list.hpp"
#include "queue.hpp"
#include "case_petugas.hpp"
#include "operasi_file.hpp"


int main(int argc, char const *argv[]){
	int pilihan, banyak_buku = 0;
    char cek;
    std::string key, username, password;
    
    pointer pBuku = nullptr, pBaru = nullptr;
	pointer head = sentinel_node();
    buat_queue(queue);

    cek_file(head);

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
                            pointer pPinjam = new Perpustakaan;
                            //dibuat node baru karena supaya bisa konfirmasi
                            buat_node(pPinjam, pBuku->kode, pBuku->judul, pBuku->penulis, pBuku->tahun, "NULL", "NULL");

                            header2("Mohon Input Identitas Anda");
                            
                            print<teks>("Nama      : "); input_string(pPinjam->peminjam);
                            print<teks>("Alamat    : "); std::getline(std::cin, pPinjam->alamat);
                            print<teks>("\nPrioritas : \n1. Express \n2. Regular\n\nPilihan : "); 
                            
                            prioritas:
                            input<int>(pPinjam->prioritas);

                            if(pPinjam->prioritas != 1 && pPinjam->prioritas != 2){ 
                                error(); goto prioritas;
                            }

                            clear_screen();
                            header2("Konfirmasi Peminjaman"); endl();
                            identitas_buku_peminjam(pPinjam); endl();
                            konfirmasi(cek, "untuk meminjam.\n");
                            
                            if(cek =='y' || cek == 'Y'){
                                pBuku->peminjam = pPinjam->peminjam;
                                pBuku->alamat = pPinjam->alamat;
                                enqueue(queue, pPinjam);
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

                print("Username : "); input<teks>(username);
                print("Password : "); input<teks>(password);

                if(username == "0" || password == "0") break;
            
                if(username == "username" && password == "password"){
                    clear_screen();
                    case_petugas(head);
                    pilihan = 0;

                }else{
                    print_endl("\n[Username Atau Password Salah!]\n");
                    kembali();
                    std::cin.get();
                }
                break;

            case 0 : 
                break;
            
            default : 
                error(); 
                break;
        }        
	
	}while(pilihan != 0);
    save_data(head);
}