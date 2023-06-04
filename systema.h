#ifndef _SYSTEMA_H_
#define _SYSTEMA_H_
#include "head.h"
#include "head_node.h"
#include "head_seq.h"
#include "node_list.h"
#include "seq_list.h"
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
class head;
class head_node;
class head_seq;
class node_list;
class seq_list;

class systema {
    public:
        head *HEAD;
        head_node *HEAD_NODE;
        head_seq *HEAD_SEQ;
        node_list *ptr_node;
        seq_list *ptr_seq;
        node_list *store_node;
        seq_list *store_seq;
        string name;
        pthread_t tid[2];
    public:
        systema(head *pt, head_node *p, head_seq *w);
        systema();
        ~systema();
        void seta_afiliacao_n(head_node *p);
        void seta_afiliacao_s(head_seq *w);
        void seta_afiliacao(head *pt);
        void menu();
        void save_node();
        void save_seq();
};
#endif