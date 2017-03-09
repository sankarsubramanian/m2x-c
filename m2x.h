/** @file m2x.h
 *  @brief Wrapper for <a href="https://m2x.att.com/developer/documentation/v2/overview">AT&T M2X API</a>
 */

/*! \mainpage C toolkit for the <a href="https://m2x.att.com/developer/documentation/v2/overview">AT&T M2X API</a>
 *
 * View the <a href="https://github.com/attm2x/m2x-c/blob/master/README.md">M2X C Client README</a> for usage details
 *
 * All methods in this client library require an API Key for authentication. There are multiple types of API Keys which provide granular access to your M2X resources. Please review the <a href="https://m2x.att.com/developer/documentation/v2/overview#API-Keys">API Keys documentation</a> for more details on the different types of keys available
 *
 * If an invalid API Key is utilized, you will receive the following error when calling client methods:
 *
 * ```javascript
 * >>>client.method(...)
 * Traceback (most recent call last):
 * ...
 * requests.exceptions.HTTPError: 401 Client Error: Unauthorized
 * ```
 */
#ifndef M2X_H
#define M2X_H

#include <curl/curl.h>

#include "config.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct m2x_context {
  CURL *curl;
  struct curl_slist *headers;
  int verbose;
  int expand_json;
} m2x_context;

m2x_context *m2x_open(const char *key);
void m2x_close(m2x_context *ctx);

void m2x_set_verbose(m2x_context *ctx, int verbose);

void *m2x_malloc(m2x_context *ctx, size_t len);
void *m2x_realloc(m2x_context *ctx, void *p, size_t len);
void m2x_free(void *p);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_H */
