#include <Producer.h>
#include <cassert>

unsigned int Producer::nbOutput() const{
    return m_nbOutput;
}

std::shared_ptr<Pipe> Producer::getOutput(unsigned int noOutput) const{
    assert("This output doesn't exist" && noOutput < m_nbOutput);
    return m_output[noOutput];
}

Producer::Producer(unsigned int nbOutput):
    m_nbOutput(nbOutput),m_output(nbOutput,std::shared_ptr<Pipe>(NULL)){
    assert("nbOutput must be >= 1" && 0 < nbOutput);
}

void Producer::connectOutput(const std::shared_ptr<Pipe> p,unsigned int noOutput){
    assert("This output doesn't exist" && noOutput < m_nbOutput);
    m_output[noOutput] = p;
}

void Producer::write(unsigned int noOutput, double value){
    assert("This output doesn't exist" && noOutput < m_nbOutput);
    return m_output[noOutput]->insert(value);
}
