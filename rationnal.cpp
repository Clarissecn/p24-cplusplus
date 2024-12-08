#include <iostream> 

class Rational {
private:
    int denom;
    int num;
public:
    //implement a default-constructor that initializes the object 0/1
    Rational () : num(0), denom(1) {}
    //implement a constructor with one argument that initializes the object n/1
    Rational(int n) : num(n), denom(1){}
    //implement a constructor with two arguments
    Rational(int n, int d) : num(n), denom(d) {}
    
    friend bool operator==(const Rational& r1, const Rational& r2){
        return r1.num*r2.denom==r1.denom*r2.num;
    }
    
    friend Rational operator+(const Rational& r1, const Rational& r2){
        int newnum = r1.num * r2.denom + r1.denom * r2.num;
        int newdenom = r2.denom * r1.denom;
        return Rational(newnum, newdenom);
    }
    
    double to_float() const {
        return static_cast<double>(num) / denom;
    }
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.num << "/" << r.denom;
        return os;
    }
};

int main(){
    Rational r1; 
    Rational r2(5); 
    Rational r3(3, 4); 
    Rational r4(2, 8);
    std::cout << "R1: " << r1 << std::endl;
    std::cout << "R2: " << r2 << std::endl;
    std::cout << "R3: " << r3 << std::endl;
    std::cout << "R4: " << r4 << std::endl;
    std::cout << "R3 == R4? " << (r3 == r4 ? "True": "False") << std::endl;
    Rational r5 = r3 + r4;
    std::cout << "R3 + R4 = " << r5 << std::endl;
    std::cout << "R3 as float: " << r3.to_float() << std::endl;
    return 0;
}