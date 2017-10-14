#include <sparc-ifunc.h>

static void
__cpu_relax_generic (void)
{
  asm volatile ("rd %ccr, %g0;"
		"rd %ccr, %g0;"
		"rd %ccr, %g0");
}

static void
__cpu_relax_pause (void)
{
  asm volatile ("wr %g0, 128, %asr27;");
}

sparc_libc_ifunc (__cpu_relax,
		  hwcap & HWCAP_SPARC_PAUSE
		  ? __cpu_relax_pause
		  : __cpu_relax_generic)
