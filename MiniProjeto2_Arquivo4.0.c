//Nome:Gabriel Alves
//Uc19201924

#include <locale.h>

#include <stdlib.h>

#include <stdio.h>

#include <conio.h>

#include <ctype.h>

#include <string.h>

struct Produ {
  int cod;
  char descricao[20];
  float valor;
}
produto[10];

struct Back {
  int codB;
  char descricaoB[20];
  float valorB;
}
backup[10];

struct Clien {
  int codC;
  char descricaoC[20];
  float valorC;
}
cliente[10];

struct ClienBack {
  int codCB;
  char descricaoCB[20];
  float valorCB;
}
clienteBackup[10];

struct Car {
  int carCod, qtdeProd;
  char carDesc[20];
  float carValor;
}
Carrinho[10];

void LerArquivoPassado(char * nomeArquivo) {//Função que ler qualquer arquivo das compras do cliente
  int i, cont;
  FILE * arquivo;
  arquivo = fopen(nomeArquivo, "r");
  fscanf(arquivo, "%i", & Carrinho[0].qtdeProd);
  cont = Carrinho[0].qtdeProd;
  if (arquivo == NULL) {
    printf("Erro ao criar arquivo.");
    exit(1);
  }
  for (i = 0; i < cont; i++) {
    fscanf(arquivo, "%i %s %f", & Carrinho[i].carCod, & Carrinho[i].carDesc, & Carrinho[i].carValor);
  }

  for (i = 0; i < cont; i++) {
    printf("\nCodigo: %i\n Descrição: %s \n Valor:%.2f", Carrinho[i].carCod, Carrinho[i].carDesc, Carrinho[i].carValor);
  }
  fclose(arquivo);
}

void CriarArquivoClienteBin(int cont) {//Arquivo da struct cliente
  int i;
  FILE * arquivoClienteBin = fopen("ClienteBinario.bin", "wb");

  if (arquivoClienteBin == NULL) {
    printf("Arquivo nao pode ser aberto.");
    exit(1);
  }
  printf("Arquivo Binario Criado com sucesso!\n");
  for (i = 0; i < cont; i++) {
    if (fwrite( & cliente[i], sizeof(cliente), 1, arquivoClienteBin))
      printf("\nDados cadastrados.");
    else
      printf("\nErro no cadastro.");
  }
  fclose(arquivoClienteBin);
}
void CriarArquivoProdutos() {//arquivo da struct produto
  FILE * arquivoProd; //Declara um ponteiro do tipo FILE
  if ((arquivoProd = fopen("Produtos.txt", "w")) == NULL) {
    printf("Arquivo nao pode ser aberto.");
    exit(1);
  } else
    printf("Arquivo TEXTO foi aberto com sucesso !\n\n");
  fclose(arquivoProd); //Fechando o arquivo  			
}

void GravarArquivoProdutos(int qtde) {
  int i;
  FILE * arquivoProd;
  arquivoProd = fopen("Produtos.txt", "a");

  for (i = 0; i < qtde; i++) {
    fprintf(arquivoProd, "%i\n %s\n %f\n", produto[i].cod, produto[i].descricao, produto[i].valor);
  }

  fclose(arquivoProd);
}

void CriarArquivoBin(int qtde) {//arquivo bin da struct produto
  int i;
  FILE * arquivoBin = fopen("ProdutosBinario.bin", "wb");

  if (arquivoBin == NULL) {
    printf("Arquivo nao pode ser aberto.");
    exit(1);
  }
  printf("Arquivo Binario Criado com sucesso!\n");
  for (i = 0; i < qtde; i++) {
    if (fwrite( & produto[i], sizeof(produto), 1, arquivoBin))
      printf("\nDados cadastrados.");
    else
      printf("\nErro no cadastro.");
  }
  fclose(arquivoBin);
}

void CriarArquivo(char * nomeArquivo) {
  FILE * arquivo; //Declara um ponteiro do tipo FILE
  if ((arquivo = fopen(nomeArquivo, "w")) == NULL) {
    printf("Arquivo nao pode ser aberto.");
    exit(1);
  } else
    printf("Arquivo TEXTO foi aberto com sucesso !\n\n");
  fclose(arquivo); //Fechando o arquivo  			
}

