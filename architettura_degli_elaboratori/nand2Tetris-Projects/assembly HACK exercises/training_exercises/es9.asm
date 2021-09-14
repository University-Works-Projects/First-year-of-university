// RAM[RAM[0],...,RAM[1]] = 1,...,1 (Assuming RAM[1] > RAM[0] > 1)
// Example: RAM[RAM[0]=6, RAM[1]=10] --> RAM[6]=1, RAM[7]=1, RAM[8]=1, RAM[9]=1, RAM[10]=1

 (LOOP)
	@1
	A=M		// @A=RAM[0]
	M=1		// RAM[A]=1

	@1
	M=M-1	// RAM[1]--
	D=M		// D=RAM[1]--
	@0
	D=D-M
	@LOOP
	D;JGT
	@0
	A=M
	M=1

 (END)
	@END
	0;JMP
