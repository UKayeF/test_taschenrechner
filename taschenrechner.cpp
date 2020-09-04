#include "taschenrechner.hpp"

#include <string>


int find_index(std::string str, char c)
{
    for (unsigned long long i = 0; i < str.length(); i++){
        if (str.at(i) == c)
        {
            return i;
        }
    }

    return - 1;
}

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

int Taschenrechner::berechne()
{
    int index_plus = find_index(m_eingabe, '+');
    int index_mul = find_index(m_eingabe, '*');
    int index_minus = find_index(m_eingabe, '-');
    int index_div = find_index(m_eingabe, '/');

    if (index_plus != -1){
       std::string first_num = m_eingabe.substr(0, index_plus);
       std::string second_num = m_eingabe.substr(index_plus + 1, m_eingabe.npos);
       int first_int = std::stoi(first_num);
       int second_int = std::stoi(second_num);
       int result = first_int + second_int;
       return result;
    }

    if (index_mul != -1){
       std::string first_num = m_eingabe.substr(0, index_mul);
       std::string second_num = m_eingabe.substr(index_mul + 1, m_eingabe.npos);
       int first_int = std::stoi(first_num);
       int second_int = std::stoi(second_num);
       int result = first_int * second_int;
       return result;
    }

    if (index_minus != -1){
       std::string first_num = m_eingabe.substr(0, index_minus);
       std::string second_num = m_eingabe.substr(index_minus + 1, m_eingabe.npos);
       int first_int = std::stoi(first_num);
       int second_int = std::stoi(second_num);
       int result = first_int - second_int;
       return result;
    }

    if (index_div != -1){
       std::string first_num = m_eingabe.substr(0, index_div);
       std::string second_num = m_eingabe.substr(index_div + 1, m_eingabe.npos);
       int first_int = std::stoi(first_num);
       int second_int = std::stoi(second_num);
       if (second_int == 0){
           std::string e = "Division by Zer0!!";
           throw e;
       }
       int result = first_int / second_int;
       return result;
    }

}
