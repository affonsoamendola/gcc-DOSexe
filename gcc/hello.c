#pragma GCC push_options
#pragma GCC optimize ("O0")

struct EXE_HEADER 
{
	unsigned short signature; /* == 0x5a4D */
	unsigned short bytes_in_last_block;
	unsigned short blocks_in_file;
	unsigned short num_relocs;
	unsigned short header_paragraphs;
	unsigned short min_extra_paragraphs;
	unsigned short max_extra_paragraphs;
	unsigned short ss;
	unsigned short sp;
	unsigned short checksum;
	unsigned short ip;
	unsigned short cs;
	unsigned short reloc_table_offset;
	unsigned short overlay_number;
};

struct EXE_RELOC 
{
	unsigned short offset;
	unsigned short segment;
};

struct EXE_HEADER g_exe_header = 
{
	0x5a4D, //Signature, should always be 0x5A4D
	0x0000, //Bytes in last block
	0x0100, //Blocks in file.
	0x0000, //Num of relocations
	0x0200, //Header Paragraphs 
	0x0100,	//Min extra paragraphs
	0xFFFF,	//Max extra paragraphs
	0x6600, //Initial Stack Segment
	0x0000, //Initial SP (Stack Offset?)
	0x0000, //Checksum (apparently this can be left blank and ignored.)
	0x0000, //Initial IP value
	0x0000, //CS register
	0x2000, //Reloc table start offset
	0x0000  //Overlay number.
};

asm (".code16gcc\n"
     "call  main\n"
     "mov   $0x4C, %ah\n"
     "int   $0x21\n");

int main()
{
	asm volatile ("mov   $0x09, %%ah\n"
                  "int   $0x21\n"
                  : /* no output */
                  : "d"("HELLO WORLD!")
                  : "ah");

	return 0;
}

#pragma GCC pop_options