class Rational{
    private:
        int denom{1};
        int num{0};
    public:
    Rational (int n, int d) : num(n), denom(d){

    }
    void print() {
        std :: cout<<num<<"/"<<denom<<std::endl;
    }    
    void r1(){
        r1 = int a /denom
    }
    void r2(int a){
        r2 = int a / denom
    }
    void r3(int a, int b){
        r3 = int a /int b
    }
}

int main(){
    Rational r1;
    Rational r2(1);
    Rational r3(1,2);
    r1.print();
    r2.print();
    r3.print();
}