
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(phalcon_0__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 0__closure, phalcon, 0__closure, phalcon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_0__closure_ce, SL("serializer"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_0__closure_ce, SL("defaultValue"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_0__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element, element_sub, defaultValue, _0, serializer, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&defaultValue, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&serializer, &_0);
	ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, element);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (ZEPHIR_IS_FALSE_IDENTICAL(element)) {
		ZEPHIR_CPY_WRT(&_1, &defaultValue);
	} else {
		ZEPHIR_CALL_METHOD(&_1, &serializer, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_1);
}

PHP_METHOD(phalcon_0__closure, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *serializer = NULL, serializer_sub, *defaultValue = NULL, defaultValue_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serializer_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(serializer)
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &serializer, &defaultValue);
	ZEPHIR_SEPARATE_PARAM(serializer);
	ZEPHIR_SEPARATE_PARAM(defaultValue);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(serializer, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(defaultValue, &_0);
	ZEPHIR_MM_RESTORE();
}

