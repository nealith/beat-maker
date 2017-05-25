#include <Pipe.h>
#include <cassert>

Pipe::Pipe():
    m_samples(){}

Pipe::~Pipe(){}

void Pipe::insert(double sample){
    m_samples.push_front(sample);
}

double Pipe::extract(){

    assert("empty pipe" && !empty());
    double ret = m_samples.back();
    m_samples.pop_back();
    return ret;

}

bool Pipe::empty(){
    return m_samples.empty();
}
