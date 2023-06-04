#ifndef _NODE_LIST_H_
#define _NODE_LIST_H_
#include "head_node.h"
#include "head.h"
#include "systema.h"
#include <string>
using namespace std;
class head_node;
class head;
class systema;
 //________________________________//
 //___________node_list_________________//
class node_list
{
  public:
  string name;
  string rg;
  head *a;
  head *head_afiliate = nullptr;
  head_node *afiliate;
  node_list *p = nullptr;
  int n;
  
  int conta;
  int n_node = 0;
  int comp = 0;
  int moviment = 0;
  
  public:
  node_list *p_next;
  node_list *p_previous;
  node_list(string namecur, string rgcur, node_list *p);
  node_list();
  ~node_list();
  void start(string namecur, string rgcur);
  string *getname();
  string *getrg();
  void return_values();
  int acres();
  
  void insert(node_list *p);
  void teste (head *p, string name, string rg);
  void set_afiliate(head *pointer, string name, string rg);
  void listar();
  void return_values1();
  void setaname(string nome);
  node_list* search_node(head_node *head, string rg_wanted);
  void partner(node_list *p);
  int count();
  void setar_address(head_node *p, string name, string rg);
};
#endif