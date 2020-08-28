#include "taschenrechner.hpp"

#include <string>

Taschenrechner::Taschenrechner() : m_eingabe("")
{

}

void Taschenrechner::setEingabe(std::string eingabe)
{
    m_eingabe = eingabe;
}

std::string Taschenrechner::getEingabe()
{
    return m_eingabe;
}
