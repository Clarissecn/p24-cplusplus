#include <iostream> 

class Rational {
    // friend bool operator==(const Rational& r1, const Rational& r2);
private:
    int denom;
    int num;
public:
    Rational(int p =0, int q = 1) : num{p}, denom(q) {}
    
    friend bool operator==(const Rational& r1, const Rational& r2){ //on met & car si on met rien ça les recopie et nous on veut directement travailler avec r1 et r2 sans les recopier
    //const c'est pour pas les modifier (par ex on pourra pas faire r1.num = 0)
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
    //j'ai trouvé ça sur internet mais jsp pourquoi sans cette partie ça ne fonctionne pas
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