#include <Filter.h>

Filter::Filter(unsigned int nbInput, unsigned int nbOutput):
    Consumer(nbInput),
    Producer(nbOutput){}