void GravarArquivo(int cont, char * nomeArquivo) {
  int i;
  FILE * arquivo;
  arquivo = fopen(nomeArquivo, "a");
  fprintf(arquivo, "%i\n", cont);
  for (i = 0; i < cont; i++) {
    fprintf(arquivo, "%i\n %s\n %f\n", cliente[i].codC, cliente[i].descricaoC, cliente[i].valorC);
  }

  fclose(arquivo);
}

void LerArquivo(int cont, char * nomeArquivo) {//ler arquivo do cliente atual.
  int i;
  i = 0;
  FILE * arquivo;
  arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao criar arquivo.");
    exit(1);
  }
  fscanf(arquivo, "%i", & Carrinho[0].qtdeProd);
  for (i = 0; i < cont; i++) {
    fscanf(arquivo, "%i %s %f", & Carrinho[i].carCod, & Carrinho[i].carDesc, & Carrinho[i].carValor);
  }

  for (i = 0; i < cont; i++) {
    printf("\nCodigo: %i\n Descrição: %s \n Valor:%.2f", Carrinho[i].carCod, Carrinho[i].carDesc, Carrinho[i].carValor);
  }
  fclose(arquivo);
}
//--------------------------------------------------------------------------------------------------------------------------
int validaCod(int i) {
  int codigo;
  int contador, flag;
  flag = 0;
  do {
    printf("\nDigite somente números para o codigo!!\nDigite o codigo do produto:");
    scanf("%i", & codigo);
    if (codigo < 0 || codigo > 100) {
      printf("Codigo Invalido\nDigite um codigo maior que 0 e menor que 100.\n");
    }

    for (contador = 0; contador <= i; contador++) {

      if (codigo == produto[contador].cod) {
        flag = 1;
        printf("\nCodigo do produto repetido.\n");
        return (-1);
      }

    }
  } while (codigo <= 0 || codigo > 100);
  if (flag = 1) {

    return (codigo);
  }
}

char validaDesc(char * descricao) {
  do {
    printf("Digite a descrição do produto:\n");
    fflush(stdin);
    gets(descricao);
    if (strcmp(descricao, "") == 0) {
      printf("Esse campo não pode ficar em branco.\n");
    }
  } while (strcmp(descricao, "") == 0);
}

float validaPreco() {
  float preco;
  do {
    printf("Digite o preço do produto:");
    scanf("%f", & preco);
    if (preco < 0) {
      printf("O preço não pode ser negativo.\nDigite um preco maior que 0\n");
    }
  } while (preco <= 0);
  return (preco);
}

void listarProdutos(int i) {

  printf("\n\nCodigo:%i\n", produto[i].cod);
  printf("Descrição:%s\n", produto[i].descricao);
  printf("Preço:%.2f\n", produto[i].valor);
  printf("--------------------------------------\n\n");
}

void listarProdutosDoCliente(int i) {

  printf("\n\nCodigo:%i\n", cliente[i].codC);
  printf("Descrição:%s\n", cliente[i].descricaoC);
  printf("Preço:%.2f\n", cliente[i].valorC);
  printf("--------------------------------------\n\n");
}

void pesquisarProduto(int procurar, int qtde) {
  int i, result, flag;
  flag = 0;
  for (i = 0; i < qtde; i++) {
    if (procurar == produto[i].cod) {
      result = i;
      flag = 1;
    }
  }
  if (flag == 0) {
    printf("\nO produto não foi encontrado!!");

  }
  if (flag == 1) {
    listarProdutos(result);
  }
}

int filtrarProduto(int procurar, int qtde) {
  int i, result, flag;
  flag = 0;
  for (i = 0; i < qtde; i++) {
    if (procurar == produto[i].cod) {
      result = i;
      flag = 1;
    }
  }
  if (flag == 0) {
    printf("\nO produto não foi encontrado!!");

  }
  if (flag == 1) {
    listarProdutos(result);
  }
  if (flag == 1) {

    return (result);
  } else
    return (-1);
}

void atualizarProduto(int result) {
  if (result >= 0) {
    validaDesc(produto[result].descricao);
    produto[result].valor = validaPreco();
    printf("\n**Produto Alterado com sucesso**\n");
  }
}

void produtosBackup(int qtde, int i) {

  for (i = 0; i < qtde; i++) { //fazendo backup
    backup[i].codB = produto[i].cod;
    backup[i].valorB = produto[i].valor;
    strcpy(backup[i].descricaoB, produto[i].descricao);
  }

}

