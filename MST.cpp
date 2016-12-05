//============================================================================
// Name        : MST.cpp
// Author      : Alex T. Carvalho
// Version     :
// Copyright   : ATC Serviços de LP Ltda.
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ordenacao{
	
private:
	
	template < class T >
	static void swap( T& a, T& b ) {
		
		T aux = a;
		a = b;
		b = aux;
	}
	
	
	static int pai(int i){
		return (int)floor(i/2);
	}
	
	
	static int esq(int i){
		return 2*i;
	}
	
	
	static int dir(int i){
		return 2*i+1;
	}
	

	template < class T >
	static void maxHeapify( vector<T>& A, int i, int &heapSize );	
	
	template < class T >
	static void buildMaxHeap( vector<T>& A, int &heapSize );
		
		
public:
	
	template < class T >
	static void heapsort( vector<T>& A );
};
	template <class T>
	void Ordenacao::maxHeapify( vector<T>& A, int i, int &heapSize ){
		
		int l = esq(i), r = dir(i), maior = -1;
		if (l <= heapSize and A[l] > A[i])
			maior = l;
		else
			maior = i;
	
		if (r <= heapSize and A[r] > A[maior])
			maior = r;
		if (maior != i){
			swap(A[i], A[maior]);
			maxHeapify(A, maior, heapSize);
		}
	}


	template <class T>
	void Ordenacao::buildMaxHeap( vector<T>& A, int &heapSize ){
		
		heapSize = (int) A.size() -1;
		for (int i=(int) floor(heapSize/2); i >=1; i--){
			maxHeapify(A, i, heapSize);
		}
	}
	
	
	template <class T>
	void Ordenacao::heapsort( vector<T>& A ){
		
		int heapSize = 0;
		buildMaxHeap(A, heapSize);
		for (int i=A.size()-1;i > 1;i--){
			swap(A[1], A[i]);
			heapSize--;
			maxHeapify(A, 1, heapSize);
		}
	}


template <class T>
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
    	Ordenacao::heapsort( items );
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
class Queue {
	
private:
	
    Node <T> *front, *back;
    static const int NILL = -1;
    
public:

    Queue (){
        this->front=new Node <T>();
        back= front;
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
                return NILL;
            }
    }

};

template <class T>
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


class MainProcessing{
	
public:
	
    vector < Graph <int> > adj;
    vector <int> enemiesPos;
    double distanceTotal;


    MainProcessing(){
    	init();
    }


    void init(){
    	this->distanceTotal = 0;
    }
    
	
    void systemInputWithDistance(Graph <int> g, int strings){
        int vertex1;
        int vertex2;
        double distance;
        for(int i = 0; i < strings; i++){
            cin >> vertex1;
            cin >> vertex2;
            cin >> distance;
            g.insertEdge(vertex1, vertex2, distance);
        }
    }
};

int main() {
	MainProcessing pp2;
	int vertexes, strings;
	cin >> vertexes;
	cin >> strings;
	Graph <int> g (vertexes);
	
	pp2.systemInputWithDistance(g, strings);
	
	return 0;
}
