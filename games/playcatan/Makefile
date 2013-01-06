# Created by: Mark Johnston <markj@freebsd.org>
# $FreeBSD$

PORTNAME=	playcatan
PORTVERSION=	1022
CATEGORIES=	games java
MASTER_SITES=	http://download.catan.com/en/download/
DISTNAME=	PlayCatan_3_${PORTVERSION}_eng_linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	markj@freebsd.org
COMMENT=	A Java implementation of Settlers of Catan

FETCH_ARGS=	-AFr -o ${DISTDIR}/?${DISTNAME}${EXTRACT_SUFX}

NO_BUILD=	yes
USE_JAVA=	yes

JAVA_OS=	native
JAVA_VERSION=	1.7+
JAVA_VENDOR=	openjdk

.include <bsd.port.mk>
