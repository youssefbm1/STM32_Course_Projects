MEMORY
{
  FLASH (wx) : ORIGIN = 0x08000000, LENGTH = 1M
  SRAM1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
  SRAM2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
}

ENTRY(_start)

SECTIONS
{
  .text :
  {
    *(.text)
  } > SRAM1

  .rodata :
  {
    *(.rodata)
  } > SRAM1

  .data :
  {
    *(.data)
  } > SRAM1
  .bss :
  {
    *(.bss) *(COMMON)
  } > SRAM1
}

