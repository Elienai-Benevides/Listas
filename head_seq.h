#ifndef _HEAD_SEQ_H_
#define _HEAD_SEQ_H_
#include <string>
#include <cstddef>
#include "systema.h"
using namespace std;
class node_list;
class seq_list;
class systema;
class head_seq
{
  public:
  systema *afilia;
  systema *ptr;
  
  seq_list *afiliate1;
  string name;
  seq_list *sequencial_f = nullptr;
  seq_list *sequencial_s = nullptr;
  
  int n_seq = 0;
  
  int comp_seq = 0;
  int moviment_seq = 0;
  double time_ex_seq = 0.0;
  
  public:
  head_seq();
  ~head_seq();
  
  
  void txt(string name, seq_list *ptr_seq);
  
  void seta_lista_seq(seq_list *p, string name, string rg);
  void buscanode(seq_list *b);
  
  void remov_seq_begin();
  void remov_seq_middle(int index);
  void remov_seq_end();
  void listar_seq_list();
  
  
  void insert_end_seq(string name_, string rg_, seq_list *var);
  void insert_begin_seq(string name_, string rg_, seq_list *var);
  void insert_middle_seq(string name_, string rg_, int index, seq_list *var);
  
  void end_seq(string name, string rg, seq_list *p);
  void begin_seq(string name, string rg, seq_list *p);
  void middle_seq(string name, string rg,int index, seq_list *p);
  
  void Selection();
  void Insertion();
  void Bubble();
  void Shell();
  void Quick(seq_list *p, int low, int high);
  void Merge();
  void swap(seq_list *one, seq_list *two);
  void particiona(seq_list *p, int low, int high, int pivot);
  
  void search_node(string rg_wanted);
  void menu();
  void set_name(string n);
  void afiliar(systema *p);
  void partner(systema *p);
  void loop();
  void find();
  void deleted();
  void realloca(seq_list *ptr, int new_size);
  void trig();
 };
#endif