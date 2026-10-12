
#ifndef TYPES_H
#define TYPES_H

// Dynamic array that contains exercises already given
typedef struct ArrayEs {

    int maxCapacity;

    int numberElement;

    struct ArrayEs *array;
} ArrayEs_t;

#endif