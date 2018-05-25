void cargarmedio()
{
     for(int j=0;j<M/2;j++)
     {
             c_x[j]=1;
     }
     for(int j=M/2;j<M;j++)
     {
             c_x[j]=1;
     }
}

void condinicialescero()
{
     for(int j=0;j<M;j++)
     {
             intensidad[j]=0;
             velocidad[j]=0;
     }
     
}

void condtodos1()
{
     for(int j=1;j<M-1;j++)
     {
             intensidad[j]=1;
             velocidad[j]=0;
     }
     
}

void condiniciales5()
{
      for(int j=0;j<M;j++)
     {
             intensidad[j]=0.2*sin((3.1416/2)*(j)/(M-1));
             velocidad[j]=0;
     }
}

void condsenosoidal(int n1)
{
     for(int j=0;j<M;j++)
     {
             intensidad[j]=0.2*sin(M_PI*n1*j/(M-1));
             velocidad[j]=0;
     }
}

void condiniciales2()
{
     for(int i=1;i<M;i++)
     {
             intensidad[i]=0;
             velocidad[i]=0;
     }
     intensidad[0]=0.2;
     velocidad[0]=0;
}

void condiniciales1()
{          
    for(int j=0;j<M;j++)
    {
            if(j>=500 && j<+700)
            {
                      velocidad[j]=100;
                      intensidad[j]=0.5;
            }//cierro el if
            else
            {
            velocidad[j]=0;
            intensidad[j]=0;
            }//cierro el esle
    }
}

void condicionesiniciales()
{
for(int i=0;i<M/2;i++)
    {
            intensidad[i]=(0.02/499)*i;
            velocidad[i]=0;
    }
    for(int i=M/2;i<M;i++)
    {
            intensidad[i]=0.04-(0.02/500)*i;
            velocidad[i]=0;      
    }
}

void condguitarra2()
{
     for(int i=0;i<M/4;i++)
    {
            intensidad[i]=(0.02/(M/4))*i;
            velocidad[i]=0;
    }
    for(int i=M/4;i<3*M/4;i++)
    {
            intensidad[i]=0.04-(0.02/(M/4))*i;
            velocidad[i]=0;      
    }
    for(int i=3*M/4;i<M;i++)
    {
            intensidad[i]=-0.08+(0.02/(M/4))*i;
            velocidad[i]=0;      
    }
}

void condviolin()
{
     for(int i=0;i<3*M/4;i++)
     {
             intensidad[i]=0.02*i/(((3*M)/4)-1);
             velocidad[i]=0;
     }
     for(int i=3*M/4;i<M;i++)
     {
             intensidad[i]=0.08-0.02*i/(M-(3*M/4));
     }
}

void soliton()
{
     double w=1;
     for(int i=0;i<M;i++)
     {
             intensidad[i]=sqrt(4*alfa/(beta*(1+cosh(2*sqrt(alfa/(velocidaddeprop*velocidaddeprop-w*w))*(w*i-400)))));
     }
}
