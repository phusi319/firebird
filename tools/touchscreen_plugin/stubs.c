/*
 * Stubs for newlib references that nothing else provides on the
 * Ubuntu 24.04 host arm-none-eabi toolchain (newlib 4.4).
 *
 * - _fini: called by __libc_fini_array; we never run global C++ dtors.
 * - _sbrk: heap break syscall; this plugin doesn't malloc, so failing
 *   the request (returning -1) is correct/safe.
 *
 * Without these, ld errors with:
 *   libc.a(libc_a-fini.o): undefined reference to `_fini'
 *   libc.a(libc_a-sbrkr.o): undefined reference to `_sbrk'
 */
void _fini(void) {}

void *_sbrk(int incr)
{
    (void)incr;
    return (void *)-1;
}
