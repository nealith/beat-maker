// -*- c++ -*-

#ifndef PRODUCER_H
#define PRODUCER_H

#include <vector>
#include <Component.h>
#include <Pipe.h>

namespace components.base

class Producer {

private:

    unsigned int m_nbOutput;

    std::vector<Pipe> m_output;

public:

    virtual ~Producer(){}

    unsigned int nbOutput() const;

    Pipe getOutput(unsigned int noOutput) const;

    virtual void compute() = 0;

protected:

    Producer(unsigned int nbOutput = 1);

    void connectOutput(const Pipe p,unsigned int noOutput);

    void write(unsigned int noOutput);

};

#endif // PRODUCER_H
