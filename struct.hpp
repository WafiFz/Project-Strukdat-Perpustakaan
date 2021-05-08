struct Perpustakaan{
    std::string kode;
    std::string judul;
    std::string penulis;
    std::string tahun;
    std::string peminjam;
    std::string alamat;
    int prioritas;

    Perpustakaan *next;
    Perpustakaan *prev;
};

typedef Perpustakaan* pointer;

struct Queue{
    pointer head;
    pointer tail;
}Q;