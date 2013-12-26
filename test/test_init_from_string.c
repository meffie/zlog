/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
 *
 * Licensed under the LGPL v2.1, see the file COPYING in base directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "zlog.h"

const char *init1 =
    "[ global     ]\n"
    "strict init	= true\n"
    "buffer min = 1024\n"
    "buffer max = 2MB\n"
    "rotate lock file=		/tmp/zlog.lock\n"
    "\n"
    "[ rules ]\n"
    "my_cat.*		>stderr;\n";

int main(int argc, char** argv)
{
	int rc;

	zlog_category_t *zc;

	rc = zlog_init_from_string(init1);
	if (rc) {
		printf("init fail");
		return -2;
	}
	zc = zlog_get_category("my_cat");
	if (!zc) {
		printf("zlog_get_category fail\n");
		zlog_fini();
		return -1;
	}

	zlog_fini();

	return 0;
}
