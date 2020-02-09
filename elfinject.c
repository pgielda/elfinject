///////////////////////////////////////////////////////
//
// (c) 2020 Antmicro <www.antmicro.com>
//
// License: Apache 2.0
//
///////////////////////////////////////////////////////

#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int __libc_start_main(int *(main) (int, char **, char **), int argc, char ** ubp_av, void (*init) (void), void (*fini) (void), void (*rtld_fini) (void), void (* stack_end)) {
        static int (*original_libc_start_main)(int *(main) (int, char **, char **), int argc, char ** ubp_av, void (*init) (void), void (*fini) (void), void (*rtld_fini) (void), void (* stack_end)) = NULL;
	puts("We are now in __lib_cstart_main!\n");

	//// enter main binary
	original_libc_start_main = dlsym(RTLD_NEXT, "__libc_start_main");
	return (*original_libc_start_main)(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

