#include <iostream>

class My_vector //считаем, что все векторы исходят из начала коордидат
{
private:
    double x, y, z;
public:
    My_vector(double a = 0, double b = 0, double c = 0)
    {
        x = a;
        y = b;
        z = c;
    }
    void print()
    {
        std::cout <<"(" << x << " " << y <<" "<< z << ")" << std::endl;
    }
    My_vector operator+ (My_vector& v)
    {
        return My_vector(x+v.x, y+v.y, z+v.z);
    }
    My_vector operator- (My_vector& v)
    {
        return My_vector(x-v.x, y-v.y, z-v.z);
    }
    My_vector operator* (double number)
    {
        return My_vector(x*number, y*number, z*number);
    }
    My_vector operator/ (double number)
    {
        return My_vector(x/number, y/number, z/number);
    }

    double sc_mult(My_vector& v)
    {
      return x*v.x+y*v.y+z*v.z;
    }
    My_vector vect_mult(My_vector& v)
    {
        return My_vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }


};

int main()
{
    My_vector v1(2., 5.5, 3.);
    My_vector v2(1., 1., 1.);
    (v1+v2).print();
    (v2-v1).print();
    (v2*6.6).print();
    (v2/3.).print();
    std::cout << v1.sc_mult(v2) << std::endl;
    (v1.vect_mult(v2)).print();
    return 0;
}

