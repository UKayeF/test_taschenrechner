#ifndef TASCHENRECHNER_HPP
#define TASCHENRECHNER_HPP

#include <string>

class Taschenrechner
{
private:
    std::string m_eingabe;
public:
    Taschenrechner();
    void setEingabe(std::string eingabe);
    std::string getEingabe();
};

#endif // TASCHENRECHNER_HPP
