# $FreeBSD$

PORTNAME=	azure-cli-hdinsight
PORTVERSION=	0.3.5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools HDInsight Command Module

LICENSE=	MIT

DEPRECATED=	Incorporated into azure-cli package
EXPIRATION_DATE=2019-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-hdinsight>=0.2.1:devel/py-azure-mgmt-hdinsight@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-storage>=3.3.0:devel/py-azure-mgmt-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-network>=3.0.0:devel/py-azure-mgmt-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
