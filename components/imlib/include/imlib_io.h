#ifndef __IMLIB_IO__
#define __IMLIB_IO__
#ifdef __cplusplus
extern "C"
{
#endif


int imlib_printf(int level, char *fmt, ...);

#define LOG_PRINT(fmt, ...) do{\
		imlib_printf(5,fmt"  [info:%s:%d] [%s]\n", ##__VA_ARGS__, __FILE__, __LINE__, __FUNCTION__);\
}while(0);


#define ERR_PRINT(fmt, ...) do{\
		imlib_printf(0, fmt"  [info:%s:%d] [%s]\n", ##__VA_ARGS__, __FILE__, __LINE__, __FUNCTION__);\
}while(0);


#ifdef __cplusplus
}
#endif
#endif // __IMLIB_IO__




