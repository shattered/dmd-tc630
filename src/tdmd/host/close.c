/*       Copyright (c) 1987 AT&T   */
/*       All Rights Reserved       */

/*       THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T   */
/*       The copyright notice above does not evidence any      */
/*       actual or intended publication of such source code.   */


static char _2Vsccsid[]="@(#)close.c	1.1.1.3	(11/13/87)";

#include "jplot.h"
#include <termio.h>

void
closepl()
{
	extern struct termio
		cooked, fcooked			/* cooked tty modes */
	;

	move((int)porigx, (int)(porigy - (36 - porigy)/scaley + porigy));
	finish();
	(void)ioctl(tojerq, TCSETAW, &cooked);
	(void)ioctl(fromjerq, TCSETAW, &fcooked);
}
