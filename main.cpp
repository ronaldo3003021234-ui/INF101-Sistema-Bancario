#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variáveis da conta
    int numeroConta = 0;
    string nomeCliente = "";
    string cpf = "";
    int tipoConta = 0; // 1 = Corrente, 2 = Poupança
    double saldo = 0.0;
    bool contaAtiva = false;
    
    int opcao = 0;

    do {
        cout << "\n=================================\n";
        cout << "         BANCO INF101            \n";
        cout << "=================================\n";
        cout << "1. Cadastrar conta\n";
        cout << "2. Consultar conta\n";
        cout << "3. Verificar saldo\n";
        cout << "4. Alterar tipo da conta\n";
        cout << "5. Ativar/Desativar conta\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) { // switch/case: para controlar o fluxo de operações 
        
            case 1:
                cout << "\n--- CADASTRAR CONTA ---\n";
                
                cout << "Digite o numero da conta (maior que 0): ";
                cin >> numeroConta;
                if (numeroConta <= 0) {
                    cout << "Numero de conta invalido!\n";
                    break;
                }

                cin.ignore(); // Limpa o buffer do teclado para ler texto
                cout << "Digite o nome do cliente: ";
                getline(cin, nomeCliente);

                cout << "Digite o CPF: ";
                getline(cin, cpf);

                cout << "Digite o tipo de conta (1-Corrente, 2-Poupanca): ";
                cin >> tipoConta;
                if (tipoConta != 1 && tipoConta != 2) {
                    cout << "Tipo de conta invalido!\n";
                    break;
                }

                cout << "Digite o saldo inicial: ";
                cin >> saldo;
                if (saldo < 0) {
                    cout << "Saldo inicial nao pode ser negativo!\n";
                    break;
                }

                contaAtiva = true;
                cout << "Conta cadastrada com sucesso!\n";
                break;

            case 2:
                cout << "\n--- CONSULTAR CONTA ---\n";
                if (!contaAtiva) { // if para verificar o estado "ativo" ou "Inativa"
                    cout << "Nenhuma conta ativa cadastrada no momento.\n";
                } else {
                    cout << "Numero da Conta: " << numeroConta << "\n";
                    cout << "Cliente: " << nomeCliente << "\n";
                    cout << "CPF: " << cpf << "\n";
                    cout << "Tipo: " << (tipoConta == 1 ? "Corrente" : "Poupanca") << "\n";
                    cout << "Status: " << (contaAtiva ? "Ativa" : "Inativa") << "\n";
                }
                break;

            case 3:
                cout << "\n--- VERIFICAR SALDO ---\n";
                if (!contaAtiva) {
                    cout << "Conta inativa ou nao cadastrada.\n";
                } else {
                    cout << "Saldo atual: R$ " << saldo << "\n";
                }
                break;

            case 4:
                cout << "\n--- ALTERAR TIPO DA CONTA ---\n";
                if (!contaAtiva) {
                    cout << "Conta inativa ou nao cadastrada.\n";
                } else {
                    cout << "Tipo atual: " << (tipoConta == 1 ? "Corrente" : "Poupanca") << "\n";
                    cout << "Digite o novo tipo (1-Corrente, 2-Poupanca): ";
                    cin >> tipoConta;
                    if (tipoConta == 1 || tipoConta == 2) {
                        cout << "Tipo de conta alterado com sucesso!\n";
                    } else {
                        cout << "Opcao invalida. Mantido o tipo anterior.\n";
                    }
                }
                break;

            case 5:
                cout << "\n--- ATIVAR / DESATIVAR CONTA ---\n";
                if (numeroConta == 0) {
                    cout << "Nenhuma conta cadastrada para alterar o status.\n";
                } else {
                    contaAtiva = !contaAtiva;
                    cout << "Status da conta alterado para: " 
                         << (contaAtiva ? "ATIVA" : "INATIVA") << "\n";
                }
                break;

            case 6:
                cout << "\nEncerrando o programa... Ate logo!\n";
                break;

            default:
                cout << "\nOpcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 6);

    return 0;
}
