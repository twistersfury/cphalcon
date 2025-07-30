
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalcon_Environment_Adapter_PhpDotEnv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Environment\\Adapter, PhpDotEnv, phalcon, environment_adapter_phpdotenv, phalcon_environment_ce, phalcon_environment_adapter_phpdotenv_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, __construct) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DotEnv\\DotEnv");
	if (UNEXPECTED(!(zephir_class_exists(&_0, 1 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Missing Required Composer Plugin vlucas/phpdotenv", "phalcon/Environment/Adapter/PhpDotEnv.zep", 13);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, getService) {

	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "DotEnv\\DotEnv");
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Missing Required Service DotEnv\\DotEnv", "phalcon/Environment/Adapter/PhpDotEnv.zep", 20);
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "DotEnv\\DotEnv");
	ZEPHIR_RETURN_CALL_METHOD(&_3, "get", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, retrieveValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *envName_param = NULL, value, _1$$3;
	zval envName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&envName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &envName_param);

	zephir_get_strval(&envName, envName_param);


	ZEPHIR_CALL_PARENT(&value, phalcon_environment_adapter_phpdotenv_ce, getThis(), "retrievevalue", &_0, 0, &envName);
	zephir_check_call_status();
	if (EXPECTED(Z_TYPE_P(&value) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getservice", NULL, 217);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&value, &_1$$3, "getenvironmentvariable", NULL, 0, &envName);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);

}

