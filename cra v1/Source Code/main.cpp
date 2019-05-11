/* 
    PATRICK DIEGO
    ENGENHARIA ELÉTRICA - UFPB
    patrick.silva@cear.ufpb.br
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include "stdc++.h"
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

fstream notas;

class Cadeira{
    protected:
        char nome[100];
        vector <float> notas;
        float media;
        int peso;
        int periodo;
    public:
        void setPeso(int p){ this->peso = p; }
        void setPeriodo(int p){ this->periodo = p;}
        void setNotas(float nota){ notas.push_back(nota); }
        void setMateria(char materia[]){ strcpy(this->nome, materia); }
        float getMedia(){
            this->media = 0;
            for(int i = 0; i < notas.size(); i++) this->media = this->media + notas[i];
            this->media = this->media / float(notas.size() );
            return this->media;
        }
        void ShowData(){ cout << this->nome << ": " << this->getMedia() << endl; }
        int getPeso(){ return this->peso; }
        float getNota(int n){ 
            float nots; 
            nots = notas[n];
            return nots; 
        }
        char * getMateria(){ return this->nome; } 
};

void setNota();
void viewMedias();
void getCra();
void load_files();
void save_file();

vector <Cadeira> mat;
float cra;

int main(){
    load_files();
    int op;

    cout << setprecision(3);
    do{
        system("clear");
        cout << "1. inserir nota" << endl;
        cout << "2. Visualizar medias das cadeiras" << endl;
        cout << "3. Calculo CRA" << endl << endl;
        cout << "0. Sair do programa" << endl << endl;
        cout << "opcao: ";
        cin >> op;
        cin.ignore();
        cout << endl;
        system("clear");

        switch (op)
        {
        case 1:
            setNota();
            system("read -p \"Enter ...\"");
            break;
        case 2:
            viewMedias();
            system("read -p \"Enter ...\"");
            break;
        case 3:
            getCra();
            system("read -p \"Enter ...\"");
            break;
        default:
            break;
        }
    }while(op !=0);
    save_file();
    return 0;
}
void setNota(){
    char nome[100];
    float nota;
    int peso;
    Cadeira *aux = new Cadeira;

    system("clear");

    cout << "\tCadastro de cadeiras (concluidas)\n\n";

    cout << "nome da cadeira: ";
    cin.getline(nome,100);
    cout << endl;
    aux->setMateria(nome);

    cout << "peso: ";
    cin >> peso;
    cout << endl;
    aux->setPeso(peso);

    for(int i = 0; i < peso - 1; i++){
        cout << "digite a nota " << i + 1 << ": ";
        cin >> nota;
        cout << endl;
        aux->setNotas(nota);
    }
    mat.push_back(*aux);
    delete aux;
}
void viewMedias(){
    system("clear");
    cout << "\tMedias\n\n";
    for(int i = 0; i < mat.size(); i++){
        mat[i].ShowData();
    }
    cout << endl;
}
void getCra(){
    system("clear");
    viewMedias();
    float totalNota = 0, soma;
    int totalPeso = 0;
    int aux;
    for(int i = 0; i < mat.size(); i++){
        soma = 0;
        totalPeso += mat[i].getPeso();
        totalNota = totalNota + (mat[i].getPeso()*mat[i].getMedia());
    }
    totalNota = totalNota / totalPeso;
    cout << "Cra = " << totalNota << endl << endl;
}
void load_files(){
    Cadeira * aux; 
    string auxiliar;
    float nota;
    char auxText[100];
    int peso;

    notas.open("notas.csv", ios::in);
    if(!notas.is_open()) cout << "arquivo notas nao carregado" << endl;
    else{
        while( notas.good() ){
            getline(notas, auxiliar, ';');
            aux = new Cadeira;
            
            if(auxiliar != ""){
                peso = atoi(auxiliar.c_str());
                //cout << peso << endl;
                aux->setPeso(peso);
                for(int i = 0; i < peso - 1; i++){
                    getline(notas, auxiliar, ';');
                    nota = atof(auxiliar.c_str());
                    //cout << nota << endl;
                    aux->setNotas(nota);
                }
                getline(notas, auxiliar, '\n');
                strcpy(auxText, auxiliar.c_str());
                //cout << auxText << endl;
                aux->setMateria(auxText);
                mat.push_back(*aux); 
            }
            delete aux;
        }
        
    }
    notas.close();
}
void save_file(){
    notas.open("notas.csv", ios::out);
    if(!notas.is_open()) cout << "arquivo notas nao carregado" << endl;
    else{
        for(int i = 0; i < mat.size(); i++){
            notas << mat[i].getPeso() << ';';
            
            for(int j = 0; j < mat[i].getPeso() - 1; j++){
                notas << mat[i].getNota(j) << ";";
            }
            if(i < mat.size() - 1) notas << mat[i].getMateria() << "\n";
            else notas << mat[i].getMateria();
        }
    }
    notas.close();
}