// -*- c++ -*-

#ifndef COMPONENT_H
#define COMPONENT_H

namespace components.base

class Component {

public:

    virtual ~Component(){}

    virtual void compute() = 0;

};

#endif // COMPONENT_H
