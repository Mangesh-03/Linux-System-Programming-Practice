int Addition(int a,int b)
{
    int Ans = 0;

    Ans = a + b;

    return Ans;
}

int Subtraction(int a,int b)
{
    int Ans = 0;

    Ans = a - b;

    return Ans;
}

// for compile
// 1. gcc -c client1.c -o client1.o

// 2.ar rcs libClient1.a client1.o 

// rcs   => r replace
//       => c create
//       => s symbol index 

// ar => archive utility 