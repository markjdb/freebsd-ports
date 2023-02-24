PORTNAME=	kutrace-kmod
PORTVERSION=	20230223
CATEGORIES=	devel kld

MAINTAINER=	markj@FreeBSD.org
COMMENT=	Kernel module for the KUtrace tracing framework
WWW=		https://github.com/dicksites/KUtrace

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	markjdb
GH_PROJECT=	KUtrace
GH_TAGNAME=	20230223

BUILD_WRKSRC=	${WRKSRC}/freebsd/module
INSTALL_WRKSRC=	${WRKSRC}/freebsd/module

MAKE_ENV+=	MAKEOBJDIRPREFIX=${WRKSRC}/freebsd/obj

pre-build:
	${MKDIR} ${WRKSRC}/obj
	(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} obj)

.include <bsd.port.mk>
