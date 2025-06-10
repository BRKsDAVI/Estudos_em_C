#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

// Define códigos ANSI básicos para cores e atributos
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m" // Reseta todos os atributos
#define ANSI_BOLD           "\x1b[1m" // Negrito
#define ANSI_UNDERLINE      "\x1b[4m" // Sublinhado

// Função para configurar o console no Windows para interpretar ANSI
void setup_console_windows() {
#ifdef _WIN32
    // Para saída e entrada UTF-8 no console do Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) return;
#endif
}
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirBannerChemicalBurger() {
    // Limpar a tela (opcional, mas pode melhorar o visual do banner)
    // system("cls"); // Para Windows. system("clear") para Linux/macOS.
    // Cuidado: system() pode ter implicações de segurança e portabilidade.

    printf("\n%s%s", ANSI_BOLD, ANSI_COLOR_GREEN);
    printf("   #####   #    #  ######  #    #  #   ####    ##   #        \n");
    printf("  #     #  #    #  #       ##  ##  #  #    #  #  #  #       \n");
    printf("  #        ######  #####   # ## #  #  #      #    # #        \n");
    printf("  #        #    #  #       #    #  #  #      ###### #       \n");
    printf("  #     #  #    #  #       #    #  #  #    # #    # #       \n");
    printf("   #####   #    #  ######  #    #  #   ####  #    # ######  \n");
    printf("                                                             \n");
    printf("  #####   #    #  #####    #####  ######  #####        \n");
    printf("  #    #  #    #  #    #  #     # #       #    #      \n");
    printf("  #####   #    #  #    #  #       #####   #    #     \n");
    printf("  #    #  #    #  #####   #  #### #       #####     \n");
    printf("  #    #  #    #  #   #   #     # #       #   #       \n");
    printf("  #####    ####   #    #   #####  ######  #    #      \n");
    printf("%s\n", ANSI_COLOR_RESET);
    printf("\n%sPressione qualquer tecla para continuar...%s\n", ANSI_BOLD, ANSI_COLOR_RESET);
    getchar(); // Espera o usuário pressionar uma tecla
}

