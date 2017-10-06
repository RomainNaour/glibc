/* For __ARM_NEON__ memchr_neon defines memchr.  */
#ifndef __ARM_NEON__
# define memchr __memchr_noneon
# undef libc_hidden_builtin_def
# define libc_hidden_builtin_def(name)

# include <sysdeps/arm/armv6t2/memchr.S>
#endif
