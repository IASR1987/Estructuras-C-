/*ISMAEL ÁNGEL SORIA RIVERO*/
#include <iostream>
#include <stdlib.h>

using namespace std;

/*creamos un struct con las siguientes caracteristicas                          /
/ ID (Número entero)                                                            /
/ Raza (Cadena de texto)                                                        /
/ Nombre (Cadena de texto)                                                      /
/ Estado (Sus valores posibles serán: "Bien", "Por Revisar", "En tratamiento"   /
/ Disponible (bool) Nos permitira el control de huecos vacios en la matriz     */

struct animales{
    int ID;
    string raza;
    string nombre;
    string estado;
    bool disponible;
    };

int main()
{

    int eleccion=0, estado=0, contador=0, borrarAnimal=0, modificarAnimal=0, ID_busqueda=0, control_nombre=0;
    float contadorAnimales=0, contadorBien=0, contadorRevision=0, contadorTrata=0;
    string nombre_busqueda;
    animales lista[10];
    

    
    
    for(int i=0; i<10; i++){
        lista[i].disponible=false;/* Definimos nuestro booleano como false nos indica que el hueco de nuestra matriz está vacio*/
        lista[i].ID=1+i;/*Rellenamos los id directamente(para ellos sumamos 1) del 1 al 10*/
    }


    /*Creamos el menú de la aplicación*/

    do{

            cout<<"Menú inicial"<<endl;
            cout<<"******************************************"<<endl;
            cout<<"1. Agregar nuevos animales"<<endl;
            cout<<"2. Eliminar animales"<<endl;
            cout<<"3. Cambiar el estado de un animal"<<endl;
            cout<<"4. Ver lista de todos los animales"<<endl;
            cout<<"5. Busqueda de animales"<<endl;
            cout<<"6. Ver estadísticas"<<endl;
            cout<<"7. Abandonar la aplicación"<<endl;
            cin>>eleccion;


            switch (eleccion)/*cada case nos indica una funcionalidad de la app*/
            {
                case 1:
                    cout<<"Vas a introducir a un animal"<<endl;
                    cout<<"..........................................."<<endl;
                    for(int i=0; i<10; i++){
                    /*recorremos la matriz buscando la primera posicion que tenga false, asi sabremos que está vacia */
                    /*creamos un contador, para que solo inscribamos un animal cada vez*/
                            if(contador==0 && lista[i].disponible==false){
                            contador++;

                            cout<<"Se le asignará el ID "<<i+1<<"."<<endl;
                            cout<<".............................."<<endl;
                            cout<<"Introduce el nombre del animal"<<endl;
                            cin>>lista[i].nombre;
                            cout<<".............................."<<endl;
                            cout<<"Introduce la raza del animal"<<endl;
                            cin.ignore();
                            getline(cin,lista[i].raza);

                            if(lista[i].raza.size()>10){
                                cout<<"La raza sólo puede contener 10 carácteres"<<endl;
                                cout<<"Introduce de nuevo la raza del animal"<<endl;
                                getline(cin,lista[i].raza);
                                lista[i].raza = lista[i].raza.substr(0, 10);/*.substr castea la palabra introducida en raza reduciendala a 10 caracteres*/
                            }
                            lista[i].estado="Por revisar";/*Estado por defecto debía ser "Por Revisar"*/
                            lista[i].disponible=true;/*Cambiamos a true así ya sabremos que nuestro hueco esta ocupado*/
                            }               
                    }
                    contador=0;/*Hay que reiniciar el contador para que la proxima vez que entremos en el case podamos inscribir a otro animal*/

                    system("PAUSE");

                break;

                case 2:
                    cout<<"Vas a eliminar a un animal"<<endl;
                    cout<<"..........................................."<<endl;
                    cout<<"Indica el ID del animal a eliminar"<<endl;
                    cin>>borrarAnimal;/*variable creada para identifcar al animal*/

                    /*creamos el contadorAnimales, para saber si hay animales inscritos en nuesta base de datos*/
                    for(int i=0; i<10; i++){
                            if(lista[i].disponible==true){
                                contadorAnimales++;
                            }
                        }
                        
                        if(borrarAnimal>contadorAnimales){/*comprobamos que el ID introducido sea correcto*/
                            cout<<"O el número introducido es incorrecto, o no existe aún animal con esos datos en la base de datos"<<endl;
                        }else if(lista[borrarAnimal-1].estado=="Bien"){/*solo en el caso que el animal se encuentre en estado "Bien" podrá ser borrado*/
                            lista[borrarAnimal-1].nombre="";
                            lista[borrarAnimal-1].raza="";
                            lista[borrarAnimal-1].estado="";
                            lista[borrarAnimal-1].disponible=false;/*volvemos aponer false para indicar que el hueco esta disponible*/
                            cout<<"El animal con ID "<<borrarAnimal<<" ha sido eliminado correctamente";
                        }else{
                            cout<<"El animal seleccionado aún esta en tratamiento no es posible eliminarlo"<<endl;                    
                        }
                    
                system("PAUSE");

                break;

                case 3:
                    cout<<"Vas a cambiar el estado de un animal"<<endl;
                    cout<<"..........................................."<<endl;
                    cout<<"Indica el ID del animal al cual vamos a modificar su estado"<<endl;
                    cin>>modificarAnimal;/*variable que utilizamos para identificar el animal*/
                    cout<<"..........................................."<<endl;

                    /*Recorremos la matriz en busca del animal seleccionado*/
                    if(lista[modificarAnimal-1].disponible==true){
                        cout<<"El estado actual del animal es: "<<lista[modificarAnimal-1].estado<<endl;
                        cout<<"Introduce el nuevo estado del animal"<<endl;
                        cout<<"1. Bien"<<endl;
                        cout<<"2. Por revisar"<<endl;
                        cout<<"3. En tratamiento"<<endl;
                        cin>>eleccion;
                        switch (eleccion)/*ofrecemos las opciones de cambio de estado*/
                        {
                        case 1:
                            lista[modificarAnimal-1].estado="Bien";
                            break;
                        case 2:
                            lista[modificarAnimal-1].estado="Por revisar";
                            break;
                        case 3:
                            lista[modificarAnimal-1].estado="En tratamiento";
                            break;
                        
                        default:
                            break;
                        }
                        cout<<"El estado del animal ha cambiado a: "<<lista[modificarAnimal-1].estado<<"."<<endl;

                    }else{
                        cout<<"No hay ningún animal registrado con ese ID"<<endl;
                    }
                    
                
                    system("PAUSE");
                    
                    break;
                
                
                
                case 4:
                        cout<<"LISTA DE ANIMALES"<<endl;
                        cout<<"..................................................................................."<<endl;
                        for(int i=0; i<10; i++){
                            if(lista[i].disponible==true){/*solo imprime los animales registrados*/
                                cout<<"ID: "<<lista[i].ID<<". NOMBRE: "<<lista[i].nombre<<". RAZA: "<<lista[i].raza<<". ESTADO: "<<lista[i].estado<<"."<<endl;
                                cout<<"----------------------------------------------------------------------------------"<<endl;
                            }
                            
                        }
                    
                    system("PAUSE");

                break;

                case 5:
                        cout<<"BÚSQUEDA DE ANIMALES"<<endl;
                        cout<<"..............................................................................."<<endl;
                        cout<<"Indica que parámetro vas a utilizar para buscar al animal de nuestra base de datos"<<endl;
                        cout<<"1. ID"<<endl;
                        cout<<"2. Nombre"<<endl;
                        cin>>eleccion;
                        switch (eleccion)/*indica la opcion escogida pra la busqueda ID o Nombre*/
                        {
                        case 1:
                            cout<<"Introduce el ID del animal que buscas"<<endl;
                            cin>>ID_busqueda;/*variable creada para indicar la ID del animal que buscamos*/

                            if(lista[ID_busqueda-1].disponible==true){
                                cout<<"El animal que buscas es"<<endl;
                                cout<<"ID: "<<lista[ID_busqueda-1].ID<<". NOMBRE: "<<lista[ID_busqueda-1].nombre<<". RAZA: "<<lista[ID_busqueda-1].raza<<". ESTADO: "<<lista[ID_busqueda-1].estado<<"."<<endl;
                            }else{
                                cout<<"No hay ningún animal registrado con ese ID"<<endl;
                            }
                            break;

                        case 2:
                            cout<<"Introduce el nombre del animal que buscas"<<endl;
                            cin.ignore();
                            getline(cin,nombre_busqueda);/*nombre_busqueda variable creada que indica el nombre que queremos buscar*/

                            for(int i=0; i<10; i++){
                                if(nombre_busqueda==lista[i].nombre){
                                    cout<<"El animal que buscas es"<<endl;
                                    cout<<"ID: "<<lista[i].ID<<". NOMBRE: "<<lista[i].nombre<<". RAZA: "<<lista[i].raza<<". ESTADO: "<<lista[i].estado<<"."<<endl;
                                    control_nombre++;/*esta variable indica que existe un animal con el nombre buscado*/
                                }
                            }

                            if(control_nombre==0){/*si no hay ningun animal con ese nombre entrará aquí*/
                                    cout<<"No hay ningún animal con ese nombre."<<endl;
                            }
                            control_nombre=0;/*reiniciamos la variable*/
                            break;
                            
                        default:
                            break;
                    }

                system("PAUSE");
                
                break;

                case 6:
                        /*creamos múltiples contadores que nos indique los animales que hay en total, y despúes dependiendonos del estado*/
                        /*Animales totales*/
                        for(int i=0; i<10; i++){
                            if(lista[i].disponible==true){
                                contadorAnimales++;
                            }
                        }

                        /*Animales estado bien*/
                        for(int i=0; i<10; i++){
                            if(lista[i].estado=="Bien"){
                                contadorBien++;
                            }
                        }

                        /*Animales estado Revision*/
                        for(int i=0; i<10; i++){
                            if(lista[i].estado=="Por revisar"){
                                contadorRevision++;
                            }
                        }

                        /*Animales estado En tratamiento*/
                        for(int i=0; i<10; i++){
                            if(lista[i].estado=="En tratamiento"){
                                contadorTrata++;
                            }
                        }
                        

                        cout<<"ESTADÍSTICAS"<<endl;
                        cout<<"..............................................................................."<<endl;
                        if(contadorAnimales>0){
                            cout<<"Animales en nuestra base de datos: "<<contadorAnimales<<"."<<endl;
                            cout<<"..............................................................................."<<endl;
                            cout<<"Número total de animales en estado *Bien*:                  ............. "<<contadorBien<<"."<<endl;
                            cout<<"Porcentaje del total de animales en estado *Bien*:           ............. "<<(contadorBien/contadorAnimales)*100<<" %."<<endl;/*para calcular los porcentajes*/
                            cout<<"..............................................................................."<<endl;
                            cout<<"Número total de animales en estado *En revisión*:            ............. "<<contadorRevision<<"."<<endl;
                            cout<<"Porcentaje del total de animales en estado *en revisión*:    ............. "<<((contadorRevision/contadorAnimales)*100)<<" %."<<endl;/*para calcular los porcentajes*/
                            cout<<"..............................................................................."<<endl;
                            cout<<"Número total de animales en estado *En tratamiento*:         ............. "<<contadorTrata<<"."<<endl;
                            cout<<"Porcentaje del total de animales en estado *En tratamiento*: ............. "<<((contadorTrata/contadorAnimales)*100)<<" %."<<endl;/*para calcular los porcentajes*/
                        }else{
                            cout<<"La base de datos esta vacía"<<endl;
                        }
                    
                        /*reiniciamos las variables*/
                        contadorAnimales=0;
                        contadorBien=0;
                        contadorRevision=0;
                        contadorTrata=0;

                    system("PAUSE");

                break;
            
                default:

                break;
            }

        }while(eleccion!=7);
return 0;

}
