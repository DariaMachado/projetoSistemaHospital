#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LOG 2
#define MAX_PAC 10

typedef struct{
    int id;
    char nome[20];
    char dtNascimento[15];
    char telefone[20];
    char rg[15];
    float sensor;
}Paciente;

typedef struct{
    char login[20];
    int tipo;
    int senha;
}Usuario;

Usuario usuario[MAX_LOG];
Paciente paciente[MAX_PAC];

void carregar_usuario();
void carregar_pacientes();
void inicializar();
void lista_pacientes();
void cadastrar_paciente();
void alterar_paciente();
void excluir_paciente();
void visualizar_paciente();
void limpaTela();
void logo_hosp();
void alerta(float *sensor);

int main() {
    system("color 1f");

    carregar_usuario();
    carregar_pacientes();
    inicializar();

    // Login

    int aux = 0,auxSenha;
    char auxLogin[20];
    while(aux==0){
        logo_hosp();
        printf("\t\tLogin: ");
        scanf("%s",auxLogin);
        printf("\t\tSenha: ");
        scanf("%d",&auxSenha);
        for(int cont = 0; cont<2; cont++){
            if((strcmp(auxLogin, usuario[cont].login)==0)&&(auxSenha==usuario[cont].senha)){
                aux = usuario[cont].tipo;
            }
        }
        limpaTela();
        if(aux==0){
            printf("\t\tLogin ou senha invalidos\n\n");
        }
    }

    // Paciente

    if(aux==2){
            limpaTela();
            int auxPac = 0,escolhaPac=0;
            logo_hosp();
            printf("\tLogado como paciente.\n\n");
        while(auxPac == 0){
            printf("\n\t1: Ver historico\n");
            printf("\t2: Ver dados do sensor\n");
            printf("\t3: Sair\n");
            printf("\tEscolha uma opcao:");
            scanf("%d",&escolhaPac);
            switch(escolhaPac){
                case 1:
                    limpaTela();
                    printf("\n\tHistorico:\n\t14/06/00:-------------\n\t10/04/15:-------------\n\t13/08/20:-------------\n\t25/02/21:-------------\n");
                    break;
                case 2:
                    limpaTela();
                    printf("\n\tSensor de temperatura : 37 graus\n");
                    break;
                case 3:
                    auxPac = 1;
                    break;
                default:
                    limpaTela();
                    printf("\n\tEscolha invalida\n");
            }
        }
    }

    // Medico

    if(aux==1){
        limpaTela();
        int auxMed = 0,escolhaMed=0;
        int escpac=0;
        logo_hosp();
        printf("\tLogado como medico.\n\n");

        while(auxMed == 0){
            printf("\n\t1: Ver lista de pacientes\n");
            printf("\t2: Cadastrar paciente\n");
            printf("\t3: Alterar paciente\n");
            printf("\t4: Excluir paciente\n");
            printf("\t5: Ver dados do paciente\n");
            printf("\t6: Sair\n");
            printf("\tEscolha uma opcao: ");
            scanf("%d",&escolhaMed);

            switch(escolhaMed){
                case 1:
                    lista_pacientes();
                    break;
                case 2:
                    cadastrar_paciente();
                    break;
                case 3:
                    alterar_paciente();
                    break;
                case 4:
                    excluir_paciente();
                    break;
                case 5:
                    visualizar_paciente();
                    break;
                case 6:
                    auxMed = 1;
                    break;
                default:
                    limpaTela();
                    printf("\n\tEscolha invalida\n\n");
            }
        }
    }

    return 0;
}

void carregar_usuario(){
    strcpy(usuario[0].login, "med");
    usuario[0].senha = 123;
    usuario[0].tipo = 1;
    strcpy(usuario[1].login, "pac");
    usuario[1].senha = 321;
    usuario[1].tipo = 2;
}

void carregar_pacientes(){
    paciente[0].id = 1;
    strcpy(paciente[0].nome,"Antonio");
    strcpy(paciente[0].dtNascimento,"05/04/1993");
    strcpy(paciente[0].telefone,"1234567898");
    strcpy(paciente[0].rg,"12365478");
    paciente[0].sensor = 37.2;

    paciente[1].id = 2;
    strcpy(paciente[1].nome,"Maria");
    strcpy(paciente[1].dtNascimento,"26/07/2004");
    strcpy(paciente[1].telefone,"8754621395");
    strcpy(paciente[1].rg,"87654321");
    paciente[1].sensor = 38.2;
}

void inicializar(){
    for(int conInicia = 2; conInicia<=9;conInicia++){
        paciente[conInicia].id = 0;
        strcpy(paciente[conInicia].nome,"Vazio");
        strcpy(paciente[conInicia].dtNascimento,"0");
        strcpy(paciente[conInicia].telefone,"0");
        strcpy(paciente[conInicia].rg,"0");
        paciente[conInicia].sensor = 0.0;
    }
}

void lista_pacientes(){
    limpaTela();
    printf("------------------------------PACIENTES------------------------------");
    for(int mospac=0;mospac<=9;mospac++){
        if(paciente[mospac].id != 0){
            printf("\n\tId: %d\n\tNome: %s\n\n",paciente[mospac].id,paciente[mospac].nome);
        }
    }
}

