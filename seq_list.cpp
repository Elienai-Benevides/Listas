#define CLOCKS_PER_SEC 
#include "seq_list.h"
#include <iostream>
#include <string>
#include "node_list.h" 
#include "head_seq.h"
using namespace std;
seq_list::seq_list(string name_, string rg_, seq_list *p) {
    //start_seq(name_, rg_);
    //insert(p);
}
seq_list::seq_list(){
    next = NULL;
    previous = NULL;
    name = "";
    rg = "";
}

seq_list::~seq_list(){
    next = NULL;
    previous = NULL;
    name = "";
    rg = "";
}

void seq_list::start_seq(string name_, string rg_, seq_list *p) {
    p->name = name_;
    p->rg = rg_;
}
void seq_list::afiliate(head_seq *p, string name, string rg) {
    head_afiliate = p;
    head_afiliate->seta_lista_seq(this, name, rg);
}
void seq_list::tam_zero(){
    N = 0;
}
int seq_list::increase() {
    N = N+1;
    return N;
}
int seq_list::get_tam() {
    return N;
}
void seq_list::return_values() {
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
    //seq_list::~seq_list();
}
void seq_list::return_values1() {
    cout << "DELETED DATA: " << endl;
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
}
void seq_list::insert(seq_list *p) {
    p = (seq_list*)malloc(sizeof(seq_list));
}
void seq_list::teste (head *p) {
    a = p;
    a->seta_lista_seq(this);
}
seq_list* seq_list::search_node(head_seq *head, string rg_wanted){
     clock_t startTime = clock();    
    seq_list *iterator , *no = NULL;
    int flag = 0;
    iterator = head->sequencial_f;
    while((iterator != NULL) && !flag)
    {
        if (((iterator->rg).compare(rg_wanted)) == 0) {
            /*cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            */
            iterator->return_values();
            no = iterator;
            clock_t endTime = clock();
            clock_t clockTicksTaken = endTime - startTime;
            double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
            head->time_ex_seq = timeInSeconds;
            cout << "time de execucao lista sequencial " << head->time_ex_seq << endl;
            return no;
            flag = 1;
        }
        iterator = iterator->next;
    }
    return 0;
}