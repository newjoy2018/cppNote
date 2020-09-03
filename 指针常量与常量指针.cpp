#include <iostream>

using namespace std;

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *p=&a[3];
    int b=p[3];
    cout << b << endl;

    const int m = 10;
    cout << "const int m = " << m << endl;

    const int* n = &m;
    cout << "\nn->m" << endl;
    cout << "  const int* n = " << n << endl;
    cout << "  const int* *n = " << *n << endl;
    cout << "let n point to others" << endl;
    n = &a[5];
    cout << "  n = &a[5], *n = " << *n << endl;
    cout << "  we did, because n itself is not a const"  << endl;

    int const* q = &m;
    cout << "\nq->m" << endl;
    cout << "  int const* q = " << q << endl;
    cout << "  int const* *q = " << *q << endl;
    cout << "  int const and const in is the same" << endl;


    const int* const r = &m;
    cout << "\nr->m" << endl;
    cout << "  const int* const r = " << r << endl;
    cout << "  const int* const r = " << *r << endl;
    cout << "  Since r is a const pointer, we cannot let it point to others, like r = &a[7]" << endl;

    int const* const s = &m;
    cout << "\ns->m" << endl;
    cout << "  int const* const s = " << s << endl;
    cout << "  int const* const s = " << *s << endl;
    cout << "  Since s is a const pointer, we cannot let it point to others, like s = &a[7]" << endl;


    int c=66;
    const int* pc = &c;
    cout << "\npc = " << *pc << endl;
    c = 77;
    cout << "\npc = " << *pc << endl;
    //*pc = 88;
    //cout << "\npc = " << *pc << endl;
    //Notice: const int*指向的普通整型变量，可以直接修改变量，但不能通过指针修改


    return 0;
}
