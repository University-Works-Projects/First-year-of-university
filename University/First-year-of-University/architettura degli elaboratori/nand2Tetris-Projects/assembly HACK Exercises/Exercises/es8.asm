// RAM[2] = RAM[1] nand RAM[0] (nand bit a bit)
// Assuming that RAM[0] and RAM[1] are equal to 0 or 1
// WORK

    @2
    M=0       // Clear RAM[2]=0

    @1
    D=M       // D=RAM[1]
    @0
    D=D&M     // D=RAM[1] & RAM[0]
    @FALSE
    D;JEQ

    @2
    M=0
    
    @END
    0,JMP

 (FALSE)
    @2
    M=1  
    
 (END)
    @END
    0;JMP