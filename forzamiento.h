void forzamiento()
{
     /////////////////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!     
     /*double w=0.2;
     if(FR<=3000)
     {
     intensidad[M-2]=0.25*sin(3.1415*FR*2/100)*sqrt(4*alfa/(beta*(1+cosh(2*sqrt(alfa/(velocidaddeprop*velocidaddeprop-w*w))*(-w*FR+200)))));    //esta es la ecuación de un soliton (no la borremos que es canson de escribir)
     if(FR==3000)
     {
                intensidad[M-2]=0;
     }
     }*/
     /////////////////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!
     
     
     //if(FR<=400){intensidad[0]=sin(2*3.141592*FR/400)*sin(2*3.141592*FR/250);}
     
     /*if(FR<=1500)
     {
                intensidad[0]=sin(2*3.141592*FR/100)*sin(2*3.141592*FR/3000);           
     if(FR==1500){intensidad[0]=0;}
     }*/
     
     
     /*if(FR<=500)
     {
     intensidad[M-1]=sin(2*M_PI*FR/1000);           
     if(FR==1000){intensidad[M-1]=0;}
     }*/
     
     intensidad[0]=0.1*sin(2*M_PI*FR/4000);
     
     FR=FR+1;
     
}
