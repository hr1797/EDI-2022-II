#include "Sets.h"

int main()
{
    Set setA;
    Set setB;
    Set setC;

    init_set(&setA);
    init_set(&setB);
    init_set(&setC);

    add(&setA, 23);
    add(&setA, 16);
    add(&setA, 11);
    add(&setA, 7);
    add(&setA, 5);

    add(&setB, 10);
    add(&setB, 5);
    add(&setB, 11);
    add(&setB, 21);

    printf("Set A:\n");
    printSet(setA);
    printf("\n");
    printf("Set B:\n");
    printSet(setB);
    printf("\n");
     
    printf("Set de intersección:\n");
    intersect(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf("Set de unión:\n");
    unionSet(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf("Set complemento de A a B:\n");
    complementSet(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf("Set complemento de B a A:\n");
    complementSet(setB, setA, &setC);
    printSet(setC);

    init_set(&setC);
    printf("Set diferencia de A a B:\n");
    diferenceSet(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf("Set diferencia de B a A:\n");
    diferenceSet(setB, setA, &setC);
    printSet(setC);
}