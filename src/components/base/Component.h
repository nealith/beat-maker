// -*- c++ -*-

#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

class Component {

public:

    virtual ~Component(){}

    virtual void compute() = 0;

};

#endif // COMPONENT_H
