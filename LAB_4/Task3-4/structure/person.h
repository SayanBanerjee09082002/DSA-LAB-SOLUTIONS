#ifndef PERSON_H
#define PERSON_H

struct Person
{
    int id;
    char name[32];
    int age;
    int height;
    int weight;
};
typedef struct Person Person;

#endif