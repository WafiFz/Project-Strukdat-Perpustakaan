
template <typename tipe>
void print(tipe isi){ 
    std::cout << isi;
}

template <typename tipe>
void print_endl(tipe isi){ 
    std::cout << isi << std::endl;
}

template <typename tipe>
void input(tipe& isi){ 
    std::cin >> isi;
}

void endl(){ 
    std::cout << std::endl;
}

template <typename tipe>
void input_string(tipe teks){ 
    std::getline(std::cin, teks);
}

void clear_screen(){
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif

}