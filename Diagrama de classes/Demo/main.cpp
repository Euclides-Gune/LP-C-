#include <iostream>

class A {
private:
    int priv{};
protected:
    int proct{};
public:
    int pub{};

    void print()
    {
        std::cout << "In A\n";
    }
};

class B : public A {

};

int main()
{
    A a;
    // a.priv = 5;
    // a.proct = 5;
    a.pub = 5;

    B b;
    b.print();
    return 0;
}