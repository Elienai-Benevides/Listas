#define CLOCKS_PER_SEC 
#include "head_seq.h"
#include "node_list.h"
#include "seq_list.h"
#include "systema.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <time.h>
#include <cstdlib>
using namespace std;
head_seq::head_seq(){
     sequencial_f = NULL;
     sequencial_s = NULL;
}
 
head_seq::~head_seq(){
     sequencial_f = NULL;
     sequencial_s = NULL;
}
void head_seq::seta_lista_seq(seq_list *p, string name, string rg) {
     p = (seq_list*)malloc(20*sizeof(seq_list));
    if (sequencial_f == NULL) {
        sequencial_f = p;
        sequencial_s = p;
        sequencial_f->previous = NULL;
        sequencial_s->previous = NULL;
        sequencial_f->name = name;
        sequencial_f->rg = rg;
        sequencial_s->name = name;
        sequencial_s->rg = rg;
    }
    else {
        sequencial_s->next = p;
        sequencial_s = p;
        sequencial_s->name = name;
        sequencial_s->rg = rg;
        sequencial_s->next = NULL;
        sequencial_s->previous = NULL;
    }
    //sequencial_s->next = NULL;
   // sequencial_s->previous = NULL;
    n_seq = (n_seq) + 1;
}
void head_seq::remov_seq_begin() {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    comp_seq = 0;
    int pos = 1;
    aux = sequencial_f;
    aux->return_values1();
    var_ant = aux->next;
    sequencial_f->previous = NULL;
    sequencial_f = var_ant;
    
    moviment_seq = 5;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << pos << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
}
void head_seq::remov_seq_middle(int index) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    int i = 2;
    seq_list *var_curr, *aux, *var_ant;
    comp_seq = 0;
    aux = sequencial_f;
    while (i < index) {
        aux = aux->next;
        i++;
    }
    
    var_ant = aux->next;
    var_ant->return_values();
    var_curr = var_ant;
    var_ant = var_ant->next;
    aux->next = var_ant;
    
    var_curr->previous = NULL;
    var_curr->next = NULL;
    
    moviment_seq = 7;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << index << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
}
void head_seq::remov_seq_end() {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    int pos = 0;
    aux = sequencial_s;
    
    if(aux != NULL) {
        aux->return_values();
        var_ant = aux->previous;
        //var_ant->next = NULL;
        sequencial_s->next = NULL;
        sequencial_s = var_ant;
    }
    
    moviment_seq = 5;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << n_seq << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
}
void head_seq::listar_seq_list() {
    int i = 0;
    seq_list *iterator;
    string name_;
    string rg_;
    
    iterator = sequencial_f;
    ofstream arq("arq.txt");
    while(iterator != NULL) {
        name_ = iterator->name;
        rg_ = iterator->rg;
        cout << "name+:" << name_ << endl;
        cout << "rg+:" << rg_ << endl;
        if (arq.is_open(), ios::app) {
            arq << name_ <<","<< rg_ <<endl;
        }
        iterator = iterator->next;
    }
    arq.close();
}
void head_seq::find() {
    cout << "aqui: " << sequencial_f << endl;
}
void head_seq::loop() {
    int i;
    seq_list *iterator;
    iterator = sequencial_f;
     for(i = 0; i < n_seq; i++) {
        cout << "objs: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator -> next;
    }
}
void head_seq::search_node(string rg_wanted) {
    clock_t startTime = clock();    
    seq_list *iterator, *no = NULL;
    int flag = 0;
    iterator =  sequencial_f;
    while((iterator != NULL) && !flag)
    {
        if (((iterator->rg).compare(rg_wanted)) == 0) {
            /*cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            */
            iterator->return_values();
            no = iterator;
            //return no;
            flag = 1;
        }
        iterator = iterator->next;
    }
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
}
void head_seq::insert_begin_seq(string name_, string rg_, seq_list *var) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *prim;
    //seq_list *var;
    int pos = 1;
    comp_seq = 0;
    var = (seq_list*)malloc(10*sizeof(seq_list));
    prim = sequencial_f;
    if ((prim->previous) == NULL) {
        comp_seq = (comp_seq) + 1;
        prim->previous = var;
        var->next = prim;
        sequencial_f = var;
        sequencial_f->previous = NULL;
    }
    //seta_lista_seq(var);
    n_seq = (n_seq) + 1;
    var->name = name_;
    var->rg = rg_;
    moviment_seq = 5;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds; // analisar aqui
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
}
void head_seq::insert_end_seq(string name_, string rg_, seq_list *var) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *percorre;
    //seq_list *var;
    comp_seq = 0;
    var = (seq_list*)malloc(10*sizeof(seq_list));
    
    percorre = sequencial_s;
    if((percorre->next) == NULL) {
        comp_seq = (comp_seq) + 1;
        percorre->next = var;
        var->previous = percorre;
        sequencial_s = var;
    }
    //seta_lista_seq(var);
    var->name = name_;
    var->rg = rg_;
    moviment_seq = 4;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    n_seq = n_seq + 1;
    cout << "posic " << n_seq << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
    
}
void head_seq::insert_middle_seq(string name_, string rg_, int index, seq_list *var) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    int i = 2;
    seq_list *aux;
    seq_list *var_ant;
    //seq_list *var;
    comp_seq = 0;
    var = (seq_list*)malloc(10*sizeof(seq_list));
    aux = sequencial_f;
    while (i < index) {
        aux = aux->next;
        i++;
    }
    var_ant = aux->next;
    var->previous = aux;
    aux->next = var;
    var->next = var_ant;
    //seta_lista_seq(var);
    var->name = name_;
    var->rg = rg_;
    
    moviment_seq = 6;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << index << endl;
    n_seq = (n_seq) + 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
}
void head_seq::end_seq(string name, string rg, seq_list *p) {
    insert_end_seq(name, rg, p);
}
void head_seq::begin_seq(string name, string rg, seq_list *p) {
    insert_begin_seq(name, rg, p);
}
void head_seq::middle_seq(string name, string rg,int index, seq_list *p) {
    insert_middle_seq(name, rg,index, p);
}

