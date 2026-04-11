#include<iostream>
#include<vector>
#include<string>

using namespace std;

void burbuja(vector<int>& lista,int n){
    int i,j;
    bool burbujeado;

    //i es un indice auxiliar que acorta el limite superior de j
    for(i=0;i<=n-2;i=i+1){
        //el burbujeado aun no se ha ejecutado  
        burbujeado=false;

        for(j=0;j<=n-2-i;j=j+1){
            if(lista[j]>lista[j+1]){
                swap(lista[j],lista[j+1]);

                //el burbujeado se ejecuto con exito
                burbujeado=true;
            }
        }

        //si el burbujeado no se ejecuto entonces la lista ya esta ordenada
        if(burbujeado==false){
            return;
        }
    }
}

void seleccion(vector<int>&lista,int n){
    int i,k,j;
    //indice auxiliar
    for(i=0;i<=n-2;i=i+1){
        k=i;

        for(j=i+1;j<=n-1;j=j+1){
            if(lista[k]>lista[j]){
                k=j;
            }
        }

        if(k!=i){
            swap(lista[k],lista[i]);
        }
    }
}

vector<int> merge(const vector<int>&izq,const vector<int>&der){
    vector<int> resultado;
    int i=0,j=0;

    while(i<izq.size()&&j<der.size()){
        if(izq[i]<der[j]){
            resultado.push_back(izq[i]);
            i=i+1;
        }
        else{
            resultado.push_back(der[j]);
            j=j+1;
        }
    }

    //Agrega los elementos restantes de izq (si los hay)
    while(i<izq.size()){
        resultado.push_back(izq[i]);
        i=i+1;
    }

    //Agrega los elementos restantes de der (si los hay)
    while(j<der.size()){
        resultado.push_back(der[j]);
        j=j+1;
    }

    return resultado;
}

vector<int> mergesort(const vector<int>&lista){
    int medio;

    //la lista ya esta ordenada
    if(lista.size()<=1){
    //devuelve una copia
        return lista;
    }

    medio=lista.size()/2;

    //dividir
    vector<int> izq(lista.begin(),lista.begin()+medio);
    vector<int> der(lista.begin()+medio,lista.end());   

    //llamadas recursivas
    izq=mergesort(izq);
    der=mergesort(der);

    return merge(izq,der);
}

int main(){
    string algoritmo;
    int n,i;

    cin>>algoritmo;
    cin>>n;

    vector<int>lista(n);

    //LEER elementos
    for(i=0;i<n;i=i+1){
        cin>>lista[i];
    }

    //ejecutar algoritmo
    if(algoritmo=="burbuja"){
        burbuja(lista,n);
    }
    else if(algoritmo=="seleccion"){
        seleccion(lista,n);
    }
    else if(algoritmo=="mergesort"){
        lista=mergesort(lista);
    }
    else{
        cout<<"ezkriba bien";
        return 0;
    }

    //imprimir lista separada por espacios
    for(i=0;i<n;i=i+1){
        cout<<lista[i];
        if(i<n-1){
            cout<<" ";
        }
    }

    cout<<endl;

    return 0;
}