int deletarProduto(int result, int j, int i, int qtde) {

  if (result >= 0) {

    for (j = result; j < qtde; j++) //Excluindo fazendo a cópia para outro vetor
    {
      backup[i].codB = produto[j + 1].cod;
      backup[i].valorB = produto[j + 1].valor;
      strcpy(backup[i].descricaoB, produto[j + 1].descricao);
      printf("\n**Produto deletado com sucesso**\n");
    }
    qtde--;
  }

  if (result == -1) {
    printf("\nNão foi possivel deletar.");
  }

  return (qtde);

}

void listarProdutosCliente(int i, int qtde) {
  for (i = 0; i < qtde; i++) {
    listarProdutos(i);
  }
}

void FazerBackupCliente(int cont, int i) {

  for (i = 0; i < cont; i++) { //fazendo backup
    clienteBackup[i].codCB = cliente[i].codC;
    clienteBackup[i].valorCB = cliente[i].valorC;
    strcpy(clienteBackup[i].descricaoCB, cliente[i].descricaoC);
  }

}

int filtrarProdutoNoCarrinho(int procurar, int cont) {
  int i, result, flag;
  flag = 0;
  for (i = 0; i < cont; i++) {
    if (procurar == cliente[i].codC) {
      result = i;
      flag = 1;
    }
  }
  if (flag == 0) {
    printf("\nO produto não foi encontrado!!");

  }
  if (flag == 1) {
    listarProdutosDoCliente(result);
  }
  if (flag == 1) {

    return (result);
  } else
    return (-1);
}

int deletarProdutoDoCarrinho(int result, int j, int i, int cont) {
  int flag;
  flag = 0;
  if (result >= 0) {

    for (j = result; j < cont; j++) //Excluindo fazendo a cópia para outro vetor
    {
      clienteBackup[i].codCB = cliente[j + 1].codC;
      clienteBackup[i].valorCB = cliente[j + 1].valorC;
      strcpy(clienteBackup[i].descricaoCB, clienteBackup[j + 1].descricaoCB);
      if (flag == 0) {
        printf("\n**Produto deletado com sucesso**\n");
        flag = 1;
      }
    }
    cont--;
  }

  if (result == -1) {
    printf("\nNão foi possivel deletar.");
  }

  return (cont);

}

int adicionarProdutosCarrinho(int result, int resultado, int cont) {

  if (result >= 0) {
    cliente[cont].codC = produto[resultado].cod;
    strcpy(cliente[cont].descricaoC, produto[resultado].descricao);
    cliente[cont].valorC = produto[resultado].valor;
    cont = cont + 1;
  }
  return (cont);

}

void mostrarCarrinho(int i, int cont) {
  for (i = 0; i < cont; i++) {
    printf("Codigo:%i\n", cliente[i].codC);
    printf("Descrição:%s\n", cliente[i].descricaoC);
    printf("Preço:%.2f\n", cliente[i].valorC);
    printf("----------------------------\n");
  }
}

void pagamento(char pay, float total, char next) {

  printf("\nQual será a forma de pagamento (C) para credito ou (V) para a vista?\n");
  pay = getche();
  pay = toupper(pay);
  if (pay == 'C') {
    printf("\nTotal da compra sem desconto:%.2f\n", total);
    printf("\nAguardando efetuação do pagamento.\n");
    next = getche();
    printf("\n********Pagamento efetuado********");
  }

  if (pay == 'V') {
    total = total - (total * 0.1);
    printf("\nTotal da compra com desconto:%.2f\n", total);
    printf("\nAguardando efetuação do pagamento...\n");
    next = getche();
    printf("\n********Pagamento efetuado********\n");
  }
}

float totalCompras(float total, int cont) {
  int i;
  total = 0;
  for (i = 0; i < cont; i++) {
    total = total + cliente[i].valorC;
  }
  return (total);
}

char leValidaContinuidade(char parar) {
  do {
    printf("\nDeseja continuar S para (sim) ou N para (não)?");
    parar = getche();
    parar = toupper(parar);
    if (parar != 'S' && parar != 'N') {
      printf("\nPor favor, digite um comando valido.\nExemplo:(S) para sim ou (N) para não.\n");
    }
  } while (parar != 'S' && parar != 'N');
  return (parar);
}

