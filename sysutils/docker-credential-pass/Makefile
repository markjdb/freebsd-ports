# $FreeBSD$

PORTNAME=	docker-credential-pass
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	sysutils

MAINTAINER=	dg@syrec.org
COMMENT=	Helper to use sysutils/password-store as Docker credentials store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/pass:sysutils/password-store

USES=		go

GO_PKGNAME=	github.com/docker/docker-credential-helpers
GO_TARGET=	./pass/cmd

USE_GITHUB=	yes
GH_ACCOUNT=	docker
GH_PROJECT=	docker-credential-helpers

PLIST_FILES=	bin/docker-credential-pass

pre-build:
	${LN} -s ${GO_WRKSRC}/pass/cmd/main_linux.go ${GO_WRKSRC}/pass/cmd/main_freebsd.go
	${LN} -s ${GO_WRKSRC}/pass/pass_linux.go ${GO_WRKSRC}/pass/pass_freebsd.go

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/cmd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
