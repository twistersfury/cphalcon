
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Environment Class To Retrieve Environment Variables (IE: getenv).
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Environment) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Environment, phalcon, environment, phalcon_di_injectable_ce, phalcon_environment_method_entry, 0);

	/** @var array */
	zend_declare_property_null(phalcon_environment_ce, SL("envVars"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/** @var bool */
	zend_declare_property_bool(phalcon_environment_ce, SL("_isLoaded"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_environment_ce->create_object = zephir_init_properties_Phalcon_Environment;
	return SUCCESS;

}

/**
 * Has environment been loaded?
 */
PHP_METHOD(Phalcon_Environment, isLoaded) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_isLoaded");

}

/**
 * Disables Debug Info
 */
PHP_METHOD(Phalcon_Environment, __debugInfo) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

/**
 * Set Environment Variable Override
 *
 * @param string envName Environment Variable To Set
 * @param string envValue Environment Variable Value
 */
PHP_METHOD(Phalcon_Environment, setValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *envName_param = NULL, *envValue, envValue_sub;
	zval envName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&envName);
	ZVAL_UNDEF(&envValue_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &envName_param, &envValue);

	zephir_get_strval(&envName, envName_param);


	zephir_update_property_array(this_ptr, SL("envVars"), &envName, envValue);
	RETURN_THIS();

}

/**
 * Retrive Environemnt Variable
 *
 * @param string envName ENV To Retrieve
 * @param mixed defaultValue Default Value If ENV Does Not Exist
 */
PHP_METHOD(Phalcon_Environment, getValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *envName_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, value;
	zval envName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&envName);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &envName_param, &defaultValue);

	zephir_get_strval(&envName, envName_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isloaded", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadenvironment", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "retrievevalue", NULL, 0, &envName);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&value) == IS_NULL)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsevalue", NULL, 105, &value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve Value.
 *
 * @param string envName ENV To Retrieve
 * @private
 * @return mixed
 */
PHP_METHOD(Phalcon_Environment, retrieveValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *envName_param = NULL, value, _0, _1$$4, _2$$4;
	zval envName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&envName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &envName_param);

	zephir_get_strval(&envName, envName_param);


	ZEPHIR_CALL_FUNCTION(&value, "getenv", NULL, 106, &envName);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("envVars"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_CCTOR(&value);
	} else if (zephir_array_isset(&_0, &envName)) {
		zephir_read_property(&_1$$4, this_ptr, SL("envVars"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$4, &_1$$4, &envName, PH_NOISY | PH_READONLY, "phalcon/Environment.zep", 82 TSRMLS_CC);
		RETURN_CTOR(&_2$$4);
	}
	ZEPHIR_INIT_NVAR(&value);
	ZVAL_NULL(&value);
	RETURN_CCTOR(&value);

}

/**
 * Parses ENV To Scalar Type If Possible
 *
 * @param string Value To Parse
 * @return mixed
 */
PHP_METHOD(Phalcon_Environment, parseValue) {

	zend_bool _0, _4, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value = NULL, value_sub, _1, _2, _3, _5, _6, _13, _7$$3, _8$$3, _9$$3, _11$$4, _12$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	_0 = zephir_fast_strlen_ev(value) > 1;
	if (_0) {
		ZVAL_LONG(&_1, 0);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(&_3);
		zephir_substr(&_3, value, 0 , 1 , 0);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "\"");
	}
	_4 = _0;
	if (_4) {
		ZVAL_LONG(&_5, -1);
		ZEPHIR_INIT_VAR(&_6);
		zephir_substr(&_6, value, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_4 = ZEPHIR_IS_STRING_IDENTICAL(&_6, "\"");
	}
	if (UNEXPECTED(_4)) {
		ZVAL_LONG(&_7$$3, 1);
		ZVAL_LONG(&_8$$3, -1);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_substr(&_9$$3, value, 1 , -1 , 0);
		ZEPHIR_CPY_WRT(value, &_9$$3);
	}
	if (zephir_is_numeric(value)) {
		_10$$4 = !ZEPHIR_IS_LONG(value, zephir_get_intval(value));
		if (!(_10$$4)) {
			ZEPHIR_INIT_VAR(&_11$$4);
			ZVAL_STRING(&_11$$4, ".");
			ZEPHIR_INIT_VAR(&_12$$4);
			zephir_fast_strpos(&_12$$4, value, &_11$$4, 0 );
			_10$$4 = !ZEPHIR_IS_FALSE_IDENTICAL(&_12$$4);
		}
		if (_10$$4) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		RETURN_MM_LONG(zephir_get_intval(value));
	}
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_strtolower(&_13, value);
	do {
		if (ZEPHIR_IS_STRING(&_13, "true") || ZEPHIR_IS_STRING(&_13, "(true)")) {
			RETURN_MM_BOOL(1);
		}
		if (ZEPHIR_IS_STRING(&_13, "false") || ZEPHIR_IS_STRING(&_13, "(false)")) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_IS_STRING(&_13, "empty") || ZEPHIR_IS_STRING(&_13, "(empty)")) {
			RETURN_MM_STRING("");
		}
		if (ZEPHIR_IS_STRING(&_13, "null") || ZEPHIR_IS_STRING(&_13, "(null)")) {
			RETURN_MM_NULL();
		}
	} while(0);

	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Loads Project Overrides
 */
PHP_METHOD(Phalcon_Environment, loadEnvironment) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("_isLoaded"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_isLoaded"), &__$false);
	}
	RETURN_THISW();

}

zend_object *zephir_init_properties_Phalcon_Environment(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("envVars"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("envVars"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

