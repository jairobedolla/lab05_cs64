#include "DecodeCode.h"


mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = value & 0x3F;
	if ((value & (1 << 15)) >> 15){
		instr.immediate = ((value & 0xFFFF) | 0xFFFF0000);
	}	
	else{
		instr.immediate = value & 0xFFFF;
	}
	instr.rd = (value & (0x1F << 11)) >> 11;
	instr.rt = (value & (0x1F << 16)) >> 16;
	instr.rs = (value & (0x1F << 21)) >> 21;
	instr.opcode = (value & (0x3F << 26)) >> 26;

	return instr;
}


