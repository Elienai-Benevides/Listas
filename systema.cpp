#include "systema.h"
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
systema::systema(head *pt, head_node *p, head_seq *w) {
    head_node();
    head_seq();
    HEAD = pt;
    HEAD_NODE = p;
    HEAD_SEQ = w;
}
systema::systema() {
    HEAD = NULL;
    HEAD_NODE = NULL;
    HEAD_SEQ = NULL;  
}
systema::~systema() {
    HEAD = NULL;
    HEAD_NODE = NULL;
    HEAD_SEQ = NULL;
}
void systema::seta_afiliacao_n(head_node *p) {
    HEAD_NODE = p;
}
void systema::seta_afiliacao_s(head_seq *w) {
    HEAD_SEQ = w;
}
void systema::seta_afiliacao(head *pt) {
    HEAD = pt;
}
void systema::save_node() {
    store_node = HEAD_NODE->first;
}
void systema::save_seq() {
    store_seq = HEAD_SEQ->sequencial_f;
}
void systema::menu() {
}