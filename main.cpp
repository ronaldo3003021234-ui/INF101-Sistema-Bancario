#include <iostream>
#include <string>

using namespace std;

int main() {
    // 2.1 Dados das contas (Capacidade máxima: 100 contas)
    const int MAX_CONTAS = 100;      // const: defini um valor fixo que não pode ser alterado
    int numeroConta[MAX_CONTAS];     // Armazena os números das contas
    string nomeCliente[MAX_CONTAS];  // Armazena os nomes dos titulares
    string cpf[MAX_CONTAS];          // Armazena os CPFs dos titulares 
    int tipoConta[MAX_CONTAS];       // Define o tipo (1 = Corrente, 2 = Poupança)
    double saldo[MAX_CONTAS];        // Armazena os saldos atuais das contas
    bool contaAtiva[MAX_CONTAS];     // Status das contas (true = ativa, false = desativada)
    int quantidadeContas = 0;        // Controla quantas contas foram cadastradas
    
    // 2.2 Histórico de movimentações (Capacidade máxima: 500 movimentações)
    const int MAX_MOVIMENTACOES = 500;
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;

    int opcao = 0;           // Armazena a opção escolhida pelo usuário no menu
    
    /*O programa utiliza um loop do-while para exibir o menu repetidamente até
    que o usuário decida sair (escolhendo a opção 9)*/
    do {
        cout << "\n=================================\n";
        cout << "         BANCO INF101            \n";
        cout << "=================================\n";
        cout << "1. Cadastrar conta\n";
        cout << "2. Listar contas\n";
        cout << "3. Consultar conta pelo numero\n";
        cout << "4. Realizar deposito\n";
        cout << "5. Realizar saque\n";
        cout << "6. Realizar transferencia\n";
        cout << "7. Exibir extrato\n";
        cout << "8. Ativar/Desativar conta\n";
        cout << "9. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

/*O switch-case é uma estrutura de controle de fluxo em C++ (e em várias outras linguagens)
usada para substituir múltiplos if-else if quando você precisa comparar uma única
variável contra vários valores constantes possíveis.*/
        
        switch (opcao) { // switch-case: para controlar o fluxo de operações, ele direciona para uma das operações.
            case 1: {
                cout << "\n--- CADASTRAR CONTA ---\n";
                
                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite maximo de contas atingido!\n";
                    break;
                }

                int numTemp;
                cout << "Digite o numero da conta (maior que 0): ";
                cin >> numTemp;
                if (numTemp <= 0) {
                    cout << "Numero de conta invalido!\n";
                    
/*O break interrompe imediatamente a execução do loop (como while ou for) ou de um
bloco de controle (switch), fazendo o programa continuar a partir da linha logo após essa estrutura.*/                    
                    break;
                }

                // Verificar se a conta já existe
                bool encontrada = false;
                // bool serve para armazenar duas possiveis situações, se é verdadeiro ou falso.
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numTemp) {
                        encontrada = true;
                        break;
                    }
                }

                if (encontrada) {
                    cout << "Ja existe uma conta cadastrada com este numero!\n";
                    break;
                }

                numeroConta[quantidadeContas] = numTemp;

                cin.ignore(); // Limpa o buffer do teclado para ler texto
                cout << "Digite o nome do cliente: ";
                getline(cin, nomeCliente[quantidadeContas]); // lê a linha inteira de texto

                cout << "Digite o CPF: ";
                getline(cin, cpf[quantidadeContas]);

                cout << "Digite o tipo de conta (1-Corrente, 2-Poupanca): ";
                cin >> tipoConta[quantidadeContas];
                if (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                    cout << "Tipo de conta invalido!\n";
                    break;
                }

                cout << "Digite o saldo inicial: ";
                cin >> saldo[quantidadeContas];
                if (saldo[quantidadeContas] < 0) {
                    cout << "Saldo inicial nao pode ser negativo!\n";
                    break;
                }

                contaAtiva[quantidadeContas] = true;
                quantidadeContas++;
                cout << "Conta cadastrada com sucesso!\n";
                break;
            }

            case 2: {
                cout << "\n--- LISTA DE CONTAS ---\n";
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada no momento.\n";
                } else {
                    for (int i = 0; i < quantidadeContas; i++) {
                        cout << "---------------------------\n";
                        cout << "Numero da Conta: " << numeroConta[i] << "\n";
                        cout << "Cliente: " << nomeCliente[i] << "\n";
                        cout << "CPF: " << cpf[i] << "\n";
                        cout << "Tipo: " << (tipoConta[i] == 1 ? "Corrente" : "Poupanca") << "\n";
                        cout << "Saldo: R$ " << saldo[i] << "\n";
                        cout << "Status: " << (contaAtiva[i] ? "Ativa" : "Inativa") << "\n";
                    }
                }
                break;
            }

            case 3: {
                cout << "\n--- CONSULTAR CONTA ---\n";
                int buscaNum;
                cout << "Digite o numero da conta que deseja consultar: ";
                cin >> buscaNum;

                int indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == buscaNum) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                } else {
                    cout << "Numero da Conta: " << numeroConta[indice] << "\n";
                    cout << "Cliente: " << nomeCliente[indice] << "\n";
                    cout << "CPF: " << cpf[indice] << "\n";
                    cout << "Tipo: " << (tipoConta[indice] == 1 ? "Corrente" : "Poupanca") << "\n";
                    cout << "Saldo atual: R$ " << saldo[indice] << "\n";
                    cout << "Status: " << (contaAtiva[indice] ? "Ativa" : "Inativa") << "\n";
                }
                break;
            }

            case 4: {
                cout << "\n--- REALIZAR DEPOSITO ---\n";
                int buscaNum;
                cout << "Digite o numero da conta: ";
                cin >> buscaNum;

                int indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == buscaNum) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta inativa ou nao encontrada.\n";
                    break;
                }

                double valor;
                cout << "Digite o valor do deposito: ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido para deposito!\n";
                    break;
                }

                // Atualiza o saldo e registra a movimentação
                saldo[indice] = saldo[indice] + valor;
                if (quantidadeMovimentacoes < MAX_MOVIMENTACOES) {
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;
                }

                cout << "Deposito realizado com sucesso!\n";
                break;
            }

            case 5: {
                cout << "\n--- REALIZAR SAQUE ---\n";
                int buscaNum;
                cout << "Digite o numero da conta: ";
                cin >> buscaNum;

                int indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == buscaNum) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta inativa ou nao encontrada.\n";
                    break;
                }

                double valor;
                cout << "Digite o valor do saque: ";
                cin >> valor;

                if (valor <= 0 || valor > saldo[indice]) {
                    cout << "Valor invalido ou saldo insuficiente!\n";
                    break;
                }

                // Atualiza o saldo e registra a movimentação
                saldo[indice] = saldo[indice] - valor;
                if (quantidadeMovimentacoes < MAX_MOVIMENTACOES) {
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;
                }

                cout << "Saque realizado com sucesso!\n";
                break;
            }

            case 6: {
                cout << "\n--- REALIZAR TRANSFERENCIA ---\n";
                int numOrigem, numDestino;
                cout << "Digite o numero da conta de origem: ";
                cin >> numOrigem;
                cout << "Digite o numero da conta de destino: ";
                cin >> numDestino;

                int idxOrigem = -1, idxDestino = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numOrigem) idxOrigem = i;
                    if (numeroConta[i] == numDestino) idxDestino = i;
                }

                if (idxOrigem == -1 || !contaAtiva[idxOrigem] || idxDestino == -1 || !contaAtiva[idxDestino]) {
                    cout << "Uma das contas nao foi encontrada ou esta inativa.\n";
                    break;
                }

                double valor;
                cout << "Digite o valor da transferencia: ";
                cin >> valor;

                if (valor <= 0 || valor > saldo[idxOrigem]) {
                    cout << "Valor invalido ou saldo insuficiente na conta de origem!\n";
                    break;
                }

                if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                    cout << "Espaco insuficiente para registrar as movimentacoes!\n";
                    break;
                }

                // Atualiza saldos
                saldo[idxOrigem] = saldo[idxOrigem] - valor;
                saldo[idxDestino] = saldo[idxDestino] + valor;

                // Registra os dois movimentos (Saída na origem e Entrada no destino)
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[idxOrigem];
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;

                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[idxDestino];
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;

                cout << "Transferencia realizada com sucesso!\n";
                break;
            }

            case 7: {
                cout << "\n--- EXTRATO DA CONTA ---\n";
                int buscaNum;
                cout << "Digite o numero da conta: ";
                cin >> buscaNum;

                bool encontrada = false;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == buscaNum) {
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada) {
                    cout << "Conta nao encontrada.\n";
                    break;
                }

                cout << "\nMovimentacoes para a conta " << buscaNum << ":\n";
                bool temMov = false;
                for (int i = 0; i < quantidadeMovimentacoes; i++) {
                    if (contaMovimentacao[i] == buscaNum) {
                        temMov = true;
                        if (tipoMovimentacao[i] == 'D') {
                            cout << "  [Deposito] R$ " << valorMovimentacao[i] << "\n";
                        } else if (tipoMovimentacao[i] == 'S') {
                            cout << "  [Saque] R$ " << valorMovimentacao[i] << "\n";
                        }
                    }
                }
                if (!temMov) {
                    cout << "  Nenhuma movimentacao registrada para esta conta.\n";
                }
                break;
            }

            case 8: {
                cout << "\n--- ATIVAR / DESATIVAR CONTA ---\n";
                int buscaNum;
                cout << "Digite o numero da conta: ";
                cin >> buscaNum;

                int indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == buscaNum) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                } else {
                    contaAtiva[indice] = !contaAtiva[indice];
                    cout << "Status da conta alterado para: " 
                         << (contaAtiva[indice] ? "ATIVA" : "INATIVA") << "\n";
                }
                break;
            }

            case 9:
                cout << "\nEncerrando o programa... Ate logo!\n";
                break;

            default: /* executado caso o valor da variavel não corresponda
                a nenhuma das opções dos cases anteriores.*/
                
                cout << "\nOpcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 9);

    return 0;
}
