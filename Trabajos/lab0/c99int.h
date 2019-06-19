typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
# if __WORDSIZE == 64
typedef long int		int64_t;
typedef unsigned long int	uint64_t;
# else
__extension__
typedef long long int		int64_t;
typedef unsigned long long int	uint64_t;
# endif
