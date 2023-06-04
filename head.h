#ifndef _HEAD_H_
#define _HEAD_H_
#include <string>
#include <cstddef>
#include "systema.h"
#include "head_node.h"
#include "head_seq.h"
#include <vector> 
using namespace std;
class node_list;
class seq_list;
class systema;
class head_node;
class head_seq;
class head
{
  public:
  head_node *pnode;
  head_seq  *pseq;
  vector <node_list*> HEAD_NODE;
  vector <seq_list*> HEAD_SEQ;
  
  
  
  node_list *afilia;
  node_list *afiliate;

  seq_list *afiliate1;
  node_list *previous;
  node_list *first = NULL;
  node_list *second = NULL;
  
  seq_list *sequencial_f = NULL;
  seq_list *sequencial_s = NULL;
  
  int n_seq = 0;
  int n_node = 0;
  
  int comp = 0;
  int moviment = 0;
  double time_ex = 0.0;
  
  int comp_seq;
  int moviment_seq;
  double time_ex_seq = 0.0;
  
  public:
  head();
  ~head();
  
  
  void seta_lista_up(node_list *p, string name, string rg);
 
  void remov_node_begin();
  void remov_node_middle(int index);
  void remov_node_end();
  void listar_nodes_up();
  void listar_nodes_down();
  void search_node(string rg_wanted);
  
  void txt (node_list *p, seq_list *a);
  
  void seta_lista_seq(seq_list *p);
  
  void remov_seq_begin();
  void remov_seq_middle(int index);
  void remov_seq_end();
  void listar_seq_list();
  
  void insert_end_node(string name_, string rg_, node_list *node1);
  void insert_begin_node(string name_, string rg_, node_list *node2);
  void insert_middle_node(string name_, string rg_,int index, node_list *node3);
  
  
  void insert_end_seq(string name_, string rg_, seq_list *var);
  void insert_begin_seq(string name_, string rg_, seq_list *var);
  void insert_middle_seq(string name_, string rg_, int index, seq_list *var);
  
  
  void end_node(string name, string rg, node_list *p);
  void begin_node(string name, string rg, node_list *p);
  void middle_node(string name, string rg,int index, node_list *p);
  
  void end_seq(string name, string rg, seq_list *p);
  void begin_seq(string name, string rg, seq_list *p);
  void middle_seq(string name, string rg,int index, seq_list *p);
  
  void menu();
  
  void afiliar(node_list *ptr_node, string name, string rg);
  void loop();
  void find();
  void deleted();

 };
#endif