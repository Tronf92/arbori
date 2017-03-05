#include <iostream>
#include <string>
using namespace std;

int rnd=0;

typedef struct nod{
	string nume;
	int varsta;
	struct nod *stanga;
	struct nod *dreapta;
}un_nod;

un_nod *radacina;

nod *cauta_insereaza(nod *n, string p){
	if(n==NULL){
		n= new un_nod;
		if(rnd==0){
			radacina = n;
			rnd=1;
		}
		n->nume = p;
		cout << "Introduceti varsta" << endl;
		cin >> n->varsta;
		n->stanga = NULL;
		n->dreapta = NULL;
	}
	else if(n->nume > p  ){
		n->stanga = cauta_insereaza(n->stanga, p);
	}else{
		n->dreapta = cauta_insereaza(n->dreapta, p);
	}
	return n;
}

void afisare(nod *p){
	if(p!= NULL){
		afisare(p->stanga);
		cout << "Nume:" << p->nume << " varsta" << p->varsta << endl;
		afisare(p->dreapta);
	}
}
int main(){
	string x;
	cout << "Introduceti un nume:" << endl;
	cout <<"Pentru terminare \"t\"" << endl; 
	cin >> x;
	while(x!= "t" ){
		cauta_insereaza(radacina,x);
		cout << "Alt nume:" << endl;
		cin >> x;
	}
	afisare(radacina);

	system("pause");
	return 0;
}