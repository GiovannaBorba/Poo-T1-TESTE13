// Programacao.hpp (Roland Teodorowitsch; 4 set. 2023)
#include "Programacao.hpp"
#include "Cinema.hpp"
#include "Filme.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Programacao::Programacao(Cinema *c, int s, Filme *f, int t, string h){
   cinema = c; 
   sala = s;
   filme = f; 
   tipoDeExibicao = t;
   horarios = h;
}

Programacao::~Programacao(){
   //cout << filme << "/" << tipoDeExibicao << " [Foi destruido...]" << endl; 
}

Cinema *Programacao::obtemCinema() const{return cinema;}

int Programacao::obtemSala() const {return sala;}

Filme *Programacao::obtemFilme() const{return filme;}

int Programacao::obtemTipoDeExibicao() const {return tipoDeExibicao;}

string Programacao::obtemHorarios() const {return horarios;}

string Programacao::str(bool incluiCinema) const {
   stringstream ss;

   if(incluiCinema){ss << cinema->obtemNome() << " - ";}
      
      ss << "Sala " << sala << ": ";
      ss << filme->obtemTitulo() << " | " << horarios << " | ";

              switch (tipoDeExibicao) {
            case 1:
                ss << "LEG";
                break;
            case 2:
                ss <<"DUB";
                break;
            case 3:
                ss <<"3D LEG";
                break;
            case 4:
                ss <<"3D DUB";
                break;
            case 5:
                ss <<"NAC";
                break;
            }

           ss << " | " << "[";

           if(filme->obtemFaixaEtaria() < 1){
               ss << "LIVRE";
            } else {
               ss << filme->obtemFaixaEtaria();
            }

           ss << "]";
           ss << " | " << filme->obtemEstilo();
        return ss.str();
   
}

void Programacao::defineCinema(Cinema *c) { cinema = c;}
void Programacao::defineSala(int s) {sala = s;}
void Programacao::defineFilme(Filme *f) {filme = f;}
void Programacao::defineTipoDeExibicao(int t) {tipoDeExibicao = t;}
void Programacao::defineHorarios(string h) {horarios = h;}