void cadastrar_paciente(){
    limpaTela();
    int escpac = 0;

    printf("------------------------------CADASTRO------------------------------");
    while(escpac<=9){
        if(paciente[escpac].id == 0){
            printf("\n\n\tNome: ");
            scanf("%s",paciente[escpac].nome);
            fflush(stdin);
            printf("\n\tData de nascimento: ");
            scanf("%s",paciente[escpac].dtNascimento);
            paciente[escpac].id = escpac+1;
            fflush(stdin);
            printf("\n\tTelefone(sem pontuacao): ");
            scanf("%s",paciente[escpac].telefone);
            fflush(stdin);
            printf("\n\tRG(sem pontuacao): ");
            scanf("%s",paciente[escpac].rg);
            fflush(stdin);
            printf("\n\tPaciente cadastrado.\n");
            escpac=10;
        }
        else{escpac++;}
    }
}

void alterar_paciente(){
    limpaTela();
    int escpac = 0;
    printf("------------------------------ALTERAR CADASTRO------------------------------");
    for(int altpac=0; altpac<=9; altpac++) {
        if(paciente[altpac].id != 0){
            printf("\n\tId: %d\n\tNome: %s\n\n",paciente[altpac].id,paciente[altpac].nome);
        }
    }

    printf("\tEscolha qual paciente alterar: ");
    scanf("%d",&escpac);

    if(strcmp(paciente[escpac - 1].nome,"Vazio") == 0){
        printf("\n\tCodigo invalido. Paciente nao registrado!\n");
    }
    else{
        printf("\n\n\tNome: ");
        scanf("%s",paciente[escpac-1].nome);
        fflush(stdin);
        printf("\n\tData de nascimento: ");
        scanf("%s",paciente[escpac-1].dtNascimento);
        fflush(stdin);
        printf("\n\tTelefone(sem pontuacao): ");
        scanf("%s",paciente[escpac-1].telefone);
        fflush(stdin);
        printf("\n\tRG(sem pontuacao): ");
        scanf("%s",paciente[escpac-1].rg);
        fflush(stdin);
        limpaTela();
        printf("\n\tPaciente alterado.");
    }
}

void excluir_paciente(){
    limpaTela();
    int escpac;
    printf("------------------------------DELETAR CADASTRO------------------------------");
    for(int excpac=0;excpac<=9;excpac++){
        if(paciente[excpac].id != 0){
            printf("\n\tId: %d\n\tNome: %s\n\n",paciente[excpac].id,paciente[excpac].nome);
        }
    }

    printf("\tEscolha qual paciente excluir: ");
    scanf("%d",&escpac);
    if(strcmp(paciente[escpac - 1].nome,"Vazio") == 0){
        printf("\n\tCodigo invalido. Paciente nao registrado!\n");
    }
    else{
        paciente[escpac-1].id = 0;
        strcpy(paciente[escpac-1].nome,"Vazio");
        strcpy(paciente[escpac-1].dtNascimento,"0");
        strcpy(paciente[escpac-1].rg,"0");
        strcpy(paciente[escpac-1].telefone,"0");
        limpaTela();
        printf("\n\tPaciente excluido.\n");
    }

}

void visualizar_paciente(){
    limpaTela();
    int escpac;
    float sensor;
    printf("------------------------------VISUALIZAR CADASTRO------------------------------");
    for(int dadpac=0;dadpac<=9;dadpac++){
        if(paciente[dadpac].id != 0){
            printf("\n\tId: %d\n\tNome: %s\n\n",paciente[dadpac].id,paciente[dadpac].nome);
        }
    }
    printf("\tEscolha qual paciente: ");
    scanf("%d",&escpac);
    limpaTela();
    if(strcmp(paciente[escpac - 1].nome,"Vazio") == 0){
        printf("\n\tCodigo invalido. Paciente nao registrado!\n");
    }
    else{
        if(paciente[escpac-1].sensor == 0.0){
            printf("\n\n\tId: %d\n\tNome: %s\n\tRG: %s\n\tData de nascimento: %s\n\tTelefone: %s\n\tSensor de temperatura: 37 graus\n\tHistorico:\n\t14/06/00:-------------\n\t10/04/15:-------------\n\t13/08/20:-------------\n\t25/02/21:-------------\n\n"
           ,paciente[escpac-1].id,paciente[escpac-1].nome,paciente[escpac-1].rg,paciente[escpac-1].dtNascimento,paciente[escpac-1].telefone);

        }
        else{
        printf("\n\n\tId: %d\n\tNome: %s\n\tRG: %s\n\tData de nascimento: %s\n\tTelefone: %s\n\tSensor de temperatura: %.1f graus\n\tHistorico:\n\t14/06/00:-------------\n\t10/04/15:-------------\n\t13/08/20:-------------\n\t25/02/21:-------------\n\n"
           ,paciente[escpac-1].id,paciente[escpac-1].nome,paciente[escpac-1].rg,paciente[escpac-1].dtNascimento,paciente[escpac-1].telefone, paciente[escpac-1].sensor);

            sensor = paciente[escpac-1].sensor;
            alerta(&sensor);
            /*forma que nós encontramos de simular um
            alerta caso a temp do paciente se eleve, sem ter uma conexão com o banco
            e pré definindo temperaturas para pacientes fictícios*/
        }
    }
}

void logo_hosp(){
    printf("\n\t          IIII\n");
        printf("\t          IIII\n");
        printf("\t      IIIIIIIIIIII\n");
        printf("\t      IIIIIIIIIIII\n");
        printf("\t          IIII\n");
        printf("\t          IIII\n\n");

        printf(" \t ...... HOSPITAL ......\n \tSistema de Monitoramento\n\n\n");
}

void alerta(float *sensor){
    if(*sensor > 37.5){
        printf("\n\tALERTA: TEMPERATURA ELEVADA!!!!\n\n");
    }
}

void limpaTela(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif // para usuarios com sistema Linux, Unix e Apple

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif // para usuarios com sistema windows
}

