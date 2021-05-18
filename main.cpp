#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "template.hpp"
#include "antarmuka.hpp"
#include "struct.hpp"
#include "linked_list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "petugas.hpp"
#include "operasi_file.hpp"


int main(int argc, char const *argv[]){
	int pilihan, banyak_buku = 0;
    char cek;
    std::string key, username, password;
    std::string kode, judul, penulis, tahun, peminjam, alamat;
    
    pointer pBuku = nullptr, pDel = nullptr, stack = nullptr;
    pointer pPinjam = new Perpustakaan;
    pointer pAntri = new Perpustakaan;
    pointer pKembali = new Perpustakaan;
	pointer head = sentinel_node();

    buat_queue(qpinjam);
    buat_queue(qkembali);
    buat_stack(stack);

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
                    
                    print_endl<teks>("Buku akan dikirim ke alamat anda, dengan biaya");
                    print_endl<teks>("-Express Rp 20.000,-/buku.");
                    print_endl<teks>("-Regular Rp 10.000,-/buku.");
                    print_endl<teks>("Dibayar secara COD.");

                    header2("Mohon Input Identitas Anda");
                            
                    print<teks>("Nama      : "); input_string(pPinjam->peminjam);
                    if(pPinjam->peminjam == "0") break;
                    print<teks>("Alamat    : "); std::getline(std::cin, pPinjam->alamat);
                    print_endl<teks>("\nPrioritas : \n1. Express \n2. Regular\n");
                    
                    prioritas:
                    print("Pilihan : ");
                    input<int>(pPinjam->prioritas);

                    if(pPinjam->prioritas != 1 && pPinjam->prioritas != 2){ 
                        error(); goto prioritas;
                    }
                    
                    pinjam_buku:
                    clear_screen();
                    print<teks>("\nKode/Judul buku yang akan dipinjam: ");
                    input_string(key);

                    pBuku = cari_buku(head, key);

                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk meminjam buku lain.\n");
                        if(cek == 'y' || cek == 'Y'){
                        	goto pinjam_buku;
                        }
                    }else{
                        header2("BUKU DITEMUKAN");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);

                        if(banyak_buku > 1){
                            input_kode_buku:
                            print_endl<teks>("[Input 0 untuk kembali]\n");
                            print<teks>("Input Kode Buku Pada Tabel di Atas : ");
                            std::getline(std::cin, key);

                            if(key == "0")  goto pinjam_buku;;

                            pBuku = cari_buku(head, key);

                            if(pBuku == nullptr || key != pBuku->kode){
                                print_endl<teks>("Input Salah!");
                                goto input_kode_buku;
                            }
                        } 

                        if(pBuku->peminjam != "NULL"){
                            header2("Buku Sedang Dipinjam");
                            konfirmasi(cek, "untuk meminjam buku lain.\n");
                            if(cek == 'y' || cek == 'Y'){
                                goto pinjam_buku;
                            }else{
                                break;
                            }
                        }     
                        
                        buat_node(pPinjam, pBuku->kode, pBuku->judul, pBuku->penulis, pBuku->tahun, pPinjam->peminjam, pPinjam->alamat, pPinjam->prioritas);
                        
                        push(stack, pPinjam);

                        print_endl("\n-Buku dimasukkan ke keranjang-\n");
                        
                        undo:
                        konfirmasi2(cek, "untuk lanjutkan.\nInput 'u' untuk undo.\nInput 'l' untuk pinjam buku lainnya.\n");

                        if(cek == 'n' || cek == 'N') break;
                            
                        if(cek == 'y' || cek == 'Y'){
                        	clear_screen();
                        	header2("Konfirmasi Pengiriman Buku");
                        	if(peek(stack) == nullptr){
                                print_endl<teks>("\nKeranjang Kosong.");
                                kembali();
                                std::cin.get();
                                break;
                            }
                            identitas_peminjam(stack);
                        	endl();

                      		identitas_buku_keranjang(stack, banyak_buku);
                      		cetak_banyak_buku(banyak_buku);
                      		biaya(pPinjam->prioritas, banyak_buku);

                        	konfirmasi(cek, "untuk kirim buku.\n");
                        	if(cek == 'y' || cek == 'Y'){
                                
                                
                                do{
                                    pBuku = cari_buku(head, stack->kode);
                                    pBuku->peminjam = stack->peminjam;
                                    pBuku->alamat = stack->alamat;

                                    kode += stack->kode + " | ";
                                    judul += stack->judul + "\t|";
                                    penulis += stack->penulis + "\t|";
                                    tahun += stack->tahun + "\t\t|";
                        			pop(stack);
 
                        		}while(!isEmpty(stack));
                                
                                buat_node(pAntri, kode, judul, penulis, tahun, pPinjam->peminjam, pPinjam->alamat, pPinjam->prioritas);
                                enqueue(qpinjam, pAntri);
								// while(!isEmpty(stack)){
        //                             pBuku = cari_buku(head, stack->kode);
        //                             pBuku->peminjam = stack->peminjam;
        //                             pBuku->alamat = stack->alamat;
     
        //                 			enqueue(pinjam, pop(stack));
 
        //                 		}
                        		print_endl("\n-Buku dalam proses pengiriman-");
                        		kembali();
                        		std::cin.get();
                        	}
                        }else if(cek == 'u' || cek == 'U'){
                        	pop(stack);
                        	print_endl("\n-Undo Berhasil-");
                        	goto undo;
                        }else if(cek == 'l' || cek || 'L'){
                        	goto pinjam_buku;
                        }
                        break;
                    }
                }
                
                while(!isEmpty(stack)){
                  pop(stack);
                }
                break;
            
            case 4:
                cek = 'y';
                while(cek == 'y' || cek == 'Y'){
                    clear_screen();
                    header("KEMBALIKAN BUKU");
                    cek_batal();
                    print<teks>("Kode/Nama peminjam buku yang akan dikembalikan: ");
                    input_string(key);

                    if(key == "0") break;
                    
                    pBuku = cari_buku(head, key);

                    if(pBuku == nullptr){
                        header2("BUKU TIDAK DITEMUKAN");
                        konfirmasi(cek, "untuk mengembalikan buku lain.\n");
                    }else{
                    	if(pBuku->peminjam == "NULL"){
                            header2("Buku Tidak Sedang Dipinjam");
                            konfirmasi(cek, "untuk mengembalikan buku lain.\n");
                            if(cek == 'y' || cek == 'Y'){
                                goto pinjam_buku;
                            }else{
                                break;
                            }
                        } 

                        header2("Anda Meminjam");
                        tabel();
                        traversal_buku(head, key, banyak_buku);
                        batas_akhir_tabel();
                        cetak_banyak_buku(banyak_buku);
                        
                        print_endl<teks>("Buku akan dijemput ke alamat anda, dengan biaya");
                        print_endl<teks>("-Express Rp 20.000,-/buku.");
                        print_endl<teks>("-Regular Rp 10.000,-/buku.");
                        print_endl<teks>("Dibayar secara COD.");

                        print_endl<teks>("\nPrioritas : \n1. Express \n2. Regular\n");
                        input<int>(pKembali->prioritas);

                        biaya(pKembali->prioritas, banyak_buku);

                        konfirmasi(cek, "untuk mengembalikan.\n");

                        if(cek == 'y' || cek == 'Y'){
                        	for(int i = 0; i < banyak_buku; i++){
                        		pBuku = cari_buku(head, key);
                                kode += pBuku->kode + " | ";

                                peminjam = pBuku->peminjam;
                                alamat = pBuku->alamat;

                                pBuku->peminjam = "NULL";
                                pBuku->alamat = "NULL";
                        	}

                            buat_node(pKembali, kode, judul, penulis, tahun, peminjam, alamat, pKembali->prioritas);
                            enqueue(qkembali, pKembali);   

                        	print_endl("\n-Buku sedang dijemput ke alamat anda-");
                        	kembali();
                        	std::cin.get();
                        }
                        break;
                    }
                }
                break;
            
            case 5:
        		clear_screen();
                buku_dipinjam(head);
            	break;
                // cek = 'y';
                // while(cek == 'y' || cek == 'Y'){ 
                //     clear_screen();
                //     header("BUKU DIPINJAM");
                //     print<teks>("Peminjam : ");
                //     input_string<teks>(key);
                //     //print<teks>(pBuku->peminjam);
                //     pBuku = cari_buku(head, key);
                //     //print<teks>(pBuku->peminjam);
                //     if(key == "0") break;
                    
                //     if(pBuku == nullptr){
                //         header2("PEMINJAM TIDAK DITEMUKAN");
                //         konfirmasi(cek, "untuk mengembalikan buku lain.\n");
                //     }else{
                //         header2("BUKU DITEMUKAN");
                //         tabel();
                //         traversal_buku(head, key, banyak_buku);
                //         batas_akhir_tabel();
                //         kembali();
                //         break;
                //     }
                // }
                // break;

            case 6:
            	clear_screen();
                buku_tersedia_dipinjam(head);
            	break;

            case 9:
                clear_screen();
                header("LOGIN PETUGAS");
                cek_batal();

                print("Username : "); input<teks>(username);
                if(username == "0") break;
                print("Password : "); input<teks>(password);

            
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
                kembali();
                std::cin.get(); 
                break;
        }        
	
	}while(pilihan != 0);
    
    save_data(head);
    save_order(front(qpinjam));
}