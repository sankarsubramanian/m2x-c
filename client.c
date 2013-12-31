#include <curl/curl.h>
#include <string.h>

#include "m2x.h"
#include "client.h"

static const char *M2X_HOST = "http://api-m2x.att.com/v1";

char *create_url(m2x_context *ctx, const char *path)
{
  int host_len, path_len;
  char *p;

  host_len = strlen(M2X_HOST);
  path_len = strlen(path);
  p = m2x_malloc(ctx, host_len + path_len + 1);
  strncpy(p, M2X_HOST, host_len);
  strcpy(p + host_len, path);
  return p;
}

typedef struct curl_write_context {
  m2x_context *m2x_ctx;
  int length;
  int index;
  char* p;
} curl_write_context;

static curl_write_context *create_write_context(m2x_context *ctx)
{
  curl_write_context *write_ctx;

  write_ctx = m2x_malloc(ctx, sizeof(curl_write_context));
  write_ctx->m2x_ctx = ctx;
  write_ctx->length = 0;
  write_ctx->index = 0;
  write_ctx->p = NULL;
  return write_ctx;
}

static void release_write_context(curl_write_context* write_ctx, int release_buf)
{
  if (release_buf) {
    m2x_free(write_ctx->p);
  }
  m2x_free(write_ctx);
}

static size_t calculate_new_length(size_t old_len, size_t need_len)
{
  size_t cal_len;

  /* NOTE: This is a very dump algorithm here, but it can be a good start. */
  if (old_len <= 0) {
    cal_len = 128;
  } else {
    cal_len = old_len / 2;
  }
  return old_len + ((need_len > cal_len) ? need_len : cal_len);
}

static size_t
write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  curl_write_context *ctx;
  int left_size, need_size;

  ctx = (curl_write_context *) userdata;
  left_size = ctx->length - ctx->index;
  need_size = size * nmemb + 1;
  if (need_size > left_size) {
    ctx->length = calculate_new_length(ctx->length, need_size);
    ctx->p = m2x_realloc(ctx->m2x_ctx, ctx->p, ctx->length);
  }

  strncpy(ctx->p + ctx->index, ptr, size * nmemb);
  ctx->index += size * nmemb;
  ctx->p[ctx->index] = '\0';
  return (size * nmemb);
}

int m2x_client_get(m2x_context *ctx, const char *path, char **out)
{
  curl_write_context *write_ctx;
  char *url;
  CURLcode res;

  write_ctx = create_write_context(ctx);
  url = create_url(ctx, path);
  curl_easy_reset(ctx->curl);
  curl_easy_setopt(ctx->curl, CURLOPT_URL, url);
  m2x_free(url);
  curl_easy_setopt(ctx->curl, CURLOPT_HTTPHEADER, ctx->headers);
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEDATA, write_ctx);
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEFUNCTION, write_callback);
  res = curl_easy_perform(ctx->curl);

  if (res != CURLE_OK) {
    fprintf(stderr, "GET failed: %s\n",
            curl_easy_strerror(res));
    release_write_context(write_ctx, 1);
    return res;
  }

  if (out != NULL) {
    *out = write_ctx->p;
  } else {
    m2x_free(write_ctx->p);
  }
  release_write_context(write_ctx, 0);
  return res;
}

int m2x_client_post(m2x_context *ctx, const char *path, const char *data,
                    char **out)
{
  curl_write_context *write_ctx;
  char *url;
  CURLcode res;

  write_ctx = create_write_context(ctx);
  url = create_url(ctx, path);
  curl_easy_reset(ctx->curl);
  curl_easy_setopt(ctx->curl, CURLOPT_URL, url);
  m2x_free(url);
  curl_easy_setopt(ctx->curl, CURLOPT_HTTPHEADER, ctx->headers);
  curl_easy_setopt(ctx->curl, CURLOPT_POSTFIELDS,
                   (data && (strlen(data) > 0)) ? data : "");
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEDATA, write_ctx);
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEFUNCTION, write_callback);
  res = curl_easy_perform(ctx->curl);

  if (res != CURLE_OK) {
    fprintf(stderr, "POST failed: %s\n",
            curl_easy_strerror(res));
    release_write_context(write_ctx, 1);
    return res;
  }

  if (out != NULL) {
    *out = write_ctx->p;
  } else {
    m2x_free(write_ctx->p);
  }
  release_write_context(write_ctx, 0);
  return res;
}

int m2x_client_put(m2x_context *ctx, const char *path, const char *data,
                   char **out)
{
  curl_write_context *write_ctx;
  char *url;
  CURLcode res;

  write_ctx = create_write_context(ctx);
  url = create_url(ctx, path);
  curl_easy_reset(ctx->curl);
  curl_easy_setopt(ctx->curl, CURLOPT_URL, url);
  m2x_free(url);
  curl_easy_setopt(ctx->curl, CURLOPT_HTTPHEADER, ctx->headers);
  curl_easy_setopt(ctx->curl, CURLOPT_CUSTOMREQUEST, "PUT");
  curl_easy_setopt(ctx->curl, CURLOPT_POSTFIELDS,
                   (data && (strlen(data) > 0)) ? data : "");
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEDATA, write_ctx);
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEFUNCTION, write_callback);
  res = curl_easy_perform(ctx->curl);

  if (res != CURLE_OK) {
    fprintf(stderr, "POST failed: %s\n",
            curl_easy_strerror(res));
    release_write_context(write_ctx, 1);
    return res;
  }

  if (out != NULL) {
    *out = write_ctx->p;
  } else {
    m2x_free(write_ctx->p);
  }
  release_write_context(write_ctx, 0);
  return res;
}

int m2x_client_delete(m2x_context *ctx, const char *path, char **out)
{
  curl_write_context *write_ctx;
  char *url;
  CURLcode res;

  write_ctx = create_write_context(ctx);
  url = create_url(ctx, path);
  curl_easy_reset(ctx->curl);
  curl_easy_setopt(ctx->curl, CURLOPT_URL, url);
  m2x_free(url);
  curl_easy_setopt(ctx->curl, CURLOPT_HTTPHEADER, ctx->headers);
  curl_easy_setopt(ctx->curl, CURLOPT_CUSTOMREQUEST, "DELETE");
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEDATA, write_ctx);
  curl_easy_setopt(ctx->curl, CURLOPT_WRITEFUNCTION, write_callback);
  res = curl_easy_perform(ctx->curl);

  if (res != CURLE_OK) {
    fprintf(stderr, "DELETE failed: %s\n",
            curl_easy_strerror(res));
    release_write_context(write_ctx, 1);
  }

  if (out != NULL) {
    *out = write_ctx->p;
  } else {
    m2x_free(write_ctx->p);
  }
  release_write_context(write_ctx, 0);
  return res;
}
