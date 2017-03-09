/** @file job.h
 *  @brief Wrapper for AT&T M2X <a href="https://m2x.att.com/developer/documentation/v2/jobs">Jobs API</a>
 */
#ifndef M2X_JOB_H
#define M2X_JOB_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/jobs#List-Jobs">List Jobs</a> endpoint
 * @param ctx - m2x_context structure
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_job_list(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/jobs#View-Job-Details">View Job Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param job_id (str) - ID of the job to view details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_job_view(m2x_context *ctx, const char *job_id);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_JOB_H */
