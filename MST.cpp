//============================================================================
// Name        : MST.cpp
// Author      : Alex T. Carvalho
// Version     :
// Copyright   : ATC Serviços de LP Ltda.
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class List {
private:
    vector <T> items;
    vector <double> distance;
    bool empty (){return items.size() == 0;}
public:
    List(){
    }
    void insert(T x, double d){
    	items.push_back(x);
    	distance.push_back(d);
    	int tam = (int) items.size();
    	items.push_back( items[0] );
    	quicksort(items, 0, tam - 1);
    	items.pop_back();
    }
    void remove(T& x){
    	if (!empty()){
    		int pos = search(x);
    		items.erase(pos);
    	}
    }

    T getVertex(int pos){
    	return items[pos];
    }

    double getDistance(int pos){
    	return distance[pos];
    }

    int search(T k) {
        for (unsigned int i=0;i<items.size();i++){
        	if (items[i] == k)
        		return i;
        }
        return -1;
    }

    void destroy(){
    	for (unsigned int i=0; i <  items.size();i++){
    		delete(&items[i]);
    	}
    }

    int getSize(){
    	return items.size();
    }

};

template <typename T>
class Node {
public:
    T code;
    Node <T>* next;
    Node(){ this->next = NULL;}
};

template <typename T>
class Queue
{
private:
    Node <T> *front, *back;
public:

    Queue (){
        this->front=new Node <T>();
        back= front;
        back->next = NULL;
    }

    bool empty(){ return front == back;}
    void queue(T x){
        Node <T>* aux= new Node <T>();
        back->next= aux;
        back->code = x;
        back=aux;

    }

    T dequeue(){
            if(!this->empty()){
                Node <T>* aux = this->front;
                this->front=front->next;
                aux->next = NULL;
                int x = aux->code;
                delete aux;
                return x;
            }else{
                return -1;
            }
    }

};

template <typename T>
class Queue
{
private:
    Node <T> *front, *back;
public:

    Queue (){
        this->front=new Node <T>();
        back= front;
        back->next = NULL;
    }

    bool empty(){ return front == back;}
    void queue(T x){
        Node <T>* aux= new Node <T>();
        back->next= aux;
        back->code = x;
        back=aux;

    }

    T dequeue(){
            if(!this->empty()){
                Node <T>* aux = this->front;
                this->front=front->next;
                aux->next = NULL;
                int x = aux->code;
                delete aux;
                return x;
            }else{
                return -1;
            }
    }

};

template <typename T>
class Graph{
	List <T> *adj;

	int n, m;
public:
	Graph(int n){
		this->n = 0;
		this->m = 0;
		init(n);
	}

	void destroy(){
		for (int i = 1; i <= n; i++) {
			adj[i].destroy(); // destroi lista
		}
		delete(adj);
		n = m = 0;
	}

	void init(int n){
		if (this-> n != 0) destroy();
		this-> n = n;
		adj = new List <T> [n];
	}

	List <T> getAdj(int pos){
		return adj[pos];
	}

	int getAdjSize(int pos){
		return adj[pos].getSize();
	}

	void insertEdge(T u, T v, double d){
		adj[u].insert(v, d);
		adj[v].insert(u, d);
		m++;
	}

	int getOrder(){
		return this->n;
	}

	int getSize(){
		return this->m;
	}

};


int main() {
	cout << "PAA PERÍODO QUE VEM PORRA" << endl;
	return 0;
}
