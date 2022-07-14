#include<stdio.h>
#include<windows.h>
#define V 21
#define H 75
#define PELOTA 254
#define RAQJUG 178
#define RAQSIS 219

void  borde (char campo[V][H])
{
    int i,j;
    for (i=0; i<V; i++) //vertical
    {

        for(j=0; j<H; j++) //horizontal
        {

            if(i==0||i==V-1)
            {

                campo[i][j]='-';
            }
            else if(j==0||j==H-1)
            {

                campo[i][j]='|';
            }
            else
            {

                campo[i][j]=' ';
            }
        }
    }

}

void raqjug(char campo[V][H], int inijug,int finjug)
{
    int i,j;

    for(i=inijug; i<=finjug; i++)
    {

        for(j=2; j<=3; j++)
        {
            campo[i][j]=RAQJUG;

        }
    }


}

void raquia(char campo[V][H], int iniia,int finia)
{
    int i,j;
    for(i=iniia; i<=finia; i++)
    {

        for(j=H-4; j<=H-3; j++)
        {

            campo[i][j]=RAQSIS;
        }

    }
}
void pel(char campo [V][H],int pelX,int pelY)

{
    campo[pelY][pelX]=PELOTA;
}

void leercamp(char campo[V][H])
{
    int i,j;
    for(i=0; i<V; i++)
    {

        for(j=0; j<H; j++)
        {
            printf("%c",campo[i][j]);
        }
        printf("\n");
    }
}


////////////////////////////////////////////////////////
void gameloop(char campo[V][H],int pelx,int pely,int inijug, int finjug,int iniia, int finia,int modX, int modY,int modia )
{
    int gol;
    gol=0;

    do
    {
        draw(campo); //dibujar pantalla
        input(campo,&pelx,&pely,&inijug,&finjug,&iniia,&finia,&modX,&modY,&modia,&gol);//verificar y actualizar posiciones
        update(campo,pelx,pely,inijug,finjug,iniia,finia);//actualuzar matriz campo
        Sleep(10);

    }
    while(gol == 0);

}

void draw(char campo[V][H])
{
    system("cls");
    leercamp(campo);
}

void input(char campo[V][H],int *pelx,int *pely,int *inijug, int *finjug,int *iniia, int *finia,int *modX, int *modY,int *modia, int *gol)
{
    int i;
    char key;

//verificacion
    if (*pely ==1 || *pely==V-2)
    {
        *modY *=-1;
    }

    if(*pelx == 1 || *pelx == H-2)
    {
        *gol = 1;
    }
    if(*pelx ==4)
    {
        for(i=(*inijug); i<=(*finjug); i++)
        {
            if (i== (*pely))
            {
                *modX *= -1;
            }
        }
    }

    if(*pelx==H-5)
    {
        for (i=(*iniia); i <=(*finia); i++)
        {
            if(i==(*pely))
            {
                *modX*=-1;
            }
        }

    }

    if(*iniia==1 || *finia==V-1)
    {
        *modia *=-1;
    }




//modificacion

    if(*gol == 0)
    {

//pelota:

        *pelx+=(*modX);
        *pely+=(*modY);

//raqueta de la IA

        *iniia +=(*modia);
        *finia +=(*modia);

//raqueta jugador:
        if(kbhit() ==1 ) //provisional
        {
            key = getch();

            if(key =='8')
            {
                if(*inijug != 1)
{
                    *inijug -= 1;
                    *finjug -= 1;
                }
            }

            if (key == '2'){
                if(*finjug!=V-2){
                    *inijug+=1;
                    *finjug+=1;
                }

            }

        }

    }

}

void update(char campo[V][H],int pelx,int pely,int inijug, int finjug,int iniia, int finia){
    borde(campo);
    raqjug(campo,inijug,finjug);
    raquia(campo,iniia,finia);
    pel(campo,pelx,pely);
}

////////////////////////////




int main()
{

    int pelx, pely,inijug,finjug,iniia,finia;  //variables de posicion
    int modX,modY,modia;   //variables de movidificacion
    char campu[V][H];

    //posicion
    pelx=37;
    pely=10;

    inijug=8;
    finjug=12;

    iniia =3;
    finia=18;

    //modificacion
    modX=-1;
    modY=-1;
    modia=-1;


    inicio(campu,pelx,pely,inijug,finjug,iniia,finia);
    gameloop(campu,pelx,pely,inijug,finjug,iniia,finia,modX,modY,modia);
    system("pause");

    return 0;
}

void inicio(char campo[V][H],int pelx,int pely,int inijug, int finjug,int iniia, int finia)
{
    borde(campo);
    raqjug(campo,inijug,finjug);
    raquia(campo,iniia,finia);
    pel(campo,pelx,pely);

}



