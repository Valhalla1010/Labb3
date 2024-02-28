#include <iostream>

template<int N, bool Enable = true>
struct S {
    static void print(){
        std::cout << N << ", ";
        S<N-1>::print();
    }
};

template<int N>
struct S<N, N < 0>{
    static void print(){
        std::cout << N << ", ";
        S<N + 1>::print();
    }
};


template<>
struct S<0>{
    static void print(){
        std::cout << "0.\n";
    }
};
int main() {
    S<-5>::print();
    S<0>::print();
}
