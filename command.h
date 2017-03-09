/** @file command.h
 *  @brief Wrapper for AT&T M2X <a href="https://m2x.att.com/developer/documentation/v2/commands">Commands API</a>
 */

#ifndef M2X_COMMAND_H
#define M2X_COMMAND_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#List-Sent-Commands">List Sent Commands</a> endpoint
 * @param ctx - m2x_context structure
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_command_list(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#Send-Command">Send Command</a> endpoint
 * @param ctx - m2x_context structure
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_command_send(m2x_context *ctx, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#View-Command-Details">View Command Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param command_id (str) - ID of the command to view details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_command_view(m2x_context *ctx, const char *command_id);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_COMMAND_H */
