#ifndef _BLURB_
#define _BLURB_
/*

            Coda: an Experimental Distributed File System
                             Release 4.0

          Copyright (c) 1987-1996 Carnegie Mellon University
                         All Rights Reserved

Permission  to  use, copy, modify and distribute this software and its
documentation is hereby granted,  provided  that  both  the  copyright
notice  and  this  permission  notice  appear  in  all  copies  of the
software, derivative works or  modified  versions,  and  any  portions
thereof, and that both notices appear in supporting documentation, and
that credit is given to Carnegie Mellon University  in  all  documents
and publicity pertaining to direct or indirect use of this code or its
derivatives.

CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,
SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS
FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON
DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER
RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF
ANY DERIVATIVE WORK.

Carnegie  Mellon  encourages  users  of  this  software  to return any
improvements or extensions that  they  make,  and  to  grant  Carnegie
Mellon the rights to redistribute these changes without encumbrance.
*/

static char *rcsid = "$Header: /coda/coda.cs.cmu.edu/project/coda/cvs/coda/coda-src/vice/ViceErrorMsg.c,v 4.1 1998/04/14 20:55:34 braam Exp $";
#endif /*_BLURB_*/


/*

                         IBM COPYRIGHT NOTICE

                          Copyright (C) 1986
             International Business Machines Corporation
                         All Rights Reserved

This  file  contains  some  code identical to or derived from the 1986
version of the Andrew File System ("AFS"), which is owned by  the  IBM
Corporation.    This  code is provded "AS IS" and IBM does not warrant
that it is free of infringement of  any  intellectual  rights  of  any
third  party.    IBM  disclaims  liability of any kind for any damages
whatsoever resulting directly or indirectly from use of this  software
or  of  any  derivative work.  Carnegie Mellon University has obtained
permission to distribute this code, which is based on Version 2 of AFS
and  does  not  contain the features and enhancements that are part of
Version 3 of AFS.  Version 3 of  AFS  is  commercially  available  and
supported by Transarc Corporation, Pittsburgh, PA.

*/


/************************************************************************/
/*									*/
/*  ViceErrorMsg - Change a vice error code to a string			*/
/*									*/
/************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif __cplusplus

#include <errno.h>
#include <errors.h>

#include <rpc2.h>

#ifdef __cplusplus
}
#endif __cplusplus

#include <inconsist.h>

char *ViceErrorMsg(int errorCode)
{
    if(errorCode < 0)
	return(RPC2_ErrorMsg((long)errorCode));

    switch(errorCode) {
	case 0:			return("Success");
	case VSALVAGE:		return("Volume needs to be salvaged");
	case VNOVNODE:		return("Bad vnode number");
	case VNOVOL:		return("Volume not online");
	case VVOLEXISTS:	return("Volume already exists");
	case VNOSERVICE:	return("Volume is not in service");
	case VOFFLINE:		return("Volume offline");
	case VONLINE:		return("Volume is already online");
	case EPERM:		return("Not owner");
	case ENOENT:		return("No such file or directory");
	case ESRCH:		return("No such process");
	case EINTR:		return("Interupted system call");
	case EIO:		return("I/O error");
	case ENXIO:		return("No such device or address");
	case E2BIG:		return("Argument list too long");
	case ENOEXEC:		return("Exec format error");
	case EBADF:		return("Bad file number");
	case ECHILD:		return("No children");
	case EAGAIN:		return("No more processes");
	case ENOMEM:		return("Not enough storage");
	case EACCES:		return("Permission denied");
	case EFAULT:		return("Bad address");
	case ENOTBLK:		return("Block device required");
	case EBUSY:		return("Mount device busy");
	case EEXIST:		return("File already exists");
	case EXDEV:		return("Cross device link");
	case ENODEV:		return("No such device");
	case ENOTDIR:		return("Not a directory");
	case EISDIR:		return("Is a directory");
	case EINVAL:		return("Invalid argument");
	case ENFILE:		return("File table overflow");
	case EMFILE:		return("Too many open files");
	case ENOTTY:		return("Not a typewriter");
	case ETXTBSY:		return("Text file busy");
	case EFBIG:		return("File too large");
	case ENOSPC:		return("No space left on the device");
	case ESPIPE:		return("Illegal seek");
	case EROFS:		return("Read-only file system");
	case EMLINK:		return("Too many links");
	case EPIPE:		return("Broken pipe");
	case EDOM:		return("Math argument");
	case ERANGE:		return("Result too large");
#ifdef __MACH__
    case EWOULDBLOCK:	return("Operation would block");
#endif
	case EINPROGRESS:	return("Operation now in progress");
	case EALREADY:		return("Operation already in progress");
	case ENOTSOCK:		return("Socket operation on a non-socket");
	case EDESTADDRREQ:	return("Destination address required");
	case EMSGSIZE:		return("Message too long");
	case EPROTONOSUPPORT:	return("Protocol not supported");
	case EADDRINUSE:	return("Address already in use");
	case EADDRNOTAVAIL:	return("Cannot assign requested address");
	case ENETDOWN:		return("Network is down");
#ifdef __MACH__
	case ENETUNREACH:	return("Network is unreachable");
	case ENETRESET:		return("Network dropped connection on reset");
	case ECONNABORTED:	return("Software caused connection abort");
	case ECONNRESET:	return("Connection reset by peer");
	case ENOBUFS:		return("No buffer space available");
	case EISCONN:		return("Socket is already connected");
        case ENOTCONN:		return("Socket is not connected");
#endif
	case ESHUTDOWN:		return("Cannot send after socket shutdown");
	case ETIMEDOUT:		return("Connection timed out");
	case ECONNREFUSED:	return("Connection refused");
	case ELOOP:		return("Too many levels of symbolic link");
	case ENAMETOOLONG:	return("Name too long");
	case ENOTEMPTY:		return("Directory not empty");
	case EINCONS:		return("Inconsistent Object");
	default:		return("Unknown error");
    }
}
