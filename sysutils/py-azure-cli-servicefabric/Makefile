# $FreeBSD$

PORTNAME=	azure-cli-servicefabric
PORTVERSION=	0.1.20
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Service Fabric Command-Line Tools

LICENSE=	MIT

DEPRECATED=	Incorporated into azure-cli package
EXPIRATION_DATE=2019-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-graphrbac>=0.60.0:devel/py-azure-graphrbac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault>=1.1.0:devel/py-azure-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-network>=3.0.0:devel/py-azure-mgmt-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-compute>=5.0.0:devel/py-azure-mgmt-compute@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-storage>=3.3.0:devel/py-azure-mgmt-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicefabric>=0.2.0:devel/py-azure-mgmt-servicefabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-keyvault>=1.1.0:devel/py-azure-mgmt-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
