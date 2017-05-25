// -*- c++ -*-

#ifndef CONSUMER_H
#define CONSUMER_H

#include <vector>
#include <Component.h>
#include <std::shared_ptr<Pipe>.h>

namespace components.base

class Consumer {

private:

    unsigned int m_nbInput;

    std::vector<std::shared_ptr<Pipe>> m_input;

public:

    virtual ~Consumer(){}

    unsigned int nbInput() const;

    std::shared_ptr<Pipe> getInput(unsigned int noInput) const;

    void connectInput(const std::shared_ptr<Pipe> p,unsigned int noInput);

    bool thereAreSamples() const;

    virtual void compute() = 0;

protected:

    Consumer(unsigned int nbInput = 1);

    double read(unsigned int noInput);

};

#endif // CONSUMER_H
