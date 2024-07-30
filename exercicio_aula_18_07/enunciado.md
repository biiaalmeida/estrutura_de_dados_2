
# Exercício
Considere os seguintes tempos para o algoritmo abaixo:
- Chamada Recursiva: 2ns
- Retorno de chamada recursiva: 1ns
- Atribuição e soma: 0.5ns
- Divisão e multiplicação: 1.5 ns

Algoritmo:

int f(int n){
    if(n == 0){
        return 1;
    }
    return f(n-1) + 1/f(n-1);
}

Modifique o código e/ou use o gdb para calcular os tempos deste algoritmo para n = 20