#include <ctype.h>
#include <stdarg.h>
#include <string.h>

#include "m2x.h"

size_t m2x_internal_encode_string(char *dst, const char *src)
{
  static const char *HEX = "0123456789ABCDEF";
  size_t len, i;

  for (i = 0, len = 0; src[i] != 0; i++) {
    if (isalnum(src[i]) ||
        (src[i] == '-') || (src[i] == '_') ||
        (src[i] == '.') || (src[i] == '~')) {
      if (dst) { dst[len] = src[i]; }
      len++;
    } else {
      if (dst) {
        dst[len] = '%';
        dst[len + 1] = HEX[src[i] / 16];
        dst[len + 2] = HEX[src[i] % 16];
      }
      len += 3;
    }
  }
  if (dst) { dst[len] = '\0'; }
  return len;
}

size_t m2x_internal_get_encoded_length(const char *src)
{
  return m2x_internal_encode_string(NULL, src);
}

char *m2x_internal_get_encoded_string(m2x_context *ctx, const char *str)
{
  size_t len;
  char *ret;

  len = m2x_internal_encode_string(NULL, str);
  ret = (char *) m2x_malloc(ctx, len + 1);
  m2x_internal_encode_string(ret, str);

  return ret;
}

int m2x_internal_encoded_sprintf(char *dst, const char *fmt, ...)
{
  int i, len;
  va_list vl;

  i = len = 0;
  va_start(vl, fmt);
  while (fmt[i] != '\0') {
    if ((fmt[i] == '%') && (fmt[i + 1] == 's')) {
      len += m2x_internal_encode_string(dst + len, va_arg(vl, const char *));
      i += 2;
    } else {
      if (dst) {
        dst[len] = fmt[i];
        dst[len + 1] = '\0';
      }
      len++;
      i++;
    }
  }
  va_end(vl);
  return len;
}
