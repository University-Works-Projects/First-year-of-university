// RAM[10] = max(RAM[9],RAM[8],...,RAM[0])

	@10
	D=A
	@11
	M=D		// RAM[11]=10
	@0
	D=M		// D=RAM[0]
	@10
	M=D		// RAM[10]=RAM[0]

 (LOOP)
	@11
	M=M-1
	A=M		// @A=@RAM[11]--
	D=M		// D=RAM[A]
	@10
	D=D-M	// D-=RAM[10]
	@ELSE
	D;JGT

	@11
	M=M-1
	D=M
	@LOOP
	D;JGT
 (END)
	@END
	0;JMP

 (ELSE)
	@11
	A=M
	D=M
	@10
	M=D

	@11
	M=M-1
	D=M
	@LOOP
	D;JGT
 (END)
	@END
	0;JMP
