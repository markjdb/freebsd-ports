# Created by: Adriaan de Groot <groot@kde.org>
# $FreeBSD$

PORTNAME=	libmal
PORTVERSION=	0.44.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.jlogday.com/code/libmal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library encapsulating malsync

LICENSE=	MPL10
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	obsolete technology
EXPIRATION_DATE=	2019-09-21

LIB_DEPENDS=	libpisock.so:palm/pilot-link

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pilot-prefix=${LOCALBASE}
USE_LDCONFIG=	yes
CONFLICTS=	malsync-[0-9]*
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
