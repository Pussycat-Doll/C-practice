#include<iostream>                                       
#include<cstddef>

struct A {
    char a;
    int t;
    char c;
    char b;
    double e;
}A;

int main() {
    std::cout << sizeof(A) << std::endl;
    printf("offsetof(class A,a) is %d\n", (int)offsetof(struct A, a));
    printf("offsetof(class A,t) is %d\n", (int)offsetof(struct A, t));
    printf("offsetof(class A,c) is %d\n", (int)offsetof(struct A, c));
    printf("offsetof(class A,b) is %d\n", (int)offsetof(struct A, b));
    printf("offsetof(class A,e) is %d\n", (int)offsetof(struct A, e));
    return 0;
}
