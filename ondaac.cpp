#include"definiciones.h"
#include"condiniciales.h"
#include"resultados.h"
#include"forzamiento.h"
#include"transdiscretafourier.h"

void copiaceldas()
{
     for(int j=0;j<M;j++)
     {
             copiaintensidad[j]=intensidad[j];
             copiavelocidad[j]=velocidad[j];
     }
     //cout<<"todo bien"<<endl;
}

void copioold()
{
     for(int j=0;j<M;j++)
     {
             oldint[j]=copiaintensidad[j];
             oldvel[j]=copiavelocidad[j];
     }
     //cout<<"todo bien"<<endl;
}

void automata()
{
     for(int i=1;i<M-1;i++)
     {
             intensidad[i]=oldint[i]+(dt)*copiavelocidad[i];
             velocidad[i]=oldvel[i]+c_x[i]*(copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4*dt);  //mucho ojo parce que el c_x da cuenta de la velocidad en el medio, si es 1, la velocidad es 500 m/s
     }
     //copioold();
     //copiaceldas();
}

void automataverlet()
{
     
     for(int i=1;i<M-1;i++)
     {
             velocidad[i]=oldvel[i]+0.5*(copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4*dt)+0.5*(intensidad[i-1]-2*intensidad[i]+intensidad[i+1])/(4*dt);
     }
     for(int i=1;i<M-1;i++)
     {
             intensidad[i]=oldint[i]+(dt)*copiavelocidad[i]+0.5*(copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4);
     }
     //copioold();
     //copiaceldas();
}

void automataKG()
{
     for(int i=1;i<M-1;i++)
     {
             intensidad[i]=oldint[i]+(dt)*copiavelocidad[i];
             velocidad[i]=oldvel[i]+(copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4*dt)-alfa*dt*copiaintensidad[i]-beta*dt*pow(copiaintensidad[i],3);
            
     }
     //copioold();
     //copiaceldas();
}


void automatanabla()
{
     double Kc=1e004;
     for(int i=1;i<M-1;i++)
     {
             intensidad[i]=oldint[i]+(dt)*copiavelocidad[i];
             velocidad[i]=oldvel[i]+((copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4*dt))+ Kc*pow((copiaintensidad[i+1]-copiaintensidad[i-1]),2)*(dt)/(4*dx*dx);
            
     }
     //copioold();
     //copiaceldas();
}

void automatafijo_libre()
{
     for(int i=1;i<M;i++)
     {
             if(i==M-1)
             {
                       intensidad[i]=intensidad[i-1];
             }
             else
             {
             intensidad[i]=oldint[i]+dt*copiavelocidad[i];
             velocidad[i]=oldvel[i]+(copiaintensidad[i-1]-2*copiaintensidad[i]+copiaintensidad[i+1])/(4*dt);
             }//cierro el else
            
     }
     //copioold();
     //copiaceldas();
}


void cronometro()
{
     if(intensidad[M/2]>0 & disparador==1)
     {
                             cout<<FR*dt<<endl;
                             disparador=0;
     }
}

int main()
{
    cargarmedio();                                                              //de lo mas importante, si no se llama a esta funcion el automata no arranca ya que el comp pone a todos los c_x en 0
    //condicionesiniciales();
    //condviolin();
    //condguitarra2();
    //condiniciales1();
    //condiniciales2();
    //condsenosoidal(1);                                                          //el numero corresponde al numeo de la funcion normal que se quiera
    //condiniciales4();
    //condiniciales5();
    //soliton();
    condinicialescero();
    //condtodos1();
    copiaceldas();
    copioold();
    //resultados();
    //DFTespacial();
    for(int z=0;z<iteraciones;z++)
    {
            iter=z;                                                             //una copia global de la iteración en la que se va
            //resultadosenergiacinetica();        
            //resultadosenergiapotencial();
            //resultadosenergiatotal(); 
            /*if(z%20==0)                                                        //debe ser el doble del que esta en definiciones
            {                
            DFTcapturadatos(M/2);
            contentradasDFT=contentradasDFT+1;                                  //esto es para contar las veces que toma datos de un punto para calcular la DFT
            }*/
            if(z%30==0)
            {
            contcadena+=1;
            //DFTespacial();
            datosencadena();
            }
            automata();
            //automataverlet();                                                 //es muy inestable, parece no creo que sirva para integrar estas ecuaciones
            //automataKG();
            //automatanabla();
            //automatafijo_libre();
            forzamiento();
            //cronometro();
            copioold();
            copiaceldas();
    }                                                                           //cierro el for para las iteraciones                                                                          
    //DFT();
    //DFTespacial();    
    //resultados();
    //cout<<T<<endl;
}
