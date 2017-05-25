// -*- c++ -*-

#ifndef PIPE_H
#define PIPE_H

#include <deque>

class Pipe {

private:

    std::deque<double> m_samples;

public:

    Pipe();

    ~Pipe();

    void insert(double sample);

    double extract();

    bool empty();

};

#endif // PIPE_H
