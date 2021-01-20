// RAM[2] = max(RAM[0],RAM[1])
// WORK

	@0
	D=M 	// D=RAM[0]
	@1
	D=D-M 	// D -= RAM[1]
	@ELSE
	D;JLT 	// jump if(D<0)

	@0
	D=M
	@2
	M=D 	// RAM[2]=RAM[0]
	@END
	0;JMP

 (ELSE) 	// else
	@1
	D=M
	@2
	M=D 	// RAM[2]=RAM[1]

 (END)
	@END
	0;JMP