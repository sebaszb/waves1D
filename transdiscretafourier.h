void DFTcapturadatos(int a)
{
     entrada[contentradasDFT]=intensidad[a];
     //cout<<"ok"<<endl;
}

void DFT()
{     
     //entrada[0]=1, entrada[1]=2, entrada[2]=3, entrada[3]=4, entrada[4]=5;
     transformadapreal=0;
     transformadapimaginaria=0;
     /*for(int l=0;l<NUMERO;l++)
     {
             entrada[l]=sin(l*3.141592*2*(0.01)*30)+sin(l*3.141592*2*(0.01)*40);                           //me parece que el 1/delta de t debe ser igual al numero de celdas, si es asi tendria un problema ya que el delta t en el automata es del orden de 10 a la menos 6, por lo tanto necesitaria del orden de un millon de datos para la transformada!!!
     }*/
     for(int a=0;a<NUMERO;a++)
     {
             for(int b=0;b<NUMERO;b++)
             {
                     transformadapreal+=entrada[b]*cos(3.141592*2*a*b/NUMERO);
                     transformadapimaginaria+=entrada[b]*(-1)*sin(3.141592*2*a*b/NUMERO);
             }
             transformada[a]=sqrt(pow(transformadapreal,2)+pow(transformadapimaginaria,2));
             transformadapreal=0;
             transformadapimaginaria=0;
     }     
     for(int q=0;q<NUMERO;q++)
     {
             cout<<q<<"  "<<transformada[q]<<endl;
             //cout<<entrada[q]<<endl;
     }
}

void DFTespacial()
{     
     transformadapreal=0;
     transformadapimaginaria=0;
     int esp=int (1/dx);                                                        //Defino el numero de entradas que se van a tener en cuenta para calcular la transformada discreta espacia
     double *transespacial=new double[esp];
     int Cont;
     
     /*for(int a=0;a<M;a++)
     {
             intensidad[a]=sin(a*3.141592*2*200/M);
     }*/
     for(int a=0;a<esp;a++)
     {
             for(int b=0;b<esp;b++)
             {
                     Cont=b;
                     while(Cont>M){Cont=Cont-M;}                                //esto se hace para que al momento de calcular para la celda M+T donde T es un numero entre 0 y M, lo calcule segun la celda T ya que muy seguramente necesitaremos mas de los M datos que tenemos, en este caso 1/dx datos
                     transformadapreal+=intensidad[Cont]*cos(3.141592*2*a*b/esp);
                     transformadapimaginaria+=intensidad[Cont]*(-1)*sin(3.141592*2*a*b/esp);
             }
             transespacial[a]=sqrt(pow(transformadapreal,2)+pow(transformadapimaginaria,2));
             transformadapreal=0;
             transformadapimaginaria=0;
     }
     
     //de aca pa bajo escribo el archivo en cadena
     string Archivo;                           //declara una palabra (Archivo)
     ofstream myfile;                          //declara que quiero abrir un archivo
     stringstream s;                           //convierte de numero a palabra
     s<<contcadena<<"DFTesp.dat";              //ojo que estoy usando el mismo "contcadena" que uso para imprimir la forma de la cuerda en cadena
     s>>Archivo;
     myfile.open(Archivo.c_str());//aca pilas abajo
     ///////////////////////////////////////////////////////////////////////////
         for(int q=0;q<esp;q++)
         {
                 myfile<<q<<"  "<<transespacial[q]<<endl;
         }
     //////////////////////////////////////////////////////////////////////////////
  myfile.close();
}     
