#include <cstdio>
#include "Math.h"
using namespace std;
int main() {
    printf("Add(1, 2): %d \n", Math::Add(1, 2));
    printf("Add(1, 2, 3): %d \n", Math::Add(1, 2, 3));
    printf("Add(1.2, 2.5)): %d \n", Math::Add(1.2, 2.5));
    printf("Add(1.2, 2.5,3.7): %d \n", Math::Add(1.2, 2.5,3.7));
    printf("Mul(3, 2): %d \n", Math::Mul(3, 2));
    printf("Mul(3, 2,5): %d \n", Math::Mul(3, 2,5));
    printf("Mul(3.3, 2.7): %d \n", Math::Mul(3.3, 2.7));
    printf("Mul(3.3, 2.7,1.5): %d \n", Math::Mul(3.3, 2.7,1.5));
    printf("Add(5, 1, 2,3,5,7): %d \n", Math::Add(5, 1, 2,3,5,7));
    printf("Add( da , nu ): %s \n", Math::Add("unu", "doi"));
    printf("Add(nullptr,  nu ): %s \n", Math::Add(nullptr, "nu"));

}