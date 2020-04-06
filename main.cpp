//
//  main.cpp
//  LDE_I_F
//
//  Created by Jafeth Alonso Carreón on 4/2/20.
//  Copyright © 2020 Jafeth Alonso Carreón. All rights reserved.
//
/* Equipo 4:
-Trejo Sebastian Rodolfo*
-Daniel Román Ortiz Valencia
-Gonzalez Hernandez Marco Antonio
-Mendez Roman Juan carlos
*/
#include <iostream>
using namespace std;

class Nodo
{
private:
    int dato;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo()
    {    dato=0;
        sig=NULL;
        ant=NULL;
    }
    Nodo(int x)
    {    dato=x;
        sig=NULL;
        ant=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    int Obtienedato();
};
class LDE
{    private:
    Nodo *Inicio, *Fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    void Imprimir();
    void ImprimirR();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    LDE()
    {
        Inicio=NULL;
        Fin=NULL;
        
    }
    
};
//Funciones de Nodo
void Nodo::Asignasig(Nodo *x)
{
    this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{
    this->ant=x;
}


void Nodo::Leer(int x)
{
    this->dato=x;
}
void Nodo::Imprimir()
{
    cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{
    return(this->sig);
}

Nodo* Nodo::Obtieneant()
{
    return(this->ant);
}


int Nodo::Obtienedato()
{
    return(this->dato);
}
//Funciones LDE
void LDE::InsertarI(int x)
{
    if(!Inicio)
    {
        Inicio=new Nodo(x);
        
		Inicio=Fin;
    }
    
    else
    {
        Nodo *n=new Nodo(x);
        n->Asignasig(Inicio);
        Inicio->Asignaant(n);
        Inicio=n;
    }
}
void LDE::InsertarF(int x)
{
	if(!Inicio)
    {
    	Inicio = new Nodo(x);
    }
    
    else
    {
        Nodo *n2 = new Nodo(x);
        Fin->Asignasig(n2);
        n2->Asignaant(Fin);
        Fin = n2;
    }
}
void LDE::BorrarI()
{
    if(!Inicio)
        cout<<"Lista Vacia"<<endl;
    else
    {
        if(Inicio==Fin)
        	{
           	 	delete Inicio;
           		Fin=NULL;
            	Inicio=NULL;
        	}
        else
        	{
        		Nodo *otro=Inicio;
            	Inicio=Inicio->Obtienesig();
            	otro->Asignasig(NULL);
            	Inicio->Asignaant(NULL);
            	delete otro;
        	}
    }
}
void LDE::BorrarF()
{    
    if(Inicio==NULL)
    cout<<"Lista Vacia";
    else
    {
        if(Inicio==Fin)
        {delete Inicio;
            Inicio=NULL;
            Fin=NULL;
        }
        else
        {
          Nodo *Sharys;
          Sharys=Fin->Obtieneant();
          Sharys->Asignasig(NULL);
          Fin->Asignaant(NULL);
          delete Fin;
          Fin=Sharys;
        }
     }
}
void LDE::Imprimir()
{
    if(Inicio==NULL)
        cout<<"Lista Vacia"<<endl;
    else
    {Nodo *temp=Inicio;
        while(temp!=NULL)
        {
            temp->Imprimir();
            temp=temp->Obtienesig();
        }
    }
}
void LDE::ImprimirR()
{
    if(Inicio==NULL)
        cout<<"Lista Vacia"<<endl;
    else
    {Nodo *xl=Fin;
        while(xl!=NULL)
        {
            xl->Imprimir();
            xl=xl->Obtieneant();
        }
    }
}
int LDE::Contar()
{    
	int piojo = 0;
    if(!Inicio)
        piojo = 0;
    else
    {
        Nodo *REC = Inicio;
        while(REC!=NULL)
        {
            piojo++;
            REC = REC->Obtienesig();
        }
    }
    return piojo;
}
Nodo* LDE::Buscar(int x)
{
    Nodo *pan=Inicio;
    if(Inicio)
    {
        while (pan!=NULL)
        {
        if (pan->Obtienedato()==x)
            return pan;
        pan = pan->Obtienesig();
        }
    }
    return pan;
}
void LDE::Borrar(int x)
{
    Nodo *aux=Buscar(x);
    if(aux==NULL)
        cout<<"DATO NO ENCONTRADO";
    else
    {
        if(aux==Inicio)
            BorrarI();
        else
        {
            if(aux==Fin)
                BorrarF();
            else
            {
                Nodo *XL = aux-> Obtieneant();
                XL->Asignasig(aux->Obtienesig());
                aux->Obtienesig()->Asignaant(XL);
                aux->Asignasig(NULL);
                aux->Asignaant(NULL);
                delete aux;
            }
        }
    }
}


int main(int argc, const char * argv[])
{
    
    
    
    LDE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Imprimir en Reversa"<<endl;
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);
                break;
            case 7:
                A.Imprimir();
                break;
            case 8:
                A.ImprimirR();
                break;
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<9);
    
    return 0;
}
