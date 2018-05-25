void resultados()
{
 for(int l=0;l<M;l++)
 {
         cout<<xreal<<"    "<<intensidad[l]<<endl;
         xreal=xreal+dx;
         //cout<<M<<endl;
 }    
}

void datosencadena()
{
     string Archivo;                           //declara una palabra (Archivo)
     ofstream myfile;                          //declara que quiero abrir un archivo
     stringstream s;                           //convierte de numero a palabra
     s<<contcadena<<"cx.dat";
     s>>Archivo;
     myfile.open(Archivo.c_str());//aca pilas abajo
     ///////////////////////////////////////////////////////////////////////////
         for(int b=0;b<=M;b++)
         {
                 
                 //cout<<xreal<<"    "<<yreal<<"    "<<intensidad[b][a]<<endl;
                 myfile<<xreal<<"   "<<intensidad[b]<<endl;
                 xreal=xreal+dx;
         }
         xreal=0;                        //toca poner esto para que x vuelva a 0
     //////////////////////////////////////////////////////////////////////////////
  myfile.close();
}


void velocidades()
{
     for(int l=0;l<M;l++)
     {
             cout<<velocidad[l]<<endl;
     }
}

void resultadosenergiacinetica()
{
     for(int w=0;w<M;w++)
     {
             energiak=energiak+(0.5*densidad*velocidad[w]*velocidad[w]);
     }
     if(energia_t_disp==0)
     {
                          cout<<iter*dt/2<<"   "<<energiak<<endl;
                          energiak=0;                       //toca ponerla en 0 despues de calcularla
                                            
     }
}

void resultadosenergiapotencial()
{
     for(int w=1;w<M;w++)
     {
             energiap=energiap+0.5*tension*(pow((intensidad[w-1]-intensidad[w+1])/(2*dx),2));
     }
     if(energia_t_disp==0)
     {
                          
                          cout<<iter*dt/2<<"   "<<energiap<<endl;
                          energiap=0;                       //toca ponerla en 0 despues de calcularla                    
     }
}

void resultadosenergiatotal()
{
     energia_t_disp=1;
     resultadosenergiacinetica();
     resultadosenergiapotencial();
     energiat=energiak+energiap;
     cout<<iter*dt/2<<"   "<<energiat<<endl;
     energiat=0;
     energiap=0;
     energiak=0;
     
}


