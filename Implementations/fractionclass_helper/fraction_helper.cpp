#include <iostream>
#include <cmath>
#include <variant>
using namespace std;


/* trying variants */
// typedef std::variant<int,float, long double> tt;

// void num_test_var(tt x, tt y){
//     long double n = std::get<long double>(x);
//     long double d = std::get<long double>(y);
//     while(fmod(n,10)!=0 && fmod(d,10)!=0){
//         n *= 10;
//         d *= 10;
//     }
//     tt x_f = n;
//     tt y_f = d;
//     cout << x_f << " " << y_f << "\n";
// }

/* recursive version */
// int num_test(long double n,long double d){
//     if(fmod(n,10)==0 && fmod(d,10)!=0)
//         return 0;
//     num_test(n*10,d*10);
// }

/* iterative version */
void num_test(long double n, long double d){
    while(fmod(n,10)!=0 && fmod(d,10)!=0){
        n *= 10;
        d *= 10;
    }
    cout << n << " " << d << "\n";
}

//long long fraction::get_decimal_places(const long double &n, const long double& d)
//{
//    //float to int
//    std::stringstream ns;
//    std::string count;
//    ns << fabsl(n - int(n));
//    ns >> count;
//    long long decimal_n = count.length()-2;

//    std::stringstream ds;
//    ds << fabsl(d - int(d));
//    ds >> count;
//    long long decimal_d = count.length()-2;

//    return decimal_n > decimal_d ? decimal_n : decimal_d;
//}

int main() {
    

    return 0;
}