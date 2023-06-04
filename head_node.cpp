#define CLOCKS_PER_SEC 
#include "head_node.h"

#include "systema.h"

#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
head_node::head_node(){
     first = NULL;
     second = NULL;
     afilia = NULL;
}
 
head_node::~head_node(){
     first = NULL;
     second = NULL;
     afilia = NULL;
}
 
void head_node::seta_lista_up(node_list *p, string name, string rg) {
     p = (node_list*)malloc(sizeof(node_list));
     //p->setar_address(this, name, rg);
     if (first == NULL)
     {  
         first = p;
         second = p;
         first->p_previous = NULL;
         second->p_previous = NULL;
         first->start(name, rg);
         second->start(name, rg);
         //first->name = name;
         //first->rg = rg;
         //second->name = name;
         //second->rg = rg;
     }else {
         //node_list *aux;
         //aux = second;
         second->p_next = p;
         p->p_previous = second;
         second = p;
         second->start(name, rg);
         //second->rg = rg;
         second->p_next = NULL;
         second->p_previous = NULL;
         //second->p_previous = aux;
         moviment = moviment + 3;
     }
      n_node = n_node + 1;
}
void head_node::remov_node_begin() {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    comp = 0;
    int pos = 1;
    aux = first;
    
    aux->return_values1();
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
void head_node::remov_node_middle(int index) {
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
    var_ant->return_values();
    var_curr = var_ant;
    var_ant = var_ant->p_next;
    aux->p_next = var_ant;
    var_curr = var_ant;
    
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
void head_node::remov_node_end(){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    node_list *ult;
    node_list *var_curr;
    comp = 0;
    aux = second;
    
    if(aux != NULL) {
        aux->return_values();
        var_ant = aux->p_previous;
        //var_ant->p_next = NULL;
        second->p_next = NULL;
        second = var_ant; 
    }
    
    moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    n_node = n_node - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    cout << "time de execucao" << time_ex << endl;
}
void head_node::listar_nodes_up(){
    node_list *iterator;
    string name_;
    string rg_;
    iterator = first;
    ofstream arq1("arq1.txt");
    while(iterator != NULL) {
        name_ = iterator->name;
        rg_ = iterator->rg;
        cout << "name: " << name_ << endl;
        cout << "rg: " << rg_ << endl;
        if (arq1.is_open(), ios::app) {
            arq1 << name_ << "," << rg_ << endl;
        }
        iterator = iterator->p_next;
    }
    arq1.close();
}
void head_node::listar_nodes_down() {
    node_list *iterator;
    iterator = first;
    while(iterator!= NULL)
    {
        cout << "name: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator->p_next;
    }
}
void head_node::find() {
    cout << "aqui: " << first << endl;
}
void head_node::loop() {
    int i;
    node_list *iterator;
    iterator = first;
     for(i = 0; i < n_node; i++) {
        cout << "objs: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator -> p_next;
    }
}
void head_node::search_node(string rg_wanted) {
    clock_t startTime = clock();    
    node_list *percorre, *no = NULL;
    int flag = 0;
    //phead->txt();
    percorre = first;
    while((percorre != NULL) && !flag)
    {
        if (rg_wanted == percorre->rg) {
            /*cout << "Nome do Rg encontrado: " << percorre->name << endl;
            cout << "Rg encontrado: " << percorre->rg << endl;*/

            percorre->return_values();
            no = percorre;
            //return no;
            flag = 1;
        }
        percorre = percorre->p_next;
    }
    
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex = timeInSeconds;
    
    cout << "time de execucao node_list" << time_ex << endl;
}
void head_node::insert_end_node(string name_, string rg_, node_list *node1){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    //node_list *node1;
    node1 = (node_list*)malloc(10*sizeof(node_list));
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
void head_node::insert_begin_node(string name_, string rg_, node_list *node2) {
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
        node2->p_next = first;
        first = node2;
        first->p_previous = NULL;
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
void head_node::insert_middle_node(string name_, string rg_, int index, node_list *node3) {
    time_ex = 0.0;
    clock_t startTime = clock();
    int i = 2;
    comp = 0;
    node_list *aux;
    //node_list *node3;
    node_list *var_ant;
    node3 = (node_list*)malloc(10*sizeof(node_list));
    node3->setar_address(this, name_, rg_);
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
void head_node::end_node(string name, string rg, node_list *p) {
    insert_end_node(name,rg, p);

}
void head_node::begin_node(string name, string rg, node_list *p) {
    insert_begin_node(name, rg, p);
    //afiliate = p;
    //afiliate->set_afiliate(this);
}
void head_node::middle_node(string name, string rg,int index, node_list *p) {
    insert_middle_node(name, rg,index, p);
}
void head_node::menu() {
    
}
void head_node::afiliar(head *p, string name, string rg, node_list *pp) {
    phead = p;
    phead->afiliar(pp, name, rg);
}
void head_node::partner(systema *p) {
    ptr = p;
}
void head_node::txt(string name, node_list *ptr_node) {
    string name_;
    string rg_;
    int flag;
    int i,j;
    string dados;
    //node_list *ptr_node;
    ifstream txt(name);
    if(txt.is_open())
    {
        while(getline(txt, dados))
        {
            flag = 0;
            j = 0;
            name_ = "";
            rg_ = "";
            for (j = 0; j < dados.size(); j++) {
                if (dados[j] != ',' && !flag)
                {
                    name_ = name_ + dados[j];
                }else{
                    flag = 1;
                }
                if (flag) {
                    rg_ = rg_ + dados[j+1];
                }
            }
            
            //node_list(name_, rg_, ptr_node);
            //insert(dados.size(), name_, rg_, ptr_node);
            //ptr_node->insert(ptr_node);
            seta_lista_up(ptr_node, name_, rg_);
            //HEAD1.seta_lista_up(ptr_node);
        }
    }else{
        cout << "(arq.fail()) = " << txt.fail() << endl;
    }
    //seta_lista_up(ptr_node);
    txt.close();
}
void head_node::trig(){
    string name_;
    string rg_;
    int flag;
    int i,j;
    string dados;
    node_list *p;
    //first = NULL;
    //second = NULL;
   //head_node::~head_node();
    ifstream txt_("arq1.txt");
    if(txt_.is_open())
    {
        while(getline(txt_, dados))
        {
            flag = 0;
            j = 0;
            name_ = " ";
            rg_ = " ";
            for (j = 0; j < dados.size(); j++) {
                if (dados[j] != ',' && !flag)
                {
                    name_ = name_ + dados[j];
                }else{
                    flag = 1;
                }
                if (flag) {
                    rg_ = rg_ + dados[j+1];
                }
            }
            
            //node_list(name_, rg_, ptr_node);
            //insert(dados.size(), name_, rg_, ptr_node);
            //ptr_node->insert(ptr_node);
     p = (node_list*)malloc(20*sizeof(node_list));
     if (first == NULL)
     {  
         first = p;
         second = p;
         first->p_previous = NULL;
         second->p_previous = NULL;
         first->name = name_;
         first->rg = rg_;
         second->name = name_;
         second->rg = rg_;
     }else {
         //node_list *aux;
         //aux = second;
         second->p_next = p;
         p->p_previous = second;
         second = p;
         second->name = name_;
         second->rg = rg_;
         second->p_next = NULL;
         second->p_previous = NULL;
         //second->p_previous = aux;
         moviment = moviment + 3;
     }
      n_node = n_node + 1;
            //HEAD1.seta_lista_up(ptr_node);
        }
    }else{
        cout << "(arq.fail()) = " << txt_.fail() << endl;
    }
    txt_.close();
    
}
void head_node::set_name(string n) {
    name = n;
}
void head_node::insert(int size, string name_, string rg_, node_list *ptr) {
    ptr = (node_list*)malloc(size * sizeof(node_list));
    ptr->name =  name_;
    ptr->rg = rg_;
}
void head_node::Selection() {
    node_list *percorre;
    node_list *aux;
    int menor;
    percorre = first;
    for (int i = 0; i < n_node; i++)
    {
        menor = i;
        for (int j = i+1; j < n_node; j++)
        {
            if (percorre[j].rg < percorre[menor].rg);
            {
               menor = j;
            }
            swap(&percorre[menor], &percorre[i]);
        }
        
    }
}
void head_node::Insertion(){
    node_list *percorre;
    percorre = first;
    int index_ant, index_curr;
    for (int i = 1; i < n_node; i++) {
        //string key = percorre[i].rg;
        int j = i - 1;
        int key_curr = i;
        index_ant = j;
        index_curr = j+1;
        while ((percorre[key_curr].rg < percorre[j].rg) && j >= 0) {
            index_curr = index_ant;
            swap(&percorre[index_curr], &percorre[index_ant]);
            j--;
        }
        
        swap(&percorre[j+1], &percorre[key_curr]);
        //percorre[j+1] = key;
    }
}
void head_node::Bubble(node_list *p){
    int ant, curr;
    int index;
    node_list *percorre;
    percorre = p;
    int index_ant, index_curr;
    for (int i = 0; percorre != NULL; i++)
    {
        for (int j = 0; j < n_node - i; j++)
        {   
            index = j;
            index_curr = j+1;
            if (percorre[index_curr].rg < percorre[index].rg) {
                index = index_curr;
                node_list aux;
                
                aux.rg = percorre[index].rg;
                percorre[index].rg= percorre[index_curr].rg;
                percorre[index_curr].rg= aux.rg;
                
                //swap(&percorre[index], &percorre[index_curr]);
            }
            percorre = percorre->p_next;
        }
     percorre = percorre->p_next;
    }
}
void head_node::Shell(){
    
}
void head_node::Quick(node_list *p, int low, int high){
    int index_pivot;
    high = n_node;
    low = 0;
    p = first;
    while (low < high){
        particiona(p, low, high, index_pivot);

        Quick(p, low, index_pivot-1);
        Quick(p, index_pivot+1, high);
    }
}
void head_node::Merge(){
    
}
void head_node::swap(node_list *one, node_list *two){
    node_list aux;
    aux.rg = one->rg;
    one->rg = two->rg;
    two->rg = aux.rg;
}
void head_node::particiona(node_list *p, int low, int high, int pivot){
    //p = sequencial_f;
    low = 1;
    high = n_node;
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
void head_node::listar() {
    node_list *iterator;
    node_list *p;
    iterator = first;
    while(iterator != NULL) {
        cout << "name:" << iterator->name << endl;
        cout << "rg:" << iterator->rg << endl;
        //afiliar(phead, iterator->name, iterator->rg, iterator);
       // phead->HEAD_NODE.push_back(iterator);
        iterator = iterator->p_next;
    }
    //iterator->p_next = NULL;
}