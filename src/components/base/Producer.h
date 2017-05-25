// -*- c++ -*-

#ifndef PRODUCER_H
#define PRODUCER_H

#include <vector>
#include <Component.h>
#include <Pipe.h>

class Producer : public virtual Component {

private:

    unsigned int m_nbOutput;

    std::vector<std::shared_ptr<Pipe>> m_output;

public:

    virtual ~Producer(){}

    unsigned int nbOutput() const;

    std::shared_ptr<Pipe> getOutput(unsigned int noOutput) const;

    virtual void compute() = 0;

protected:

    Producer(unsigned int nbOutput = 1);

    void connectOutput(const std::shared_ptr<Pipe> p,unsigned int noOutput);

    void write(unsigned int noOutput, double value);

};

#endif // PRODUCER_H
