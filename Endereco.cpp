// Endereco.hpp (Roland Teodorowitsch; 4 set. 2023)
#include "Endereco.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


 Endereco::Endereco(string l, int n, string c, string b, string cp, string cd, string e){
    logradouro = l;
    numero = n;
    complemento = c;
    bairro = b;
    cep = cp;
    cidade = cd;
    estado = e;   
 }

  Endereco::~Endereco(){
        //cout << logradouro << ", " << numero << " [Foi destruido...]" << endl; 
 }

 string  Endereco::obtemLogradouro() const {return logradouro;}
 int  Endereco::obtemNumero() const {return numero;}
 string  Endereco::obtemComplemento() const {return complemento;}
 string  Endereco::obtemBairro() const {return bairro;}
 string  Endereco::obtemCEP() const {return cep;}
 string  Endereco::obtemCidade() const {return cidade;}
 string  Endereco::obtemEstado() const {return estado;}
 
 string  Endereco::str() const{
        stringstream ss;
        ss << logradouro << ", " << numero;

        if (complemento != "") {
        ss << " - " << complemento;
        }
        ss << " - Bairro " << bairro << " - " << cidade << " - " << estado << endl;
        return ss.str();

}

 void  Endereco::defineLogradouro(string l) {logradouro = l;}
 void  Endereco::defineNumero(int n) {numero = n;}
 void  Endereco::defineComplemento(string c) {complemento = c;}
 void  Endereco::defineBairro(string b) {bairro = b;}
 void  Endereco::defineCEP(string cp) {cep = cp;}
 void  Endereco::defineCidade(string cd) {cidade = cd;}
 void  Endereco::defineEstado(string e) {estado = e;}

  istream &operator>>(istream &in,Endereco &e){
    getline(in,e.logradouro);
    in >> e.numero;
    string descarte;
    getline(in,descarte);
    string temp;
    getline(in, temp);

    if (temp != "") {
        e.complemento = temp;
    } else {
        e.complemento = "";
    }

    getline(in,e.bairro);
    getline(in,e.cep);
    getline(in,e.cidade);
    getline(in,e.estado);

    return in;
  }
  ostream &operator<<(ostream &out,const Endereco &e){
       out << e.str();
       return out;
  }

