OUTPUT_FORMAT(binary)
SECTIONS
{
	. = 0x0100;

	.data :
	{
		*(.data);
		*(.bss);
		*(.rodata);	
	}

	.text :
	{
		*(.text);
	}
	
	heap = ALIGN(4);
}