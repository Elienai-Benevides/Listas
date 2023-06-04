#define CLOCKS_PER_SEC 
#include <iostream>
#include <fstream>
#include <string>
#include "node_list.h"
#include "head_node.h"
using namespace std;

node_list::node_list(string namecur, string rgcur, node_list *p){
   // start(namecur, rgcur);
    //insert(p);
}

node_list::node_list() {
    p_next = nullptr;
    p_previous = nullptr;
    name = "";
    rg = "";
}

node_list::~node_list() {
    p_next = nullptr;
    p_previous = nullptr;
    name = "";
    rg = "";
}

void node_list::start(string namecur,string rgcur) {
    name = namecur;
    rg = rgcur;
}

void node_list::set_afiliate(head *pointer, string name, string rg) {
    head_afiliate = pointer;
    head_afiliate->seta_lista_up(this, name, rg);
}
void node_list::listar() {
    cout << "name: " << name << endl;
    cout << "rg: " << rg << endl;
}
int node_list::acres() {
    n = n+1;
    return n;
}
void node_list::return_values() {
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
    //node_list::~node_list();
}
void node_list::return_values1() {
    cout << "DELETED DATA: " << endl;
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
}
void node_list::insert(node_list *p) {
    p = (node_list*)malloc(sizeof(node_list));
}
void node_list::teste(head *p, string name, string rg) {
    a = p;
    a->seta_lista_up(this, name, rg);
}
int node_list::count() {
    return (n_node++);
}
void node_list::setaname(string nome) {
    name = nome;
}
node_list* node_list::search_node(head_node *head, string rg_wanted) {
    clock_t startTime = clock();    
    node_list *percorre, *no = NULL;
    int flag = 0;
    //trig();
    percorre = head->first;
    while((percorre != NULL) && !flag)
    {
        if (((percorre->rg).compare(rg_wanted)) == 0) {
            cout << "Nome do Rg encontrado: " << percorre->name << endl;
            cout << "Rg encontrado: " << percorre->rg << endl;
            
            percorre->return_values();
            no = percorre;
            clock_t endTime = clock();
            clock_t clockTicksTaken = endTime - startTime;
            double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
            head->time_ex = timeInSeconds;
            
            cout << "time de execucao node_list" << head->time_ex << endl;
            return no;
            flag = 1;
        }
        percorre = percorre->p_next;
    }
    
    return 0;
}
void node_list::setar_address(head_node *p, string name, string rg) {
    afiliate = p;
    afiliate->seta_lista_up(this,name,rg);
}