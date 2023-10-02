// Cinema.hpp (Roland Teodorowitsch; 17 maio 2023)
#include "Endereco.hpp"
#include "Cinema.hpp"
#include <iostream>
#include <sstream>

using namespace std;

 Cinema::Cinema(){
    numero = 0;
    nome = "";
    endereco = Endereco();
    salas = 0;
 }
 
 Cinema::Cinema(int n, string nm, Endereco &e, int s){
    numero = n;
    nome = nm;
    endereco = e;
    salas = s;
 }

 Cinema::~Cinema(){
    //cout << numero << ", " << nome << " - " << endereco << " [Foi destruido...]" << endl;
 }

 int Cinema::obtemNumero() const {return numero;}
 string Cinema::obtemNome() const {return nome;}
 Endereco Cinema::obtemEndereco() const {return endereco;}
 int Cinema::obtemSalas() const {return salas;}

 string Cinema::str() const {
        stringstream ss;
        ss << nome << " [" << numero << "] " << endl << endereco << "Cinema(s): " << salas << endl;
        return ss.str();
 }

 void Cinema::defineNumero(int n) {numero = n;}
 void Cinema::defineNome(string nm) {nome = nm;}
 void Cinema::defineEndereco(Endereco &e) {endereco = e;}
 void Cinema::defineSalas(int s) {salas = s;}

 bool Cinema::operator<(const Cinema &c) const{
                 if(c.nome<nome){
          return true;
     } else {
          return false;
     }
 }
 
istream &operator>>(istream &in,Cinema &c){
   
   in >> c.numero;
   string descarte;
   getline(in,descarte);
   getline(in,c.nome);
   in >> c.endereco;
   getline(in,descarte);
   in >> c.salas;
   
   return in;
}

ostream &operator<<(ostream &out,const Cinema &c){
out << c.str();
return out;
}


