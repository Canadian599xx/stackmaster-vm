#include <stdio.h>

enum OpCode {
    PUSH,
    ADD,
    POP,
    SUB
};


struct Instruction{
    enum OpCode op;
    int value;
    
};

struct VM
{
    
    struct Instruction instruct[10];
    int stack[10];
    int sp;
    int pc;
    int instruction_count;
};




void push(struct VM *vm, int value){
    vm->stack[vm->sp] = value;
    vm->sp++;
}

int pop(struct VM *vm){
    vm->sp--;
    return vm->stack[vm->sp];
}

void run(struct VM *vm){
    while (vm->pc < vm->instruction_count){
        struct Instruction curr_instruction = vm->instruct[vm->pc];
        enum OpCode decision = curr_instruction.op;
        
        switch(decision){
            case PUSH:{ push(vm, curr_instruction.value);
                break;}

            case POP:{ pop(vm);
                break;}

            case ADD: {
                int val1 = pop(vm);
                int val2 = pop(vm);
                int val3 = val1 + val2;
                push(vm, val3);
                break;}

            case SUB: {
                int val1 = pop(vm);
                int val2 = pop(vm);
                int val3 = val1 - val2;
                push(vm, val3);
                break;
            }
        }
        vm->pc++;
    }
    
}

int main(void){
    struct VM box;
    box.sp = 0;
    box.pc = 0;
    int i = 0;
    int decision = 1;

    while (i < 10 && (decision == 1 || decision == 2 || decision == 3 || decision == 4)){
        printf("which operation would you like to do? 1 for PUSH, 2 for POP, 3 for ADD, 4 for SUB, else exit\n");
        scanf("%d", &decision);

        if (decision == 1){
            box.instruct[i].op = PUSH;
            printf("which value would you like to add?\n");
            scanf("%d", &box.instruct[i].value);
            i++;
        }
    
        else if (decision == 2){
            box.instruct[i].op = POP;
            i++;
        }
    
        else if (decision == 3){
            box.instruct[i].op = ADD;
            i++;
        }

        else if (decision == 4){
            box.instruct[i].op = SUB;
            i++;
        }
        
    }
    printf("\n");
    
    
    box.instruction_count = i;
    run(&box);

    for ( int j = 0; j < box.sp; j++){
            printf("%d, ", box.stack[j]);
            }
}