#include "php.h"

static PHP_FUNCTION(pftest) {
    zval *inp;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT(inp);
    ZEND_PARSE_PARAMETERS_END();

    zend_class_entry *obj = Z_OBJCE_P(inp);

    RETURN_STR(obj->name);
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_pftest, 0, 1, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, object, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

static zend_function_entry patfinding_functions[] = {
    PHP_FE(pftest, arginfo_pftest)
    PHP_FE_END
};

zend_module_entry patfinding_module_entry = {
    STANDARD_MODULE_HEADER,
    "patfinding",
    patfinding_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "1.0.0",
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(patfinding)