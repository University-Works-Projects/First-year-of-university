/*
Assuming this --> STACK| x  y

VM HACK code:
gt: if x > y is true puts true in stack, else false

ASSEMBLY HACK code:
If RAM[x] > RAM[y] is true --> RAM[x] = 1, else RAM[x] = 0

So VM gt instruction is equal to: max(RAM[x], RAM[y]) in assembly (see es5.asm of assembly HACK exercices).

(We just need change the jump condition of eq or lt instructions)
*/

// Commented code

   // Move to RAM[x]
   @SP
   AM=M-1        // Go to RAM[x]
   D=M           // D = x
  
   // Move to RAM[y]
   @SP
   AM=M+1        // Now SP point to RAM[y] and we move to it
    
   // D = x - y and SP--
   D=D-M         // x -= y
   @SP           // Now SP point to RAM[y]
   AM=M-1        // Now SP point to RAM[x] and we move to it

   // if case
   @TRUE
   D;JLT         // Jump if D < 0, so only if x > y

   // else case
   M=0           // Set RAM[x] false --> RAM[x] = 0
   @CONTINUE
   0;JMP

 (TRUE)
   M=1           // Set RAM[x] true --> RAM[x] = 1

 (CONTINUE)
   @SP
   M=M+1

   // Others instructions

 (END)
   @END
   0;JMP

/* // Code for project 6
   @SP
   AM=M-1
   D=M
   @SP
   AM=M+1
   D=D-M
   @SP
   AM=M-1
   @TRUE
   D;JLT
   M=0
   @CONTINUE
   0;JMP
 (TRUE)
   M=1
 (CONTINUE)
   @SP
   M=M+1

*/