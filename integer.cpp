class Integer{
    private:
        int value{};
    public:
        void incr(){
            value=value +1;
        }
        Integer (intv){
            value=v;
        }
};

int main(){
    Integer i;
    Integer j=i;
    i=j;
    i.incr();
}