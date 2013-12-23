#ifndef M2X_CLIENT_H
#define M2X_CLIENT_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct m2x_context {
  CURL *curl;
  struct curl_slist *headers;
} m2x_context;

m2x_context *m2x_open(const char *key);
void m2x_close(m2x_context *ctx);

int m2x_client_get(m2x_context *ctx, const char *path, char **out);
int m2x_client_post(m2x_context *ctx, const char *path, const char *data, char **out);
int m2x_client_put(m2x_context *ctx, const char *path, const char *data, char **out);
int m2x_client_delete(m2x_context *ctx, const char *path, const char *data);

void *m2x_malloc(m2x_context *ctx, size_t len);
void *m2x_realloc(m2x_context *ctx, void *p, size_t len);
void m2x_free(void *p);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_CLIENT_H */
