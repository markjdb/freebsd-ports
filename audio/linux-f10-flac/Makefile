PORTNAME=	flac
PORTVERSION=	1.2.1
CATEGORIES=	audio linux
MASTER_SITES=	http://archives.fedoraproject.org/pub/archive/fedora/linux/releases/10/Fedora/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Free lossless audio codec

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	4.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libFLAC.so.8 usr/lib/libFLAC.so.8.2.0 \
		usr/lib/libFLAC++.so.6 usr/lib/libFLAC++.so.6.2.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.* README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
