// TRABALHO 1 - LISTAS SEQUENCIAIS E LISTAS LIGADAS//
// Aluno: Elienai Benevides da Cruz. RA: 2413914 
// 03/04/2023 Turma s73
// Turma s73 Estruturas de dados1 //
#include "node_list.h"
#include "head.h"
#include "seq_list.h"
#include "head_node.h"
#include "head_seq.h"
#include "systema.h"
#include <iostream>
#include <fstream>
#define  vfork fork
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
void search_node_main(string rg_wanted, head_seq *p);
void search_node_main_1(string rg_wanted, head_node *p);
void reading(string name);
void procura(head_node *head, string rg_wanted);
pthread_t tid[2];
int main()
{
    node_list node, *ptr_node;
    seq_list *ptr_seq;
    head_node HEAD_NODE;
    head_seq HEAD_SEQ;
    head_node *HEAD_RAND = &HEAD_NODE;
    systema sistema;
    string name = "NomeRG50.txt";
    //HEAD1.set_name(name);
    //sistema.seta_afiliacao_n(&HEAD1);
    //sistema.seta_afiliacao_s(&HEAD2);
    int options;
        string name_;
        string rg_;
        int index;
        node_list *p;
        seq_list *a;
        string rg_wanted;
        HEAD_NODE.txt(name,p);
        HEAD_SEQ.txt(name, a);
        head HEAD;
        //HEAD_NODE.txt(name,p);
       // read(&HEAD_NODE);
        int flag = 0;
        cout << "ENTRE COM A OPCAO"  << endl;
        cout << "********************************************************"  << endl;
        cout << "1)Inserção de um nó no início da lista                 *"  << endl;
        cout << "2)Inserção de um nó no fim da lista                    *"  << endl;
        cout << "3)Inserção de um nó na posição N                       *"  << endl;
        cout << "4)Retirar um nó do início da lista                     *"  << endl;
        cout << "5)Retirar um nó no fim da lista                        *"  << endl;
        cout << "6)Retirar um nó na posição N                           *"  << endl;
        cout << "7)Procurar um nó com o campo RG                        *"  << endl;
        cout << "8)ordenacao por selection sort                         *"  << endl;    
        cout << "9)ordenacao por insertion sort                         *"  << endl;
        cout << "10)ordenacao por bubble sort                           *"  << endl;   
        cout << "11)ordenacao por shell sort                            *"  << endl;    
        cout << "12)ordenacao por quick sort                            *"  << endl;    
        cout << "13)ordenacao por merge sort                            *"  << endl;    
        cout << "14)Mostrar a lista na tela.                            *"  << endl;     
        cout << "15)Salvar a lista em um arquivo.                       *"  << endl; // 
        cout << "16)Ler a lista de um arquivo, colocar na lista         *"  << endl; //
        cout << "17)Sair do sistema.                                    *"  << endl;
        cout << "********************************************************"  << endl;
        options = 0;
        int i = 0;  
        
        while ((options) != -1) {
            
            cin >> options;
            switch(options)
            {   
                case 0:
                   
                break;
                case 1:
                 cout << "Entre com nome e rg" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.insert_begin_node(name_,rg_,p);
                 cout << " sequencial :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.begin_seq(name_, rg_, a);
                break;
                case 2:
                 cout << "Entre com nome e rg" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.end_node(name_ , rg_, p);
                 //ptr_node->set_afiliate(&HEAD1);
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.end_seq(name_ , rg_, a);
                 //ptr_seq->afiliate(&HEAD1);
                break;
                case 3:
                 cout << "Entre com nome e rg e indice" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cin >> index;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.middle_node(name_ , rg_,index, p);
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.middle_seq(name_ , rg_, index, a);
                break;
                case 4:
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_begin();
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.remov_seq_begin();
                break;
                case 5:
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_end();
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.remov_seq_end();
                break;
                case 6:
                 cout << "Entre com o indice da remocao" << endl;
                 cin >> index;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_middle(index);
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.remov_seq_middle(index);
                break;
                case 7:
                 cout << "Entre com o rg desejado" << endl;
                 cin >> rg_wanted;
                 cout << "--------------" << endl;
                 HEAD_NODE.search_node(rg_wanted);
                 HEAD_SEQ.search_node(rg_wanted);
                    //cout << "retorno NODE" << ptr_node->rg << endl;
                // HEAD_SEQ.search_node(a, rg_wanted);
                  //cout << "retorno seq" << ptr_seq->rg << endl;
                 //search_node_main_1(rg_wanted, &HEAD_NODE);
                //search_node_main(rg_wanted, &HEAD_SEQ);
                 cout << "--------------" << endl;
                 //a->search_node(rg_wanted, &HEAD_SEQ);
                 
                break;
                case 8:
                 
                break;
                case 9:
                 HEAD_NODE.Insertion();    
                break;
                case 10:
                 HEAD_NODE.Bubble(p);
                break;
                case 11:
                 HEAD_NODE.listar_nodes_down();
                break;
                case 12:
                    
                break;
                case 13:
                
                break;
                case 14:
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 //HEAD1.listar_seq_list(ptr_seq);
                 HEAD_NODE.listar();
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.listar_seq_list();
                break;
                case 15:
                 HEAD_NODE.listar_nodes_up();
                 //code here
                break;
                case 16:
                 //code here
                // HEAD.txt();
                break;
                case 17:
                 options = -1;
                break;
                default:
                if(options != -1) {
                    cout << "opcao invalida" << endl;
                }
            }
        }
    return 0;
}
void search_node_main(string rg_wanted, head_seq *p) {
    seq_list *iterator;
    int flag = 0;
    iterator = p->sequencial_f;
    while((iterator != NULL) && !flag)
    {
        if (((iterator->rg).compare(rg_wanted)) == 0) {
            cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            flag = 1;
        }
        iterator = iterator->next;
    }

}
void search_node_main_1(string rg_wanted, head_node *p) {
    node_list *iterator;
    int flag = 0;
    iterator = p->first;
    while((iterator != NULL) && !flag)
    {
        if (((iterator->rg).compare(rg_wanted)) == 0) {
            cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            flag = 1;
        }
        iterator = iterator->p_next;
    }
}
void reading(string name) {
}
void procura(head_node *head, string rg_wanted) {
    node_list *iterator;
    int flag = 0;
    iterator = head->first;
    while((iterator != NULL) && !flag)
    {
        if (((iterator->rg).compare(rg_wanted)) == 0) {
            cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            flag = 1;
        }
        iterator = iterator->p_next;
    }
}



