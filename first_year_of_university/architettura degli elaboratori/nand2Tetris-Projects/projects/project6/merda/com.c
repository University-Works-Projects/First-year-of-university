List callFunction(const char nameF[], const char nArgs[], int funcN, int *error)
{
    List out;
    init(&out);
    char text[256];

    if (atoiMine(nArgs) < 0)
    {
        *error = 1;
    }
    else
    {
        *error = 0;
        /*
        call f nArgs
        n-parametri devono già essere stati caricati nello stack
        in sp+1 salvo l'indirizzo di ritorno
        in sp+2 salvo LCL
        in sp+3 salvo ARG
        in sp+4 salvo THIS
        in sp+5 salvo THAT
        sposto sp a sp+5+nVars

        Es. 
        SP = 256
        nArgs = 4
        nVars = 2

        @return$nameF.funcN
        D=A   --> D = funcN
        @SP   --> 0
        A=M   --> A = RAM[0] (261)
        M=D   --> RAM[261] = D (funcN)

        @SP
        M=M+1 --> RAM[0] = RAM[0] + 1
    */
        strcpy(text, "@return$");
        strcat(text, nameF);
        strcat(text, ".");
        strcat(text, itoaMine(funcN));
        push(&out, text);

        push(&out, "D=A");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");
        push(&out, "@SP");
        push(&out, "M=M+1");

        /*    

        @LCL
        D=M   --> D = RAM[1]
        @SP
        A=M   --> A = RAM[0]
        M=D   --> RAM[A] = D

        @SP
        M=M+1 --> RAM[0] = RAM[0] + 1
    */

        push(&out, "@LCL");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");

        push(&out, "@SP");
        push(&out, "M=M+1");

        /*
        @ARG
        D=M   --> D = RAM[2]
        @SP
        A=M   --> A = RAM[0]
        M=D   --> RAM[A] = D

        @SP
        M=M+1 --> RAM[0] = RAM[0] + 1
    */

        push(&out, "@ARG");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");

        push(&out, "@SP");
        push(&out, "M=M+1");

        /*
        @THIS
        D=M   --> D = RAM[3]
        @SP
        A=M   --> A = RAM[0]
        M=D   --> RAM[A] = D

        @SP
        M=M+1 --> RAM[0] = RAM[0] + 1
    */

        push(&out, "@THIS");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");

        push(&out, "@SP");
        push(&out, "M=M+1");

        /*
        @THAT
        D=M   --> D = RAM[4]
        @SP
        A=M   --> A = RAM[0]
        M=D   --> RAM[A] = D

        @SP
        M=M+1 --> RAM[0] = RAM[0] + 1
    */

        push(&out, "@THAT");
        push(&out, "D=M");
        push(&out, "@SP");
        push(&out, "A=M");
        push(&out, "M=D");

        push(&out, "@SP");
        push(&out, "M=M+1");

        /*
        @(nArgs+5) --> 4+5 = 9
        D=A
        @SP
        D=M-D --> RAM[0] = RAM[0] - D (9)

        @ARG  --> ARG = SP-(nArgs+5)
        M=D

        @SP
        D=M

        @LCL  --> LCL = SP
        M=D

        @nameF
        0;JMP --> eseguo la funzione nameF

        (return$nameF.funcN)
    */

        int tmpArgs = atoiMine(nArgs) + 5;
        strcpy(text, "@");
        strcat(text, itoaMine(tmpArgs));
        push(&out, text);

        push(&out, "D=A");
        push(&out, "@SP");
        push(&out, "D=M-D");

        push(&out, "@ARG");
        push(&out, "M=D");

        push(&out, "@SP");
        push(&out, "D=M");

        push(&out, "@LCL");
        push(&out, "M=D");

        strcpy(text, "@");
        strcat(text, nameF);
        push(&out, text);
        push(&out, "0;JMP");

        strcpy(text, "(return$");
        strcat(text, nameF);
        strcat(text, ".");
        strcat(text, itoaMine(funcN));
        strcat(text, ")");
        push(&out, text);
    }

    return out;
}

