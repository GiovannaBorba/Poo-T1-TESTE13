// Filme.cpp (Giovanna Borba; 21 set. 2023)
#include "Filme.hpp"
#include <string>
#include <sstream>
#include <iostream>

Filme::Filme(int n, string t, int f, string e){
    numero = n;
    titulo = t;
    faixaEtaria = f;
    estilo = e;
 }

 Filme::~Filme(){
    //cout << titulo << " [Foi destruido...]" << endl; 
 }

 int Filme::obtemNumero() const {return numero;}
 string Filme::obtemTitulo() const {return titulo;}
 int Filme::obtemFaixaEtaria() const {return faixaEtaria;}
 string Filme::obtemEstilo() const {return estilo;}

 string Filme::str() const{
        stringstream ss;
        ss << titulo << " [" << numero << "] - ";
        if(faixaEtaria == -1){
            ss << "LIVRE";
        } else {
         ss << faixaEtaria << " anos";
        }
        ss << " - " << estilo << endl;

        return ss.str();
}

 void Filme::defineNumero(int n) {numero = n;}
 void Filme::defineTitulo(string t) {titulo = t;}
 void Filme::defineFaixaEtaria(int f) {faixaEtaria = f;}
 void Filme::defineEstilo(string e) {estilo = e;}

 bool Filme::operator<(const Filme &f) const{
              if(f.titulo < this->titulo){
          return true;
     } else {
          return false;
     }
 }

    istream &operator>>(istream &in,Filme &f){
    in >> f.numero;
    getline(in, f.titulo);
    in >> f.faixaEtaria;
    getline(in, f.estilo);

    return in;
 }
    ostream &operator<<(ostream &out,const Filme &f){
        out << f.str();
        return out;
 }


