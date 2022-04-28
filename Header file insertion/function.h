#ifndef FUNCTION_H
#define FUNCTION_H 

class Function {
    private:
        int x;
        int y;
    public:
        Function (int a, int b) {x=a; y=b;}
        int add();
        int multiply();
};

int Function::add(){
    return x + y;
}

int Function::multiply(){
    return x*y;
}

#endif
