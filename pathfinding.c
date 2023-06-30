#include "php.h"

PHP_FUNCTION(pftest);

const zend_function_entry pathfinding_functions[] = {
	PHP_FE(pftest, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry pathfinding_module_entry = {
	STANDARD_MODULE_HEADER,       // #if ZEND_MODULE_API_NO >= 20010901
	"pathfinding",                       // название модуля
	pathfinding_functions,               // указываем экспортируемые функции
	NULL,                         // PHP_MINIT(test), Module Initialization
	NULL,                         // PHP_MSHUTDOWN(test), Module Shutdown
	NULL,                         // PHP_RINIT(test), Request Initialization
	NULL,                         // PHP_RSHUTDOWN(test), Request Shutdown
	NULL,                         // PHP_MINFO(test), Module Info (для phpinfo())
	"1.0",                        // версия нашего модуля
	STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(pathfinding)

PHP_FUNCTION(pftest)
{
	RETURN_STRING("Hello from cs 3", 1);
}
