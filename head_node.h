#ifndef _HEAD_NODE_H_
#define _HEAD_NODE_H_
#include <string>
#include <cstddef>
#include "systema.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "head.h"
#include "node_list.h"
#include "seq_list.h"
#include <vector>
using namespace std;
class node_list;
class seq_list;
class systema;
class head_node
{
  public:
  head *phead;
  
  systema *afilia;
  systema *ptr;
  //node_list *afiliate;
  node_list *previous;
  node_list *cont;
  node_list *first = nullptr;
  node_list *second = nullptr;
  string name;
  node_list *vector;
  
  int n_node = 0;
  int comp = 0;
  int moviment = 0;
  
  double time_ex = 0.0;
  public:
  head_node();
  ~head_node();
  
  void set_name(string n);
  
  void seta_lista_up(node_list *p, string name, string rg);
 
  void remov_node_begin();
  void remov_node_middle(int index);
  void remov_node_end();
  void listar_nodes_up();
  void listar_nodes_down();
  
  void search_node(string rg_wanted);
  
  void txt(string name, node_list *ptr_node);
  
  void insert_end_node(string name_, string rg_, node_list *node1);
  void insert_begin_node(string name_, string rg_, node_list *node2);
  void insert_middle_node(string name_, string rg_,int index, node_list *node3);
  
  void end_node(string name, string rg, node_list *p);
  void begin_node(string name, string rg, node_list *p);
  void middle_node(string name, string rg,int index, node_list *p);
  void Selection();
  void Insertion();
  void Bubble(node_list *p);
  void Shell();
  void Quick(node_list *p, int low, int high);
  void Merge();
  void swap(node_list *one, node_list *two);
  void particiona(node_list *p, int low, int high, int pivot);

  
  void menu();
  void insert(int size, string name_, string rg_, node_list *p);
  void afiliar(head *p, string name, string rg, node_list *pp);
  void partner(systema *p);
  void loop();
  void find();
  void deleted();
  void trig();
  void listar();
 };
#endif