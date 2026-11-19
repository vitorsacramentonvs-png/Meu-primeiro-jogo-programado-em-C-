#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



typedef struct Player{

    char * nome;
    int forca;
    int velocidade;
    int vida;
    int sanidade;
    int moedas;

}Player;

typedef struct Visitante{

    char * nome;
    char * raca;
    int humano;
    int vida;
    int forca;
    int idade;

    struct Visitante * prox;
    struct Visitante * ants;

}Visitante;

typedef struct Itens{

    char * nome;
    char * classe;
    int preco;
    char * descricao;

    struct Itens * prox;
    struct Itens * ants;

}Itens;


int MAX_INVENTARIO = 10;

Visitante * inicio_humanos = NULL;
Visitante * fim_humanos = NULL;
int tam_humanos = 0;

Visitante * inicio_anomalias = NULL;
Visitante * fim_anomalias = NULL;
int tam_anomalias = 0;

Itens * inicio_itens = NULL;
Itens * fim_itens = NULL;
int tam_itens = 0;

Itens * inicio_inventario = NULL;
Itens * fim_inventario = NULL;
int tam_inventario = 0;



void adicionar_humano(char *nome, char * raca, int humano, int vida, int forca, int idade, int pos){

    Visitante * novo = malloc(sizeof(Visitante));
    novo->nome = nome;
    novo->humano = humano;
    novo->raca = raca;
    novo->vida = vida;
    novo->idade = idade;
    novo->forca = forca;
    novo->ants = NULL;
    novo->prox = NULL;

    if(pos<=tam_humanos && pos >= 0){
        if(inicio_humanos == NULL){
            inicio_humanos = novo;
            fim_humanos = novo;

            tam_humanos ++;
        }else{
            if(pos == 0){
                novo->prox = inicio_humanos;
                inicio_humanos->ants = novo;
                inicio_humanos = novo;

                tam_humanos++;
            }else if(pos == tam_humanos){
                fim_humanos->prox = novo;
                novo->ants = fim_humanos;
                fim_humanos = novo;

                tam_humanos++;
            }else{
                Visitante * aux = inicio_humanos;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->prox;
                }

                novo->prox = aux->prox;
                aux->prox = novo;
                novo->prox->ants = novo;
                novo->ants = aux;
                
                tam_humanos++;
            }
        }
    }else{
        printf("A posição que você escolheu é inválida");
    }

}

void adicionar_anomalia(char *nome, char * raca, int humano, int vida, int forca, int idade, int pos){

    Visitante * novo = malloc(sizeof(Visitante));
    novo->nome = nome;
    novo->humano = humano;
    novo->raca = raca;
    novo->vida = vida;
    novo->idade = idade;
    novo->forca = forca;
    novo->ants = NULL;
    novo->prox = NULL;

    if(pos<=tam_anomalias && pos >= 0){
        if(inicio_anomalias == NULL){
            inicio_anomalias = novo;
            fim_anomalias = novo;

            tam_anomalias ++;
        }else{
            if(pos == 0){
                novo->prox = inicio_anomalias;
                inicio_anomalias->ants = novo;
                inicio_anomalias = novo;

                tam_anomalias++;
            }else if(pos == tam_anomalias){
                fim_anomalias->prox = novo;
                novo->ants = fim_anomalias;
                fim_anomalias = novo;

                tam_anomalias++;
            }else{
                Visitante * aux = inicio_anomalias;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->prox;
                }

                novo->prox = aux->prox;
                aux->prox = novo;
                novo->prox->ants = novo;
                novo->ants = aux;
                
                tam_anomalias++;
            }
        }
    }else{
        printf("A posição que você escolheu é inválida");
    }

}

void adicionar_itens(char *nome, char * classe, int preco, char * descricao, int pos){

    Itens * novo = malloc(sizeof(Itens));
    novo->nome = nome;
    novo->classe = classe;
    novo -> preco = preco;
    novo->descricao = descricao;
    novo->ants = NULL;
    novo->prox = NULL;

    if(pos<=tam_itens && pos >= 0){
        if(inicio_itens == NULL){
            inicio_itens = novo;
            fim_itens = novo;

            tam_itens ++;
        }else{
            if(pos == 0){
                novo->prox = inicio_itens;
                inicio_itens->ants = novo;
                inicio_itens = novo;

                tam_itens++;
            }else if(pos == tam_itens){
                fim_itens->prox = novo;
                novo->ants = fim_itens;
                fim_itens = novo;

                tam_itens++;
            }else{
                Itens * aux = inicio_itens;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->prox;
                }

                novo->prox = aux->prox;
                aux->prox = novo;
                novo->prox->ants = novo;
                novo->ants = aux;
                
                tam_itens++;
            }
        }
    }else{
        printf("A posição que você escolheu é inválida");
    }

}

