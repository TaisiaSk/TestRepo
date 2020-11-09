#include <iostream>

void natural(int N) {
    if (N == 1)                                    
        std::cout << N << ' ';
    else {
        natural(N - 1);
        std::cout << N << ' ';
    }
}

void output_integers(int A, int B) {
        if (A == B)
            std::cout << A << ' ';
        else {
            std::cout << A << ' ';
            if(A<B)
                output_integers(A + 1, B);
            else
                output_integers(A - 1, B);
        }
}

int main() {

   // natural(5);

    output_integers(2, 8);
    output_integers(8, 2);

    system("pause");
    return 0;
}