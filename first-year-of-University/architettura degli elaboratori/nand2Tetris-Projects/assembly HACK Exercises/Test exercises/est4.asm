// es4 test
// Assembly HACK code:
// Exercise: Translate a C program (see INDEX.txt)
// Assuming that RAM[0] = i and RAM[1] = j.
// WORK

    @0
    D=M
    @1
    D=D-M   // D = RAM[0] - RAM[0]
    @JWIN
    D;JGE   // if i > j jump

    // if i > j is false
    @5
    D=A     // D = 5
    @1
    M=M-D   // j -= 5
    @END
    0;JMP

 (JWIN)     // if i > j is true
    @1
    D=M     // D = j
    @0
    M=M+D   // i += j

 (END)
    @END
    0;JMP
