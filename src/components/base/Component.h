// -*- c++ -*-

#ifndef COMPONENT_H
#define COMPONENT_H

namespace components.base

class component {

public:

    virtual ~component(){}

    virtual void compute() = 0;

};

#endif // COMPONENT_H