char leValidaContinuidadeDeletar(char parar) {
  do {
    printf("\nDeseja tirar algum produto do carrinho?\nS para (sim) ou N para (não)?");
    parar = getche();
    parar = toupper(parar);
    if (parar != 'S' && parar != 'N') {
      printf("\nPor favor, digite um comando valido.\nExemplo:(S) para sim ou (N) para não.\n");
    }
  } while (parar != 'S' && parar != 'N');
  return (parar);
}

char leValidaContinuidadePagar(char parar) {
  do {
    printf("\nDeseja realizar o pagamento agora?\nS para (sim) ou N para (não)?\n");
    parar = getche();
    parar = toupper(parar);
    if (parar != 'S' && parar != 'N') {
      printf("\nPor favor, digite um comando valido.\nExemplo:(S) para sim ou (N) para não.\n");
    }
  } while (parar != 'S' && parar != 'N');
  return (parar);
}

char leValidaContinuidadeCriarProduto(char parar) {
  do {
    printf("\nDeseja adicionar mais 1 produto?\nS para (sim) ou N para (não)?");
    parar = getche();
    parar = toupper(parar);
    if (parar != 'S' && parar != 'N') {
      printf("\nPor favor, digite um comando valido.\nExemplo:(S) para sim ou (N) para não.\n");
    }
  } while (parar != 'S' && parar != 'N');
  return (parar);
}

