#
#if !defined(RGB_H_)
#define RGB_H_

namespace caveofprogramming{
struct Rgb{
    double red{0},green{0},blue{0};
    
    Rgb(double r,double g, double b);
};

 Rgb operator-(const Rgb &first,const Rgb &second);

}
#endif // RGB_H_
