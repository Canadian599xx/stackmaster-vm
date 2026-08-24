#include <stdio.h>

enum OpCode {
    PUSH,
    ADD,
    POP
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

            case ADD: {int val1 = pop(vm);
                int val2 = pop(vm);
                int val3 = val1 + val2;
                push(vm, val3);
                break;}
        }
        vm->pc++;
    }
    
}

int main(void){
    struct VM box;
    box.sp = 0;
    box.pc = 0;
    int i = 0;

    box.instruct[i].op = PUSH;
    box.instruct[i].value = 9;
    i++;
    box.instruct[i].op = PUSH;
    box.instruct[i].value = 2;
    i++;
    box.instruct[i].op = POP;
    i++;
    box.instruct[i].op = PUSH;
    box.instruct[i].value = 1;
    i++;
    box.instruct[i].op = ADD;
    i++;

    box.instruction_count = i;

    run(&box);
    printf("%d\n", box.stack[box.sp-1]);
}