List function(const char nameF[], const char nVars[], int *error)
{
    /*
        la definizione di mi dice il suo nome (label)
        e il numero di variabili locali
        poi imposto SP a SP+nVars

        (nameF)

        ripeti nVars volte
        @SP
        A=M  --> A = RAM[0] (256)
        M=0  --> RAM[RAM[0]] (RAM[256]) = 0
        @SP
        M=M+1
    */
    List out;
    init(&out);
    char text[256];
    int intVars = atoi(nVar

Gianmaria Rovelli, [20.01.21 16:43]
s);

    if (intVars < 0)
    {
        *error = 1;
    }
    else
    {
        *error = 0;

        strcpy(text, "(");
        strcat(text, nameF);
        strcat(text, ")");
        push(&out, text);

        for (int i = 0; i < intVars; i++)
        {
            push(&out, "@SP");
            push(&out, "A=M");
            push(&out, "M=0");
            push(&out, "@SP");
            push(&out, "M=M+1");
        }
    }

    return out;
}

List returnFunction(int *error)
{
    List out;
    init(&out);

    /*
        setto @R14 = RAM[RAM[13]-5]
        @5
        D=A
        @LCL
        A=M-D
        D=M    --> D = RAM[RAM[0]-D]
        @R14
        M=D
    */

    push(&out, "// RIPRISTINO @R14");
    push(&out, "@5");
    push(&out, "D=A");
    push(&out, "@LCL");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@R14");
    push(&out, "M=D");

    /*
        pop argument 0
        riposiziono il risultato della funzione
    */

    push(&out, "// ESEGUO IL POP ARGUMENT 0");
    List popArg0 = popCmd(NULL, "argument", "0", error);
    while (popArg0.head != NULL)
    {
        push(&out, popArg0.head->text);
        popArg0.head = popArg0.head->next;
    }
    delete (&popArg0);

    /*
        @LCL
        D=M
        @R13
        M=D   --> RAM[13] = D (RAM[1])
    */

    push(&out, "// IMPOSTO @R13 (TEMP) = LCL");
    push(&out, "@LCL");
    push(&out, "D=M");
    push(&out, "@R13");
    push(&out, "M=D");

    /*
        @ARG
        D=M
        @SP
        M=D+1
    */

    push(&out, "// IMPOSTO SP = ARG+1");
    push(&out, "@ARG");
    push(&out, "D=M");
    push(&out, "@SP");
    push(&out, "M=D+1");

    /*
        setto THAT = RAM[RAM[13]-1]
        @1
        D=A
        @R13
        A=M-D  --> A = RAM[13](317)-D(1)
        D=M    --> D = RAM[RAM[13]-1]
        @THAT
        M=D 
    */

    push(&out, "// RIPRISTINO THAT");
    push(&out, "@1");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@THAT");
    push(&out, "M=D");

    /*
        setto THIS = RAM[RAM[13]-2]
        @2
        D=A
        @R13
        A=M-D  --> A = RAM[13](317)-D(2)
        D=M    --> D = RAM[RAM[13]-2]
        @THIS
        M=D 
    */

    push(&out, "// RIPRISTINO THIS");
    push(&out, "@2");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@THIS");
    push(&out, "M=D");

    /*
        setto ARG = RAM[RAM[13]-3]
        @3
        D=A
        @R13
        A=M-D  --> A = RAM[13](317)-D(3)
        D=M    --> D = RAM[RAM[13]-3]
        @ARG
        M=D 
    */

    push(&out, "// RIPRISTINO ARG");
    push(&out, "@3");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@ARG");
    push(&out, "M=D");

    /*
        setto LCL = RAM[RAM[13]-4]
        @4
        D=A
        @R13
        A=M-D  --> A = RAM[13](317)-D(4)
        D=M    --> D = RAM[RAM[13]-4]
        @LCL
        M=D 
    */

    push(&out, "// RIPRISTINO LCL");
    push(&out, "@4");
    push(&out, "D=A");
    push(&out, "@R13");
    push(&out, "A=M-D");
    push(&out, "D=M");
    push(&out, "@LCL");
    push(&out, "M=D");

    /*
        goto RAM[RAM[14]]
        @R14
        A=M   --> A = RAM[14]
        D=M   --> D = RAM[RAM[14]]
        @R14
        M=D   --> RAM[14] = D (RAM[RAM[14]])
        0;JMP

    */

    push(&out, "@R14");
    push(&out, "A=M");
    push(&out, "0;JMP");

    return out;
}