#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#include "head_seq.h"
#include "head.h"
#include "systema.h"
#include <string>
using namespace std;
class head;
class head_seq;
class systema;
class seq_list {
    public:
    string name;
    string rg;
    head *a;
    head_seq *head_afiliate;
    int N;
    
    int n_seq = 0;
  
    int comp_seq = 0;
    int moviment_seq = 0;
    public:
    seq_list *next = NULL;
    seq_list *previous = NULL;
    seq_list(string name_, string rg_, seq_list *p);
    seq_list();
    ~seq_list();
    void start_seq(string name_, string rg_, seq_list *p);
    void afiliate(head_seq *p, string name, string rg);
    int increase();
    void tam_zero();
    int get_tam();
    void return_values();
    
    void insert(seq_list *p);
    void teste(head *p);
    string *getname();
    string *getrg();
    void return_values1();
    
    seq_list* search_node(head_seq *head, string rg_wanted);
};
#endif