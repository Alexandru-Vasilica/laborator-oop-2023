#include<cstdio>
using namespace std;
float operator"" _Kelvin(const unsigned long long value) {
    float celsius = (float)value - 273.15;
    return celsius;
}
float operator"" _Fahrenheit(const unsigned long long value) {
    float celsius = ((float)value - 32)/1.8;
    return celsius;
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("300 de grade Kelvin sunt %f de grade Celsius \n",a);
    printf("120 de grade Fahrenheit sunt %f de grade Celsius \n",b);
    return 0;
}