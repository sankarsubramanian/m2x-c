#include "response.h"

m2x_response m2x_make_response(m2x_context *ctx, int status, char *raw)
{
  m2x_response r;
  r.status = status;
  r.raw = raw;
  if (ctx->expand_json && raw) {
    r.json = json_parse_string(raw);
  } else {
    r.json = NULL;
  }
  return r;
}

int m2x_is_success(const m2x_response *response)
{
  return response->status >= 200 && response->status < 300;
}

int m2x_is_client_error(const m2x_response *response)
{
  return (response->status >= 400 && response->status < 500) ||
      response->status < 0;
}

int m2x_is_server_error(const m2x_response *response)
{
  return response->status >= 500;
}

int m2x_is_error(const m2x_response *response)
{
  return m2x_is_client_error(response) || m2x_is_server_error(response);
}

void m2x_release_response(m2x_response *response)
{
  if (response->raw) {
    m2x_free(response->raw);
    response->raw = NULL;
  }
  if (response->json) {
    json_value_free(response->json);
    response->json = NULL;
  }
}
