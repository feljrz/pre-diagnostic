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
    printf("> %s: \nDoença: %s\n %u anos;\n", paciente.nome, paciente.doenca,
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
                "2)Forte dor de cabeça",
                "3)Dor atrás dos olhos que piora com o movimento dos mesmos",
                "4)Perda do paladar e apetite",
                "5)Tonturas",
                "6)Moleza e dor no corpo",
                "7)Muitas dores nos ossos",
                "8)Dores abdominais fortes e contínuas",
                "9)Pele pálida fria e úmida",
                "10)Sangramento pelo nariz boca e gengivas",
                "11)Manchas vermelhas na pele",
                "12)Sonolência agitação e confusão mental",
                "13)Sede excessiva e boca seca",
                "14)Pulso rápido e fraco",
                "15)Perda de consciência",
                "16)Depósitos de gordura no corpo",
                "17)Emagrecimento e pele frágil",
                "18)Cicatrização lenta",
                "19)Acne",
                "20)Diminuição da libido",
                "21)Diminuição da fertilidade",
                "22)Disfunção erétil",
                "23)Depósito de gordura no corpo",
                "24)Cabelo facial (hirsutismo)",
                "25)Períodos menstruais irregulares ou ausente",
                "26)Depressão ansiedade e irritabilidade",
                "27)Perda de controle emocional",
                "28)Dificuldades cognitivas",
                "29)Pressão arterial elevada",
                "30)Intolerância à glicose que pode levar à diabetes",
                "31)Dor de cabeça",
                "32)Perda óssea",
                "33)Tosse seca tosse com catarro de cor amarelada",
                "34)Falta de ar ",
                "35)Dificuldade de respirar",
                "36)Dor no peito ou tórax",
                "37)Mal-estar generalizado",
                "38)Fraqueza",
                "39)Suores intensos",
                "40)Ronco ou chiado no peito",
                "41)Fadiga",
                "42)Febre e calafrios",
                "43)Desconforto no peito",
                "44)Inchaço nos tornozelos pés e pernas",
                "45)Lábios roxos devido ao nível baixo de oxigênio",
                "46)Infecções respiratórias frequentes como resfriados ou gripes",
                "47)Febre baixa",
                "48)Dor nas articulações",
                "49)Dor muscular",
                "50)Dor atrás dos olhos",
                "51)Erupções cutâneas",
                "52)Conjuntivite",
                "53)Diarreia",
                "54)Constipação",
                "55)Fotofobia",
                "56)Pequenas úlceras na mucosa oral",
                "57)Febre",
                "58)Dor nas articulações",
                "59)Dor nas costas",
                "60)Dor de cabeça",
                "61)Náuseas",
                "62)Vômitos",
                "63)Excesso de urina",
                "64)Sede excessiva",
                "65)Fome frequente",
                "66)Visão embaçada",
                "67)Cicatrização lenta",
                "68)Infecções",
                "69)Confusão",
                "70)Formigamento",
                "71)Insuficiências hepática e renal",
                "72)Icterícia (olhos e pele amarelados)",
                "73)Manifestações hemorrágicas",
                "74)Perda de apetite",
                "75)Suor noturno",
                "76)Expectoração de sangue",
                "77)Perda de peso",
                "78)Dor durante a respiração",
                "79)Calafrios",
                "80)Febre",
                "81)Manchas e erupções na pele semelhantes ao sarampo principalmente no tórax e membros superiores",
                "82)Bronquite",
                "83)Coceira",
                "84)Prostração (abatimento físico e psíquico)",
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
        printf("1)Caso queira cadastrar o paciente: \n2)Para ver a possivel doença do paciente: \n3)Para ver todos os pacientes: \n4)Para sair do programa: \n");
        scanf("%d",&opp);

        if (opp==1)
        {

            printf("Digite o nome do paciente com '_':\n\n");
            scanf("%s",&paciente.nome);
            printf("\nDigite a doença:\n\n");
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
            printf("Digite o número dos sintomas sentidos pelos pacientes,caso esteja sentindo menos que 10 sintomas, digite 0 :\n");

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
                printf("Você provavelmente está com: ");
            else
                printf("Seus sintomas não se encaixam em nenhuma doença");

            // jogar vetflag na matriz
            for(i=0; i<12; i++)
            {
                d[i][11]=vetflag[i];
            }
            // Mostrar doenças

            for (i=0; i<12; i++)
            {
                if (d[i][10]==1 && d[i][11]>3)
                    printf("Dengue clássica---Score:%d/10\n",flagd1);

                if (d[i][10]==2 && d[i][11]>3)
                    printf("Dengue hemorragica---Score:%d/10\n",flagd2);

                if (d[i][10]==3 && d[i][11]>3)
                    printf("Doença de Cushing---Score:%d/10\n",flagd3);

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
                    printf("Lúpus---Score:%d/10\n",flagd12);
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
