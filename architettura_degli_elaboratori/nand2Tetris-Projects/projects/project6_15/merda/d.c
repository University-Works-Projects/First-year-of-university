List callFunction(const char nameF[], const char nArgs[], int funcN, int *error){
    List out;
    init(&out);
    char text[256];

    if (atoiMine(nArgs) < 0){
        *error = 1;
    }
    else {
        *error = 0;
        
        // Serve nomeFile nomeFunzione

        // push return-address
        strcpy(text, "@return$");
        strcat(text, nameF);
        strcat(text, ".");
        strcat(text, itoaMine(funcN));
        push(&out, text);
        // @return$nameFile.nameFunction ------- function nomeProgramma.nomeFunzione nArgs
        push(&out, "D=A");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        // push LCL
        push(&out, "@LCL");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        // push ARG
        push(&out, "@ARG");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        // push THIS
        push(&out, "@THIS");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        // push THAT
        push(&out, "@THAT");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        // push ARG = SP - n - 5
        int tmpArgs = atoiMine(nArgs) + 5;  // nArgs = n + 5
        strcpy(text, "@");
        strcat(text, itoaMine(tmpArgs));
        push(&out, text);   // text = @nArgs
        push(&out, "D=A");
        push(&out, "@SP");
        push(&out, "D=M-D");
        push(&out, "@ARG");
        push(&out, "M=D");

        // LCL = SP
        push(&out, "@SP");
        push(&out, "D=M");
        push(&out, "@LCL");
        push(&out, "M=D");

        // goto f
        strcpy(text, "@");              // text = @
        strcat(text, nameF);            // text = @nomeFunzione
        push(&out, text);               // @nomeFunzione
        push(&out, "0;JMP");            // 0;JMP

        // (return-address)
        strcpy(text, "(return$");
        strcat(text, nameF);
        strcat(text, ".");
        strcat(text, itoaMine(funcN));
        strcat(text, ")");
        push(&out, text);               // (return-address)
    }

    return out;
}

List function(const char nameF[], const char nVars[], int *error){
    List out;
    init(&out);
    char text[256];
    int intVars = atoi(nVars);

    if (intVars < 0){
        *error = 1;
    }
    else {
        *error = 0;

        // (functionName)
        strcpy(text, "(");
        strcat(text, nameF);
        strcat(text, ")");
        push(&out, text);

        // repeat k times
        for (int i = 0; i < intVars; i++){
            push(&out, "@SP");
            push(&out, "A=M");
            push(&out, "M=0");      // push 0 <-- inizializzi le var locali a 0
            push(&out, "@SP");
            push(&out, "M=M+1");
        }
    }

    return out;
}

List returnFunction(int *error){
    List out;
    init(&out);

    // FRAME=LCL - 5
    push(&out, "// RIPRISTINO @R14");
    push(&out, "@5");
    push(&out, "D=A");          // D = 5
    push(&out, "@LCL");
    push(&out, "A=M-D");        // @(RAM[LCL] - 5)
    push(&out, "D=M");
    // RET = FRAME              // RET = tmp var in RAM[14]
    push(&out, "@R14");
    push(&out, "M=D");

    // *ARG=pop()
    push(&out, "// ESEGUO IL POP ARGUMENT 0");
    List popArg0 = popCmd(NULL, "argument", "0", error);
    while (popArg0.head != NULL){
        push(&out, popArg0.head->text);
        popArg0.head = popArg0.head->next;
    }
    delete (&popArg0);
    push(&out, "// IMPOSTO @R13 (TEMP) = LCL");
    push(&out, "@LCL");
    push(&out, "D=M");
    push(&out, "@R13");
    push(&out, "M=D");

    // SP=ARG+1
    push(&out, "// IMPOSTO SP = ARG+1");
    push(&out, "@ARG");
    push(&out, "D=M");
    push(&out, "@SP");
    push(&out, "M=D+1");

    // THAT=*(FRAME-1)
    push(&out, "// RIPRISTINO THAT");
    push(&out, "@1");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@THAT");
    push(&out, "M=D");

    // THIS=*(FRAME-2)
    push(&out, "// RIPRISTINO THIS");
    push(&out, "@2");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@THIS");
    push(&out, "M=D");

    // ARG=*(FRAME-3)
    push(&out, "// RIPRISTINO ARG");
    push(&out, "@3");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@ARG");
    push(&out, "M=D");

    // LCL=*(FRAME-4)
    push(&out, "// RIPRISTINO LCL");
    push(&out, "@4");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@LCL");
    push(&out, "M=D");

    // goto RET     <-- a quanto pare RET è un numero
    push(&out, "@R14");
    push(&out, "A=M");          // goto @RAM[14]
    push(&out, "0;JMP");

    return out;