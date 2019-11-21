#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef
struct Paciente
{
    char nome[256];
    char doenca[20];
    unsigned int idade;
}
Paciente;


void mostrar(Paciente paciente)
{
    printf("> %s: \nDoen�a: %s\n %u anos;\n", paciente.nome, paciente.doenca,
           paciente.idade);
}

void gravar(Paciente paciente)
{
    FILE * arq;
    arq = fopen("registro.txt","a+");
    fprintf(arq, "%s\t%s\t%u\n\n\n", (paciente.nome), (paciente.doenca), (paciente.idade));
    fclose(arq);
}
int ler(FILE * arq, Paciente *ppaciente, unsigned int id)
{
    fseek(arq,0,SEEK_CUR);
    int ok = fscanf(arq, "%s\t%s\t%u\n\n", &(ppaciente->nome), &(ppaciente->doenca), &(ppaciente->idade));
    return ok;
}

int main()
{

    Paciente paciente;
    setlocale(LC_ALL,"Portuguese");
    int opp;
    FILE * arq;
    unsigned int i;
    arq = fopen("registro.txt","w+");
    if(arq==NULL)
    {
        printf("Nao foi possivel ler o arquivo");
        exit(0);
    }
    char sintomas[][200]=
            {
                "1)Febre alta",
                "2)Forte dor de cabe�a",
                "3)Dor atr�s dos olhos que piora com o movimento dos mesmos",
                "4)Perda do paladar e apetite",
                "5)Tonturas",
                "6)Moleza e dor no corpo",
                "7)Muitas dores nos ossos",
                "8)Dores abdominais fortes e cont�nuas",
                "9)Pele p�lida fria e �mida",
                "10)Sangramento pelo nariz boca e gengivas",
                "11)Manchas vermelhas na pele",
                "12)Sonol�ncia agita��o e confus�o mental",
                "13)Sede excessiva e boca seca",
                "14)Pulso r�pido e fraco",
                "15)Perda de consci�ncia",
                "16)Dep�sitos de gordura no corpo",
                "17)Emagrecimento e pele fr�gil",
                "18)Cicatriza��o lenta",
                "19)Acne",
                "20)Diminui��o da libido",
                "21)Diminui��o da fertilidade",
                "22)Disfun��o er�til",
                "23)Dep�sito de gordura no corpo",
                "24)Cabelo facial (hirsutismo)",
                "25)Per�odos menstruais irregulares ou ausente",
                "26)Depress�o ansiedade e irritabilidade",
                "27)Perda de controle emocional",
                "28)Dificuldades cognitivas",
                "29)Press�o arterial elevada",
                "30)Intoler�ncia � glicose que pode levar � diabetes",
                "31)Dor de cabe�a",
                "32)Perda �ssea",
                "33)Tosse seca tosse com catarro de cor amarelada",
                "34)Falta de ar ",
                "35)Dificuldade de respirar",
                "36)Dor no peito ou t�rax",
                "37)Mal-estar generalizado",
                "38)Fraqueza",
                "39)Suores intensos",
                "40)Ronco ou chiado no peito",
                "41)Fadiga",
                "42)Febre e calafrios",
                "43)Desconforto no peito",
                "44)Incha�o nos tornozelos p�s e pernas",
                "45)L�bios roxos devido ao n�vel baixo de oxig�nio",
                "46)Infec��es respirat�rias frequentes como resfriados ou gripes",
                "47)Febre baixa",
                "48)Dor nas articula��es",
                "49)Dor muscular",
                "50)Dor atr�s dos olhos",
                "51)Erup��es cut�neas",
                "52)Conjuntivite",
                "53)Diarreia",
                "54)Constipa��o",
                "55)Fotofobia",
                "56)Pequenas �lceras na mucosa oral",
                "57)Febre",
                "58)Dor nas articula��es",
                "59)Dor nas costas",
                "60)Dor de cabe�a",
                "61)N�useas",
                "62)V�mitos",
                "63)Excesso de urina",
                "64)Sede excessiva",
                "65)Fome frequente",
                "66)Vis�o emba�ada",
                "67)Cicatriza��o lenta",
                "68)Infec��es",
                "69)Confus�o",
                "70)Formigamento",
                "71)Insufici�ncias hep�tica e renal",
                "72)Icter�cia (olhos e pele amarelados)",
                "73)Manifesta��es hemorr�gicas",
                "74)Perda de apetite",
                "75)Suor noturno",
                "76)Expectora��o de sangue",
                "77)Perda de peso",
                "78)Dor durante a respira��o",
                "79)Calafrios",
                "80)Febre",
                "81)Manchas e erup��es na pele semelhantes ao sarampo principalmente no t�rax e membros superiores",
                "82)Bronquite",
                "83)Coceira",
                "84)Prostra��o (abatimento f�sico e ps�quico)",
                "85)Apatia",
                "86)Feridas no canto da boca"

            };

            int d[][12]=
            {
                {1,2,3,4,83,63,64,5,6,7,1,0},
                {8,66,9,10,11,12,13,14,38,15,2,0},
                {16,17,18,19,20,43,40,27,29,30,3,0},
                {1,34,35,36,38,39,40,41,64,42,4,0},
                {49,59,51,32,52,53,54,8,56,57,5,0},
                {82,60,61,32,53,43,63,64,51,85,6,0},
                {65,66,43,79,67,68,69,70,71,72,7,0},
                {1,81,43,32,51,63,73,74,75,76,8,0},
                {82,77,34,36,78,45,79,80,81,86,9,0},
                {43,40,9,39,5,63,36,4,87,88,10,0},
                {38,63,64,51,50,35,43,4,87,89,11,0},
                {6,82,50,39,38,61,32,40,87,88,12,0}
            };
    do
    {
        system("cls");
        printf("1)Caso queira cadastrar o paciente: \n2)Para ver a possivel doen�a do paciente: \n3)Para ver todos os pacientes: \n4)Para sair do programa: \n");
        scanf("%d",&opp);

        if (opp==1)
        {

            printf("Digite o nome do paciente com '_':\n\n");
            scanf("%s",&paciente.nome);
            printf("\nDigite a doen�a:\n\n");
            scanf("%s",&paciente.doenca);
            printf("\nDigite a idade:\n\n");
            scanf("%d",&paciente.idade);
            gravar(paciente);
        }
        if (opp==2)
        {
            int i;
            int op[12];
            int j=0,k=0;
            int flagd1=0,flagd2=0,flagd3=0,flagd4=0,flagd5=0,flagd6=0,flagd7=0,flagd8=0,flagd9=0,flagd10=0,flagd11=0,flagd12=0;



            for(i=0; i<86; i++)
            {
                printf("%s ",sintomas[i]);
                printf("\n");
            }


            //encher vetor com 0;
            for(i=0; i<10; i++)
                op[i]=0;
            //interface
            printf("\n\n");
            printf("Digite o n�mero dos sintomas sentidos pelos pacientes,caso esteja sentindo menos que 10 sintomas, digite 0 :\n");

            //Recebimento dos sintomas
            for(i=0; i<10; i++)
            {
                scanf("%d",&op[i]);

            }
            //comparar
            for(k=0; k<10; k++)
            {
                for(i=0; i<12; i++)
                {
                    for(j=0; j<10; j++)
                    {
                        if(op[k]==d[i][j])
                        {
                            if(d[i][10]==1)
                                flagd1++;
                            if(d[i][10]==2)
                                flagd2++;
                            if(d[i][10]==3)
                                flagd3++;
                            if(d[i][10]==4)
                                flagd4++;
                            if(d[i][10]==5)
                                flagd5++;
                            if(d[i][10]==6)
                                flagd6++;
                            if(d[i][10]==7)
                                flagd7++;
                            if(d[i][10]==8)
                                flagd8++;
                            if(d[i][10]==9)
                                flagd9++;
                            if(d[i][10]==10)
                                flagd10++;
                            if(d[i][10]==11)
                                flagd11++;
                            if(d[i][10]==12)
                                flagd12++;

                        }
                    }
                }
            }
            int flavinho=0;
            int vetflag[12]= {flagd1,flagd2,flagd3,flagd4,flagd5,flagd6,flagd7,flagd8,flagd9,flagd10,flagd11,flagd12};
            for(i=0; i<10; i++)
            {
                if(vetflag[i]>3)
                    flavinho++;
            }
            if(flavinho!=0)
                printf("Voc� provavelmente est� com: ");
            else
                printf("Seus sintomas n�o se encaixam em nenhuma doen�a");

            // jogar vetflag na matriz
            for(i=0; i<12; i++)
            {
                d[i][11]=vetflag[i];
            }
            // Mostrar doen�as

            for (i=0; i<12; i++)
            {
                if (d[i][10]==1 && d[i][11]>3)
                    printf("Dengue cl�ssica---Score:%d/10\n",flagd1);

                if (d[i][10]==2 && d[i][11]>3)
                    printf("Dengue hemorragica---Score:%d/10\n",flagd2);

                if (d[i][10]==3 && d[i][11]>3)
                    printf("Doen�a de Cushing---Score:%d/10\n",flagd3);

                if (d[i][10]==4 && d[i][11]>3)
                    printf("Pneumonia---Score:%d/10\n",flagd4);

                if (d[i][10]==5 && d[i][11]>3)
                    printf("Zica---Score:%d/10",flagd5);
                if (d[i][10]==6 && d[i][11]>3)
                    printf("Chycungunia---Score:%d/10\n",flagd6);

                if (d[i][10]==7 && d[i][11]>3)
                    printf("Diabete Mellitos---Score:%d/10\n",flagd7);

                if (d[i][10]==8 && d[i][11]>3)
                    printf("Febre Amarela---Score:%d/10\n",flagd8);
                if (d[i][10]==9 && d[i][11]>3)
                    printf("Tuberculose---Score:%d/10\n",flagd9);

                if (d[i][10]==10 && d[i][11]>3)
                    printf("Anemia---Score:%d/10\n",flagd10);

                if (d[i][10]==11 && d[i][11]>3)
                    printf("Hepatite---Score:%d/10\n",flagd11);
                if (d[i][10]==12 && d[i][11]>3)
                    printf("L�pus---Score:%d/10\n",flagd12);
            }
            printf("\n");
        }
        if (opp==3)
        {
            {
                i = 0;
                while(!feof(arq))
                {

                    if(ler(arq, &paciente, i))
                        mostrar(paciente);
                    i++;
                }
            }
            fclose(arq);
        }
        system("pause");
    }
    while (opp<4);
    system("pause");
    return 0;
}