void adicionar_inventario(char *nome, char * classe, int preco, char * descricao, int pos){

    Itens * novo = malloc(sizeof(Itens));
    novo->nome = nome;
    novo->classe = classe;
    novo -> preco = preco;
    novo->descricao = descricao;
    novo->ants = NULL;
    novo->prox = NULL;

    if(pos<=tam_inventario && pos >= 0){
        if(inicio_inventario == NULL){
            inicio_inventario = novo;
            fim_inventario = novo;

            tam_inventario ++;
        }else{
            if(pos == 0){
                novo->prox = inicio_inventario;
                inicio_inventario->ants = novo;
                inicio_inventario = novo;

                tam_inventario++;
            }else if(pos == tam_inventario){
                fim_inventario->prox = novo;
                novo->ants = fim_inventario;
                fim_inventario = novo;

                tam_inventario++;
            }else{
                Itens * aux = inicio_inventario;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->prox;
                }

                novo->prox = aux->prox;
                aux->prox = novo;
                novo->prox->ants = novo;
                novo->ants = aux;
                
                tam_inventario++;
            }
        }
    }else{
        printf("A posição que você escolheu é inválida");
    }

}

void remover_inventario(int posição){
    Itens * lixo = inicio_inventario;
    if(posição >= 0 && posição < tam_inventario){
        if(tam_inventario > 0){
            if(posição == 0){
                inicio_inventario = inicio_inventario -> prox;
                inicio_inventario -> ants = NULL;
                if(tam_inventario == 1){
                    fim_inventario = fim_inventario -> prox;
                }
                free(lixo);
                tam_inventario --;
            }
        
            else if(posição == tam_inventario -1){
                
                lixo = fim_inventario;
                fim_inventario -> ants -> prox = NULL;
                fim_inventario = fim_inventario -> ants;
                free(lixo);
                tam_inventario --;
        }
            else{
                
                Itens * aux = inicio_inventario;
                for(int i = 0; i < posição - 1; i++){
                    aux = aux -> prox;
                }
                lixo = aux -> prox;
                aux -> prox = lixo -> prox;
                lixo -> prox -> ants = aux;
                free(lixo);
                tam_inventario --;

            }}
    }
}

void listar_itens(Itens * inicio, int tam){
    Itens * aux = inicio;

    for(int i = 1; i <= tam; i++){
        printf("\n%d - %s\n", i, aux->nome);

        printf("    classe: %s\n", aux->classe);
        printf("    preço: %d\n", aux -> preco);
        printf("    descrição: %s\n\n", aux->descricao);

        aux = aux->prox;
        
    }
}

void listar_visitantes(Visitante * inicio, int tam){
    Visitante * aux = inicio;

    for(int i = 1; i <= tam; i++){
        printf("\n%d - %s\n", i, aux->nome);

        printf("    idade: %d\n", aux->idade);
        printf("    humano: %d\n", aux->humano);
        printf("    vida: %d\n", aux->vida);
        printf("    força: %d\n\n", aux->forca);

        aux = aux->prox;
        
    }
}

/* ================= INVENTARIO ================= */

// Le um inteiro com seguranca (se digitar letra, nao trava o jogo)
int ler_inteiro(){
    int n;
    if(scanf("%d", &n) != 1){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        return -1;
    }
    return n;
}

int item_e_arma(Itens *item){
    return strcmp(item->nome, "faca") == 0 ||
           strcmp(item->nome, "revolver") == 0;
}

// Coloca no inventario um item do catalogo (inicio_itens), pelo nome.
// Retorna 1 se conseguiu, 0 se cheio ou item inexistente.
int dar_item(char *nome){
    if(tam_inventario >= MAX_INVENTARIO){
        printf("\nSua mochila esta cheia! (%d/%d)\n", tam_inventario, MAX_INVENTARIO);
        return 0;
    }

    Itens *aux = inicio_itens;
    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){
            adicionar_inventario(aux->nome, aux->classe, aux->preco,
                                 aux->descricao, tam_inventario);
            printf("\nVoce guardou: %s\n", aux->nome);
            return 1;
        }
        aux = aux->prox;
    }

    printf("\nItem nao encontrado no catalogo.\n");
    return 0;
}

// Aplica o efeito do item (mesmos efeitos da batalha).
// Retorna 1 se o item foi consumido, 0 se nao foi usado.
int usar_item(Player *player, Itens *item){

    if(strcmp(item->nome, "poção de força") == 0){

        if(player->forca < 5){
            player->forca++;
            printf("\nSua forca aumentou para %d!\n", player->forca);
            return 1;
        }
        printf("\nSua forca ja esta no maximo!\n");
        return 0;

    }else if(strcmp(item->nome, "poção de velocidade") == 0){

        if(player->velocidade < 5){
            player->velocidade++;
            printf("\nSua velocidade aumentou para %d!\n", player->velocidade);
            return 1;
        }
        printf("\nSua velocidade ja esta no maximo!\n");
        return 0;

    }else if(strcmp(item->nome, "comida sintetica") == 0){

        player->vida += 20;
        if(player->vida > 50) player->vida = 50;
        printf("\nVoce recuperou 20 de HP!\n");
        return 1;

    }else if(strcmp(item->nome, "maça") == 0){

        player->vida += 15;
        player->sanidade += 10;
        if(player->vida > 50) player->vida = 50;
        if(player->sanidade > 100) player->sanidade = 100;
        printf("\nVoce recuperou 15 de HP e 10 de sanidade!\n");
        return 1;

    }else if(strcmp(item->nome, "café") == 0){

        player->sanidade += 25;
        if(player->sanidade > 100) player->sanidade = 100;
        printf("\nVoce recuperou 25 de sanidade!\n");
        return 1;
    }

    printf("\nEsse item nao pode ser usado agora.\n");
    return 0;
}

