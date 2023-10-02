#include <string>
#include "Aplicacao.hpp"
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Programacao.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

//[PRIMEIRA ETAPA - APP1]:

 Aplicacao::Aplicacao(){
    numCinemas = 0;
        for(int i = 0 ; i < MAX_CINEMAS ; i++){
            cinemas[i] = nullptr;
        }

    numFilmes = 0;
        for (int i = 0 ; i < MAX_FILMES; i++){
            filmes[i] = nullptr;
        }

    numProgramacao = 0;
        for (int i = 0 ; i < MAX_PROGRAMACAO ; i++){
            programacao[i] = nullptr;
        }     
 } 
 


 Aplicacao::~Aplicacao(){
    //cout << "[Deletando Aplicacao...]" << endl;

    for (int i = 0 ; i < numCinemas ; i++){
        if (cinemas[i] != nullptr){
            //cout << "-- " << cinemas[i]->obtemNome() << " [Foi destruido...]" << endl;
            delete cinemas[i];
            cinemas[i] = nullptr;
        }
    }

    //cout << "-------------" << endl;

    for (int i = 0 ; i < numFilmes ; i++){
        if (filmes[i] != nullptr){
            //cout << "-- " << filmes[i]->obtemTitulo() << " [Foi destruido...]" << endl;
            delete filmes[i];
            filmes[i] = nullptr;
        }
    }

    //cout << "-------------" << endl;

    for (int i = 0 ; i < numProgramacao ; i++){
        if (programacao[i] != nullptr){
            delete programacao[i];
            programacao[i] = nullptr;
        }
    }
 }



 bool Aplicacao::carregaFilmes(string nomeArquivo){ 
        ifstream arqFilme;
        arqFilme.open(nomeArquivo, ios::in);

        if (!arqFilme.is_open()) {
            cerr << "Erro ao abrir o arquivo [CarregaFilmes]" << endl;
            return false;
        }

        int numero, faixaEtaria;
        string titulo, estilo, temp;
        int i = 0;

        for (int i = 0; arqFilme >> numero; i++) {
            getline(arqFilme, temp); //Descarta o \n

            getline(arqFilme, titulo);

            arqFilme >> faixaEtaria;
            getline(arqFilme, temp); //Descarta o \n

            getline(arqFilme, estilo);

            filmes[i] = new Filme(numero, titulo, faixaEtaria, estilo);
            numFilmes++;
        }
        arqFilme.close();
        return true;
    }



 bool Aplicacao::salvaFilmes(string nomeArquivo){
        ofstream arqFilme;
        arqFilme.open(nomeArquivo, ios::out);

        if (arqFilme.is_open() == false){
            cerr << "Erro ao abrir o arquivo [SalvaFilmes]";
            return false;
        }

        int i = 0;
        while (i < numFilmes && filmes[i] != nullptr) {
            arqFilme << filmes[i]->str() << endl;
            i++;
        }
        arqFilme.close();
        return true;
    }



 void Aplicacao::mostraFilmes(){
    for (int i = 0; i < numFilmes; i++){
        if (filmes[i] != nullptr){
            cout << filmes[i]->str();
        }
    }
 }



 void Aplicacao::ordenaFilmes(){
        int i = 0;
        bool troca;

        while (i < numFilmes - 1) {
            if (filmes[i] == nullptr) {
                i++;
                continue;
            }

            troca = false;
            int j = 0;

            while (j < numFilmes - i - 1) {
                if ((*filmes[j + 1] < *filmes[j]) == false) {
                    Filme *aux = filmes[j];
                    filmes[j] = filmes[j + 1];
                    filmes[j + 1] = aux;
                    troca = true;
                }
                j++;
            }
            if (!troca) {
                break;
            }

            i++;
        }
 }
 


 Filme *Aplicacao::obtemFilme(int id){
        int flag = 0;
        for (int i = 0; i < numFilmes; i++){
            if (filmes[i]->obtemNumero() == id){
            return filmes[i];
            flag = 1;
            }
        }
        if(flag == 0){return nullptr;}
    }


