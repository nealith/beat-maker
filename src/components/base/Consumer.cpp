#include <Consumer.h>
#include <cassert>

unsigned int Consumer::nbInput() const{
    return m_nbInput;
}

std::shared_ptr<Pipe> Consumer::getInput(unsigned int noInput) const{
    assert("This input doesn't exist" && noInput < m_nbInput);
    return m_input[noInput];
}

void Consumer::connectInput(const std::shared_ptr<Pipe> p,unsigned int noInput){
    assert("This input doesn't exist" && noInput < m_nbInput);
    m_input[noInput] = p;
}

bool Consumer::thereAreSamples() const{
    bool ret = true;
    for (std::vector<std::shared_ptr<Pipe>>::const_iterator  it = m_input.begin(); (it != m_input.end() && ret); it++) {
        if ((*it)->empty()) {
            ret = false;
        }
    }
    return ret;
}

Consumer::Consumer(unsigned int nbInput):
    m_nbInput(nbInput),m_input(nbInput,std::shared_ptr<Pipe>(NULL)){
    assert("nbInput must be >= 1" && 0 < nbInput);
}

double Consumer::read(unsigned int noInput){
    assert("This input doesn't exist" && noInput < m_nbInput);
    return m_input[noInput]->extract();
}