void head_seq::menu() {
    
}
void head_seq::afiliar(systema *p) {
    afilia = p;
    p->seta_afiliacao_s(this);
}
void head_seq::partner(systema *p) {
    ptr = p;
}
void head_seq::txt(string name, seq_list *ptr_seq) {
    int flag;
    int i,j;
    //seq_list *ptr_seq;
    string dados1;
    string name_1;
    string rg_1;
    i = 0;
    ifstream txt1(name);
    if(txt1.is_open())
    {
        i++;
            while(getline(txt1, dados1))
            {
                
                flag = 0;
                j = 0;
                name_1 = "";
                rg_1 = "";
                for (j = 0; j < dados1.size(); j++) {
                    if (dados1[j] != ',' && !flag)
                    {
                        name_1 = name_1 + dados1[j];
                    }else{
                        flag = 1;
                    }
                    if (flag) {
                        rg_1 = rg_1 + dados1[j+1];
                    }
                }
                //seq_list(name_1, rg_1);
                //seq_list(name_1, rg_1);
                //ptr_seq[i].start_seq(name_1, rg_1, ptr_seq + i);
                //ptr_seq[i].name = name_1;
                //ptr_seq[i].rg = rg_1;
                //cout << "list" << ptr_seq[i].name <<endl;
                //sequence[i].name = ptr_seq[i].name;
                //ptr_seq[i].afiliate(this, name_1, rg_1);
                seta_lista_seq(ptr_seq, name_1, rg_1);
                //HEAD2.seta_lista_seq(ptr_seq);
                
        }
    }else {
        cout << "(arq.fail()) = " << txt1.fail() << endl;
    }
    txt1.close();
}
void head_seq::trig() {
}
void head_seq::set_name(string n) {
    name = n;
}
void head_seq::realloca(seq_list *ptr, int new_size) {
    seq_list *new_ptr;
    new_ptr = (seq_list*)realloc(ptr, (new_size)*sizeof(seq_list));
}
void head_seq::Selection() {
    seq_list *percorre;
    seq_list *aux;
    int menor;
    percorre = sequencial_f;
    for (int i = 0; i < n_seq; i++)
    {
        menor = i;
        for (int j = i+1; j < n_seq; j++)
        {
            if (percorre[j].rg < percorre[menor].rg);
            {
               menor = j;
            }
            swap(&percorre[menor], &percorre[i]);
        }
        
    }
}
void head_seq::Insertion(){
    seq_list *percorre;
    percorre = sequencial_f;
    int index_ant, index_curr;
    for (int i = 1; i < n_seq; i++) {
        string key = percorre[i].rg;
        int j = i - 1;
        int key_curr = i;
        index_ant = j;
        index_curr = j+1;
        while ((key < percorre[j].rg) && j >= 0) {
            index_curr = index_ant;
            swap(&percorre[index_curr], &percorre[index_ant]);
            j--;
        }
        
        swap(&percorre[j+1], &percorre[key_curr]);
        //percorre[j+1] = key;
    }
}
void head_seq::Bubble(){
    int ant, curr;
    int index;
    seq_list *percorre;
    percorre = sequencial_f;
    int index_ant, index_curr;
    for (int i = 0; i < n_seq; i++)
    {
        for (int j = 0; j < n_seq - i; j++)
        {   
            index = j;
            index_curr = j+1;
            if (percorre[index_curr].rg < percorre[index].rg) {
                index = index_curr;
                swap(&percorre[index], &percorre[index_curr]);
            }
        }
        
    }
    
}
void head_seq::Shell(){
    
}
void head_seq::Quick(seq_list *p, int low, int high){
    int index_pivot;
    high = n_seq;
    low = 0;
    p = sequencial_f;
    while (low < high){
        particiona(p, low, high, index_pivot);

        Quick(p, low, index_pivot-1);
        Quick(p, index_pivot+1, high);
    }
}
void head_seq::Merge(){
    
}
void head_seq::swap(seq_list *one, seq_list *two){
    seq_list aux;
    aux = *one;
    *one = *two;
    *two = aux;
}
void head_seq::particiona(seq_list *p, int low, int high, int pivot){
    //p = sequencial_f;
    low = 1;
    high = n_seq;
    int index_pivot = high;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (p[j].rg <= p[index_pivot].rg) {
            i++;
            
            swap(&p[j], &p[i]);
        }
    }
    swap(&p[i+1], &p[index_pivot]);
    
    pivot = i+1;
}
void head_seq::buscanode(seq_list *b) {
    afiliate1 = b;
}