//[SEGUNDA ETAPA - APP2]:


 bool Aplicacao::carregaCinemas(string nomeArquivo){
        ifstream arqCinema;
        arqCinema.open(nomeArquivo, ios::in);

        if (arqCinema.is_open() == false){
            cerr << "Erro ao abrir o arquivo [CarregaCinemas]";
            return false;
        }

        Cinema cinema;
        string nome, temp; 
        Endereco Endereco = cinema.obtemEndereco();
        int numero, salas; 
        int i = 0;

        while (arqCinema >> numero){
            getline(arqCinema, temp); //Descarta o \n
            getline(arqCinema, nome);
            arqCinema >> Endereco;
            arqCinema >> salas;
            cinemas[i] = new Cinema(numero, nome, Endereco, salas);
            numCinemas++;
            i++;
        }
        arqCinema.close();
        return true;
 } 



 bool Aplicacao::salvaCinemas(string nomeArquivo){
        ofstream arqCinema;
        arqCinema.open(nomeArquivo, ios::out);

        if (arqCinema.is_open() == false){
            cerr << "Erro ao abrir o arquivo [SalvaCinemas]";
            return false;
        }

        for (int i = 0; i < numCinemas && cinemas[i] != nullptr; i++) {
            arqCinema << cinemas[i]->str() << endl;
        }  
        arqCinema.close();
        return true;
 }



 void Aplicacao::mostraCinemas(){
        for (int i = 0; i < numCinemas && i <= MAX_CINEMAS; i++) {
            if (cinemas[i] == nullptr) {
            break;
        }
        cout << cinemas[i]->str() << endl;
        }
 }



 void Aplicacao::ordenaCinemas(){
        int i = 0;
        bool troca2 = false;

        while (i < numCinemas) {
            if (cinemas[i] == nullptr) {
                i++;
                continue;
            }

            troca2 = false;
            int j = 0;

            while (j < numCinemas - i - 1) {
                if (cinemas[j + 1] == nullptr) {
                    j++;
                    continue;
                }

                if ((*cinemas[j + 1] < *cinemas[j]) == false) {
                    Cinema *aux2 = cinemas[j];
                    cinemas[j] = cinemas[j + 1];
                    cinemas[j + 1] = aux2;
                    troca2 = true;
                }

                j++;
            }
            if (!troca2) {
                break;
            }
            i++;
        }
 }



 Cinema *Aplicacao::obtemCinema(int id){
        int flag = 0;
        for (int i = 0; i < numCinemas; i++){
            if (cinemas[i]->obtemNumero() == id){
            return cinemas[i];
            flag = 1;
            }
        }
        if(flag == 0){return nullptr;}
 }


//[TERCEIRA ETAPA - APP3]:


 bool Aplicacao::carregaProgramacao(string nomeArquivo){
        ifstream arqProg;
        arqProg.open(nomeArquivo, ios::in);

        if (arqProg.is_open() == false){
            cerr << "Erro ao abrir o arquivo [CarregaProgramacao]";
            return false;
        }

        int numCinema, salaCinema, numFilme, tipoExibicao;
        string horarios, temp;
    
        for (int i = 0 ; arqProg >> numCinema ; ++i){
            arqProg >> salaCinema;
            arqProg >> numFilme;
            arqProg >> tipoExibicao;
            getline(arqProg, temp); //Descarta o \n
            getline(arqProg, horarios);

            Filme *filme_temp = obtemFilme(numFilme);
            Cinema *cinema_temp = obtemCinema(numCinema);

                programacao[i] = new Programacao(cinema_temp, salaCinema, filme_temp, tipoExibicao, horarios);
                numProgramacao++;
        }
        return true;
 } 



 void Aplicacao::mostraProgramacao(){
        int i = 0, j = 0;
        while(i<numCinemas){
            cout << cinemas[i]->obtemNome() << endl << endl; 
            j = 0;
            
            while(j < numProgramacao){
                Cinema *temp = programacao[j]->obtemCinema();
                    if (temp->obtemNumero() == cinemas[i]->obtemNumero()){
                        cout << programacao[j]->str(false) << endl;
                    }
            j++;
        }
        cout << endl;
        i++;
    }
 }