int main(int argc, char * argv[]) {
  setlocale(LC_ALL, "");
  int stop, i, qtde, result, j, menu, comprar, cont, resultado, continu, valida, senha, control;
  float total;
  char next, pay, delet, parar, nomeArquivo[20];
  continu = 0;
  senha = 0;
  i = 0;
  j = 0;
  qtde = 0; //quantidade de produtos do adm
  valida = 0;
  result = 0;
  cont = 0; //quantidade de produtos do cliente
  total = 0;
  control = 0;
  int procurar;

  do {
    system("cls");
    printf("1 - Cliente\n");
    printf("2 - Administrador\n");
    printf("3 - Documento\n");
    printf("4 - Sair\n");
    scanf("%i", & menu);

    do {

      switch (menu) {

      case 1: //Cliente
        continu = 0;
        system("cls");
        printf("-----------------------Cliente-----------------------\n");
        printf("1 - Escolher produtos\n");
        printf("2 - Carrinho\n");
        printf("3 - Pagamento\n");
        printf("4 - Voltar para o menu principal\n");
        scanf("%i", & stop);

        switch (stop) {

        case 1: //Escolher produtos	
          do {
            system("cls");
            printf("-----------------------Produtos disponiveis-----------------------\n");
            listarProdutosCliente(i, qtde);
            printf("Digite o codigo do produto que deseja comprar:");
            scanf("%i", & comprar);
            system("cls");
            printf("********Produto escolhido********\n");
            resultado = filtrarProduto(comprar, qtde);
            if (resultado >= 0) {
              cont = adicionarProdutosCarrinho(result, resultado, cont);
            }
            parar = leValidaContinuidade(parar);
          } while (parar != 'N');
          continu = 5;

          break;

        case 2: //Carrinho
          system("cls");
          printf("-----------------------Carrinho-----------------------\n");
          printf("----------------------------\n");
          mostrarCarrinho(i, cont);
          total = totalCompras(total, cont);
          printf("Total:%.2f", total);
          delet = leValidaContinuidadeDeletar(parar);

          if (delet == 'S') {
            printf("\nDigite o codigo do produto que deseja Deletar:");
            scanf("%i", & procurar);
            FazerBackupCliente(cont, i);
            result = filtrarProdutoNoCarrinho(procurar, cont);
            cont = deletarProdutoDoCarrinho(result, j, i, cont);
            continu = 5;
          }
          if (delet == 'N') {
            continu = 5;
            break;
          }
          printf("\nPressione qualquer tecla para voltar para o menu principal:");
          next = getche();
          continu = 5;
          break;

        case 3: //pagamento
          system("cls");
          parar = leValidaContinuidadePagar(parar);
          if (parar == 'N') {
            printf("\nPressione qualquer tecla para voltar para o menu principal:");
            next = getche();
            continu = 5;
            break;
          }
          printf("Finalizar Compra\n");
          total = totalCompras(total, cont);
          printf("\n------------Total=%.2f------------\n", total);
          pagamento(pay, total, next);
          getche();
          system("cls");
          printf("\n-----------------------Geração de arquivo-----------------------\n");
          printf("\nDigite o nome do arquivo:");
          fflush(stdin);
          gets(nomeArquivo);
          printf("\n");
          CriarArquivo(nomeArquivo);
          GravarArquivo(cont, nomeArquivo);
          getche();
          printf("\n-------Dados sobre o cliente gravados no arquivo %s.-------\n ", nomeArquivo);
          LerArquivo(cont, nomeArquivo);
          getche();
          return (0);
          break;

        }
        break;

      case 2: //Administrador

        do {

          system("cls");
          printf("\nMenu\n");
          printf("1-Criar Produto\n");
          printf("2-Pesquisar Produto\n");
          printf("3-Atualizar Produto\n");
          printf("4-Listar Produto\n");
          printf("5-Deletar Produto\n");
          printf("6-Voltar para painel principal\n");
          printf("Escolha:\n");
          scanf("%i", & stop);

          switch (stop) {

          case 1: //Create
            system("cls");
            i = qtde;
            do {
              printf("-----------------------Criar:-----------------------\n");
              printf("Produtos Cadastrados:%i\n", i);
              valida = validaCod(i);
              if (valida > 0) {
                produto[i].cod = valida;
                validaDesc(produto[i].descricao);
                produto[i].valor = validaPreco();
              }
              if (valida < 0) {
                i = i - 1;
              }
              parar = leValidaContinuidadeCriarProduto(parar);

              system("cls");
              i = i + 1;
            } while (parar != 'N');
            qtde = i;
            stop = 9;

            break;

          case 2: //Pesquisar
            system("cls");
            printf("-----------------------Pesquisar:-----------------------\n");
            printf("Digite o codigo do produto que deseja pesquisar:");
            scanf("%i", & procurar);
            pesquisarProduto(procurar, qtde);
            printf("\nPressione qualquer tecla para voltar para o menu principal:");
            next = getche();
            stop = 9;

            break;

          case 3: //Atualizar
            system("cls");
            printf("-----------------------Atualizar:-----------------------\n");
            printf("Digite o codigo do produto que deseja Atualizar:");
            scanf("%i", & procurar);
            result = filtrarProduto(procurar, qtde);
            atualizarProduto(result);
            printf("\nPressione qualquer tecla para voltar para o menu principal:");
            next = getche();
            stop = 9;
            break;

          case 4: //Listar
            system("cls");
            printf("Listagem de todos os produtos.\n\n-----------------------");
            for (i = 0; i < qtde; i++) {
              listarProdutos(i);
            }

            printf("\nPressione qualquer tecla para voltar para o menu principal:");
            next = getche();
            system("cls");
            stop = 9;
            break;

          case 5: //delete
            system("cls");
            printf("-----------------------Deletar:-----------------------\n");
            printf("Digite o codigo do produto que deseja Deletar:");
            scanf("%i", & procurar);
            produtosBackup(qtde, i);
            result = filtrarProduto(procurar, qtde);
            qtde = deletarProduto(result, j, i, qtde);
            printf("\nPressione qualquer tecla para voltar para o menu principal:");
            next = getche();
            stop = 9;
            break;
          }
        } while (stop > 6);
        menu = 1;
        break;
      case 3:
        do {

          system("cls");
          printf("\n-----------------------Gerar Arquivo-----------------------\n");
          printf("  1 - Criar Arquivo dos produtos\n ");
          printf(" 2 - Pesquisar compras passadas\n ");
          printf(" 3 - Gerar o arquivo Binario do Cliente Atual\n ");
          printf(" 4 - Sair\n ");
          scanf("   %i", & control);

          if (control == 1) {
            printf("\n-----------------------Criar Arquivo dos produtos-----------------------\n");
            CriarArquivoProdutos();
            GravarArquivoProdutos(qtde);
            CriarArquivoBin(qtde);
            getche();
            control = 3;
          } else
          if (control == 2) {
            printf("\n-----------------------Pesquisar compras passadas-----------------------\n");
            printf("Digite o nome do arquivo.\n");
            fflush(stdin);
            gets(nomeArquivo);
            LerArquivoPassado(nomeArquivo);
            getche();
            control = 3;
          } else
          if (control == 3) {
            printf("\n-----------------Gerar o arquivo Binario do Cliente Atual-----------------\n");
            CriarArquivoClienteBin(cont);
            getche();
            control = 3;
          } else
          if (control == 4) {
            break;
          }

        } while (control < 4);
        break;

      }
    } while (continu == 5);

  } while (menu <= 5);

  return 0;
}