void exibirMensagemBoasVindas() {
    printf("\n%s%s", ANSI_BOLD, ANSI_COLOR_GREEN);
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*          🧪Bem-vindo(a) ao CHEMICAL BURGER🧪!           *\n");
    printf("*          Sua lanchonete de sabores explosivos!           *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("%s\n", ANSI_COLOR_RESET);
}

struct Menu {
  int codigo;
  char nome[70];
  char ingredientes[100];
  float preco;
};

struct Bebida {
  int codigo;
  char nome[30];
  float preco;
};

struct Adicionais {
  int codigo;
  char nome[70];
  float preco;
};

struct Pagamento {
  int codigo;
  char metodo[20];
};

struct Pedido {
  struct Menu comida;
  int comida_qtd;
  struct Bebida bebida;
  int bebida_qtd;
  struct Adicionais adicionais_selecionados[5]; // Permitir até 5 adicionais por item principal
  int num_adicionais_selecionados;
  struct Pagamento pagamento;
  float total_pedido_calculado; // Para armazenar o total do pedido individual
};

int escolherComida(struct Menu comidas[], int tamanho) {
  int cod, i;
  int scanf_ret;
  while (1) {
    printf("\n%s%s--- \U0001F354 MENU DE COMIDAS \U0001F354 ---%s\n", ANSI_BOLD, ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    printf("\n");
    // Cabeçalho da tabela com cores específicas por coluna
    printf("%s%s%-15s %s%-20s %s%-60s %s%s%-10s%s\n",
           ANSI_BOLD,
           ANSI_COLOR_YELLOW, "Código",
           ANSI_COLOR_GREEN, "Prato",
           ANSI_COLOR_RESET, "Ingredientes", // Cor padrão (branco no seu caso)
           ANSI_COLOR_YELLOW, "Preço",
           ANSI_COLOR_RESET); // Reset final para a linha do cabeçalho

    printf("%s------------------------------------------------------------------------------------------------------------%s\n", ANSI_BOLD, ANSI_COLOR_RESET); // Linha separadora em negrito (108 hífens)

    for (i = 0; i < tamanho; i++) {
      // Linhas de dados com cores específicas por coluna
      printf("%s%-15d %s%-20s %s%-60s %sR$ %-6.2f%s\n",
             ANSI_COLOR_YELLOW, comidas[i].codigo,
             ANSI_COLOR_GREEN, comidas[i].nome,
             ANSI_COLOR_RESET, comidas[i].ingredientes, // Cor padrão
             ANSI_COLOR_YELLOW, comidas[i].preco,
             ANSI_COLOR_RESET); // Reset no final de cada linha de dados
    }
    printf("\nEscolha uma comida (código): ");
    scanf_ret = scanf("%d", &cod);

    if (scanf_ret != 1) {
      printf("%s\u274C Entrada invalida. Por favor, digite um numero.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
      limparBufferEntrada();
      continue;
    }
    limparBufferEntrada(); // Limpar o newline restante ou caracteres extras

    for (i = 0; i < tamanho; i++)
      if (comidas[i].codigo == cod)
        return i;

    printf("%s\u274C Código inválido. Tente novamente.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
  }
}

int escolherBebida(struct Bebida bebidas[], int tamanho) {
  int cod, i;
  int scanf_ret;
  while (1) {
    printf("\n%s%s--- \U0001F964 BEBIDAS \U0001F964 ---%s\n", ANSI_BOLD, ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    printf("\n");
    // Cabeçalho da tabela de bebidas
    printf("%s%s%-10s %s%-25s %s%s%-10s%s\n",
           ANSI_BOLD,           // Negrito para todo o cabeçalho
           ANSI_COLOR_YELLOW, "Código",
           ANSI_COLOR_GREEN,  "Nome da Bebida",
           ANSI_COLOR_YELLOW, "Preço",
           ANSI_COLOR_RESET);   // Reset final para a linha do cabeçalho

    printf("%s--------------------------------------------------%s\n", ANSI_BOLD, ANSI_COLOR_RESET); // Linha separadora (47 hífens)

    for (i = 0; i < tamanho; i++)
      // Linhas de dados com cores e alinhamento
      printf("%s%-5d%s - %s%-25s%sR$ %-6.2f%s\n",
             ANSI_COLOR_YELLOW, bebidas[i].codigo,      // Código em amarelo
             ANSI_COLOR_RESET,                          // " - " em branco (cor padrão)
             ANSI_COLOR_GREEN,  bebidas[i].nome,        // Nome em verde
             ANSI_COLOR_YELLOW, bebidas[i].preco,       // Preço em amarelo
             ANSI_COLOR_RESET);                         // Reset no final da linha
    printf("Escolha uma bebida (codigo): ");
    scanf_ret = scanf("%d", &cod);

    if (scanf_ret != 1) {
      printf("%s\u274C Entrada invalida. Por favor, digite um numero.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
      limparBufferEntrada();
      continue;
    }
    limparBufferEntrada();

    for (i = 0; i < tamanho; i++)
      if (bebidas[i].codigo == cod)
        return i;

    printf("%s\u274C Código inválido. Tente novamente.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
  }
}

int escolherAdicional(struct Adicionais adicionais[], int tamanho) {
  int cod, i;
  int scanf_ret;
  while (1) {
    printf("\n%s%s--- \U0001F35F ADICIONAIS \U0001F35F ---%s\n", ANSI_BOLD, ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    printf("\n");

    printf("%s%s%-11s %s%-24s %s%s%-10s%s\n",
           ANSI_BOLD,           // Negrito para todo o cabeçalho
           ANSI_COLOR_YELLOW, "Código",
           ANSI_COLOR_GREEN,  "Nome do Adicional",
           ANSI_COLOR_YELLOW, "Preço",
           ANSI_COLOR_RESET);   // Reset final para a linha do cabeçalho
    printf("%s--------------------------------------------------%s\n", ANSI_BOLD, ANSI_COLOR_RESET); // Linha separadora (47 hífens)
    for (i = 0; i < tamanho; i++) {
      const char* nome_color = ANSI_COLOR_GREEN; // Cor padrão para o nome
      if (adicionais[i].codigo == 308) { // "NÃO QUERO ADICIONAIS"
        nome_color = ANSI_COLOR_CYAN;
      }
      // Linhas de dados com cores e alinhamento
      printf("%s%-10d%s  %s%-28s%sR$ %-15.2f%s\n",
             ANSI_COLOR_YELLOW, adicionais[i].codigo,   // Código em amarelo
             ANSI_COLOR_RESET,                          // " - " em branco (cor padrão)
             nome_color,  adicionais[i].nome,     // Nome com cor definida
             ANSI_COLOR_YELLOW, adicionais[i].preco,    // Preço em amarelo
             ANSI_COLOR_RESET);                         // Reset no final da linha
    }
    printf("Escolha um adicional (codigo): ");
    scanf_ret = scanf("%d", &cod);


    if (scanf_ret != 1) {
      printf("%s\u274C Entrada invalida. Por favor, digite um numero.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET); // Corrigido para mensagem de entrada inválida
      limparBufferEntrada();
      continue;
    }
    limparBufferEntrada();

    for (i = 0; i < tamanho; i++)
      if (adicionais[i].codigo == cod)
        return i;

    printf("%s\u274C Código inválido. Tente novamente.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
  }
}

int escolherPagamento(struct Pagamento pagamentos[], int tamanho, float totalConta) {
  int cod, i;
  int scanf_ret;
  while (1) {
    printf("\n%s%s--- \U0001F4B3 FORMAS DE PAGAMENTO \U0001F4B0 ---%s\n", ANSI_BOLD, ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    printf("\n");
    // Cabeçalho da tabela de pagamentos
    printf("%s%s%-10s %s%s%s\n",
           ANSI_BOLD,
           ANSI_COLOR_YELLOW, "Código",
           ANSI_COLOR_RESET, "Forma de Pagamento", // Cor padrão
           ANSI_COLOR_RESET);
    printf("%s------------------------------------%s\n", ANSI_BOLD, ANSI_COLOR_RESET); // Linha separadora

    for (i = 0; i < tamanho; i++)
      printf("%s%-5d%s - %s%s%s\n",
             ANSI_COLOR_YELLOW, pagamentos[i].codigo,
             ANSI_COLOR_RESET, ANSI_COLOR_RESET, pagamentos[i].metodo,
             ANSI_COLOR_RESET);

    printf("Escolha a forma de pagamento (codigo): ");
    scanf_ret = scanf("%d", &cod);

    if (scanf_ret != 1) {
      printf("%s\u274C Entrada invalida. Por favor, digite um numero.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
      limparBufferEntrada();
      continue;
    }
    limparBufferEntrada();

    for (i = 0; i < tamanho; i++) {
      if (pagamentos[i].codigo == cod) {
        printf("\n%sOpção de Pagamento Selecionada: %s%s \u2728 %s%s\n", ANSI_BOLD, ANSI_COLOR_GREEN, pagamentos[i].metodo, ANSI_COLOR_RESET, ANSI_COLOR_RESET);
        printf("%sValor Total da Compra: R$ %.2f%s\n", ANSI_BOLD, totalConta, ANSI_COLOR_RESET);

        switch (pagamentos[i].codigo) {
          case 1: // Pix
            printf("%s\U0001F4F1 Pagamento via Pix.%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
            printf("\n");
            printf("Por favor, escaneie o QR Code abaixo para pagar R$ %.2f:\n", totalConta);
            printf("\n");
            printf("%s===================================%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
            printf("%s||                                ||%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
            printf("%s||     [\U0001F4F1 QR CODE SIMULADO \U0001F4F1]    ||%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
            printf("%s||         Valor: R$ %-7.2f       ||%s\n", ANSI_COLOR_CYAN, totalConta, ANSI_COLOR_RESET);
            printf("%s||                                ||%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
            printf("%s===================================%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
            printf("%s\u2705 Pagamento confirmado (simulação).%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
            break;

          case 2: // Cartão de Crédito
            printf("%s\U0001F4B3 Pagamento com Cartão de Crédito.%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
            if (totalConta > 100.00) {
              printf("Este valor pode ser parcelado:\n");
              printf("  2x de R$ %.2f (total R$ %.2f)\n", totalConta / 2, totalConta);
              printf("  3x de R$ %.2f (total R$ %.2f)\n", totalConta / 3, totalConta);
              // Poderia adicionar uma pergunta sobre o número de parcelas aqui
            }
            printf("\n");
            printf("Processando pagamento (simulação)...\n");
            printf("%s\u2705 Pagamento aprovado (simulação).%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
            break;

          case 3: // Cartão de Débito
            printf("%s\U0001F4B3 Pagamento com Cartão de Débito.%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
            printf("\n");
            printf("Processando pagamento (simulação)...\n");
            printf("%s\u2705 Pagamento aprovado (simulação).%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
            break;

          case 4: // Dinheiro
            printf("%s\U0001F4B0 Pagamento em Dinheiro.%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
            printf("\n");
            float valorRecebido;
            while (1) {
              printf("Digite o valor recebido: R$ ");
              if (scanf("%f", &valorRecebido) == 1) {
                limparBufferEntrada();
                if (valorRecebido < totalConta) {
                  printf("%s\u274C Valor insuficiente. Faltam R$ %.2f%s\n", ANSI_COLOR_RED, totalConta - valorRecebido, ANSI_COLOR_RESET);
                } else {
                  float troco = valorRecebido - totalConta;
                  if (troco > 0.009) { // Adicionada pequena margem para evitar problemas de precisão de float
                    printf("%sTroco: R$ %.2f%s\n", ANSI_COLOR_GREEN, troco, ANSI_COLOR_RESET);
                  } else {
                    printf("%sValor exato recebido. Sem troco.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
                  }
                  printf("%s\u2705 Pagamento confirmado.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
                  break;
                }
              } else {
                printf("%s\u274C Entrada inválida. Por favor, digite um valor numérico.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                limparBufferEntrada();
              }
            }
            break;
        }
        return i; // Retorna o índice do método de pagamento escolhido
      }
    }

    printf("%s\u274C Código inválido. Tente novamente.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
  }
}

int main() {
  // Configura o locale para UTF-8.
  // Tente "C.UTF-8", "en_US.UTF-8" ou deixe "" se o sistema já estiver configurado.
  // "" usa o locale do ambiente, que pode ou não ser UTF-8.
  // "C.UTF-8" é uma opção mais portável para garantir UTF-8.
  setlocale(LC_ALL, "C.UTF-8");

  // Configura o console do Windows para ANSI e UTF-8 ANTES de qualquer saída
  // Para outros sistemas, setlocale e a configuração do terminal são chave.
#ifdef _WIN32
  setup_console_windows();
#endif

  // Exibir o banner principal e aguardar tecla
  exibirBannerChemicalBurger();

  // Exibir mensagem de boas-vindas
  exibirMensagemBoasVindas();

  struct Menu comidas[8] = {
      {101, "HIDRO-BURGER", "Pão, hambúrguer, salada e queijos ", 16.00},
      {102, "ZINCO-BURGER", "Pão, hambúrguer e cheddar ", 16.00},
      {103, "FERRO-BURGER", "Pão, hambúrguer, salada, bacon e queijo ", 18.00},
      {104, "OURO-BURGER",  "Pão, 2 hambúrgueres, cheddar e bacon ", 20.00},
      {105, "OXI-BURGER",   "Pão, hambúrguer, ovo, cheddar e salada ", 22.00},
      {106, "POTÁSSIO-BURGER", "Pão, frango empanado, ovo, salada e queijo ", 24.00}, // Exemplo com acento
      {107, "NITRO-BURGER", "Pão, hambúrguer de soja, salada ", 26.00},
      {108, "CÉSIO-BURGUER","Pão, 2 hambúrgueres, salada, queijo, ovo e bacon ", 30.00}, // Exemplo com acento
  };

  struct Bebida bebidas[4] = {
      {201, "HELIO-LARANJA", 6.00},
      {202, "CRIPRITONIO-MARACUJA", 6.00},
      {203, "COCA-COLA LATA", 5.50},
      {204, "GUARANAR LATA", 5.50},
  };

  struct Adicionais adicionais[8] = {
      {301, "HAMBÚRGUER EXTRA", 5.00}, // Exemplo com acento
      {302, "HAMBÚRGUER DE SOJA EXTRA", 5.00},
      {303, "FRANGO EMPANADO EXTRA", 5.00},
      {304, "BACON", 3.00},
      {305, "CHEDDAR EXTRA", 3.00},
      {306, "SALADA", 2.50},
      {307, "QUEIJO EXTRA", 2.00},
      {308, "NÃO QUERO ADICIONAIS", 0.00}, // Exemplo com acento
  };

  struct Pagamento pagamentos[4] = {
      {1, "Pix"},
      {2, "Cartão de Crédito"},
      {3, "Cartão de Débito"},
      {4, "Dinheiro"},
  };

  struct Pedido pedidos[100];
  unsigned int max_pedidos = sizeof(pedidos) / sizeof(pedidos[0]);
  int qtdPedidos = 0;
  char continuar[10];

  // Calcular tamanhos dos arrays de menu
  int num_comidas = sizeof(comidas) / sizeof(comidas[0]);
  int num_bebidas = sizeof(bebidas) / sizeof(bebidas[0]);
  int num_adicionais = sizeof(adicionais) / sizeof(adicionais[0]);
  int num_pagamentos = sizeof(pagamentos) / sizeof(pagamentos[0]);


  do {
    if (qtdPedidos >= max_pedidos) {
      printf("Numero maximo de pedidos (%u) atingido. Nao eh possivel adicionar mais pedidos.\n", max_pedidos);
      break;
    }

    int idxComida = escolherComida(comidas, num_comidas);
    int idxBebida = escolherBebida(bebidas, num_bebidas);
    // int idxAdicional = escolherAdicional(adicionais, num_adicionais); // Movido para dentro do loop de adicionais
    printf("\n");
    pedidos[qtdPedidos].comida = comidas[idxComida];
    printf("Quantidade para %s%s%s: ", ANSI_COLOR_GREEN, pedidos[qtdPedidos].comida.nome, ANSI_COLOR_RESET); // Emojis não são apropriados aqui para entrada
    while (scanf("%d", &pedidos[qtdPedidos].comida_qtd) != 1 || pedidos[qtdPedidos].comida_qtd <= 0) {
        printf("%s❌ Quantidade inválida. Digite um número positivo: %s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        limparBufferEntrada();
    }
    limparBufferEntrada();
    printf("\n");
    pedidos[qtdPedidos].bebida = bebidas[idxBebida];
    printf("Quantidade para %s%s%s: ", ANSI_COLOR_GREEN, pedidos[qtdPedidos].bebida.nome, ANSI_COLOR_RESET); // Emojis não são apropriados aqui para entrada
    while (scanf("%d", &pedidos[qtdPedidos].bebida_qtd) != 1 || pedidos[qtdPedidos].bebida_qtd <= 0) {
        printf("%s\u274C Quantidade inválida. Digite um número positivo: %s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        limparBufferEntrada();
    }
    limparBufferEntrada();

    // Seleção de múltiplos adicionais
    pedidos[qtdPedidos].num_adicionais_selecionados = 0;
    char add_mais_adicionais[10];
    printf("\n--- \U0001F35F Adicionar extras para %s%s%s? \U0001F35F ---\n", ANSI_COLOR_GREEN, pedidos[qtdPedidos].comida.nome, ANSI_COLOR_RESET);
    do {
        if (pedidos[qtdPedidos].num_adicionais_selecionados >= 5) {
            printf("Máximo de 5 adicionais por item atingido.\n");
            break;
        }

        int idxAdicional = escolherAdicional(adicionais, num_adicionais);

        // Se "NÃO QUERO ADICIONAIS" (308) for escolhido
        if (adicionais[idxAdicional].codigo == 308) {
            if (pedidos[qtdPedidos].num_adicionais_selecionados == 0) { // Se for a primeira "escolha" de adicional
                pedidos[qtdPedidos].adicionais_selecionados[0] = adicionais[idxAdicional]; // Armazena "NÃO QUERO"
                pedidos[qtdPedidos].num_adicionais_selecionados = 1;
            }
            break; // Sai do loop de adicionar mais adicionais
        }

        pedidos[qtdPedidos].adicionais_selecionados[pedidos[qtdPedidos].num_adicionais_selecionados] = adicionais[idxAdicional];
        pedidos[qtdPedidos].num_adicionais_selecionados++;

        if (pedidos[qtdPedidos].num_adicionais_selecionados >= 5) {
             printf("Máximo de 5 adicionais por item atingido.\n");
             break;
        }

        printf("Adicionar outro extra para %s%s%s? (sim/nao): ", ANSI_COLOR_GREEN, pedidos[qtdPedidos].comida.nome, ANSI_COLOR_RESET);
        scanf(" %s", add_mais_adicionais);
        limparBufferEntrada();
        for (int k = 0; add_mais_adicionais[k]; k++) add_mais_adicionais[k] = tolower(add_mais_adicionais[k]);
    } while (strcmp(add_mais_adicionais, "sim") == 0);

    qtdPedidos++;
    if (qtdPedidos >= max_pedidos) {
        printf("Numero maximo de pedidos atingido. Indo para o pagamento.\n");
        break;
    }

    printf("Deseja fazer outro pedido? (sim/nao): ");
    scanf(" %s", continuar); // Largura especificada e sem & para array
    limparBufferEntrada(); // Limpar qualquer entrada extra

    for (int k = 0; continuar[k]; k++) {
      continuar[k] = tolower(continuar[k]);
    }

  } while (strcmp(continuar, "sim") == 0);

  // Calcula o total geral ANTES de escolher a forma de pagamento
  float totalGeral = 0;
    for (int i = 0; i < qtdPedidos; i++) {
        // ... (cálculos de preco_comida_total, preco_adicionais_total, preco_bebida_total) ...
        // Esta parte já calcula e atribui a pedidos[i].total_pedido_calculado
        // e soma a totalGeral, o que está correto.
        float preco_comida_total = pedidos[i].comida.preco * pedidos[i].comida_qtd;
        float preco_adicionais_total = 0;

        // Soma o preço dos adicionais, apenas se não for "NÃO QUERO ADICIONAIS"
        if (!(pedidos[i].num_adicionais_selecionados == 1 && pedidos[i].adicionais_selecionados[0].codigo == 308)) {
            for (int j = 0; j < pedidos[i].num_adicionais_selecionados; j++) {
                // O preço do adicional é por item de comida principal
                preco_adicionais_total += pedidos[i].adicionais_selecionados[j].preco * pedidos[i].comida_qtd;
            }
        }
        float preco_bebida_total = pedidos[i].bebida.preco * pedidos[i].bebida_qtd;
        pedidos[i].total_pedido_calculado = preco_comida_total + preco_adicionais_total + preco_bebida_total;
        totalGeral += pedidos[i].total_pedido_calculado;
    }

  float subTotalGeral = totalGeral; // Armazena o subtotal antes de qualquer desconto
  float valorDescontoAplicado = 0.0f; // Para armazenar o valor do desconto, se houver

  // Se houver pedidos, processa o pagamento
  int idxPagamento = -1;
  if (qtdPedidos > 0) {
    char temCupom[10];
    printf("\n%sVocê possui algum cupom de desconto? (sim/nao): %s", ANSI_BOLD, ANSI_COLOR_RESET);
    scanf(" %s", temCupom);
    limparBufferEntrada();
    for (int k = 0; temCupom[k]; k++) temCupom[k] = tolower(temCupom[k]);

    if (strcmp(temCupom, "sim") == 0) {
      char cupomDigitado[50];
      printf("%sDigite o código do cupom: %s", ANSI_BOLD, ANSI_COLOR_RESET);
      scanf(" %s", cupomDigitado);
      limparBufferEntrada();
      for (int k = 0; cupomDigitado[k]; k++) cupomDigitado[k] = tolower(cupomDigitado[k]);

      if (strcmp(cupomDigitado, "cobre") == 0) {
        valorDescontoAplicado = subTotalGeral * 0.10; // Calcula desconto sobre o subTotalGeral
        totalGeral = subTotalGeral - valorDescontoAplicado;
        printf("%s\U0001F389 Cupom 'COBRE' aplicado! Desconto de R$ %.2f.%s\n", ANSI_COLOR_GREEN, valorDescontoAplicado, ANSI_COLOR_RESET);
        printf("%sNovo total da conta: R$ %.2f%s\n", ANSI_BOLD, totalGeral, ANSI_COLOR_RESET);
      } else {
        printf("%s\u274C Cupom inválido ou não encontrado.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
      }
    }

    idxPagamento = escolherPagamento(pagamentos, num_pagamentos, totalGeral);
  }

  for (int i = 0; i < qtdPedidos; i++) {
    if (idxPagamento != -1) { // Garante que um pagamento foi escolhido
      pedidos[i].pagamento = pagamentos[idxPagamento];
    } else {
      // Se nenhum pedido foi feito, ou algo deu errado, define um pagamento padrão ou lida com o erro
      // Para este exemplo, vamos apenas deixar em branco ou com um valor padrão se necessário
      // strcpy(pedidos[i].pagamento.metodo, "N/A"); // Exemplo, se fosse string
    }
  }

  printf("\n%s%s--- \u2728 CHEMICAL BURGER - RESUMO FINAL DOS PEDIDOS \u2728 ---%s\n", ANSI_BOLD, ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

  // Cabeçalho do resumo
  printf("\n%s%-10s %-18s %-10s %-15s %-18s %-10s %-28s %-28s %-18s %-10s%s\n",
         ANSI_BOLD, "Pedido", "Comida", "Qtd", "Preço Uni.", "Bebida", "Qtd", "Preço Uni.",
         "Adicionais (Preço Uni. x Qtd Comida)", "Forma Pag.", "Total Item", ANSI_COLOR_RESET);
  printf("%s%s------------------------------------------------------------------------------------------------------------------------------------------------------%s\n",
         ANSI_BOLD, ANSI_COLOR_RESET); // Removido ANSI_COLOR_BLUE desnecessário

  for (int i = 0; i < qtdPedidos; i++) {
    // Define o nome do método de pagamento para o resumo
    char metodoPagamentoStr[20] = "N/A"; // Padrão caso nenhum pagamento tenha sido processado
    if(idxPagamento != -1) strcpy(metodoPagamentoStr, pedidos[i].pagamento.metodo);

    // Monta a string de adicionais
    char adicionaisStr[200] = ""; // Buffer para a string de adicionais
    if (pedidos[i].num_adicionais_selecionados == 1 && pedidos[i].adicionais_selecionados[0].codigo == 308) {
        strcpy(adicionaisStr, pedidos[i].adicionais_selecionados[0].nome); // "NÃO QUERO ADICIONAIS"
    } else if (pedidos[i].num_adicionais_selecionados > 0) {
        for (int j = 0; j < pedidos[i].num_adicionais_selecionados; j++) {
            char tempAdicional[100];
            sprintf(tempAdicional, "%s (R$%.2f)", pedidos[i].adicionais_selecionados[j].nome, pedidos[i].adicionais_selecionados[j].preco);
            if (j > 0) strcat(adicionaisStr, ", ");
            strcat(adicionaisStr, tempAdicional);
        }
    } else {
        strcpy(adicionaisStr, "Nenhum");
    }


    printf("%-10d %-18.18s %-10d R$ %-15.2f %-18.18s %-10d R$ %-28.2f %-30.30s %-18.18s R$ %-10.2f\n",
           i + 1,
           pedidos[i].comida.nome,
           pedidos[i].comida_qtd,
           pedidos[i].comida.preco,
           pedidos[i].bebida.nome,
           pedidos[i].bebida_qtd,
           pedidos[i].bebida.preco,
           adicionaisStr,
           metodoPagamentoStr,
           pedidos[i].total_pedido_calculado);
  }
  printf("%s%s------------------------------------------------------------------------------------------------------------------------------------------------------%s\n", ANSI_BOLD, ANSI_COLOR_RESET);

  if (qtdPedidos > 0) {
    if (valorDescontoAplicado > 0.009) { // Se um desconto foi aplicado
        printf("\n%sSubtotal: R$ %.2f%s", ANSI_BOLD, subTotalGeral, ANSI_COLOR_RESET);
        printf("\n%sDesconto Cupom ('COBRE'): %s- R$ %.2f%s", ANSI_COLOR_GREEN, ANSI_BOLD, valorDescontoAplicado, ANSI_COLOR_RESET);
        printf("\n%s------------------------------------%s", ANSI_BOLD, ANSI_COLOR_RESET); // Linha separadora para o total
    }
    printf("\n%sTOTAL A PAGAR: R$ %.2f%s\n", ANSI_BOLD, totalGeral, ANSI_COLOR_RESET);
  }

  printf("\n");
  system("pause"); // Pausa para o usuário ver o resumo final
  return 0;
}
