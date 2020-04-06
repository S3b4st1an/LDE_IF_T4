//
//  main.cpp
//  LDE_I_F
//
//  Created by Jafeth Alonso Carreón on 4/2/20.
//  Copyright © 2020 Jafeth Alonso Carreón. All rights reserved.
//

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


void LDE::InsertarI(int x)
{
    if(!Inicio)
    {
        Inicio=new Nodo(x);
        Fin=Inicio;
    }
    
    else
    {
        Nodo *helpx3=new Nodo(x);
        helpx3->Asignasig(Inicio);
        Inicio->Asignaant(helpx3);
        Inicio=helpx3;
    }
}
void LDE::InsertarF(int x)
{
    if(!Inicio)
    {
        Inicio=new Nodo(x);
    }
    
    else
    {
        Nodo *helpx2=new Nodo(x);
        Fin->Asignasig(helpx2);
        helpx2->Asignaant(Fin);
        Fin=helpx2;
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
            Nodo *hay=Inicio;
            Inicio=Inicio->Obtienesig();
            hay->Asignasig(NULL);
            Inicio->Asignaant(NULL);
            delete hay;
        }
    }
}
void LDE::BorrarF()
{    if(!Inicio)
    cout<<"Lista Vacia";
    else
        {
            if(Inicio==Fin)
                {
                    delete Inicio;
                    Inicio=NULL;
                    Fin=NULL;
                }
            else
                {
                    Nodo *Sh;
                    Sh=Fin->Obtieneant();
                    Sh->Asignasig(NULL);
                    Fin->Asignaant(NULL);
                    delete Fin;
                    Fin=Sh;
                }
        }
}


void LDE::Imprimir()
{
    if(!Inicio)
        cout<<"Lista Vacia"<<endl;
    else
    {
        Nodo *Aux=Inicio;
        while(Aux!=NULL)
        {
            Aux->Imprimir();
            Aux=Aux->Obtienesig();
        }
    }
}



void LDE::ImprimirR()
{
    if(!Inicio)
        cout<<"Lista Vacia"<<endl;
    else
    {
        Nodo *Aux=Fin;
        while(Aux!=NULL)
        {
            Aux->Imprimir();
            Aux=Aux->Obtieneant();
        }
        
    }
}



int LDE::Contar()
{    int ESCA=0;
    if(!Inicio)
        ESCA=0;
    else
    {
        Nodo *REC=Inicio;
        while(REC!=NULL)
        {
            ESCA++;
            REC=REC->Obtienesig();
        }
    }
    return ESCA;
}

Nodo* LDE::Buscar(int x)
{
    Nodo *covid=Inicio;
    if(Inicio)
    {
        while (covid!=NULL)
        {
            if (covid->Obtienedato()==x)
                return covid;
            covid=covid->Obtienesig();
        }
    }
    return covid;
}
void LDE::Borrar(int x)
{
    Nodo *simi=Buscar(x);
    if(simi==NULL)
        cout<<"DATO NO ENCONTRADO";
    else
    {
        if(simi==Inicio)
            BorrarI();
        else
        {
            if(simi==Fin)
                BorrarF();
            else
            {
                Nodo *XL=simi->Obtieneant();
                XL->Asignasig(simi->Obtienesig());
                simi->Obtienesig()->Asignaant(XL);
                simi->Asignasig(NULL);
                simi->Asignaant(NULL);
                delete simi;
            }
        }
    }
}









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
