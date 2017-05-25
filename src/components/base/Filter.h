// -*- c++ -*-

#ifndef FILTER_H
#define FILTER_H

#include <Consumer.h>
#include <Producer.h>

class Filter : public Consumer, public Producer {

public:

    virtual ~Filter(){}

    virtual void compute() = 0;

protected:

    Filter(unsigned int nbInput, unsigned int nbOutput);

};

#endif // FILTER_H
