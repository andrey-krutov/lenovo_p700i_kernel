/* vi: set sw=4 ts=4: */
/*
 * Utility routines.
 *
 * Copyright (C) 2007 Denys Vlasenko
 *
 * Licensed under GPLv2, see file LICENSE in this source tree.
 */

#include "libbb.h"

const char*  bb_basename(const char *name)
{
	const char *cp = strrchr(name, '/');
	if (cp)
		return cp + 1;
	return name;
}
