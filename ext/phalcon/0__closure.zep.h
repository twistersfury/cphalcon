
extern zend_class_entry *phalcon_0__closure_ce;

ZEPHIR_INIT_CLASS(phalcon_0__closure);

PHP_METHOD(phalcon_0__closure, __invoke);
PHP_METHOD(phalcon_0__closure, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_0__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_0__closure___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, serializer)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_0__closure_method_entry) {
	PHP_ME(phalcon_0__closure, __invoke, arginfo_phalcon_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(phalcon_0__closure, __construct, arginfo_phalcon_0__closure___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};