void acessar_loja(Player *jogador) {
    int escolha;
    Itens *itens_do_dia[3];
    int indices_escolhidos[3];

    //SORTEIA 3 ITENS ÚNICOS DO CATÁLOGO
    for (int i = 0; i < 3; i++) {
        int indice_aleatorio;
        int repetido;
        do {
            repetido = 0;
            indice_aleatorio = rand() % tam_itens;
            
            // VERIFICA SE ESTE ÍNDICE JÁ FOI SORTEADO HOJE
            for (int j = 0; j < i; j++) {
                if (indices_escolhidos[j] == indice_aleatorio) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);
        
        indices_escolhidos[i] = indice_aleatorio;
        
        // PERCORRE A LISTA PARA BUSCAR O ITEM CORRESPONDENTE AO ÍNDICE SORTEADO
        Itens *aux = inicio_itens;
        for (int k = 0; k < indice_aleatorio; k++) {
            aux = aux->prox;
        }
        itens_do_dia[i] = aux; // SALVA O PONTEIRO DO ITEM NO NO DO DIA
    }

    while (1) {
        printf("\n============================================================\n");
        printf("                             LOJA                       \n");
        printf("============================================================\n");
        printf("Suas Moedas: %d\n\n", jogador->moedas);
        
        // LISTA APENAS OS 3 ITENS SORTEADOS PARA O AQUELE DIA
        for (int i = 0; i < 3; i++) {
            printf("[%d] %s (%s) - %d moedas\n", i + 1, itens_do_dia[i]->nome, itens_do_dia[i]->classe, itens_do_dia[i]->preco);
            printf("    Descricao: %s\n", itens_do_dia[i]->descricao);
        }
        
        printf("\n Sair da Loja e ir dormir...\n");
        printf("------------------------------------------------------------\n");
        printf("O que deseja comprar? Selecione o numero: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("\nFechando a loja! Bom descanso...\n");
            sleep(1.5);
            break;
        }

        if (escolha >= 1 && escolha <= 3) {
            Itens *item_comprado = itens_do_dia[escolha - 1];

            if (jogador->moedas >= item_comprado->preco) {
                jogador->moedas -= item_comprado->preco;
                
                // Adiciona ao inventário
                adicionar_inventario(item_comprado->nome, item_comprado->classe, item_comprado->preco, item_comprado->descricao, tam_inventario);
                
                printf("\n>>> Sucesso! '%s' foi adicionado ao seu inventario! <<<\n", item_comprado->nome);
                sleep(2.0);
            } else {
                printf("\n>>> Moedas insuficientes! Voce precisa trabalhar melhor amanhã . <<<\n");
                sleep(2.0);
            }
        } else {
            printf("\n>>> Opcao invalida! Olhe duas vezes para o catalogo. <<<\n");
            sleep(1.5);
        }
    }
}


void abrir_inventario(Player *player){

    int opcao;
    int escolha;

    while(1){

        printf("\n============================================================\n");
        printf("                         INVENTARIO\n");
        printf("============================================================\n");

        printf("\n  Vida: %d/50        Sanidade: %d/100", player->vida, player->sanidade);
        printf("\n  Forca: %d/5        Velocidade: %d/5", player->forca, player->velocidade);
        printf("\n  Moedas: %d", player->moedas);
        printf("\n  Mochila: %d/%d\n", tam_inventario, MAX_INVENTARIO);

        printf("\n------------------------------------------------------------\n");

        if(inicio_inventario == NULL){
            printf("\n  Sua mochila esta vazia...\n");
            printf("\n------------------------------------------------------------\n");
            sleep(2);
            return;
        }

        Itens *aux = inicio_inventario;
        int i = 1;
        while(aux != NULL){
            printf("  [%d] %s", i, aux->nome);
            if(item_e_arma(aux)){
                printf("  (arma - usada em batalha)");
            }
            printf("\n");
            aux = aux->prox;
            i++;
        }

        printf("\n------------------------------------------------------------\n");
        printf("[1] Usar item\n");
        printf("[2] Ver descricao\n");
        printf("[0] Fechar inventario\n");
        printf("\nSELECIONE: ");
        opcao = ler_inteiro();

        if(opcao == 0){
            return;
        }

        if(opcao != 1 && opcao != 2){
            printf("\nOpcao invalida!\n");
            continue;
        }

        printf("\nQual item? (numero): ");
        escolha = ler_inteiro();

        if(escolha < 1 || escolha > tam_inventario){
            printf("\nItem invalido!\n");
            continue;
        }

        aux = inicio_inventario;
        for(int k = 1; k < escolha; k++){
            aux = aux->prox;
        }

        if(opcao == 2){

            printf("\n%s\n", aux->nome);
            printf("    classe: %s\n", aux->classe);
            printf("    preço: %d\n", aux->preco);
            printf("    descrição: %s\n", aux->descricao);

        }else{

            if(item_e_arma(aux)){
                printf("\nArmas so podem ser usadas durante a batalha!\n");
            }else if(usar_item(player, aux)){
                remover_inventario(escolha - 1);
            }
        }
    }
}

void processar_visitante(Visitante *visitante, Player *player) {
    int resultado = visitante->humano;

    if (resultado == 1) {
        printf("\n[ACESSO PERMITIDO] O visitante %s e um humano legitimo.\n", visitante->nome);
        player->moedas += 10;
    } else if (resultado == 0) {
        printf("\n[ALERTA] O visitante %s e uma ANOMALIA!\n", visitante->nome);
    } else {
        printf("\n[ERRO] Visitante invalido.\n");
    }
}

void batalha(Player *player, Visitante *inimigo) {

    int opcao;
    int arma;
    int dado;
    int ataque;
    int itemEscolhido;

    while (player->vida > 0 && player->sanidade > 0 && inimigo->vida > 0) {

        printf("\n============================================================\n");
        printf("                         BATALHA\n");
        printf("============================================================\n");

        printf("\nSua vida: %d/50", player->vida);
        printf("\nSua sanidade: %d/100", player->sanidade);
        printf("\nForca: %d", player->forca);
        printf("\nVelocidade: %d", player->velocidade);
        printf("\nVida da anomalia: %d", inimigo->vida);

        printf("\n\n[1] Atacar");
        printf("\n[2] Usar item");
        printf("\n\nSELECIONE: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("\n------------------------------------------------------------\n");
            printf("                         ATAQUE\n");
            printf("------------------------------------------------------------\n");

            printf("\n[1] Lutar com as maos");

            if (inicio_inventario != NULL) {
                Itens *aux = inicio_inventario;

                while (aux != NULL) {

                    if (strcmp(aux->nome, "faca") == 0) {
                        printf("\n[2] Usar faca");
                    }

                    if (strcmp(aux->nome, "revolver") == 0) {
                        printf("\n[3] Usar revolver");
                    }

                    aux = aux->prox;
                }
            }

            printf("\n\nSELECIONE: ");
            scanf("%d", &arma);

            dado = rand() % 6 + 1;

            if (arma == 1) {

                ataque = player->forca * dado;

                printf("\nVoce rolou: %d\n", dado);
                printf("Ataque com as maos: %d\n", ataque);

            } else if (arma == 2) {

                int possuiFaca = 0;
                Itens *aux = inicio_inventario;

                while (aux != NULL) {

                    if (strcmp(aux->nome, "faca") == 0) {
                        possuiFaca = 1;
                    }

                    aux = aux->prox;
                }

                if (possuiFaca == 1) {

                    ataque = (player->forca * dado) + 5;

                    printf("\nVoce rolou: %d\n", dado);
                    printf("Ataque com faca: %d\n", ataque);

                } else {

                    printf("\nVoce nao possui uma faca!\n");
                    continue;
                }

            } else if (arma == 3) {

                int possuiRevolver = 0;
                Itens *aux = inicio_inventario;

                while (aux != NULL) {

                    if (strcmp(aux->nome, "revolver") == 0) {
                        possuiRevolver = 1;
                    }

                    aux = aux->prox;
                }

                if (possuiRevolver == 1) {

                    ataque = (player->velocidade * dado) + 10;

                    printf("\nVoce rolou: %d\n", dado);
                    printf("Ataque com revolver: %d\n", ataque);

                } else {

                    printf("\nVoce nao possui um revolver!\n");
                    continue;
                }

            } else {

                printf("\nOpcao invalida!\n");
                continue;
            }

            inimigo->vida -= ataque;

            if (inimigo->vida < 0) {
                inimigo->vida = 0;
            }

            printf("Vida da anomalia: %d\n", inimigo->vida);

        } else if (opcao == 2) {

            if (inicio_inventario == NULL) {

                printf("\nVoce nao possui nenhum item!\n");
                continue;
            }

            printf("\n------------------------------------------------------------\n");
            printf("                         INVENTARIO\n");
            printf("------------------------------------------------------------\n");

            Itens *aux = inicio_inventario;
            int contador = 1;

            while (aux != NULL) {

                if (strcmp(aux->nome, "faca") != 0 &&
                    strcmp(aux->nome, "revolver") != 0) {

                    printf("[%d] %s\n", contador, aux->nome);
                    contador++;
                }

                aux = aux->prox;
            }

            printf("\nSELECIONE O ITEM: ");
            scanf("%d", &itemEscolhido);

            aux = inicio_inventario;
            contador = 1;
            int posicao_real = 0;

            while (aux != NULL) {

                if (strcmp(aux->nome, "faca") != 0 &&
                    strcmp(aux->nome, "revolver") != 0) {

                    if (contador == itemEscolhido) {
                        break;
                    }

                    contador++;
                }

                aux = aux->prox;
                posicao_real++;
            }

            if (aux == NULL) {

                printf("\nItem invalido!\n");
                continue;
            }

            if (strcmp(aux->nome, "poção de força") == 0) {

                if (player->forca < 5) {
                    player->forca++;
                    printf("\nSua forca aumentou para %d!\n", player->forca);
                    remover_inventario(posicao_real);
                } else {
                    printf("\nSua forca ja esta no maximo!\n");
                    continue;
                }

            } else if (strcmp(aux->nome, "poção de velocidade") == 0) {

                if (player->velocidade < 5) {
                    player->velocidade++;
                    printf("\nSua velocidade aumentou para %d!\n", player->velocidade);
                    remover_inventario(posicao_real);
                } else {
                    printf("\nSua velocidade ja esta no maximo!\n");
                    continue;
                }

            } else if (strcmp(aux->nome, "comida sintetica") == 0) {

                player->vida += 20;

                if (player->vida > 50) {
                    player->vida = 50;
                }

                printf("\nVoce recuperou 20 de HP!\n");
                remover_inventario(posicao_real);

            } else if (strcmp(aux->nome, "maça") == 0) {

                player->vida += 15;
                player->sanidade += 10;

                if (player->vida > 50) {
                    player->vida = 50;
                }

                if (player->sanidade > 100) {
                    player->sanidade = 100;
                }

                printf("\nVoce recuperou 15 de HP e 10 de sanidade!\n");
                remover_inventario(posicao_real);

            } else if (strcmp(aux->nome, "café") == 0) {

                player->sanidade += 25;

                if (player->sanidade > 100) {
                    player->sanidade = 100;
                }

                printf("\nVoce recuperou 25 de sanidade!\n");
                remover_inventario(posicao_real);

            } else {

                printf("\nEsse item nao pode ser usado durante a batalha.\n");
                continue;
            }


        } else {

            printf("\nOpcao invalida!\n");
            continue;
        }

        if (inimigo->vida <= 0) {

            printf("\n============================================================\n");
            printf("                  ANOMALIA DERROTADA!\n");
            printf("============================================================\n");

            break;
        }

        sleep(1.5);

        printf("\nA anomalia atacou!\n");

        player->vida -= inimigo->forca;

        player->sanidade -= inimigo->forca * 2;

        if (player->vida < 0) {
            player->vida = 0;
        }

        if (player->sanidade < 0) {
            player->sanidade = 0;
        }

        printf("Voce recebeu %d de dano!\n", inimigo->forca);
        printf("Sua vida: %d\n", player->vida);
        printf("Sua sanidade: %d\n", player->sanidade);

        sleep(1.5);

        if (player->vida <= 0) {

            printf("\n============================================================\n");
            printf("                         VOCE MORREU\n");
            printf("============================================================\n");

            break;
        }

        if (player->sanidade <= 0) {

            printf("\n============================================================\n");
            printf("                   VOCE ENLOUQUECEU\n");
            printf("============================================================\n");

            break;
        }
    }
}



int main() {

    srand(time(NULL));

    Player *player = malloc(sizeof(Player));
    player->forca = 1;
    player->velocidade = 1;
    player->vida = 50;
    player->sanidade = 100;
    player->moedas = 0;

    adicionar_itens("poção de força", "poção", 10,"uma poção que aumenta a força do usuario em 1", 0);
    adicionar_itens("poção de velocidade", "poção", 10, "uma poção que aumenta a velocidade do usuario em 1", 0);
    adicionar_itens("faca", "arma", 15, "um item essencial pra um guarda, policial e qualquer defensor publico... ou um porteiro em um mundo pós apocaliptico", 0);
    adicionar_itens("revolver", "arma", 20, "um item essencial pra um guarda, policial e qualquer defensor publico... ou um porteiro em um mundo pós apocaliptico", 0);
    adicionar_itens("comida sintetica", "comida?", 5,"a forma mais comum de conseguir nutrientes na atualidade... se isso realmente tiver algum claro(regenera 20 de hp)", 0);
    adicionar_itens("maça", "comida", 10, "uma das poucas frutas dos quais ainda se tem acesso, graças a plantação do david no terraço(regenera 15 de hp e 10 de sanidade)", 0);
    adicionar_itens("café", "poção", 5, "o combustivel de toda a humanida, ou oq sobrou dela, uma poção magica q nos permite continuar trabalhando e seguindo enfrente(regenera 25 de sanidade)", 0);

    adicionar_humano("João","branco", 1, 10, 1, 20, 0);
    adicionar_humano("Maria","branca", 1, 10, 1, 19, 0);
    adicionar_humano("Felipe","negro", 1, 10, 1, 19, 0);
    adicionar_humano("Devid","negro", 1, 10, 1, 18, 0);
    adicionar_humano("Viviane","branca", 1, 10, 1, 20, 0);
    adicionar_humano("Vitor","negro", 1, 10, 1, 19, 0);
    adicionar_humano("Guilherme","negro", 1, 10, 1, 19, 0);

    adicionar_anomalia("João","branco", 0, 10, 5, 20, 0);
    adicionar_anomalia("Maria","branca", 0, 10, 5, 19, 0);
    adicionar_anomalia("Felipe","negro", 0, 10, 5, 19, 0);
    adicionar_anomalia("Devid","negro", 0, 10, 5, 18, 0);
    adicionar_anomalia("Viviane","branca", 0, 10, 5, 20, 0);
    adicionar_anomalia("Vitor","negro", 0, 10, 5, 19, 0);
    adicionar_anomalia("Guilherme","negro", 0, 10, 5, 19, 0);
    adicionar_anomalia("João","branco", 0, 25, 10, 20, 0);
    adicionar_anomalia("Maria","branca", 0, 25, 10, 19, 0);
    adicionar_anomalia("Felipe","negro", 0, 25, 10, 19, 0);
    adicionar_anomalia("Devid","negro", 0, 25, 10, 18, 0);
    adicionar_anomalia("Viviane","branca", 0, 25, 10, 20, 0);
    adicionar_anomalia("Vitor","negro", 0, 25, 10, 19, 0);
    adicionar_anomalia("Guilherme","negro", 0, 25, 10, 19, 0);
    adicionar_anomalia("João","branco", 0, 35, 15, 20, 0);
    adicionar_anomalia("Maria","branca", 0, 35, 15, 19, 0);
    adicionar_anomalia("Felipe","negro", 0, 35, 15, 19, 0);
    adicionar_anomalia("Devid","negro", 0, 35, 15, 18, 0);
    adicionar_anomalia("Viviane","branca", 0, 35, 15, 20, 0);
    adicionar_anomalia("Vitor","negro", 0, 35, 15, 19, 0);
    adicionar_anomalia("Guilherme","negro", 0, 35, 15, 19, 0);

    while (1) {

        printf("\n\n");
        printf("============================================================\n");
        printf("                       SEJA BEM-VINDO!                      \n");
        printf("============================================================\n");
        printf("                                                            \n");
        printf("                       OLHE DUAS VEZES                      \n");
        printf("                                                            \n");
        printf("                 CONTROLE DE ACESSO - BLOCO 14              \n");
        printf("                                                            \n");
        printf("============================================================\n");
        printf("\n");
        printf("                    [1] NOVO JOGO!                          \n");
        printf("                    [2] CREDITOS                            \n");
        printf("                    [3] SAIR...                             \n");
        printf("\n");
        printf("------------------------------------------------------------\n");
        printf("SELECIONE: ");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("\nIniciando novo jogo...\n");

            sleep(3.0);

            printf("\nOlá...\n");

            sleep(1.5);

            printf("Se você está lendo isso, você se tornou o novo porteiro do Hotel Abismo..\n");

            sleep(2.5);

            printf("Seu trabalho consiste em determinar se a pessoa que solicita a entrada é um humano.\n");

            sleep(2.0);

            printf("ou..\n");

            sleep(1.5);

            printf("algo que não era para estar ali.\n");

            sleep(2.5);

            printf("\nLEMBRE-SE..\n");

            sleep(2.0);

            printf("Seu trabalho mantém você e todos os moradores vivos.\n");

            sleep(2.5);

            printf("\nAlguma duvida?\n");

            printf("[1] O que aconteceu com o antigo porteiro?\n");
            printf("[2] Quando eu comeco?\n");

            int duvida;

            printf("\nSELECIONE: ");
            scanf("%d", &duvida);

            if (duvida == 1) {

                printf("\nO que aconteceu com o antigo porteiro?\n");

                sleep(2.0);

                printf("...\n");

                sleep(2.0);

                printf("...\n");

                sleep(2.5);

                printf("Você não vai querer saber...\n");

                sleep(2.5);

            } else if (duvida == 2) {

                printf("\nQuando eu comeco?\n");

                sleep(2.0);

                printf("AGORA.\n");

                sleep(2.5);
            }

            printf("\n------------------------------------------------------------\n");
            printf("                    BLOCO 14 - HOTEL ABISMO\n");
            printf("------------------------------------------------------------\n");

            sleep(3.0);

            printf("\nSeu primeiro turno começa agora.\n");

            sleep(2.5);

            printf("A noite está apenas começando...\n\n");

            sleep(2.5);
            printf("===========================================================\n");
            printf("                    *INSTRUÇÕES*\n");
            printf("===========================================================\n");
            printf("Você possui 50 de vida!\n");
            printf("Se quiser durar as 5 noites...\n");
            sleep(2.5);
            printf("Eu recomendo que não deixe ela chegar a 0...\n");
            sleep(2.5);

            printf("------------------------------------------------------------\n");
            printf("Você possui 100 de sanidade, é muito importante você se manter lúcido, se não...\n");
            printf("você coisas estranhas podem acontecer...\n");
            sleep(2.5);

            printf("------------------------------------------------------------\n");
            printf("Sua força e velocidade começam em 1 e podem chegar a 5.\n");
            printf("Você poderá comprar na loja porções que aumentem suas habilidades em +1.\n");
            sleep(2.5);

            printf("------------------------------------------------------------\n");
            printf("Batlha:");
            printf("Algumas anomalias são agressivas, caso você as deixe entrar por engano...\n");
            printf("Você precisará enfrenta-lás.\n");
            printf("Aqui os humanos podem ser infectados por três tipos de vírus, gerando diferentes anomalias\n");
            printf("Os vírus de carga viral mais baixos geram anomalias mais simples de se combater, com 10 de vida e um dano de 5.\n");
            printf("Os vírus de carga viral medianas geram anomalias de nível médio, possuindo 25 de vida e um dano de 10.\n");
            printf("As cargas virais mais altas geram anomalias extremamente fortes e compplexas, com 35 de vida e cuidado, 15 de dano.\n");
            sleep(2.5);
            printf("------------------------------------------------------------\n");
            printf("Durante cada batalha sua vida vai diminuindo e você vai ficando mais louco\n");
            printf("A cada dano tomado, sua sanidade reduz o dobro\n");
            printf("Para atacar você precisará contar com a sorte, sua força e velocidade.\n");
            sleep(2.5);
            printf("------------------------------------------------------------\n");
            printf("CHECK-IN:\n");
            printf("PEÇA INFORMAÇÕES E ANALIZE\n");
            printf("Informações básicas: nome, idade, cidade, etnia.\n");
            printf("Com isso, cabe somente a você decidir quem entra ou não.\n");
            printf("Cuidado, a carga viral do vírus pode transformar um humano por completo.\n");
            printf("Ele pode não te entender mais\n");
            sleep(2.5);
            printf("Isso é tudo\n");
            sleep(2.5);
            printf("CUIDE-SE E CUIDE\n");
            sleep(2.5);
            printf("BOA SORTE\n");

            for(int i = 1; i != 6; i++){

                if(player->vida == 0 || player->sanidade == 0){
                    break;
                }


                printf("\n===========================================================\n");
                printf("                         DIA %d\n", i);
                printf("===========================================================\n\n");

                for(int j = 1; j != i*2+1; j++){

                    if(player->vida == 0 || player->sanidade == 0){
                        break;
                    }

                    int humano_ou_anomalia = rand() % 10 + 1;

                    printf("%dº visitante do dia\n", j);

                    if(humano_ou_anomalia >= 7){// vai ser uma anomalia atendida

                        int numero_da_anomalia = rand()%tam_anomalias;
                        int escolha = 1;

                        Visitante * anomalia = inicio_anomalias;

                        for(int i = 0; i != numero_da_anomalia; i++){
                            anomalia = anomalia->prox;
                        }

                        while(escolha){

                            if(player->vida == 0 || player->sanidade == 0){
                                break;
                            }

                            printf("\n[1] abrir inventarion\n");
                            printf("[2] falar com o visitante\n");
                            printf("[3] deichar entrar\n");
                            printf("[4] expulsalo\n");
                            scanf("%d", &escolha);
                            
                            if(escolha == 1){
                                abrir_inventario(player);
                            }else if(escolha == 2){

                                int chance_de_coerencia = rand() % 100 + 1;
                                int escolha2;

                                printf("\n[1] perguntar idade\n");
                                printf("[2] perguntar raça\n");
                                printf("[3] perguntar nome\n");
                                scanf("%d", &escolha2);

                                if(anomalia->forca == 5){

                                    if(escolha2 == 1){
                                        if(chance_de_coerencia >= 60){
                                            printf("\nfiz %d um dia desses\n", anomalia->idade);
                                        }else{
                                            printf("\neu sou bem jovem\n");
                                        }
                                    }else if(escolha2 == 2){
                                        if(chance_de_coerencia >= 60){
                                            printf("\nseus olhos são de enfeite? eu sou %s\n", anomalia->raca);
                                        }else{
                                            printf("\nhumano, obiviamente\n");
                                        }
                                    }else if(escolha2 == 3){
                                        if(chance_de_coerencia >= 60){
                                            printf("\nPode me chamar de %s\n", anomalia->nome);
                                        }else{
                                            printf("\n...\n");
                                        }
                                    }

                                }else if(anomalia->forca == 10){
                                    if(escolha2 == 1){
                                        if(chance_de_coerencia >= 30){
                                            printf("\nfiz %d um dia desses\n", anomalia->idade);
                                        }else{
                                            printf("\neu sou bem jovem\n");
                                        }
                                    }else if(escolha2 == 2){
                                        if(chance_de_coerencia >= 30){
                                            printf("\nseus olhos são de enfeite? eu sou %s\n", anomalia->raca);
                                        }else{
                                            printf("\nhumano, obiviamente\n");
                                        }
                                    }else if(escolha2 == 3){
                                        if(chance_de_coerencia >= 30){
                                            printf("\nPode me chamar de %s\n", anomalia->nome);
                                        }else{
                                            printf("\n...\n");
                                        }
                                    }
                                }else{
                                    if(escolha2 == 1){    
                                        printf("\nfiz %d um dia desses\n", anomalia->idade);
                                    }else if(escolha2 == 2){ 
                                        printf("\nseus olhos são de enfeite? eu sou %s\n", anomalia->raca);                                
                                    }else if(escolha2 == 3){
                                        printf("\nPode me chamar de %s\n", anomalia->nome);
                                    }
                                }
                                
                            }else if(escolha == 3){
                                processar_visitante(anomalia, player);
                                batalha(player, anomalia);
                                escolha = 0;
                            }else if(escolha == 4){
                                printf("\n\n vc tomou a decisão de expulsar a sangue frio o visitante, para um mundo cheio de monstros\n\n");
                                sleep(2);
                                if(anomalia->forca == 15){
                                    printf("\nE ele n parece estar nada feliz com isso...");
                                    sleep(1.5);
                                    printf("\n ELE QUEBROU AS GRADES DE SEGURANÇA!!!!\n");

                                    batalha(player, anomalia);
                                }

                                escolha = 0;
                            }else{
                                printf("\nOpcao invalida!\n");
                            }

                        }
                    }else{// é humano

                        int numero_do_humano = rand() % tam_humanos;
                        int escolha = 1;

                        Visitante * humano = inicio_humanos;

                        for(int i = 0; i != numero_do_humano; i++){
                            humano = humano->prox;
                        }

                        while(escolha){
                            printf("\n[1] abrir inventarion\n");
                            printf("[2] falar com o visitante\n");
                            printf("[3] deichar entrar\n");
                            printf("[4] expulsalo\n");
                            scanf("%d", &escolha);
                            
                            if(escolha == 1){
                                abrir_inventario(player);
                            }else if(escolha == 2){

                                int chance_de_coerencia = rand() % 100 + 1;
                                int escolha2;

                                printf("\n[1] perguntar idade\n");
                                printf("[2] perguntar raça\n");
                                printf("[3] perguntar nome\n");
                                scanf("%d", &escolha2);

                                if(escolha2 == 1){    
                                    printf("\nfiz %d um dia desses\n", humano->idade);
                                }else if(escolha2 == 2){ 
                                    printf("\nseus olhos são de enfeite? eu sou %s\n", humano->raca);                                
                                }else if(escolha2 == 3){
                                    printf("\nPode me chamar de %s\n", humano->nome);
                                }
                                
                            }else if(escolha == 3){
                                processar_visitante(humano, player);
                                escolha = 0;
                            }else if(escolha == 4){
                                printf("\n\n vc tomou a decisão de expulsar a sangue frio o visitante, para um mundo cheio de monstros\n\n");
                                
                                sleep(2);

                                escolha = 0;
                            }else{
                                printf("\nOpcao invalida!\n");
                            }

                        }
                    }



                }

                acessar_loja(player);

                printf("\nDepois de uma merecida noite de sono e uma checagem com o medico local, sua vida e sanidade se recuperam\n");

                player->vida = 50;
                player->sanidade = 100;

            }

            if(player->vida >0 && player->sanidade > 0){
                printf("\n\nPARABÉNS !!!!\n");
            printf("Graças a vc todos dentro do abrigo conseguiram sobreviver até o as anomalias serem eliminadas\n\n");

            sleep(1.5);

            printf("\n...\n");

            sleep(1.5);

            printf("\n...\n");

            sleep(1.5);

            printf("\nFIM!!!\n");
            }

            break;

        } else if (opcao == 2) {

            printf("\n\n");
            printf("============================================================\n");
            printf("                                                            \n");
            printf("                    C R É D I T O S                         \n");
            printf("                                                            \n");
            printf("============================================================\n");
            printf("\n\n");

            printf("                 O L H E   D U A S   V E Z E S\n\n");
            printf("                    UM JOGO DESENVOLVIDO POR\n\n");
            printf("                     [ EQUIPE - BLOCO 14 ]\n\n");

            printf("------------------------------------------------------------\n\n");

            printf("- DESENVOLVIMENTO:\n");
            printf("@ Deivid Lins\n");
            printf("@ Guilherme Almeida\n");
            printf("@ Luis Felipe\n");
            printf("@ Vivianne de Almeida\n");
            printf("@ Joao Emaouel\n");
            printf("@ Maria Vitoria\n\n");
            printf("@ Vitor Gabriel\n\n");

            printf("- PROGRAMACAO:\n");
            printf("@ Deivid Lins\n");
            printf("@ Joao Emanoel\n");
            printf("@ Luis Felipe\n");
            printf("@ Guilherme Almeida\n\n");
            printf("@ Vitor Gabriel\n\n");

            printf("- ROTEIRO E MECANICAS:\n");
            printf("@ Vivianne\n");
            printf("@ Maria Vitoria\n\n");

            printf("EMAIL PARA CONTATO:\n");
            printf("deividlins@alu.ufc.br");

            printf("------------------------------------------------------------\n\n");

            printf("                Obrigado por jogar nosso jogo.\n\n");

            printf("            ...mas cuidado, sempre olhe duas vezes..\n\n");

            printf("                DIGITE QUALQUER NUMERO PARA VOLTAR\n");

            int voltar;
            printf("\nSELECIONE: ");
            scanf("%d", &voltar);

        } else if (opcao == 3) {

            printf("\nSaindo...\n");
            sleep(2.0);
            break;

        } else {

            printf("\nOpcao invalida!\n");
            sleep(1.5);
        }
    }

    return 0;
}