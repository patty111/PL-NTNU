#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int idx = -1;
int* stack;

void push(int val){
    stack[++idx] = val;
}

int pop(){
    if (idx == -1) return 0;
    return stack[idx--];
}

int calculate(char symbol, int num1, int num2){
    if (symbol == '+')
        return num1 + num2;
    if (symbol == '-')
        return num2 - num1;
    if (symbol == '*')
        return num1 * num2;
    if (symbol == '/')
        return num2 / num1;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    char* expn = (char*)malloc(n+1);
    scanf("%s", expn);

    stack = (int*)malloc(sizeof(int) * (n/2));

    char symbols[4] = "+-*/";

    while(*expn != '\0'){

        if (isdigit(*expn))
            push(*expn - '0');
        else {
            int a = pop();
            int b = pop();
            
            int result = calculate(*expn, a, b);
            push(result);
        }
        expn++;
    }

    printf("%d", stack[0]);
    return 0;
}