#ifndef CPPAPI_C_HEADER_ERROR_H
#define CPPAPI_C_HEADER_ERROR_H

typedef struct
{
	const char* function;
	const char* message;
} cppapi_error;

#ifdef __cplusplus
extern "C"
{
#endif

	cppapi_error cppapi_get_last_error();
	int cppapi_set_last_error(cppapi_error error);
	
#ifdef __cplusplus
}
#endif

#define CPPAPI_C_ERROR(message, error_id)				\
{														\
	cppapi_set_last_error({ __func__, message });		\
	return error_id;									\
}

#endif