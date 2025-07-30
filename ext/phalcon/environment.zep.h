
extern zend_class_entry *phalcon_environment_ce;

ZEPHIR_INIT_CLASS(Phalcon_Environment);

PHP_METHOD(Phalcon_Environment, isLoaded);
PHP_METHOD(Phalcon_Environment, __debugInfo);
PHP_METHOD(Phalcon_Environment, setValue);
PHP_METHOD(Phalcon_Environment, getValue);
PHP_METHOD(Phalcon_Environment, retrieveValue);
PHP_METHOD(Phalcon_Environment, parseValue);
PHP_METHOD(Phalcon_Environment, loadEnvironment);
zend_object *zephir_init_properties_Phalcon_Environment(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_environment_isloaded, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_environment_isloaded, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_environment_setvalue, 0, 2, Phalcon\\Environment, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_environment_setvalue, 0, 2, IS_OBJECT, "Phalcon\\Environment", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, envName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, envName)
#endif
	ZEND_ARG_INFO(0, envValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_environment_getvalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, envName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, envName)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_environment_retrievevalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, envName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, envName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_environment_parsevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_environment_loadenvironment, 0, 0, Phalcon\\Environment, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_environment_loadenvironment, 0, 0, IS_OBJECT, "Phalcon\\Environment", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_environment_method_entry) {
	PHP_ME(Phalcon_Environment, isLoaded, arginfo_phalcon_environment_isloaded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Environment, __debugInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Environment, setValue, arginfo_phalcon_environment_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Environment, getValue, arginfo_phalcon_environment_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Environment, retrieveValue, arginfo_phalcon_environment_retrievevalue, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Environment, parseValue, arginfo_phalcon_environment_parsevalue, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Environment, loadEnvironment, arginfo_phalcon_environment_loadenvironment, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
