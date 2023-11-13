extern unsigned int __bss_start__;
extern unsigned int __bss_end__;

void init_bss() {
    unsigned int *bss_ptr = &__bss_start__;
    
    while (bss_ptr < &__bss_end__) {
        *bss_ptr = 0;
        bss_ptr++;
    }
}