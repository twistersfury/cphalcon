
extern zend_class_entry *phalcon_environment_adapter_phpdotenv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Environment_Adapter_PhpDotEnv);

PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, __construct);
PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, getService);
PHP_METHOD(Phalcon_Environment_Adapter_PhpDotEnv, retrieveValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_environment_adapter_phpdotenv_getservice, 0, 0, DotEnv\\DotEnv, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_environment_adapter_phpdotenv_getservice, 0, 0, IS_OBJECT, "DotEnv\\DotEnv", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_environment_adapter_phpdotenv_retrievevalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, envName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, envName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_environment_adapter_phpdotenv_method_entry) {
	PHP_ME(Phalcon_Environment_Adapter_PhpDotEnv, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Environment_Adapter_PhpDotEnv, getService, arginfo_phalcon_environment_adapter_phpdotenv_getservice, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Environment_Adapter_PhpDotEnv, retrieveValue, arginfo_phalcon_environment_adapter_phpdotenv_retrievevalue, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
