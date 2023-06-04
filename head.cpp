#define CLOCKS_PER_SEC 
#include "head.h"
#include "node_list.h"
#include "seq_list.h"
#include "head_node.h"
#include "head_seq.h"
#include "systema.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <time.h>
using namespace std;
head::head(){
    //head_node();
    //head_seq();
     sequencial_f = NULL;
     sequencial_s = NULL;
     first = NULL;
     second = NULL;
     afiliate = NULL;
}
 
head::~head(){
     sequencial_f = NULL;
     sequencial_s = NULL;
     first = NULL;
     second = NULL;
     afiliate = NULL;
}
 
void head::seta_lista_up(node_list *p, string name, string rg) {
     if (first == NULL)
     {  
         first = p;
         second = p;
         first->p_previous = NULL;
         second->p_previous = NULL;
     }else{
         //node_list *aux;
         //aux = second;
         second->p_next = p;
         p->p_previous = second;
         second = p;
         second->p_next = NULL;
         second->p_previous = NULL;
         //second->p_previous = aux;
         moviment = moviment + 3;
     }
      n_node = n_node + 1;
}
void head::seta_lista_seq(seq_list *p) {
    if (sequencial_f == NULL) {
        sequencial_f = p;
        sequencial_s = p;
        sequencial_f->previous = NULL;
        sequencial_s->previous = NULL;
    }
    else {
        sequencial_s->next = p;
        sequencial_s = p;
    }
    n_seq = n_seq + 1;
    
}
void head::remov_node_begin() {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    comp = 0;
    int pos = 1;
    aux = first;
    aux->return_values();
    var_ant = aux->p_next;
    var_ant->p_previous = NULL;
    first->p_previous = NULL;
    first = var_ant;
    n_node = n_node - 1;
    moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
}
void head::remov_node_middle(int index) {
    time_ex = 0.0;
    clock_t startTime = clock();
    int i = 2;
    node_list *aux;
    node_list *var_ant, *var_curr;
    comp = 0;
    aux = first;
    while (i < index) {
        aux = aux->p_next;
        i++;
    }
    var_ant = aux->p_next;
    var_ant->p_previous = NULL;
    var_ant->return_values();
    var_curr = var_ant->p_next;
    var_curr->p_previous = aux;
    aux->p_next = var_curr; 
    n_node = n_node - 1;
    moviment = 7;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << index << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
}
void head::remov_node_end(){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    comp = 0;
    aux = second;
    aux->return_values();
    var_ant = aux->p_previous;
    var_ant->p_next = NULL;
    second->p_next = NULL;
    second = var_ant;
    moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    n_node = n_node -1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
}
void head::listar_nodes_up(){
    node_list *percorre;
    percorre = first;
    while(percorre != NULL)
    {
        cout << "name: " << percorre->name << endl;
        cout << "rg: " << percorre->rg << endl;
        percorre = percorre->p_next;
    }
}
void head::remov_seq_begin() {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    comp_seq = 0;
    int pos = 1;
    aux = sequencial_f;
    aux->return_values();
    var_ant = aux->next;
    var_ant->previous = NULL;
    sequencial_f->previous = NULL;
    sequencial_f = var_ant;
    
    moviment_seq = 5;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << pos << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
}
void head::remov_seq_middle(int index) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    int i = (2 - n_seq) * -1;
    seq_list *var_curr, *aux, *var_ant;
    comp_seq = 0;
    aux = sequencial_f;
    while (i < index) {
        aux = aux->next;
        i++;
    }
    var_ant = aux->next;
    var_ant->previous = NULL;
    var_ant->return_values();
    var_curr = var_ant->next;
    var_curr->previous = aux;
    aux->next = var_curr;
    moviment_seq = 7;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << index << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
}
void head::remov_seq_end() {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    int pos = 0;
    aux = sequencial_s;
    aux->return_values();
    var_ant = aux->previous;
    var_ant->next = NULL;
    sequencial_s->next = NULL;
    sequencial_s = aux;
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

void head::listar_nodes_down() {
    node_list *iterator;
    iterator = second;
    while(iterator!= NULL)
    {
        cout << "name: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator->p_previous;
    }
}
void head::listar_seq_list() {
    int i = 0;
    seq_list *iterator;
    iterator = sequencial_f;
    while(iterator != NULL) {
        cout << "name+: " << iterator->name << endl;
        cout << "rg+: " << iterator->rg << endl;
        iterator = iterator->next;
    }
}
void head::find() {
    cout << "aqui: " << sequencial_f << endl;
}
void head::loop() {
    int i;
    seq_list *iterator;
    iterator = sequencial_f;
     for(i = 0; i < n_seq; i++) {
        cout << "objs: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator -> next;
    }
}
void head::search_node(string rg_wanted) {
    clock_t startTime = clock();    
    node_list *percorre;
    seq_list *iterator;
    int flag = 0;
    percorre = first;
    iterator = sequencial_f;
    while((iterator != NULL) && !flag)
    {
        if ((rg_wanted.compare(iterator->rg)) == 0) {
            cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            flag = 1;
        }
        iterator = iterator->next;
    }
    
    while((percorre != NULL) && !flag)
    {
        if ((rg_wanted.compare(percorre->rg)) == 0) {
            cout << "Nome do Rg encontrado: " << percorre->name << endl;
            cout << "Rg encontrado: " << percorre->rg << endl;
            flag = 1;
        }
        percorre = percorre->p_next;
    }
    
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex_seq = timeInSeconds;
    time_ex = timeInSeconds;
    
    cout << "time de execucao node_list" << time_ex << endl;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
}
void head::txt (node_list *p, seq_list *a) {
    string name_;
    string rg_;
    //*******ptr_seq and ptr_node ****//
    node_list *iterator;
    seq_list *percorre;
    node_list *ptr_node;
    seq_list *ptr_seq;
    iterator = pnode->first;
    percorre = pseq->sequencial_f;
    while (iterator != NULL) {
        //ptr_node = (node_list*)malloc(sizeof(node_list));
        //ptr_node->set_afiliate(this, iterator->name, iterator->rg);
        HEAD_NODE.push_back(iterator);
        iterator = iterator->p_next;
    }
    /*while (percorre != NULL) {
        ptr_seq = (seq_list*)malloc(sizeof(seq_list));
        ptr_seq->set_afiliate(this, percorre->name, percorre->rg);
        percorre = percorre->next;
    }*/
}

void head::insert_end_node(string name_, string rg_, node_list *node1){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    //node_list *node1;
    node1 = (node_list*)malloc(sizeof(node_list));
    percorre = second;
    if((percorre->p_next) == NULL){
        comp = (comp) + 1;
        percorre->p_next = node1;
        node1->p_previous = percorre;
        second = node1;
    }
    
    node1->name = name_;
    node1->rg = rg_;
    moviment = 5;
    n_node = (n_node) + 1;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
    
}
void head::insert_begin_node(string name_, string rg_, node_list *node2) {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *prim;
    //node_list *node2;
    int pos = 1;
    comp = 0;
    node2 = (node_list*)malloc(10*sizeof(node_list));
    prim = first;
    if ((prim->p_previous) == NULL) {
        comp = (comp) + 1;
        prim->p_previous = node2;
        node2->p_next = prim;
        second = node2;
    }
    n_node = (n_node) + 1;
    node2->name = name_;
    node2->rg = rg_;
    moviment = 5;
    //head_afiliate->seta_lista_up(node2);
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
}
void head::insert_middle_node(string name_, string rg_, int index, node_list *node3) {
    time_ex = 0.0;
    clock_t startTime = clock();
    int i = (2 + (n_node));
    comp = 0;
    node_list *aux;
    //node_list *node3;
    node_list *var_ant;
    node3 = (node_list*)malloc(sizeof(node_list));
    aux = first;
    while (i < index) {
        aux = aux->p_next;
        i++;
    }
    var_ant = aux->p_next;
    node3->p_previous = aux;
    aux->p_next = node3;
    node3->p_next = var_ant;
    aux = node3;
    //seta_lista_up(node3);
    
    node3->name = name_;
    node3->rg = rg_;
    n_node = (n_node) + 1;
    moviment = 7;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << index << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
    
}

void head::insert_begin_seq(string name_, string rg_, seq_list *var) {
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
    }
    //seta_lista_seq(var);
    var->name = name_;
    var->rg = rg_;
    moviment_seq = 5;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << pos << endl;
    n_seq = (n_seq) + 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds; // analisar aqui
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
    
}
void head::insert_end_seq(string name_, string rg_, seq_list *var) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *percorre;
    //seq_list *var;
    comp_seq = 0;
    var = (seq_list*)malloc(sizeof(seq_list));
    
    percorre = sequencial_s;
    if((percorre->next) == NULL) {
        comp_seq = (comp_seq) + 1;
        percorre->next = var;
        var->previous = percorre;
    }
    //seta_lista_seq(var);
    var->name = name_;
    var->rg = rg_;
    moviment_seq = 4;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    n_seq = (n_seq) + 1;
    cout << "posic" << n_seq << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
    
}
void head::insert_middle_seq(string name_, string rg_, int index, seq_list *var) {
    time_ex_seq = 0.0;
    clock_t startTime = clock();
    int i = (2 - (n_seq)) * (-1);
    seq_list *aux;
    seq_list *var_ant;
    //seq_list *var;
    comp_seq = 0;
    var = (seq_list*)malloc(sizeof(seq_list));
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
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << index << endl;
    n_seq = (n_seq) + 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex << endl;
}

void head::end_node(string name, string rg, node_list *p) {
    insert_end_node(name,rg, p);
    free(p);
}
void head::begin_node(string name, string rg, node_list *p) {
    insert_begin_node(name, rg, p);
    //afiliate = p;
    //afiliate->set_afiliate(this);
    free(p);
}
void head::middle_node(string name, string rg,int index, node_list *p) {
    insert_middle_node(name, rg,index, p);
    free(p);
}
  
void head::end_seq(string name, string rg, seq_list *p) {
    insert_end_seq(name, rg, p);
    free(p);
}
void head::begin_seq(string name, string rg, seq_list *p) {
    insert_begin_seq(name, rg, p);
    
    free(p);
}
void head::middle_seq(string name, string rg,int index, seq_list *p) {
    insert_middle_seq(name, rg,index, p);
    free(p);
}

void head::menu() {
    
}

void head::afiliar(node_list *p, string name, string rg) {
    afilia = p;
    afilia->set_afiliate(this, name, rg);
}
