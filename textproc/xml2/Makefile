# Created by: Paul Chvostek <paul@it.ca>
# $FreeBSD$

PORTNAME=	xml2
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://download.ofb.net/gale/ \
		http://www.it.ca/~paul/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert between XML and a line-oriented format similar to XPath

LICENSE=	GPLv2

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	libxml2

PLIST_FILES=	bin/xml2 \
		bin/2xml \
		bin/csv2 \
		bin/2csv \
		bin/html2 \
		bin/2html

post-patch:
	@${REINPLACE_CMD} '/ln -sf/ s|$$(DESTDIR)||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
